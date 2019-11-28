#include "shell_libs.h"
/**
 *_printf - the printf, handled data formats prints as characters and
 *return the character count
 *@string: format string
 *Return: characters printed
 */
int _printf(char *string)
{
	return (write(STDOUT_FILENO, string, string_len(string)));
}
