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
<<<<<<< HEAD
                printf("File: %s\n", filename);
                printf("File permissions: %o\n", fileInfo.st_mode);
                printf("Last access time: %ld\n", fileInfo.st_atime);
                printf("Last modification time: %ld\n", fileInfo.st_mtime);
                printf("Last status change time: %ld\n", fileInfo.st_ctime);
=======
		printf("File: %s\n", filename);
>>>>>>> 9364ad827473b743819d76d40587e0e3fab2d92d
        }
        return (0);
}
int check_access(const char *file_path)
{
    	/*Check if the file exists and is executable*/
    	if (access(file_path, X_OK) == 0)
	{
		printf("You have access to execute the file: %s\n", file_path);
<<<<<<< HEAD
		return 1; /*Access granted*/
	}
	else
	{
        printf("You do not have access to execute the file: %s\n", file_path);
        return 0; /*Access denied*/
=======
		return 1;
	}
	else
	{
		perror("access");
		printf("You do not have access to execute the file: %s\n", file_path);
		return 0;
>>>>>>> 9364ad827473b743819d76d40587e0e3fab2d92d
	}
}
