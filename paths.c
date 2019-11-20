#include "shell_libs.h"
/**
 *check_paths - check all paths
 *@paths: check the stat of the command in each path
 *@args: arguments
 *@envp: the environment
 *Return: 0 if success
 */
int check_paths(char **paths, char **args, char **envp)
{
	char *copy;
	int i = 0;
	char *command;
	int runstatus;
	struct stat *state = malloc(sizeof(struct stat));

	command = malloc(sizeof(char) * 100);
	copy = malloc(sizeof(char) * 100);
	str_cpy(args[0], command);
	if (string_cmp("cd", command) == 2)
	{
		_cd(args[1], envp);
		free(command);
		free(state);
		free(copy);
		return (0);
	}
	runstatus = stat(command, state);
	if (runstatus == 0)
	{
		runstatus = runchildproc(args, 0, command, envp);
	}
	free(args[0]);
	while (paths[i] != NULL)
	{
		str_cpy(paths[i], copy);
		str_concat(copy, "/");
		str_concat(copy, command);
		args[0] = copy;
		runstatus = stat(args[0], state);
		if (runstatus == 0)
		{
			runstatus = runchildproc(args, 0, command, envp);
			break;
		}
		i++;
	}
	args[0] = str_dup(command);
	free(command);
	free(state);
	free(copy);
	return (runstatus);
}
