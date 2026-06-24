// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
//
#![allow(dead_code)]
mod backend;    // 后端代码生成模块
mod ir;         // 中间表示模块
mod parser;     // 解析器模块
mod ssa;        // SSA优化模块
mod util;       // 工具函数模块

use std::{collections::HashMap, error::Error, path::PathBuf};

use clap::Parser;

/// 命令行参数结构体
#[derive(Parser, Debug)]
#[command(author, version, about)]
struct Args {
    input_files: Vec<PathBuf>,      // 输入文件列表
    #[arg(short = 'o', long = "outdir")]
    output_dir: PathBuf,            // 输出目录
    #[arg(short = 'g', long, default_value_t = false)]
    no_optimize: bool,              // 是否禁用优化
}

/// 库的主函数，处理编译流程
pub fn lib_main() {
    // 解析命令行参数
    let args = Args::parse();
    
    // 验证输入文件
    if let Err(e) = { validate_input(&args.input_files) } {
        eprintln!("Error during argument validation: {}", e);
        return;
    }
    
    // 获取输出目录字符串
    let outdir = if let Some(s) = args.output_dir.to_str() {
        s
    } else {
        eprintln!("'outdir' parsing error");
        return;
    };
    
    // 读取所有输入文件内容
    let strings = args
        .input_files
        .iter()
        .map(std::fs::read_to_string)
        .map(|res| {
            res.map_err(|e| -> Box<dyn Error> {
                format!("cannot read from input file: {e}").into()
            })
        })
        .collect::<Result<Vec<_>, _>>();
    if let Err(e) = strings {
        eprintln!("Error during parsing: {e}");
        return;
    }
    let strings = strings.unwrap();
    // 解析和验证所有文件
    let parsed: Result<Vec<_>, _> = strings
        .iter()
        .map(|s| parser::parse_and_validate(s))
        .collect();
    if let Err(e) = parsed {
        eprintln!("Error during parsing: {e}");
        return;
    }
    
    // 处理全局变量和函数
    let mut globals = HashMap::new();
    let mut dual = false;
    let linearized: Vec<_> = parsed
        .unwrap()
        .into_iter()
        .map(|p| {
            // 将程序转换为中间表示
            let mut ctx = ir::Context::default();
            ir::translate_program(&mut ctx, &p);
            
            // 检查全局变量类型冲突
            for (name, ty) in &ctx.globals {
                if globals.get(name).map_or(false, |t| t != ty) {
                    eprintln!("dual declaration with different types for {}.", name);
                    dual = true;
                }
                globals.insert(name.clone(), *ty);
            }
            ctx
        })
        .collect();
    if dual {
        return;
    }
    
    // 收集所有函数并转换为SSA形式
    let funs_iter = linearized
        .into_iter()
        .flat_map(|ctx| ctx.functions.into_iter());
    let mut funs = HashMap::new();
    for (name, fun) in funs_iter {
        // println!("name: {:#?}", name);
        if funs.contains_key(&name) {
            eprintln!("Two functions with conflicting names {name}");
            return;
        }
        // 转换为控制流图并生成SSA形式
        funs.insert(name, fun.into_cfg().into_ssa());
    }

    // 应用SSA优化（如果未禁用优化）
    for v in funs.values_mut() {
        println!("cfg: {:#?}", v.get_body_mut());
        if !args.no_optimize {
            ssa::optimization_sequence(v.get_body_mut())
                .unwrap_or_else(|_| panic!("Bug found, please open an issue"));
        }
    }
    
    // 生成汇编代码
    let funs = funs.into_iter().map(|(k, v)| {
        let v = backend::to_assembly(v.into_body(), &k);
        (k, v)
    });
    
    // 将函数汇编代码写入文件
    for (name, body) in funs {
        let out_path = format!("{outdir}/{name}.s");
        let res = std::fs::write(&out_path, body);
        if let Err(e) = res {
            eprintln!("Error writing output file: {out_path}\n{e}");
            return;
        }
    }
    
    // 生成全局变量汇编代码并写入文件
    let global_asm = backend::globals_to_assembly(globals);
    let res = std::fs::write(format!("{outdir}/_globals.s"), global_asm);
    if let Err(e) = res {
        eprintln!("Error writing output file: {outdir}/_globals.s\n{e}");
    }
}

/// 验证输入文件是否有效
/// 
/// # 参数
/// - `input`: 输入文件路径列表
/// 
/// # 返回
/// 如果所有文件都存在且有效则返回Ok，否则返回错误
fn validate_input(input: &[PathBuf]) -> Result<(), Box<dyn std::error::Error>> {
    for input in input {
        if !input.is_file() {
            return Err(format!(
                "input {} is not a valid file",
                input.to_str().unwrap_or("INVALID_UTF8")
            )
            .into());
        }
    }
    Ok(())
}

/// 测试模块
#[cfg(test)]
mod tests {
    use super::ir::*;

    /// 测试中间表示生成
    #[test]
    fn test_ir() {
        let input = "
        myvar3 :: Bool;
        lambda myfun(myvar3 :: Int) :: Int {
            myvar4 :: Int = 0;
            if myvar2 then {
                myvar4 = myvar3;
            } else {
                myvar4 = 33;
            }
            return myvar4;
        }
        myvar2 :: Bool;
        ";

        let p = super::parser::parse_and_validate(input).unwrap();

        let mut context = Context::new();
        translate_program(&mut context, &p);
        let funs = context.get_functions();
        let fun = funs.get("myfun").unwrap();
        let body = fun.get_body();
        let params = fun.get_params();
        let expected = "
        li rd1, #0
        li rd2, #0
        la rd3, @myvar2
        load rd4, rd2, rd3
        li rd5, #1
        beq rd4, rd5, @_LABEL_0, @_LABEL_1
@_LABEL_0:
        mv rd1, rd0
        j @_LABEL_2
@_LABEL_1:
        li rd6, #33
        mv rd1, rd6
        j @_LABEL_2
@_LABEL_2:
        return rd1
@_LABEL_3:";
        assert_eq!(
            expected
                .chars()
                .filter(|c| !c.is_whitespace())
                .collect::<String>(),
            Displayable(&body[..])
                .to_string()
                .chars()
                .filter(|c| !c.is_whitespace())
                .collect::<String>()
        );
        assert_eq!(&params[..], &[0][..])
    }

