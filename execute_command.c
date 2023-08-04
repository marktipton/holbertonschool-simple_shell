#include "shell.h"
int executeCommand(char *line) 
{
	pid_t child_pid;
	/*char input[100] = {0};*/
	int status;
	char *binstr = "/bin";
	char *xctbl;
	char **tokstr;
	/*int env;*/
	line[strcspn(line, "\n")] = '\0'; /*Fix the line variable name*/

	child_pid = fork();

	if (child_pid == 0) /*This is the child process*/
	{	
		tokstr = tokenizer(line);

		/*Check if the command is one of the built-in commands*/
		if (strcmp(tokstr[0], "ls") == 0)
		{
			/*If the command is "ls", execute it using execvp*/
			if (execvp("/bin/ls", tokstr) == -1)
			{
				perror("Error executing ls");
				exit(EXIT_FAILURE);
			}
        	} 
		else
		{
			/*If it's not a built-in command, execute the specified command*/
			xctbl = strcat(binstr, tokstr[0]);
			/*Use environ as the third argument for execve*/
			if (execve(xctbl, tokstr, environ) == -1)
			{
				perror("Error executing command");
				exit(EXIT_FAILURE);
			}
		}
	}
	else if (child_pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else /*This is the parent process*/
	{
		waitpid(child_pid, &status, 0); /*Wait for the child process to finish*/
	}
	return (0);
}
