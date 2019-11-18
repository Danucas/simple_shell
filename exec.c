#include "shell_libs.h"

int run_command(char **list, char *context)
{
	if (execve(list[0], list, NULL) == -1)
	{
		/*	printf("%s: 1: %s: not found\n", context, list[0]);*/
		return (1);
	}
	(void) context;
	return (0);
}

int run_multiprocess(char **list, char *context)
{
	for (int i = 0; i < 5; i++)
	{
		runchildproc(list, 3, context);
	}
	return (0);
}
