#include "shell_libs.h"

int _getchar(void)
{
	char buff[1];

	if ((read(STDIN_FILENO, buff, 1)) > 0)
	{
		return (buff[0]);
	}
	return (-1);
}

size_t _getline(char **line)
{
	size_t count = 0;
	char c;

	while (1)
	{
		fflush(stdout);
		c = _getchar();
		(*line)[count] = c;
		count++;
		if(c == '\n')
			break;
	}
	return (count);
}
