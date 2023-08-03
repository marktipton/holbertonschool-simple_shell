#include "shell.h"
/**
 * #include "tokenizer.c"
#include "check_built_in.c"
#include "get_path.c"
#include "check_status.c"*/
int main(int argc, char **argv, char **env)
{
        char *line = NULL;
        size_t len = 0;
        int fd = STDIN_FILENO;
        ssize_t nchars_read;
        char **tokstr;

        (void)argc; (void)argv; (void)env;

        while (1)
        {
                if (isatty(fd) == 1)
                        printf("$ ");
                nchars_read = getline(&line, &len, stdin);
                if (nchars_read == -1)
                {
                        perror("yooooo");
                        free(line);
                        exit(EXIT_FAILURE);
                }

                if (nchars_read == 1)
                {
                        free(line);
                        printf("\n");
                        return (0);
                }
                printf("%s", line);
                tokstr = tokenizer(line);
                check_built_in(tokstr[0]);
                check_status(tokstr[0]);
                get_path(line);
                free(tokstr);
        }
        return (0);
}
