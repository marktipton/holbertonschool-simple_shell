#include "shell.h"
/**
 * execute_command - forks a process and executes a command
 *
 * @line: input string
 *
 */
void execute_command(char *line)
{
	pid_t child_pid;
	int status;
	char **tokstr;
	
	child_pid = fork();
	if (child_pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0) /*This is the child process*/
	{
		tokstr = tokenizer(line, WHITESPACE);
		status = execve(line, tokstr, NULL);
		if (status == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else /*This is the parent process*/
	{
		wait(&status);
	}
}
