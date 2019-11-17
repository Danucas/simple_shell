#include "shell_libs.h"
/**
 *_getchar - Get characters value.
 *Description: Get char by char from standard input.
 *Return: A character. -1 if fails.
 */
int _getchar(void)
{
	char buff[1];

	if ((read(STDIN_FILENO, buff, 1)) > 0)
	{
		return (buff[0]);
	}
	return (EOF);
}
/**
 *_getline - Obtain a lin fron the standard input.
 *@line: Pointer wher the line its gonna be stored.
 *Return: Number of the line's characters.
 */
size_t _getline(char **line)
{
	size_t count = 0;
	char c;

	if (*line == NULL)
	{
		printf("Line is NULL\n");
		return (-1);
	}
	while (1)
	{
		fflush(stdout);/*In case that standard output is open.*/
		c = _getchar();
		(*line)[count] = c;
		count++;
		if (c == '\n')
		{
			(*line)[count] = '\0';
			break;
		}
		if (c == -1)
			return (c);
	}
	return (count);
}
