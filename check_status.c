#include "test.h"

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
                printf("File size: %lld bytes\n", (long long)fileInfo.st_size);
                printf("File permissions: %o\n", fileInfo.st_mode);
                printf("Last access time: %ld\n", fileInfo.st_atime);
                printf("Last modification time: %ld\n", fileInfo.st_mtime);
                printf("Last status change time: %ld\n", fileInfo.st_ctime);
        }
        return (0);
}
