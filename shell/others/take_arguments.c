#include "shell_libs.h"
/**
 *take_args - Take a line of arguments and split by space.
 *@argc: Arguments count.
 *@char: List of arguments.
 *Return: The number of elements in list.
 **/
int take_args(int argc, char **argv)
{
	int count = 0;
	char current = argv;

	while (current != NULL) {
		count ++;
		current = current ++;
	}
	return (count);
}
