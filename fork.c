#include "shell_libs.h"
#include <sys/wait.h>

int runchildproc(char **process, int time, char *context)
{
	pid_t ch_pid;
	int status, runstat;

	ch_pid = fork();
	if (ch_pid == -1)
	{
		perror("Error:");
	}
	if (ch_pid == 0)
	{
	  /*		printf("Wait for me, wait for me\n");*/
		runstat = run_command(process, context);
		sleep(time);
		return (runstat);
	}
	else
	{
		wait(&status);
		return (0);
		/*		printf("I'am your father\n");*/
	}
	(void) time;
	return (0);
}
