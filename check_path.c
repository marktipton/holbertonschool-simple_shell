#include "shell.h"
/**
 * check_path - searches for the PATH variable in the env
 * @line: filename to search PATH for
 * Return: full path if PATH found and NULL if path not found
 */
char *check_path(char *line)
{
	char *path_point = NULL;
	char **env = environ;
	char **path_array;
	char *full_path;
	char *temp_path;

	while (*env != NULL)     /*Find the "PATH" variable in the environment*/
	{
		if (strncmp(*env, "PATH=", 5) == 0)
		{
			path_point = *env + 5; /*Skip "PATH=" prefix to get the actual path*/
			break;
		}
		env++;
	}
	if (path_point == NULL)
	{
		return (NULL);
	}
	path_array = tokenizer(path_point, DELIMITER);
	temp_path = path_append(path_array[5], line);
	full_path = malloc(strlen(temp_path) + 1);
	if (full_path == NULL)
	{
		free(path_array);
		return (NULL);
	}
	strcpy(full_path, temp_path);
	free(temp_path);
	return (full_path);
}
