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
	str_cpy("@", copy);
	str_concat(prompt, copy);
	if ((_gethostname(hostname, 30)) == -1)
	  {
	    if(_getenv("HOSTNAME", envp, &copy) != NULL)
	      {
		str_concat(prompt, copy);
	      }
	  }
	str_cpy("\033[0m:\033[31;1m~", copy);
	str_concat(prompt, copy);
	_getenv("HOME", envp, &copy);
	_getenv("PWD", envp, &copy2);
	str_cpy(string_rem(copy, copy2), copy);
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
	char **path;

	prompt = malloc(sizeof(char) * 70);
	line = malloc(sizeof(char) * 1024);

	while (1)
	{
		getprompt(envp, prompt);
		printf("%s", prompt);
		printf("$ ");
		fflush(stdout);
		cch = _getline(&line);
		if (cch > 1)
		{
			if ((int) cch == -1)
			{
			  /*				printf("exiting\n");*/
				exit_shell(&prompt);
			}
			list = _strtok(line, " ");
			_getenv("PATH", envp, &line);
			path = _strtok(line, ":");
			check_paths(path, list, envp);
			/*			runchildproc(list, 1, argv[0]);*/
			free_args(list);
			free_args(path);
		}
		fflush(stdin);
	}
	(void) argv;
	return (0);
}
