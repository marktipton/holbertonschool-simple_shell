#include "shell.h"
#include <stdlib.h>
#include <string.h>
/**
 * tokenizer - breaks a string up into an array of tokens
 * @line: string to break up
 * @delim: characters to look for
 * Return: array of tokens or NULL on failure
 */
char **tokenizer(char *line, char *delim)
{
	int bufsize = 10;
	char **token_array;
	char *token, *dupline;
	int i = 0, j = 0;

	dupline = strdup(line);
	token_array = malloc(bufsize * sizeof(char *));
	if (token_array == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	token = strtok(dupline, delim);

	while (token != NULL)
	{
		token_array[i] = strdup(token);
		if (token_array[i] == NULL)
		{
			perror("strdup");
			for (; j < i; j++)
			{
				free(token_array[j]);
			}
			free(token_array);
			free(dupline);
			return (NULL);
		}
		token = strtok(NULL, delim); /*Retrieve next token*/
		i++;
	}
	token_array[i] = NULL;
	free(dupline);
	return (token_array);
}
