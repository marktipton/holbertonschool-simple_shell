#include "test.h"
#include <string.h>

void printenv(void)
{
        int i = 0;

        while (environ[i])
        {
                printf("%s\n", environ[i]);
                i++;
        }
}

int check_built_in(char *str)
{
        if (str)
        {
                if (strcmp("env", str) == 0)
                {
                        printenv();
                        return (0);
                }

                else if (strcmp("exit", str) == 0)
                {
                        exit(0);
                }
        }
        return (1);
}
