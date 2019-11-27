#include "shell_libs.h"
/**
 *exit_shell - shell main
 *@prompt: Args count.
 */
void exit_shell(int code)
{
	char c = code;
	_printf("\n");
	write(STDERR_FILENO, &c, 1);
	exit(0);
}
