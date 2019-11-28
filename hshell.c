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
	char **list, **args, *line_head;
	char **paths, *path = malloc(200);
	int pos = 0, argc = 0;
	struct stat *state = malloc(sizeof(struct stat));


	list = _strtok(pipe, "\n");
	paths = _strtok(_getenv("PATH", &env, &path), ":");
	while (list[pos] != NULL)
	{
		line_head = list[pos];
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
		if (check_paths(paths, args, &env) == -1)
		{	_printf(argv[0]);
			_printf(": ");
			print_dec(hits);
			_printf(": ");
			_printf(list[0]);
			_printf(": not found\n");
		}
		hits++;
		pos++;
	}
	(void) args;
	(void) line_head;
	(void) state;
	free_args(list);
	return (0);
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
	char pipe[1024];
	int pipstat, promptstat;
	line_t *env;

	(void) argc;
	(void) argv;
	env = get_env_list(envp);
	if (!isatty(STDIN_FILENO))
	{
		pipstat = read(STDIN_FILENO, &pipe, 1024);
		if (pipstat > 0)
		{
			pipe[pipstat - 1] = '\0';
			return (runfromout(argv, env, pipe));
		}
	}
	promptstat = prompt_loop(argv, &env);
	(void) promptstat;
	(void) env;
	return (0);
}
