#include "shell.h"

/**
 * check_whitespace - counts the amount of whitespace in input
 *
 * @line: user input string
 * @line_len: number of characters in user input string
 * Return: count of whitespace in input line
 */
int check_whitespace(char *line, ssize_t line_len)
{
	ssize_t whitespace_len = strlen(WHITESPACE);
	ssize_t i = 0, j = 0, count = 0;

	for (; i < line_len; i++)
	{
		for (; j < whitespace_len; j++)
		{
			if (line[i] == WHITESPACE[j])
				count++;
		}
	}
	return (count);
}
