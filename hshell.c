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
	(void) argc;
	(void) argv;
	line_t *list;
	list = NULL;
	prompt = "\033[34;1m";
	size_t cch;
	line = malloc(1024);
	copy = malloc(200);
	copy2 = malloc(200);
	prompt = str_concat(prompt, get_env("USER", envp, &copy));
	gethostname(hostname, 100);
/*	printf("host: %s\n", hostname);*/
	prompt = str_concat(prompt, "@");
	prompt = str_concat(prompt, hostname);
	prompt = str_concat(prompt, "\033[0m:\033[36;1m~");
	prompt = str_concat(prompt, string_rem(get_env("HOME", envp, &copy2),get_env("PWD", envp, &copy)));
	prompt = str_concat(prompt, "\033[0m");
	check_paths(get_env("PATH", envp, &copy));
	while (1)
	{
		printf("%s", prompt);
		printf("$ ");
		fflush(stdout);
		cch = _getline(&line);
		if (cch > 1)
		{
			printf("init strtok");
			_strtok(line, &list, " ");
			printl(list);
			printf("%s", line);
		}
		fflush(stdin);
	}
	return (0);
}
