#include "shell_libs.h"
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
	char **list;
	line_t *env;
	(void) argc;
	(void) argv;

	if (!isatty(STDIN_FILENO))
	{
		pipstat = read(STDIN_FILENO, &pipe, 100);
		if (pipstat > 0)
		{
			pipe[pipstat - 1] = '\0';
			_printf(pipe);
			_printf("\n");
			list = _strtok(pipe, " ");
			if (execve(list[0], list, envp) == -1)
			{
				_printf(argv[0]);
				_printf(": ");
				_printf("1: ");
				_printf(list[0]);
				_printf(": not found\n");
			}
			free_args(list);
			return (0);
		}
	}
	env = get_env_list(envp);
	promptstat = prompt_loop(argv, &env);
	(void) promptstat;
	(void) env;
	return (0);
}
