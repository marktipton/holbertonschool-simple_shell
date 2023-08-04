#include "shell.h"
#include <string.h>
/**
 * printenv - prints environment of current process
 *
 */
void printenv(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
/**
 * check_built_in - checks if the input is env or exit
 *
 * @str: input string
 *
 * Return: 0 if env is input and 1 if input does not match
 */
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
