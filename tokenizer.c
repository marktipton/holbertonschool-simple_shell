#include "shell.h"
#include <stdlib.h>
#include <string.h>
/**
 *
 * tokenizer - breaks a string up into an array of tokens
 *
 * @line: string to break up
 * Return: array of tokens or NULL on failure
 */
char **tokenizer(char *line, char *delim)
{
	int bufsize = 10;
	char **token_array;
	char *token;
	char *dupline;
	int i = 0;

	dupline = strdup(line);
	token_array = malloc(bufsize * sizeof(char *));
	if (token_array == NULL)
	{
		free(token_array);
		perror("malloc");
		exit(EXIT_FAILURE);
		return (NULL);
	}
	token = strtok(dupline, delim);

	while (token != NULL)
	{
		token_array[i] = strdup(token);
		if (token_array[i] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, delim);
		i++;
	}

	token_array[i] = NULL;
	return (token_array);
}
