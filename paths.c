#include "shell_libs.h"
/**
 *def_path - check all paths
 *Return: default path pointer
 */
char *def_path()
{
	char *path = malloc(200);

	path[0] = '\0';
	str_concat(path, "/usr/local/sbin:/usr/local/bin");
	str_concat(path, ":/usr/sbin:");
	str_concat(path, "/usr/bin:/sbin:/bin");
	return (path);
}

/**
 *check_paths - check all paths
 *@paths: check the stat of the command in each path
 *@args: arguments
 *@envp: the environment
 *@ex_st: the environment
 *Return: 0 if success
 */
int check_paths(char **paths, char **args, line_t **envp, int *ex_st)
{
	char *copy, *tmp_path, *command;
	int i = 0, runstatus = -1;
	struct stat *state = malloc(sizeof(struct stat));

	command = malloc(100), copy = malloc(100);
	str_cpy(args[0], command);
	i = check_builtin(command, args, envp, ex_st);
	if (i >= 0)
	{	free(command), free(state), free(copy);
		return (i);
	}
	if (command[0] == '/' ||  command[0] == '.')
	{	runstatus = stat(command, state);
		*ex_st = runchildproc(args, 0, command, envp);
		free(command), free(state), free(copy);
		return (runstatus);
	}
	free(args[0]);
	i = 0;
	if (paths == NULL && runstatus != 0)
	{	tmp_path = def_path();
		paths = _strtok(tmp_path, ":");
		free(tmp_path);
	}
	while (paths[i] != NULL && runstatus != 0 && paths != NULL)
	{       str_cpy(paths[i], copy);
		str_concat(copy, "/"), str_concat(copy, command);
		args[0] = copy;
		runstatus = stat(copy, state);
		if (runstatus == 0)
		{	*ex_st = runchildproc(args, 0, command, envp);
			break;
		}
		i++;
	}
	args[0] = str_dup(command);
	free(command), free(state), free(copy);
	free_args(paths);
	return (runstatus);
}
/**
 *check_builtin - check all paths
 *@command: check the stat of the command in each path
 *@args: arguments
 *@envp: the environment
 *@ex_st: the environment
 *Return: 0 if success
 */
int check_builtin(char *command, char **args, line_t **envp, int *ex_st)
{
	char *context = malloc(100);

	_getenv("_", envp, &context);
	if (string_cmp("cd", command) == 2 && string_len(command) == 2)
	{
		free(context);
		*ex_st = _cd(args[1], envp);
		return (*ex_st);
	}
	if (string_cmp("alias", command) == 5 && string_len(command) == 5)
	{
		if (args[1] == NULL)
			print_alias(envp);
		else
		{
			*ex_st = write_alias(args, envp);
			free(context);
			return (*ex_st);
		}
	}
	if (string_cmp("env", command) == 3 && string_len(command) == 3)
	{
		*ex_st = printargs(envp);
		free(context);
		return (*ex_st);
	}
	if (string_cmp("exit", command) == 4 && string_len(command) == 4)
	{
		exit_shell(*ex_st);
	}
	free(context);
	return (-1);
}
