#include "shell_libs.h"

int main(int argc, char **argv, char **envp)
{
	char pipe[1024];
	int pipstat, promptstat;
	char **list = malloc(sizeof(char *));

	(void) argc;
	(void) argv;

	if (!isatty(STDIN_FILENO))
	{
		pipstat = read(STDIN_FILENO, &pipe, 100);
		if (pipstat >= 0)
		{
			pipe[pipstat - 1] = '\0';
			list = _strtok(pipe, " ");
			if (execve(list[0], list, NULL) == -1)
				printf("%s: 1: %s: not found\n", argv[0], list[0]);
			free_args(list);
			return (0);
		}
	}
	promptstat = prompt_loop(argv, envp);
	(void) promptstat;
	return (0);
}
