
// Generated from SqlParsing.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  SqlParsingLexer : public antlr4::Lexer {
public:
  enum {
    SCOL = 1, DOT = 2, OPEN_PAR = 3, CLOSE_PAR = 4, COMMA = 5, ASSIGN = 6, 
    STAR = 7, PLUS = 8, MINUS = 9, TILDE = 10, PIPE2 = 11, DIV = 12, MOD = 13, 
    LT2 = 14, GT2 = 15, AMP = 16, PIPE = 17, LT = 18, LT_EQ = 19, GT = 20, 
    GT_EQ = 21, EQ = 22, NOT_EQ1 = 23, NOT_EQ2 = 24, ABORT = 25, ACTION = 26, 
    ADD = 27, AFTER = 28, ALL = 29, ALTER = 30, ANALYZE = 31, AND = 32, 
    AS = 33, ASC = 34, ATTACH = 35, AUTOINCREMENT = 36, BEFORE = 37, BEGIN = 38, 
    BETWEEN = 39, BY = 40, CASCADE = 41, CASE = 42, CAST = 43, CHECK = 44, 
    COLLATE = 45, COLUMN = 46, COMMIT = 47, CONFLICT = 48, CONSTRAINT = 49, 
    CREATE = 50, CROSS = 51, CURRENT_DATE = 52, CURRENT_TIME = 53, CURRENT_TIMESTAMP = 54, 
    DATABASE = 55, DEFAULT = 56, DEFERRABLE = 57, DEFERRED = 58, DELETE = 59, 
    DESC = 60, DETACH = 61, DISTINCT = 62, DROP = 63, EACH = 64, ELSE = 65, 
    END = 66, ESCAPE = 67, EXCEPT = 68, EXCLUSIVE = 69, EXISTS = 70, EXPLAIN = 71, 
    FAIL = 72, FOR = 73, FOREIGN = 74, FROM = 75, FULL = 76, GLOB = 77, 
    GROUP = 78, HAVING = 79, IF = 80, IGNORE = 81, IMMEDIATE = 82, IN = 83, 
    INDEX = 84, INDEXED = 85, INITIALLY = 86, INNER = 87, INSERT = 88, INSTEAD = 89, 
    INTERSECT = 90, INTO = 91, IS = 92, ISNULL = 93, JOIN = 94, KEY = 95, 
    LEFT = 96, LIKE = 97, LIMIT = 98, MATCH = 99, NATURAL = 100, NO = 101, 
    NOT = 102, NOTNULL = 103, NULL_ = 104, OF = 105, OFFSET = 106, ON = 107, 
    OR = 108, ORDER = 109, OUTER = 110, PLAN = 111, PRAGMA = 112, PRIMARY = 113, 
    QUERY = 114, RAISE = 115, RECURSIVE = 116, REFERENCES = 117, REGEXP = 118, 
    REINDEX = 119, RELEASE = 120, RENAME = 121, REPLACE = 122, RESTRICT = 123, 
    RIGHT = 124, ROLLBACK = 125, ROW = 126, ROWS = 127, SAVEPOINT = 128, 
    SELECT = 129, SET = 130, TABLE = 131, TEMP = 132, TEMPORARY = 133, THEN = 134, 
    TO = 135, TRANSACTION = 136, TRIGGER = 137, UNION = 138, UNIQUE = 139, 
    UPDATE = 140, USING = 141, VACUUM = 142, VALUES = 143, VIEW = 144, VIRTUAL = 145, 
    WHEN = 146, WHERE = 147, WITH = 148, WITHOUT = 149, FIRST_VALUE = 150, 
    OVER = 151, PARTITION = 152, RANGE = 153, PRECEDING = 154, UNBOUNDED = 155, 
    CURRENT = 156, FOLLOWING = 157, CUME_DIST = 158, DENSE_RANK = 159, LAG = 160, 
    LAST_VALUE = 161, LEAD = 162, NTH_VALUE = 163, NTILE = 164, PERCENT_RANK = 165, 
    RANK = 166, ROW_NUMBER = 167, GENERATED = 168, ALWAYS = 169, STORED = 170, 
    TRUE_ = 171, FALSE_ = 172, WINDOW = 173, NULLS = 174, FIRST = 175, LAST = 176, 
    FILTER = 177, GROUPS = 178, EXCLUDE = 179, TIES = 180, OTHERS = 181, 
    DO = 182, NOTHING = 183, IDENTIFIER = 184, NUMERIC_LITERAL = 185, BIND_PARAMETER = 186, 
    STRING_LITERAL = 187, BLOB_LITERAL = 188, SINGLE_LINE_COMMENT = 189, 
    MULTILINE_COMMENT = 190, SPACES = 191, UNEXPECTED_CHAR = 192
  };

  SqlParsingLexer(antlr4::CharStream *input);
  ~SqlParsingLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

