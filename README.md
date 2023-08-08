# Simple Shell
##Overview
This is the first project of Operating System course
This project consists of designing a C program to serve as a shell interface that accepts user commands and then executes each command in a separate process. Completing this project will involve using the UNIX fork(), execve(), and waitpid() system calls and can be completed on Linux system.
A shell interface gives the user a prompt, after which the next command is entered. The example below illustrates the prompt and the user’s next command: ls simple_shell.c (This command displays the file simple_shell.c on the terminal using the UNIX ls command.)
One technique for implementing a shell interface is to have the parent process first read what the user enters on the command line (in this case, ls simple_shell.c) and then create a separate child process that performs the command. Unless otherwise specified, the parent process waits for the child to exit before continuing. However, UNIX shells typically also allow the child process to run in the background, or concurrently. To accomplish this, we add an ampersand (&) at the end of the command. Thus, if we rewrite the above command as.
## Synopsis
- This program is designed to implement the similar system calls and errors of the original Shell program.
This was made using C89.
## List of Files used in Program
- check_status.c
- check_path.c
- check_built_in.c
- execute_command.c
- path_append.c
- tokenizer.c
- free_tokens.c
## Requirements
Unix-like operating system (Linux, macOS, etc.)
Bash or any other compatible shell
## Description
This is a simple shell script that demonstrates how to prompt the user for input and allow the user to execute commands.
---
## Usage
Open a terminal.
Navigate to the directory where the script is located.
Run the script interactively using the following command:
./hsh

And non interactively using 'echo "ls" | ./hsh
---
## GCC Compiler
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
---
### Authors
- Mark Tipton https://github.com/marktipton
- Kier McAlister https://github.com/kier-ious
