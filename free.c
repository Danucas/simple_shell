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
		if (string_cmp("(nil)", args[counter]) != 5)
		{
			free(args[counter]);
		}
		counter++;
	}
	free(args);
}
/**
 *free_two - free arguments list
 *@one: the args to free
 *@two: the args to free
 */
void free_two(char *one, char *two)
{
	free(one);
	free(two);
}
