lexer grammar XMLLexer;

// 默认模式: 标签外
COMMENT: '<!--' .*? '-->' ;
CDATA: '<![CDATA[' .*? ']]>';
/**
 * 包含所有的DTD、类似<!ENTiTY ...> 的实体定义以及记号声明<!NOTATION>
 */
DTD: '<!' .*? '>' -> skip;
EntityRef: '&' Name ';' ;
CharRef: '&#' DIGIT+ ';' | '&#x' HEXDIGIT+ ';' ;

SEA_WS : (' ' | '\t' | '\r'? '\n');

OPEN : '<' -> pushMode(INSIDE) ;
XMLDeclOpen: '<?xml' S -> pushMode(INSIDE) ;
SPECIAL_OPEN: '<?' Name -> more,pushMode(PROC_INSTR);

TEXT: ~[<&]+;   // 匹配任意除<和&之外的16位字符

mode PROC_INSTR;
PI: '?>' -> popMode ; // 关闭<?...?>
IGNORE: . -> more;

mode INSIDE;
CLOSE: '>' -> popMode;
SPECIAL_CLOSE: '?>' -> popMode; // 关闭<?xml...?>
SLASH_CLOSE: '/>' -> popMode;
SLASH: '/';
EQUALS: '=';
STRING: '"' ~[<"]* '"' 
      | '\'' ~[<']* '\'' 
      ;

Name : NameStartChar NameChar* ;

S: [\t\r\n] -> skip;

// fragment 用于提取输入字符流中的一个子集，这个子集可以被包含在其他更复杂的规则中
fragment
HEXDIGIT: [a-fA-F0-9] ;

fragment
DIGIT: [0-9] ;


fragment
NameChar    :   NameStartChar
            |   '_' | '.' | DIGIT
            |   '\u00B7'
            |   '\u0300'..'\u036F'
            |   '\u203F'..'\u2040'
            ;

fragment
NameStartChar
            :   'A'..'Z' | 'a'..'z'
            |   '\u00C0'..'\u00D6'
            |   '\u00D8'..'\u00F6'
            |   '\u00F8'..'\u02FF'
            |   '\u0370'..'\u037D'
            |   '\u037F'..'\u1FFF'
            |   '\u200C'..'\u200D'
            |   '\u2070'..'\u218F'
            |   '\u2C00'..'\u2FEF'
            |   '\u3001'..'\uD7FF'
            |   '\uF900'..'\uFDCF'
            |   '\uFDF0'..'\uFFFF' // implicitly includes ['\u10000-'\uEFFFF]
            ;