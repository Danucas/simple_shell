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
	prompt[0] = '\0';
	copy = malloc(sizeof(char) * 200);
	copy2 = malloc(sizeof(char) * 200);
	_getenv("USER", envp, &copy);
	str_cpy("\033[31;1m", copy2);
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
	else
	{
		str_concat(prompt, hostname);
	}
	str_cpy("\033[0m:\033[32;1m~", copy);
	str_concat(prompt, copy);
	_getenv("HOME", envp, &copy);
	_getenv("PWD", envp, &copy2);
	str_cpy(string_rem(copy, copy2), copy);
	str_concat(prompt, copy);
	prompt = str_concat(prompt, "\033[0m");
	free(copy);
	free(copy2);
	(void) hostname;
	(void) envp;
}
char **ars;
char **env;
void sig_handler(int signal)
{
	printf("Signal: %d\n", signal);
	fflush(stdout);
	prompt_loop(ars, env);
}
int prompt_loop(char **argv, char **envp)
{
	char *line, *prompt;
	size_t cch;
	char **list;
	char **path;
	ars = argv;
	env = envp;

	prompt = malloc(sizeof(char) * 70);
	line = malloc(sizeof(char) * 1024);
	signal(SIGINT, sig_handler);
	while (1)
	{
		
		getprompt(envp, prompt);
		char *pwd = malloc(100);
		printf("Current Dir: %s\n", _getenv("PWD", envp, &pwd));
		printf("%s", prompt);
		printf("$ ");
		fflush(stdout);
		cch = _getline(&line);
		printf("getline result: %d pid: %d\n", (int) cch, getpid());
		if ((int) cch == -1)
		{
		  /*
		    printf("exiting\n");*/
			exit(10);
			exit_shell(&prompt);
		}
		if (cch > 1)
		{
			
			list = _strtok(line, " ");
			_getenv("PATH", envp, &line);
			path = _strtok(line, ":");
			if (check_paths(path, list, envp) == -1)
				exit(1);
			/*			runchildproc(list, 1, argv[0]);*/
			if (list[0] != NULL)
				free_args(list);
			if (path[0] != NULL)
				free_args(path);
		}
		fflush(stdin);

	}
	(void) argv;
	return (0);
}
