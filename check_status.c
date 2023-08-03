#include "shell.h"

int check_status(const char *filename)
{
        struct stat fileInfo;
	
        if (stat(filename, &fileInfo) != 0)
        {
                printf("file does not exist");
                perror("Error in stat");
                return -1;
        }
        else
        {
		printf("File: %s\n", filename);
        }
        return (0);
}
int check_access(const char *file_path)
{
    	// Check if the file exists and is executable
    	if (access(file_path, X_OK) == 0)
	{
		printf("You have access to execute the file: %s\n", file_path);
		return 1;
	}
	else
	{
		perror("access");
		printf("You do not have access to execute the file: %s\n", file_path);
		return 0;
	}
}
