#include "shell.h"
#include <stdlib.h>
#include <string.h>

int print_tokens(char **token_array)
{
        int i = 0;

        while (token_array[i] != NULL)
        {
                printf("%s\n", token_array[i]);
                i++;
        }
	return(i);
}
