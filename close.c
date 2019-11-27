#include "shell_libs.h"
/**
 *close_two - close two file descriptors
 *@one: one
 *@two: two
 *Return: 0 if ok
 */
int close_two(int one, int two)
{
	close(one);
	close(two);
}
