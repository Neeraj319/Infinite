#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

FILE *open_file(char *file_name) {
  FILE *fp = fopen(file_name, "r");
  if (fp == NULL) {
    printf("Error opening file %s\n", file_name);
    exit(EXIT_FAILURE);
  }
  return fp;
}

char *get_all_contents(FILE *fp) {
  char c;
  char *file_contents;
  int size;

  fseek(fp, 0, SEEK_END);
  size = ftell(fp);
  rewind(fp);
  file_contents = (char *)(malloc(size + 1));
  if (file_contents == NULL) {
    printf("OS error exiting");
    exit(EXIT_FAILURE);
  }
  int index;
  index = 0;

  while ((file_contents[index++] = getc(fp)) != EOF)
    ;
  return file_contents;
}

void run_prompt() {
  char *line;
  int index;
  index = 0;
  int i = 2;
  for (;;) {
    printf("> ");
    line = (char *)(malloc(MAX_LINE_LENGTH));
    if (line == NULL) {
      printf("failed while reading from sell");
      exit(EXIT_FAILURE);
    }
    while ((line[index++] = getc(stdin)) != '\n') {
      if (line[index - 1] == EOF)
        exit(EXIT_SUCCESS);
      if (index % MAX_LINE_LENGTH == 0) {
        line = (char *)realloc(line, MAX_LINE_LENGTH * i);
      }
    }
    process_line(line);
    free(line);
    index = 0;
  }
}

Token *create_token(TokenType token_type, char *lexeme, int line) {
  Token *t;
  t = (Token *)(malloc(sizeof(Token)));
  if (t == NULL) {
    printf("failure while malloc in create Token");
    exit(EXIT_FAILURE);
  }
  t->lexeme = lexeme;
  t->line = line;
  t->type = token_type;
  return t;
}

Scanner *create_scanner(char *source) {
  Scanner *s;
  s = (Scanner *)(malloc(sizeof(Scanner)));
  if (s == NULL) {
    printf("Failure while malloc in create scanner");
    exit(EXIT_FAILURE);
  }
  s->source = source;
  s->line = 1;
  s->current = 0;
  s->start = 0;
  s->token_index = 0;
  s->tokens = malloc(sizeof(Token) * 10);
  return s;
}

Boolean is_at_end(Scanner *s) { return s->current >= strlen(s->source); }

char peek(Scanner *s) {
  if (is_at_end(s))
    return '\0';
  return s->source[s->current];
}

char advance(Scanner *s) { return s->source[s->current++]; }

void add_token(TokenType type, Scanner *s) {
  char *text;
  // fix here:
  text = (char *)(malloc(100));
  strncpy(text, s->source + s->start, s->current);
  Token *t = create_token(type, text, s->line);
  s->tokens[s->token_index++] = t;
}

Boolean match(char expected, Scanner *s) {
  if (is_at_end(s))
    return False;
  if (s->source[s->current] != expected)
    return False;
  s->current++;
  return True;
}

void scan_token(Scanner *s) {
  char c = advance(s);
  switch (c) {
  case '(':
    add_token(LEFT_PAREN, s);
    break;
  case ')':
    add_token(RIGHT_PAREN, s);
    break;
  case '{':
    add_token(LEFT_BRACE, s);
    break;
  case '}':
    add_token(RIGHT_BRACE, s);
    break;
  case ',':
    add_token(COMMA, s);
    break;
  case '.':
    add_token(DOT, s);
    break;
  case '-':
    add_token(MINUS, s);
    break;
  case '+':
    add_token(PLUS, s);
    break;
  case ';':
    add_token(SEMICOLON, s);
    break;
  case '*':
    add_token(STAR, s);
    break;
  case '!':
    add_token(match('=', s) ? BANG_EQUAL : BANG, s);
    break;
  case '=':
    add_token(match('=', s) ? EQUAL_EQUAL : EQUAL, s);
    break;
  case '<':
    add_token(match('=', s) ? LESS_EQUAL : LESS, s);
    break;
  case '>':
    add_token(match('=', s) ? GREATER_EQUAL : GREATER, s);
    break;
  case '/':
    if (match('/', s)) {
      while (peek(s) != '\n' && !is_at_end(s))
        advance(s);
    } else {
      add_token(SLASH, s);
    }
    break;
  case ' ':
  case '\r':
  case '\t':
    break;
  case '\n':
    s->line++;
    break;
  case EOF:
    return;
  default:
    error(s->line, "Unexpected character.\n");
  }
}

void error(int line, char *message) {
  printf("%d -> [Error] %s", line, message);
}

void run(char *file_contents) {
  Scanner *s = create_scanner(file_contents);
  scan_token(s);
  scan_token(s);
  scan_token(s);
  scan_token(s);
  scan_token(s);
  scan_token(s);
  scan_token(s);
  scan_token(s);
  printf("here %s", s->tokens[0]->lexeme);
}

void process_line(char *line) { printf("now processing line %s", line); }
