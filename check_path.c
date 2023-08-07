#include "shell.h"
/**
 * get_path - searches for the PATH variable in the env 
 *
 * line: filename to search PATH for
 *
 * Return: 0 if PATH found and -1 if path not found
 */
int check_path(char *line)
{
	char *path_point = NULL;
	char **env = environ;
	char **path_array;

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
		return (-1);
	}
	path_array = tokenizer(path_point, DELIMITER);
	path_append(path_array[5], line);

	return (0);
}
