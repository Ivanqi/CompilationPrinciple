# 命令使用
```
cd src
antlr XMLLexer.g4
antlr XMLParser.g4
javac XML*.java
```

通过 grun 生成AST
```
grun XML document -gui ../inputs/book.xml
```

结果:
![avatar](./images/book_xml.png)

# Antlr 规则
## lexer grammar
在 Antlr 中，"lexer grammar" 指的是用 Antlr 定义的词法分析器的语法规则

词法分析器（Lexer）负责将输入的源代码字符流（charstream）分割成一系列的标记（tokens），这些标记是构成语法分析的基本元素

lexer grammar 通常包含一系列的规则，这些规则定义了如何将输入的字符序列识别为不同的标记

例如
```
lexer grammar SimpleLexer;

fragment DIGIT : '0'..'9';
NUMBER : DIGIT+;     
```

在这个例子中，NUMBER 标记由一个或多个连续的数字字符组成，而 DIGIT 是一个片段规则（fragment），它定义了数字字符的范围

词法规则通常包含片段规则，这样可以重用常见的字符定义而不必重复

## parser grammar
在 Antlr 中，"parser grammar" 指的是用 Antlr 定义的语法分析器的语法规则

语法分析器（Parser）负责根据语法规则解析由词法分析器（Lexer）处理后的标记流（token stream），以构建抽象语法树（AST）

parser grammar 定义了如何将标记序列组合成更高级的语法结构，如表达式、语句和程序块等

例子 
```
grammar SimpleParser;

// 定义操作符的优先级
operators : ('+' | '-' | '*' | '/')*;

expression
    :   NUMBER (operators NUMBER)*
    ;

fragment DIGIT : '0'..'9';
NUMBER : DIGIT+;   
```
- 在这个例子中，expression 规则定义了一个表达式，它可以包含一个数字和一个由操作符和数字组成的序列
- operators 规则定义了操作符的集合，并且通过使用圆括号来指定它们的优先级
- fragment DIGIT 是一个片段规则，它定义了数字字符的范围，这样可以在不重复定义的情况下重用

## options
在 Antlr 中，"options" 是指在语法规则文件中定义的一系列配置选项，这些选项可以影响 Antlr 生成分析器的 behavior

options 块位于语法规则文件的最顶端，在定义词法规则和语法规则之前

这些选项可以用于指定 Antlr 的一些行为，例如错误处理、解析器的类型、代码生成选项等

例子:
```

grammar MyGrammar;

options {
    language = Java;                   // 指定生成解析器的目标语言
    output = "AST";                    // 指定输出类型为抽象语法树（AST）
    backtrack = true;                  // 开启回溯，允许在遇到解析问题时回退
    tokenVocab = MyLexer;              // 指定使用已定义的词法规则
}

// 词法规则和语法规则...

        
```
- 在上面的例子中，language 选项指定了生成的解析器的目标语言为 Java
- output 选项指定了输出类型为 AST，这意味着 Antlr 将生成可以构建和遍历抽象语法树的代码
- backtrack 选项启用回溯机制，这在解析复杂或者模糊的输入时非常有用
- tokenVocab 选项允许你指定一个已定义的词法规则集，以便在语法规则中使用

## tokenVocab
tokenVocab是ANTLR4（Another Tool for Language Recognition）中的一个选项，它指的是一个词法规则文件，这个文件定义了一组Token

Token是词法分析器识别的基本元素，比如关键字、标识符、运算符等。使用tokenVocab可以映射词法规则中定义的Token到实际的Token类型，这样在语法分析阶段就可以使用这些Token类型来构建抽象语法树（AST）

如果没有指定tokenVocab，ANTLR会使用默认的Token词汇表。通过设置tokenVocab，可以避免与ANTLR标准Token类型冲突，使得生成的代码更易于理解和维护

