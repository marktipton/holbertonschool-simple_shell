#ifndef SHELL_H
#define SHELL_H

#define DEHORS 0
#define DEDANS 1
#define BUF 1000
#define BUFSIZE 1024
#define WHITESPACE " \n\r\t"
#define DELIMITER ":;"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <signal.h>
#include <inttypes.h>
#include <errno.h>

extern char **environ;

int check_built_in(char *str);
char **tokenizer(char *line, char *delim);
int print_tokens(char **token_array);
int check_path(char *line);
int check_status(char *filename);
int check_access(char *file_path);
int execute_command(char *line);
void path_append(char *tokenized_path, char *command);

#endif
