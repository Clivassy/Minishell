# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <errno.h>
# include <fcntl.h>

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

int main()
{
	int fd_infile = open("fichier_test", O_RDONLY);
	dup2(fd_infile, STDIN_FILENO);

	char *ptr = NULL;
	printf("minishell>");
	ptr = readline(ptr);
}

// compiler avec gcc maintest_stdin.c -l readline
