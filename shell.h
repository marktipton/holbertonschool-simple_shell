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
char **tokenizer(char *line);
void *print_tokens(char **token_array);
int get_path(char *line);
int check_status(const char *filename);
int check_access(const char *file_path);

#endif
