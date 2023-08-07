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

	tokstr = tokenizer(line, WHITESPACE);
	child_pid = fork();
	if (child_pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0) /*This is the child process*/
	{

		execve(line, tokstr, environ);

		perror("execve"); /*if execve failed*/
		exit(EXIT_FAILURE);
	}
	else /*This is the parent process*/
	{
		if (waitpid(child_pid, &status, 0) == -1)
		{
			perror("waitpid");
		}
		free_tokens(tokstr);
	}
}
