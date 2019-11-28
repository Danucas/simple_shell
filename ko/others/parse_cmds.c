#include "shell_libs.h"

void check_paths(char *str)
{
	char buff[100];
	int count = 0;
	char *s = str;

	while (*s != '\0')
	{
		if(*s == ':' || *(s + 1) == '\0')
		{
			buff[count] = '\0';
			printf("%s\n", buff);
			count = 0;
		}
		else
		{
			buff[count] = *s;
			count++;
		}
		s++;
	}
}
