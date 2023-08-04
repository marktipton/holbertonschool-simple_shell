#include "shell.h"
/**
 * get_path - searches for the PATH variable in the env 
 *
 * line: filename to search PATH for
 *
 * Return: 0 if PATH found and 1 if path not found
 */
int get_path(char *line)
{
	char *path_point = NULL;
	char *token = line;
	char **env = environ;

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
		return (1);
	}
	
	token = strtok(path_point, DELIMITER);
	
	while (token != NULL)     /*Loop to get the rest of the tokens*/
	{
		/*printf("%s\n", token);*/
		/*Use NULL as the first argument to get the next token*/
		token = strtok(NULL, DELIMITER);
	}
	return (0);
}
