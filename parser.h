#ifndef _STDIO_H
#include <stdio.h>
#endif

void error(int, char *);

char *get_all_contents(FILE *);

void run_prompt();

FILE *open_file(char *);

enum TokenType {
  LEFT_PAREN,
  RIGHT_PAREN,
  LEFT_BRACE,
  RIGHT_BRACE,
  COMMA,
  DOT,
  MINUS,
  PLUS,
  SEMICOLON,
  SLASH,
  STAR,

  BANG,
  BANG_EQUAL,
  EQUAL,
  EQUAL_EQUAL,
  GREATER,
  GREATER_EQUAL,
  LESS,
  LESS_EQUAL,

  INDETIFIER,
  STRING,
  NUMBER,

  AND,
  FALSE,
  FUN,
  FOR,
  IF,
  NULL_TOKEN,
  OR,
  PRINT,
  RETURN,
  TRUE,
  VAR,
  WHILE,

  EOF_TOKEN,

};
