#include <stdio.h>
#include <unistd.h>


int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/home/dan/games/", NULL};

	if (execve(argv[0], argv, NULL) == -1)
		perror("Error:");
	return (0);
}
