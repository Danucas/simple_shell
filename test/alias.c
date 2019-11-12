#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd, wr, ct = 0, stat = 0;
	char al[15], cm[100], *line = argv[1];
	if (argc != 2)
	{
		printf("Usage: ./alias new_cmd=value\n");
		return (-1);
	}
	(void) wr;
	while (*line != '\0')
	{
		if (stat == 0)
		{
			if (*line == '=')
			{
				al[ct + 5] = '\0';
				stat = 1;
			}
			else
			{
				al[ct + 5] = *line;
			}
		}
		else
		{
/*			printf("%s %d: %s\n",__FILE__, __LINE__,  line);*/
			int i;
			for (i = 0; *line != '\0'; i++, line++)
			{
				cm[i] = *line;
			}
			cm[i] = '\0';
			break;
			
		}
		ct++;
		line++;
	}
	al[0] = '/';
	al[1] = 'b';
	al[2] = 'i';
	al[3] = 'n';
	al[4] = '/';
	printf("%s %s\n", al, cm);
	fd = open(al, O_CREAT | O_WRONLY, 0755);
	if (fd == -1)
	{
		printf("Error: Can't open file %s\n", al);
	}
	wr = write(fd, "#!/bin/bash\n", 12);
	int cm_len = 0;
	while (cm[cm_len] != '\0')
	{
		cm_len++;
	}
	wr = write(fd, cm, cm_len);
	return (0);
}
