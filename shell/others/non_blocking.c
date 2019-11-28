#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv, char **envp)
{
	int envc = 0;
	int tfd; /*Terminal file descriptor*/
	char buff[1024];

	(void) argc;
	(void) argv;
	while (envp[envc] != NULL)
	{
/*		printf("%s\n", envp[envc]);*/
		envc++;
	}
	buff[1] = '\0';
	tfd = open("/dev/fd/1",STDIN_FILENO, O_NONBLOCK);
	printf("Terminal file descriptor: %d\n", tfd);
	while (1)
	{
		if ((read(STDIN_FILENO, buff, 1)) >  0)
			printf("%s", buff);
		fflush(stdin);
	}
	return (0);
}
