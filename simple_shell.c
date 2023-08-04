#include "shell.h"
/**
 * main - func to loop through builtins
 * @argc: this isn't really used and we'll take it out
 * @argv: this isn't really used and we'll take it out
 * @env: this isn't really used and we'll take it out
 * Return: 0 for success
 */
int main(int argc, char **argv, char **env)
{
	char *line = NULL;
	size_t len = 0;
	int fd = STDIN_FILENO;
	ssize_t nchars_read;
	char **tokstr;

	(void)argc;
	(void)argv;
	(void)env;

	while (1)
	{
		if (isatty(fd) == 1)
			printf("$ ");
		nchars_read = getline(&line, &len, stdin);

		if (nchars_read == -1)
		{
			perror("getline");
			free(line);
			exit(1);
		}

		if (nchars_read == 1)
		{
			free(line);
			printf("\n");
			return (0);
		}
		tokstr = tokenizer(line, WHITESPACE);
		check_built_in(tokstr[0]);
		check_status(tokstr[0]);
		get_path(line);
		free(tokstr);
	}
	return (0);
}
