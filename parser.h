#ifndef _STDIO_H
#include <stdio.h>
#endif

void error(int, char *);

char *get_all_contents(FILE *);

void run_prompt();

void process_line(char *line);

FILE *open_file(char *file_name);

typedef enum TokenType {
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

} TokenType;

typedef struct Token {
  TokenType type;
  char *lexeme;
  int line;
} Token;

typedef enum Boolean {
  False,
  True,
} Boolean;

Token *create_token(TokenType token_type, char *lexeme, int line);

typedef struct Scanner {
  char *source;
  Token **tokens;
  int line;
  int start;
  int token_index;
  int current;

} Scanner;

Scanner *create_scanner(char *source);

Token *scan_tokens(Scanner *s);

char peek(Scanner *s);

Boolean is_at_end(Scanner *s);

void add_token(TokenType type, Scanner *s);

char advance(Scanner *s);

void scan_token(Scanner *s);

Boolean match(char expected, Scanner *s);
void run(char *file_contents);
