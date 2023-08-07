#include "shell.h"
/**
 * path_append - append command to full PATH
 * @tokenized_path: path prefix for the command
 * @command: any command that is entered
 * Return: The appended path string or NULL if
 * memory allocation failed.
 */
char *path_append(char *tokenized_path, char *command)
{
	char *var1;
	char *var2;

	var1 = malloc(strlen(tokenized_path) + 2);
	if (var1 == NULL)
		return (NULL);
			
	strcpy(var1, tokenized_path);
	strcat(var1, "/");

	var2 = malloc(strlen(var1) + strlen(command) + 1);
	if (var2 == NULL)
	{
		free(var1);
		return (NULL);
	}
	strcpy(var2, var1);
	strcat(var2, command);

	free(var1);
	var1 = NULL;

	return (var2);
}
