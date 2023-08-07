#include "shell.h"
/**
 * check_status - checks if a file exists
 *
 * @userinput: string name of file to check
 *
 * Return: 0 if file exists and -1 if no file found
 */
int check_status(char *userinput)
{
	struct stat fileInfo;
	char *full_path;

	full_path = check_path(userinput);
	if (stat(userinput, &fileInfo) == 0)
	{
		if (check_access(userinput) == 0)
		{
			execute_command(userinput);
			free(userinput);
		}
		return (0);
	}	
	else if (stat(full_path, &fileInfo) == 0)
	{
		if (check_access(full_path) == 0)
		{
			execute_command(full_path);
			free(full_path);
		}
		return (0);
	}
	else
	{
		fprintf(stderr, "hsh: %s: command not found\n", userinput);
		return (-1);
	}

}
/**
 * check_access - checks if user has permission to execute a file
 *
 * file_path: full path name of executable file
 *
 * Return: 0 if user has access and -1 if user does not have access
 */
int check_access(char *file_path)
{
	if (access(file_path, X_OK) == 0)
	{
		return (0);
	}
	else
	{
		perror("access");
		printf("You do not have access to execute the file: %s\n", file_path);
		return (-1);
	}
}
