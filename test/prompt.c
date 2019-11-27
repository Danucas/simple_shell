#include "shell_libs.h"
int parse_and_run(char *arg, line_t **envp, int hits);
/**
 *handle_format - set the Prompt content
 *@token: token to the value it's beeing asked
 *Return: a pointer to he value requested
 */
char *handle_format(char *token)
{
	(void) token;
	return (NULL);
}
/**
 *getprompt - set the Prompt content
 *@envp: environment variables
 *@prompt: Pointer to the prompt line.
 */
void getprompt(line_t **envp, char *prompt)
{
	char hostname[30], *copy, *copy2;
	int p_fd = open("/tmp/prompt_line", O_RDWR | O_CREAT | O_TRUNC, 0644);

	prompt[0] = '\0';
	copy = malloc(sizeof(char) * 200);
	copy2 = malloc(sizeof(char) * 200);
	_getenv("USER", envp, &copy);
	str_cpy("\033[31;1m", copy2);
	str_concat(copy2, copy);
	str_concat(prompt, copy2);
	if ((_gethostname(hostname, 30)) == -1)
	{
		if (_getenv("HOSTNAME", envp, &copy) != NULL)
			str_concat(prompt, copy);
	}
/*	else*/
/*	{*/
/*	str_cpy("@", copy);*/
/*	str_concat(prompt, copy);*/
/**/
/*	str_concat(prompt, hostname);*/
	/*		}*/
	str_cpy("\033[0m:\033[32;1m~", copy);
	str_concat(prompt, copy);
	_getenv("HOME", envp, &copy);
	_getenv("PWD", envp, &copy2);
	str_cpy(string_rem(copy, copy2), copy);
	str_concat(prompt, copy);
	prompt = str_concat(prompt, "\033[0m");
	if (write(p_fd, prompt, string_len(prompt)) == -1)
	{
		_printf("pailas tmp\n");
	}
	close(p_fd);
	free(copy);
	free(copy2);
	(void) hostname;
	(void) envp;
}
/**
 *sig_handler - hands the signals
 *@signal: environment variables
 */
void sig_handler(int signal)
{
	(void) signal;
	_printf("\n");
	fflush(stdout);
	_printf("$ ");
	fflush(stdout);
}
/**
 *prompt_loop - init the capturing loop and the sighandler
 *@argv: arguments from main
 *@envp: environment variables
 *Return: -1 if  it fails
 */
int prompt_loop(char **argv, line_t **envp)
{
	static int enteredhits = 1, parse_stat;

	signal(SIGINT, sig_handler);
	while (1)
	{
		_printf("$ ");
		fflush(stdout);
		parse_stat = parse_and_run(argv[0], envp, enteredhits);
		if (parse_stat == -1)
		{
			free_env(envp);
			exit_shell(0);
		}
		enteredhits++;
	}
	(void) argv;
	return (1);
}
/**
 *parse_and_run - get the input parsed and runit
 *@arg: args
 *@envp: environment variables
 *@hits: hit counter
 *Return: -1 if  it fails
 */
int parse_and_run(char *arg, line_t **envp, int hits)
{
	char *line, *actual;
	char *path;
	size_t cch;
	char **list;
	char **paths;
	int ret = 0, c = 0;

	line = malloc(sizeof(char) * 1024);
	path = malloc(sizeof(char) * 1024);
	cch = _getline(&line);
	if ((int) cch == -1)
	{
		ret = -1;
	}
	actual = line;
	while (line[c] != '\0')
	{
		if (line[c] == '\t' || line[c] == ' ')
		{
			actual = &(line[c + 1]);
		}
		else if (line[c] > 31 && line[c] < 127)
			break;
		c++;
	}
	if ((int) cch > 1 && actual[0] > 31 && actual[0] < 127)
	{
		list = _strtok(actual, " \n\t");
		paths = _strtok(_getenv("PATH", envp, &path), ":");
		if (check_paths(paths, list, envp) == -1)
		{
			_printf(arg);
			_printf(": ");
			print_dec(hits);
			_printf(": ");
			_printf(list[0]);
			_printf(": not found\n");
			write(STDERR_FILENO, &((char) 127), 1);
		}
		free_args(list);
		free_args(paths);
	}
	free(line);
	free(path);
	fflush(stdin);
	return (ret);
}
