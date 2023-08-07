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
	size_t path_len = strlen(tokenized_path);
	size_t command_len = strlen(command);
	char *combined_path;

	if (tokenized_path == NULL || command == NULL)
		return (NULL);
		/*allocate memory to make room for '/' and '\0'*/
	combined_path = (char *)malloc((path_len + command_len + 2) * sizeof(char));
	if (combined_path == NULL)
		return (NULL);
	strcpy(combined_path, tokenized_path);
	if (combined_path[path_len - 1] != '/')
		strcat(combined_path, "/");

	strcat(combined_path, command);

	return (combined_path);
}
