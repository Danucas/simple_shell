#include "shell_libs.h"

/**
 *printl - Prints commands list.
 *
 */
void printl(line_t *list)
{
	line_t *l = list;
	while (l != NULL)
	{
		printf("%s\n", l->arg);
		l = l->next;
	}
}
void printargs(char **args)
{
	int counter = 0;

	while (args[counter] != NULL)
	{
		printf("%s\n", args[counter]);
		counter++;
	}
}
