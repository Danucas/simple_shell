#include "shell_libs.h"
/**
 *free_args - free arguments list
 *@args: the args to free
 */

void free_args(char **args)
{
	int counter = 0;

	while (args[counter] != NULL)
	{
		free(args[counter]);
		counter++;
	}
	free(args);
}
