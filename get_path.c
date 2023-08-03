#include "shell.h"

int get_path(char *line)
{
    char *path_point = NULL;
    char *token = line;
    char **env = environ;

    /*Find the "PATH" variable in the environment*/
    while (*env != NULL)
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
        /*"PATH" variable not found in the environment*/
        printf("PATH variable not found.\n");
        return (1);
    }

    /*Use strtok to tokenize the PATH string*/
    token = strtok(path_point, DELIMITER);

    /*Loop to get the rest of the tokens*/
    while (token != NULL)
    {
        /*Process the token (e.g., print it)*/
        printf("%s\n", token);

        /*Use NULL as the first argument to get the next token*/
        token = strtok(NULL, DELIMITER);
    }

    return (0);
}