例子:
```
antlr lexer grammar MyLexer; options { tokenVocab = MyLexer; // 指定词法规则文件 } 
```
- MyLexer是一个词法规则文件，它定义了Token的词汇表，这个词汇表会被用来生成词法分析器

## fragment
fragment 在 ANTLR 中指的是一个语法规则的一部分，它用于定义一个语法规则的字符串部分，但不构成完整的语法规则

换句话说，fragment 用于提取输入字符流中的一个子集，这个子集可以被包含在其他更复杂的规则中

使用 fragment 关键字定义的规则不能单独出现，它们必须作为其他规则的一部分。这通常用于处理那些出现在多个不同规则中的共同片段

例如，如果你想定义一个通用的数字字面量片段，你可以创建一个名为 NumberFragment 的规则，然后在需要处理数字的地方引用它

例子
```
fragment
Digit : '0'..'9';

fragment
Letter : 'a'..'z' | 'A'..'Z';

Identifier : Letter (Letter | Digit | '_')*;
```
在这个例子中，Digit 和 Letter 被定义为 fragment，因为它们只是用于构成更复杂的规则 Identifier

Identifier 规则使用 Letter、Digit 和下划线 _ 来定义一个标识符，而这些片段规则则被包含在 Identifier 中

## -> skip
在ANTLR中，-> skip 是一个语法规则，用于告诉词法分析器在匹配某个特定的标记或模式时，忽略该标记或模式本身以及其后面的所有内容，而不产生任何词法单元

这通常用在词法分析器的规则中，以避免在语法分析阶段处理不需要的标记

例子:
```
TOKEN_IGNORE : ('a'..'z'|'A'..'Z'|'0'..'9'|' ')* -> skip;     
```
- 这个规则定义了一个名为TOKEN_IGNORE的词法规则，它匹配由小写字母、大写字母、数字和空格组成的任意字符序列
- -> skip部分告诉ANTLR在匹配到这个规则时，忽略匹配到的内容，不将其作为词法单元输出

## pushMode
在 ANTLR（Another Tool for Language Recognition）中，pushMode 是一个用于在解析过程中临时改变词法模式（lexer mode）的机制

词法模式是 ANTLR 用于处理不同词法元素（tokens）的上下文设置，比如，它决定了哪些字符序列被视为单词的一部分

例子:
```

mode MODE1;
MODE1 : 'a'..'z' | 'A'..'Z' | '0'..'9' | ' ' -> skip;

mode MODE2;
MODE2 : '(' -> pushMode(MODE1); // 切换到 MODE1
        ')' -> popMode;         // 切换回当前模式（MODE2）
     
```
- 在这个例子中，当解析器遇到左括号 ( 时，它会切换到 MODE1 模式，这样就可以正确地识别括号内的字符
- 当解析器遇到右括号 ) 时，它会切换回之前的模式（在这个例子中是 MODE2）
- pushMode 和 popMode 方法用于管理这个模式栈

## mode
在ANTLR（Another Tool for Language Recognition）中，mode是指定词法分析器（lexer）在解析文本时的一种状态或模式

mode通常用于处理不同上下文中的文本，例如，在处理括号内的文本时，可以进入一个模式，处理完括号内的内容后再退出该模式

在ANTLR中，可以通过pushMode()和popMode()方法来切换和退出模式。pushMode()用于进入一个新模式，而popMode()用于返回到之前的模式。这样，lexer就可以在不同的模式之间切换，以便正确地识别和处理文本。

例如
- 假设我们有一个模式切换的规则，当遇到begin关键字时，我们进入一个名为block的模式
- 当遇到end关键字时，我们退出block模式返回到之前的模式
- 这种情况下，mode帮助我们管理不同的解析上下文，确保文本被正确地解析



# 参考资料
- [Ubuntu 20.04桌面版 安装Antlr4](https://blog.csdn.net/drutgdh/article/details/122603220)
- [XML 解析详解 - 四种解析方式](https://zhuanlan.zhihu.com/p/191476342)