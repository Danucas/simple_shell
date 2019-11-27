#include "shell_libs.c"
int checklist(va_list *ap, const char *format);
/**
 *_printf - the printf, handled data formats prints as characters and
 *return the character count
 *@format: format string
 *Return: characters printed
 */
int _printf(char *string)
{
	return (write(STDOUT_FILENO, string, string_len(string)));
}
