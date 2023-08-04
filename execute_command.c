#include "shell.h"
/**
 * execute_command - forks a process and executes a command
 *
 * @line: input string
 *
 * Return: 0 on success
 */
int execute_command(char *line) 
{
	pid_t child_pid;
	/*char input[100] = {0};*/
	int status;
	char *binstr = "/bin";
	char *exec_file_name;
	char **tokstr;

	line[strcspn(line, "\n")] = '\0'; /*Fix the line variable name*/

	child_pid = fork();

	if (child_pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0) /*This is the child process*/
	{	
		tokstr = tokenizer(line, WHITESPACE);

		if (strcmp(tokstr[0], "ls") == 0) /*Check if command is builtin*/
		{
			if (execvp("/bin/ls", tokstr) == -1)
			{
				perror("Error executing ls");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			exec_file_name = strcat(binstr, tokstr[0]);
			if (execve(exec_file_name, tokstr, environ) == -1)
			{
				exit(EXIT_FAILURE);
			}
		}
	}
	else /*This is the parent process*/
	{
		wait(&status); /*Wait for the child process to finish*/
	}
	return (0);
}
