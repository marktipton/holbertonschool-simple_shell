#include "shell.h"
/**
 * get_path - searches for the PATH variable in the env 
 *
 * line: filename to search PATH for
 *
 * Return: 0 if PATH found and -1 if path not found
 */
int get_path(char *line)
{
	char *path_point = NULL;
	char **path_array;
	char **env = environ;
	int i = 0;

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
		/*printf("PATH variable not found.\n");*/
		return (-1);
	}
	
	path_array = tokenizer(path_point, DELIMITER);
	
	while (path_array[i] != NULL)
	{
		printf("%s\n", path_array[i]);
		if (strcmp(line, path_array[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
