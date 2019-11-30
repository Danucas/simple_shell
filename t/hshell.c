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
	int pos = 0, argc = 0, status, st;
	struct stat *state = malloc(sizeof(struct stat));

	clean_up(&pipe);
	list = _strtok(pipe, "\n");
	free(pipe);
	_getenv("PATH", &env, &path);
	paths = _strtok(path, ":");
	while (list[pos] != NULL)
	{	line_head = list[pos];
		while (list[pos][argc] != '\0')
		{
			if (list[pos][argc] == '\t' || list[pos][argc] == ' ')
				line_head = &(list[pos][argc + 1]);
			else if (list[pos][argc] > 31 && list[pos][argc] < 127)
				break;
			argc++;
		}
		argc = 0;
		args = _strtok(line_head, " \n\t");
		st = check_paths(paths, args, &env, &status);
		if (st == -1)
		{	_printf(argv[0]), _printf(": ");
			print_dec(hits);
			_printf(": "), _printf(args[0]), _printf(": not found\n");
		}
		free_args(args);
		hits++, pos++;
	}
	(void) args, (void) line_head, (void) state;
	free_args(list);
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
