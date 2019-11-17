#include "shell_libs.h"
/**
 *main - shell main
 *@argc: Args count.
 *@argv: Args.
 *@envp: Environment variables.
 *Return: 0 if succed.
 */
void getprompt(char **envp, char *prompt)
{
	char hostname[30], *copy, *copy2;

	copy = malloc(sizeof(char) * 200);
	copy2 = malloc(sizeof(char) * 200);
	prompt[0] = '\0';
	_getenv("USER", envp, &copy);
	str_cpy("\033[34;1m", copy2);
	str_concat(copy2, copy);
	str_concat(prompt, copy2);
	str_cpy("\033[0m:\033[31;1m~", copy);
	str_concat(prompt, copy);
	_getenv("HOME", envp, &copy);
	_getenv("PWD", envp, &copy2);
	str_cpy(string_rem(copy2, copy), copy);
	str_concat(prompt, copy);
	prompt = str_concat(prompt, "\033[0m");
	free(copy);
	free(copy2);
	(void) hostname;
}

int prompt_loop(char **argv, char **envp)
{
	char *line, *prompt;
	size_t cch;
	char **list;

	prompt = malloc(sizeof(char) * 70);
	line = malloc(sizeof(char) * 1024);
	getprompt(envp, prompt);
	while (1)
	{
		printf("%s", prompt);
		printf("$ ");
		fflush(stdout);
		cch = _getline(&line);
		if (cch > 1)
		{
			if ((int) cch == -1)
			{
				exit_shell(&prompt);
			}
			list = _strtok(line, " ");
			run_multiprocess(list, argv[0]);
			free_args(list);
		}
		fflush(stdin);
	}
	(void) argv;
	return (0);
}
