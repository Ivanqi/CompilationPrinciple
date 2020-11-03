#include <iostream>
#include <map>

#include "antlr4-runtime.h"
#include "SqlParsingLexer.h"
#include "SqlParsingParser.h"
#include "SQLVisitor.h"
#include "SelectStmt.h"
#include "WhereExpr.h"
#include "tree/ParseTree.h"

using namespace std;
using namespace antlr4;

map<string, string> region2DB = {
    {"SDYT", "db1"},
    {"BJHD", "db2"},
    {"FJXM", "db3"},
    {"SZLG", "db4"}
    
};

int main(int argc, const char* argv[]) {

    if (argc < 2) {
        cout << "缺少测试文件" << endl; 
        return 0;
    }

    const char* filepath = argv[1];

    ifstream ifs;

    ifs.open(filepath);

    ANTLRInputStream *input = new ANTLRInputStream(ifs);

    // 词法解析
    SqlParsingLexer *lexer = new SqlParsingLexer(input);
    CommonTokenStream *tokens = new CommonTokenStream(lexer);

    tokens->fill();

    // 语法解析
    SqlParsingParser *parser = new SqlParsingParser(tokens);
    tree::ParseTree *tree = parser->sql_stmt();

    // 以 lisp格式打印AST
    cout << tree->toStringTree(parser) << endl;

    cout << " --------- " << endl;

    // 获取select 语句要素，包括表名和where条件
    SQLVisitor *visitor = new SQLVisitor();

    SelectStmt *select;
    antlrcpp::Any result = visitor->visit(tree);
    if (result.is<SelectStmt*>()) {
        select = result.as<SelectStmt*>();
    } else {
        cout << "visit error" << endl;
        return 0;
    }

    string dbName = "";

    if (select->tableName_ == "orders") {
        if (select->whereExprs_.size() > 0) {
            list<WhereExpr*>::iterator it;
            for (it = select->whereExprs_.begin(); it != select->whereExprs_.end(); it++) {
                WhereExpr *expr = *it;
                // 根据 cust_id 或 order_id 来确定库的名称
                if (expr->columnName_.compare("curst_id") || expr->columnName_.compare("order_id")) {
                    // 取编号的前4位，即区域编码
                    string region = expr->value_.substr(1, 4);
                    // 根据区域编码，获取库名称
                    dbName = region2DB[region];
                    break;
                }
            }
        }
    }

    cout << "数据库名称:" << dbName << endl;

    return 0;
}