#include "shell_libs.h"
#include <sys/wait.h>
/**
 *runchildproc - make a fork and execve a new process
 *@process: the process arguments
 *@time: some sleep time if we needed
 *@context: the shell main arg
 *@env: the environment
 *Return: 0 if sucess after child is dead
 */
int runchildproc(char **process, int time, char *context, line_t **env)
{
	pid_t ch_pid;
	int status, runstat = 0;
	char *command;

	ch_pid = fork();
	if (ch_pid == -1)
	{
		perror("Error:");
	}
	if (ch_pid == 0)
	{
	  /*		_printf("Wait for me, wait for me\n");*/
		command = process[0];
		process[0] = context;
		runstat = execve(command, process, get_env_array(env));
		if (runstat == -1)
		{
			return (-1);
		}
/*		exit(1);*/
	}
	else
	{
		wait(&status);
		/*		_printf("I'am your father\n");*/
	}
	(void) time;
	(void) context;
	return (runstat);
}
