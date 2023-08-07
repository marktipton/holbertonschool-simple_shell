#include "shell.h"
/**
 * path_append - append command to full PATH
 * @tokenized_path: path prefix for the command
 * @command: any command that is entered
 * Return:
 */
char *path_append(char *tokenized_path, char *command)
{
	char *var1 = strcat(tokenized_path, "/");
	char *var2 = strcat(var1, command);

	return (var2);
	/*if (var2 != NULL)*/
		/*free(var2), var2 = NULL;*/
	/*if (var1 != NULL)*/
		/*free(var1), var1 = NULL;*/
}
