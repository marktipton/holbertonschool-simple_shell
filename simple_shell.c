#include "shell.h"
/**
 * main - prompts user for input
 * @argc: number of arguments passed in
 * @argv: array of argument strings
 * @env: array of environment strings
 * Return: 0 for success
 */
int main(int argc, char **argv, char **env)
{
	char *line = NULL;
	size_t len = 0;
	int fd = STDIN_FILENO;
	ssize_t nchars_read;
	char **tokstr;
	int status;

	(void)argc;
	(void)argv;
	(void)env;

	while (1)
	{
		if (isatty(fd) == 1)
			printf("$ ");
		nchars_read = getline(&line, &len, stdin);
		if (nchars_read == -1)    /*If EOF from Ctrl+D input*/
		{
			printf("\n");
			free(line);
			exit(0);
		}
		tokstr = tokenizer(line, WHITESPACE);
		check_built_in(tokstr[0]);
		status = check_status(tokstr[0]);
		if (status != 0)
			get_path(line);
		free(tokstr);
	}
	return (0);
}
