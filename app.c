#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  if (argc == 2) {
    FILE *file = open_file(argv[1]);
    char *file_contents = get_all_contents(file);
  } else {
    run_prompt();
  }
}
