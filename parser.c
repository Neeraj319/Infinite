#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 6

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
  printf("\n The size of the file is %d", size);
  rewind(fp);
  file_contents = (char *)(malloc(size + 1));
  if (file_contents == NULL) {
    printf("OS error exiting");
  }
  int index;
  index = 0;

  while ((file_contents[index++] = getc(fp)) != EOF)
    ;
  return file_contents;
}

void error(int line, char *message) {
  printf("%d -> [Error] %s", line, message);
}

void process_line(char *line) { printf("now processing line %s", line); }

void run_prompt() {
  char *line;
  int index;
  index = 0;
  int i = 2;
  for (;;) {
    printf("> ");
    line = (char *)(malloc(MAX_LINE_LENGTH));
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
