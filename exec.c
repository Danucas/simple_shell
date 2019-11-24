#include "shell_libs.h"
/**
 *run_command - execve
 *@list: the arguments
 *@context: the context
 *@env: the evironmet
 *Return: 0 if success
 */
int run_command(char **list, char *context, line_t **env)
{
	if (execve(list[0], list, env) == -1)
	{
		/*	printf("%s: 1: %s: not found\n", context, list[0]);*/
		return (-1);
	}
	(void) context;
	return (0);
}
/**
 *run_multiprocess - execve multiple times
 *@list: the arguments
 *@context: the context
 *@env: the evironmet
 *Return: 0 if success
 */
int run_multiprocess(char **list, char *context, line_t **env)
{
	for (int i = 0; i < 5; i++)
	{
		runchildproc(list, 3, context, env);
	}
	return (0);
}
