#include "shell.h"
#include <stdlib.h>
#include <string.h>
char **tokenizer(char *line)
{
        int bufsize = 10;
        char **token_array;
        char *token;
        int i = 0;

        token_array = malloc(bufsize * sizeof(char *));
        if (token_array == NULL)
        {
                perror("malloc");
                exit(EXIT_FAILURE);
		return(0);
        }
        token = strtok(line, WHITESPACE);

        while (token != NULL)
        {
                token_array[i] = strdup(token);
                if (token_array[i] == NULL)
                {
                        perror("strdup");
                        exit(EXIT_FAILURE);
                }
                token = strtok(NULL, WHITESPACE);
                i++;
        }

        token_array[i] = NULL;
        return (token_array);
}
