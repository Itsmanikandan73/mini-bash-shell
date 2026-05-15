// This program will showcase the simple bash shell

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 64
#define MAX_LINE 1024

void parse_command(char *line, char **args) {
  int i = 0;
  char *token = strtok(line, "\t\n");
  while (token != NULL && i < MAX_ARGS -1) {
    args[i++] = token;
    token = strtok(NULL, " \t\n");
  }
  args[i] = NULL;
}

int main(void) {
  char line[MAX_LINE];
  char *args[MAX_ARGS];

  while (1) {
    puts("bash-shell> ");
    fflush(stdout);

    if (fgets(line , MAX_LINE, stdin) == NULL) break;

    // Removing newline
    line[strcspn(line, "\n")] = 0;

    if (strlen(line) == 0) continue;

    parse_command(line, args);

    if (strcmp(args[0], "exit") == 0){
      break;
    }

    if (strcmp(args[0], "cd") == 0) {
      if (args[1]) chdir(args[1]);
      continue;
    }

    pid_t pid = fork();

    if (pid == 0) {
      // child process
      execvp(args[0], args);
      perror("exec failed");
      exit(1);
    }
    else if (pid > 0) {
      // Parent process
      wait(NULL);
    }
    else {
      perror("fork failed");
    }
  }
  
  puts("Goodbye!");
  return 0;
}

