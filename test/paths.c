#include "shell_libs.h"

int check_paths(char **paths, char **args, char **envp)
{
	char *copy;
	int i = 0;
	char *command, *req = args[0];
	int runstatus;
	char *env;
	struct stat *state = malloc(sizeof(struct stat));

	command = malloc(sizeof(char) * 100);
	env = malloc(sizeof(char) * 100);
	copy = malloc(sizeof(char) * 100);
	(void) req;
	str_cpy(args[0], command);
	if (string_cmp("cd", args[0]) == 2)
	{
		_cd(args[1], envp);
		return (0);
	}
	runstatus = stat(command, state);
	printf("runstatus: %d\n", runstatus);
	if (runstatus == 0)
	{
		runchildproc(args, 0, command, envp);
		return(runstatus);
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
		runstatus = stat(args[0], state);
		if (runstatus == 0)
		{
			runchildproc(args, 0, command, envp);
			return(runstatus);
		}
		i++;
	}
	
	(void) paths;
	(void) env;
	(void) envp;
	return (-1);
}
