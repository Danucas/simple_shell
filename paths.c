#include "shell_libs.h"

void check_paths(char **paths, char **args, char **envp)
{
	char *copy;
	int i = 0;
	char *command, *req = args[0];
	int runstatus;
	char *env;

	command = malloc(sizeof(char) * 100);
	env = malloc(sizeof(char) * 100);
	copy = malloc(sizeof(char) * 100);
	(void) req;
	str_cpy(args[0], command);
	if (string_cmp("cd", args[0]) == 2)
	{
		_cd(args[1], envp);
		return;
	}
	runstatus = run_command(args, command);
	if (runstatus == 0)
	{
		return;
	}
	while (paths[i] != NULL)
	{
		str_cpy(paths[i], copy);
		str_concat(copy, "/");
		str_concat(copy, command);
		args[0] = copy;
/*		printf("path to check: %s\n", copy);
		if (_getenv("TERM", envp,  &env) != NULL)
		printf("TERM value: %s\n", env);*/
		runstatus = runchildproc(args, 0, command);
		if (runstatus == 0)
		{
			return;
		}
		i++;
	}
	(void) paths;
	(void) env;
	(void) envp;
}
