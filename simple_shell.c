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
	ssize_t nchars_read, count = 0;
	char **tokarray;

	(void)argc, (void)argv, (void)env;

	while (1)
	{
		if (isatty(fd) == 1)
			printf("$ ");
		nchars_read = getline(&line, &len, stdin);
		if (nchars_read == -1)/* if EOF from Ctrl+D input*/
		{
			free(line);
			exit(0);
		}
		count = check_whitespace(line, nchars_read);
		if (nchars_read == count)
			continue;
		tokarray = tokenizer(line, WHITESPACE);
		if ((check_built_in(tokarray[0]) == 0))
		{
			free_tokens(tokarray);
			continue;
		}
		check_status(tokarray[0]);
		free_tokens(tokarray);
	}
	free(line);
	return (0);
}
