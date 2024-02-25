parser grammar XMLParser;
options { tokenVocab=XMLLexer; } // 指定词法规则文件

document: prolog? misc* element misc*;

prolog: XMLDeclOpen attribute* SPECIAL_CLOSE;

content: chardata? ((element | reference | CDATA | PI | COMMENT) chardata?)* ;

element: '<' Name attribute* '>' content '<' '/' Name '>' 
       | '<' Name attribute* '/>'
       ;

reference: EntityRef | CharRef ;

attribute: Name '=' STRING ; // 我们的 STRING 就是规范里的AttValue

/**
 * 其余所有未标记的文本构成了文档中的字符数据
 */
chardata: TEXT | SEA_WS;

misc: COMMENT | PI | SEA_WS ;