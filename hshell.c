#include "shell_libs.h"
/**
 *main - shell main
 *@argc: Args count.
 *@argv: Args.
 *@envp: Environment variables.
 *Return: 0 if succed.
 */
int main(int argc, char **argv, char **envp)
{
	char *line, *prompt, hostname[100], *copy, *copy2;
	char pipe[100];
	int pipstat;
	(void) argc;
	(void) argv;
	char **list;
	close(1);
	pipstat = read(STDOUT_FILENO, &pipe, 100);
	if (pipstat >= 0)
	  {
	    pipe[pipstat - 1] = '\0';
	    printf("%s", pipe);
	    return (0);
	  }
	else if (pipstat == -1)
	  {
	    return (0);
	  }
	prompt = "\033[32;1m";
	size_t cch;
	line = malloc(1024);
	copy = malloc(200);
	copy2 = malloc(200);
	prompt = str_concat(prompt, get_env("USER=", envp, &copy));
	gethostname(hostname, 100);
/*	printf("host: %s\n", hostname);*/
	prompt = str_concat(prompt, "@");
	prompt = str_concat(prompt, hostname);
	prompt = str_concat(prompt, "\033[0m:\033[33;1m~");
	prompt = str_concat(prompt, string_rem(get_env("HOME=", envp, &copy2),get_env("PWD=", envp, &copy)));
	prompt = str_concat(prompt, "\033[0m");
	check_paths(get_env("PATH=", envp, &copy));
	while (1)
	{
		printf("%s", prompt);
		printf("$ ");
		fflush(stdout);
		cch = _getline(&line);
		if (cch > 1)
		{
			list = _strtok(line, " ");
			printargs(list);
			free_args(list);
		}
		fflush(stdin);
	}
	return (0);
}
