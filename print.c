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
 *Return: 0 if success
 */
int printargs(line_t **args)
{
	line_t *arg = *args;

	while (arg != NULL)
	{
		_printf(arg->string);
		_printf("\n");
		arg = arg->next;
	}
	return (0);
}

/**
 *print_arr - Prints commands list.
 *@args: args to print
 *Return: 0 if success
 */
int print_arr(char **args)
{
	int pos = 0;

	while (args[pos] != NULL)
	{
		_printf(args[pos]);
		_printf("||\n");
		pos++;
	}
	return (pos);
}
