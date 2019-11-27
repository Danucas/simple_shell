#include "shell_libs.h"
/**
 *exit_shell - shell main
 *@code: Args count.
 */
void exit_shell(int code)
{
	char c = code;

	write(STDERR_FILENO, &c, 1);
	_printf("\n");
	exit(0);
}
