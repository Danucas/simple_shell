#include "shell_libs.h"
/**
 *
 *
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
