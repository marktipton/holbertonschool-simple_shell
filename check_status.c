#include "shell.h"
/**
 * check_status - checks if a file exists
 * @userinput: string name of file to check
 * Return: 0 if file exists and -1 if no file found
 */
int check_status(char *userinput)
{
	struct stat fileInfo;
	char *full_path;
	int result = -1;

	full_path = check_path(userinput);
	if (full_path != NULL && userinput != NULL)
	{
		if (stat(userinput, &fileInfo) == 0) /*check if user put in name of file*/
		{
			if (check_access(userinput) == 0)
			{
				execute_command(userinput);
				result = 0;
			}
		}
		else if (stat(full_path, &fileInfo) == 0) /*check if user put in existing cmd*/
		{
			if (check_access(full_path) == 0)
			{
				execute_command(full_path);
				result = 0;
			}
		}
		else
		{
			fprintf(stderr, "hsh: %s: command not found\n", userinput);
			result = -1;
		}
		free(full_path);
	}
	return (result);
}
/**
 * check_access - checks if user has permission to execute a file
 * @file_path: full path name of executable file
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
		/*perror("access");*/
		/*printf("You do not have access to execute the file: %s\n", file_path);*/
		return (-1);
	}
}
