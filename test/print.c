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
		_printf(l->string);
		_printf("\n"); 
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
		_printf(arg->string);
		_printf("\n");
		arg = arg->next;
	}
}
