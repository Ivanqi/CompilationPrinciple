#include <iostream>
#include <exception>
#include "SimpleScript.h"
#include "SimpleParser.h"

using namespace std;

int SimpleScript::evaluate(ASTNode *node, string indent)
{
    int result = 0;

    if (verbose) {
        cout << indent << "Calculating: " << node->getType();
    }

    string varName = "";
    ASTNode *child1;
    ASTNode *child2;
    int value1 = 0;
    int value2 = 0;

    switch (node->getType()) {
        case ASTNodeType::Program:
            for (ASTNode *child: node->getChildren()) {
                result = evaluate(child, indent);
            }
            break;
        
        case ASTNodeType::Additive:
            child1 = node->getChildren()[0];
            value1 = evaluate(child1, indent + "\t");

            child2 = node->getChildren()[1];
            value2 = evaluate(child2, indent + "\t");

            if (node->getText() == "+") {
                result = value1 + value2;
            } else {
                result = value1 - value2;
            }
            break;
        
        case ASTNodeType::Multiplicative:
            child1 = node->getChildren()[0];
            value1 = evaluate(child1, indent + "\t");

            child2 = node->getChildren()[1];
            value2 = evaluate(child2, indent + "\t");

            if (node->getText() == "*") {
                result = value1 * value2;
            } else {
                result = value1 / value2;
            }
            break;
        
        case ASTNodeType::IntLiteral:
            result = atoi(node->getText().c_str());
            break;
        
        case ASTNodeType::Identifier:
            varName = node->getText();

            if (variables.find(varName) != variables.end()) {
                int value = variables[varName];
                    result = value;
            } else {
                throw "unknown variable: " + varName;
            }
            break;
        

        case ASTNodeType::AssignmentStmt:
            varName = node->getText();
            if (variables.find(varName) == variables.end()) {
                throw "unknown variable: " + varName;
            }
            // 接下来执行下面的代码
        
        case ASTNodeType::IntDeclaration:
            varName = node->getText();
            int varValue;

            if (node->getChildren().size() > 0) {
                ASTNode *child = node->getChildren()[0];
                result = evaluate(child, indent + "\t");
                varValue = result;
            }
            variables[varName] = varValue;
            break;

        default:
            break;
    }

    if (verbose) {
        cout << indent << "Result: " << result << endl;;
    } else if (indent == "") {  // 顶层语句
        if (node->getType() == ASTNodeType::IntDeclaration || node->getType() == ASTNodeType::AssignmentStmt) {
            cout << node->getText() + ": " << result << endl;;
        } else if (node->getType() != ASTNodeType::Program){
            cout << result << endl;
        }
    }
}

void SimpleScript::REPL(int argc, char* argv[])
{
    if (argc > 0 && strcmp(argv[0], "-v")) {
        verbose = true;
        cout << "verbose mode" << endl;
    }

    cout << "Simple script language!" << endl;

    SimpleParser *parser = new SimpleParser();
    SimpleScript *script = new SimpleScript();
    
    string reader;

    string scriptText;
    cout << "\n>";  // 提示符

    while (true) {
        try {
            cin >> reader;
            string line = trim(reader);
            if (line == "exit();") {
                cout << "Good Bye!" << endl;
                break;
            }

            scriptText += line + "\n";
            if (endsWith(line, ";")) {
                ASTNode *tree = parser->parse(scriptText);
                if (verbose) {
                    parser->dumpAST(tree, "");
                }

                script->evaluate(tree, "");

                cout << "\n>";  // 提示符

                scriptText = "";
            }
        } catch (exception &e) {
            cout << e.what() << endl;
            cout << "\n>";  // 提示符
            scriptText = "";
        }
    }
}