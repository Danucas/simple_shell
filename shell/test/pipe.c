#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
	if (!isatty(STDIN_FILENO))
		printf("Is not terminal\n");
	else
		printf("No file provided\n");
	return (0);
}
