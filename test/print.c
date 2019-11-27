#include "shell_libs.h"

/**
 *printl - Prints commands list.
 *@list: list to print
 */
void printl(line_t *list)
{
	line_t *l = list;

	while (l != NULL)
	{
		_printf("%s\n", l->string);
		l = l->next;
	}
}

/**
 *printargs - Prints commands list.
 *@args: args to print
 */
void printargs(line_t **args)
{
	line_t *arg = *args;

	while (arg != NULL)
	{
		_printf("%s\n", arg->string);
		arg = arg->next;
	}
}
