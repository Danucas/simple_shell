#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int _getchar(void)
{
	
	char buff[1];
	int ret;

	if ((ret = read(STDIN_FILENO, buff, 1)) > 0)
	{

		return (buff[0]);
	}
	return (EOF);
}

int main(void)
{
	char c;
	
	while (1)
	{
		printf("$ ");
		fflush(stdout);
		while (1)
		{
			c = _getchar();
			printf("%c", c);
			if (c == '\n')
				break;
		}
	}
	return (0);
}
