#include "shell_libs.h"
/**
 *runfromout - run non interactive
 *@argv: args
 *@env: environment
 *@pipe: the pipe
 *Return: 0 if success
 */
int runfromout(char **argv, line_t *env, char *pipe)
{
	static int hits = 1;
	char **list, **args, *line_head, *path = malloc(200), **paths;
	int pos = 0, status, st;
	struct stat *state = malloc(sizeof(struct stat));

	clean_up(&pipe);
	_printf("pipe: \n");
	_printf(pipe);
	_printf("\n");
	list = _strtok(pipe, "\n");
	while(list[pos] != NULL)
	{
		_printf("text from file: ");
		_printf(list[pos]);
		_printf("||\n");
		pos++;
	}
	pos = 0;
	free(pipe);
	_getenv("PATH", &env, &path);
	paths = _strtok(path, ":");
	while (list[pos] != NULL)
	{	line_head = list[pos];
		_printf("Line arg: \n");
		_printf(line_head);
		_printf("\n");
		args = _strtok(line_head, " \n\t");
		print_dec(string_cmp("(nil)", args[0]));
		_printf("\n");
		print_dec(string_len(args[0]));
		_printf("\n");
		if (string_cmp("(nil)", args[0]) != string_len(args[0]))
		{	st = check_paths(paths, args, &env, &status);
			if (st == -1)
			{	_printf(argv[0]), _printf(": ");
				print_dec(hits);
				_printf(": "), _printf(args[0]), _printf(": not found\n");
			}
		}
		free_args(args);
		_printf("\nFreed\n");
		hits++, pos++;
	}
	(void) line_head, (void) state;
	free_args(list);
	free_args(paths);
	if (status)
		return (status);
	else
		return (0);
}
/**
 *clean_pipe - main for the concha process
 *@p: the arguments count
 */
void clean_pipe(char *p)
{
	int pos = 0;

	while (pos < 1024)
	{
		p[pos] = '\0';
		pos++;
	}
}
/**
 *main - main for the concha process
 *@argc: the arguments count
 *@argv: the arguments list
 *@envp: the environment vars list
 *Return: 0 if success
 */
int main(int argc, char **argv, char **envp)
{
	char *pipe = malloc(1024);
	int pipstat, promptstat;
	line_t *env;

	(void) argc;
	(void) argv;
	env = get_env_list(envp);
	clean_pipe(pipe);
	if (!isatty(STDIN_FILENO))
	{
		pipstat = read(STDIN_FILENO, pipe, 1024);
		if (pipstat > 0)
		{
			pipe[pipstat - 1] = '\0';
			return (runfromout(argv, env, pipe));
		}
	}
	free(pipe);
	promptstat = prompt_loop(argv, &env);
	(void) promptstat;
	(void) env;
	return (promptstat);
}
