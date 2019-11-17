#include "shell_libs.h"
/**
 *exit_shell - shell main
 *@prompt: Args count.
 */
void exit_shell(char **prompt)
{
	free(*prompt);
	printf("\n");
	exit(0);
}