    /// 测试控制流图生成
    #[test]
    fn test_cfg() {
        let input = "
        myvar3 :: Bool;
        lambda myfun(myvar3 :: Int) :: Int {
            myvar4 :: Int = 0;
            i :: Int = 100;
            while (i >= 0) do {
                if i / 2 / 2 / 2 < 2 then {
                    myvar4 = myvar4 * 3;
                } else {
                    myvar4 = myvar4 / 2;
                }
            }
           return myvar4;
        }
        myvar2 :: Bool;
        ";

        let p = super::parser::parse_and_validate(input).unwrap();
        let mut context = Context::new();
        translate_program(&mut context, &p);
        let funs = context.get_functions();
        let fun = funs.get("myfun").unwrap();
        let body = fun.get_body();
        println!("{}", Displayable(&body[..]));
        let params = fun.get_params();
        /*
        rd1 = myvar4
        rd2 = i
         */
        let expected = "
        li rd1, #0
        li rd2, #100
        j @_LABEL_0
@_LABEL_0:
        li rd4, #0
        slt rd5, rd2, rd4
        li rd6, #1
        xor rd7, rd6, rd5
        li rd3, #0
        beq rd7, rd3, @_LABEL_1, @_LABEL_2
@_LABEL_2:
        li rd8, #2
        div rd9, rd2, rd8
        li rd10, #2
        div rd11, rd9, rd10
        li rd12, #2
        div rd13, rd11, rd12
        li rd14, #2
        slt rd15, rd13, rd14
        li rd16, #1
        beq rd15, rd16, @_LABEL_3, @_LABEL_4
@_LABEL_3:
        li rd17, #3
        mult rd18, rd1, rd17
        mv rd1, rd18
        j @_LABEL_5
@_LABEL_4:
        li rd19, #2
        div rd20, rd1, rd19
        mv rd1, rd20
        j @_LABEL_5
@_LABEL_5:
        j @_LABEL_0
@_LABEL_1:
        return rd1
@_LABEL_6:";
        assert_eq!(
            expected
                .chars()
                .filter(|c| !c.is_whitespace())
                .collect::<String>(),
            Displayable(&body[..])
                .to_string()
                .chars()
                .filter(|c| !c.is_whitespace())
                .collect::<String>()
        );
        assert_eq!(&params[..], &[0][..]);

        let cfg = CFG::from_linear(body, fun.get_params(), fun.get_max_reg());
        println!("{:?}", cfg);
        assert_eq!(
            cfg.get_block(0).body,
            vec![
                Operator::GetParameter(0, 0),
                Operator::Li(1, 0),
                Operator::Li(2, 100),
                Operator::J(std::rc::Rc::from("_LABEL_0"))
            ]
        );
        assert_eq!(cfg.get_block(0).children, vec![1]);
        assert_eq!(cfg.get_block(0).idom, None);
        assert_eq!(cfg.get_block(1).children, vec![6, 2]);
        assert_eq!(cfg.get_block(1).idom.unwrap(), 0);
        assert_eq!(cfg.get_block(2).children, vec![3, 4]);
        assert_eq!(cfg.get_block(2).idom.unwrap(), 1);
        assert_eq!(cfg.get_block(3).children, vec![5]);
        assert_eq!(cfg.get_block(3).idom.unwrap(), 2);
        assert_eq!(cfg.get_block(4).children, vec![5]);
        assert_eq!(cfg.get_block(4).idom.unwrap(), 2);
        assert_eq!(cfg.get_block(5).children, vec![1]);
        assert_eq!(cfg.get_block(5).idom.unwrap(), 2);
        assert_eq!(cfg.get_block(6).children, vec![7]);
        assert_eq!(cfg.get_block(6).idom.unwrap(), 1);
        assert_eq!(cfg.get_block(7).children, vec![]);
        assert_eq!(cfg.get_block(7).idom.unwrap(), 6);
        cfg.into_ssa();
    }

    /// 测试空函数的控制流图生成
    #[test]
    fn test_cfg_empty() {
        let input = "
        lambda myfun() :: Int {

        }
        ";

        let p = super::parser::parse_and_validate(input).unwrap();
        let mut context = Context::new();
        translate_program(&mut context, &p);
        let funs = context.get_functions();
        let fun = funs.get("myfun").unwrap();
        let body = fun.get_body();
        println!("{}", Displayable(&body[..]));
        let params = fun.get_params();
        /*
        rd1 = myvar4
        rd2 = i
         */
        let expected = "";
        assert_eq!(
            expected
                .chars()
                .filter(|c| !c.is_whitespace())
                .collect::<String>(),
            Displayable(&body[..])
                .to_string()
                .chars()
                .filter(|c| !c.is_whitespace())
                .collect::<String>()
        );
        assert_eq!(&params[..], &[][..]);

        let cfg = CFG::from_linear(body, fun.get_params(), fun.get_max_reg());
        println!("{:?}", cfg);
        assert_eq!(cfg.get_block(0).children, vec![]);
        assert_eq!(cfg.get_block(0).idom, None);
    }
}
