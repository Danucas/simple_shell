#include "shell_libs.h"
#include <sys/wait.h>
/**
 *runchildproc - Make a fork and execute a new process.
 *@process: Argument's process.
 *@time: Time while a new process is executed.
 *@context: Shell's main argument.
 *@env: Shell's environment.
 *Return: 0 if sucess after child is closed.
 */
int runchildproc(char **process, int time, char *context, line_t **env)
{
	pid_t ch_pid;
	int status, runstat = 0;

	ch_pid = fork();
	if (ch_pid == -1)
	{
		perror("Error:");
	}
	if (ch_pid == 0)
	{
	  /*		printf("Wait for me, wait for me\n");*/
		runstat = execve(process[0], process, env);
		printf("runstat fork: %d\n", runstat);
		if (runstat == -1)
		{
			return (-1);
		}
/*		exit(1);*/
	}
	else
	{
		wait(&status);
		/*		printf("I'am your father\n");*/
	}
	(void) time;
	(void) context;
	return (runstat);
}
