#include "shell.h"
/**
 *
 * free_tokens - free memory allocated for tokens and the token array
 *
 * @tokens: pointer to the array of tokens
 */
void free_tokens(char **tokens)
{
	int i;

	if (tokens != NULL)
	{
		for (i = 0; tokens[i] != NULL; i++)
		{
			free(tokens[i]);
		}
		free(tokens);
	}
}
