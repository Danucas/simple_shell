#include "shell_libs.h"
#include <signal.h>
void sig_handler(int signal)
{
	printf("Signal %d\n", signal);	
	if (signal  == 2)
	{
		exit(10);
	}
}

int main()
{
	signal(SIGINT, sig_handler);
	while (1);
	return (0);
}
