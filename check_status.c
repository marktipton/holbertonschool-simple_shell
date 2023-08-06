#include "shell.h"
/**
 * check_status - checks if a file exists
 *
 * @filename: string name of file to check
 *
 * Return: 0 if file exists and -1 if no file found
 */
int check_status(char *filename)
{
	struct stat fileInfo;
	
	if (stat(filename, &fileInfo) != 0)
	{
		fprintf(stderr, "hsh: %s: command not found\n", filename);
		return (-1);
	}
	if (check_access(filename) == 0)
	{
		execute_command(filename);
	}
	return (0);
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
