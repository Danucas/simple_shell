#include "shell_libs.h"
char *get_current(char *fullpath);
int change_dir(char *newpath, char *pwdir, char **envp)
{
	char *newpwd = malloc(100);
	printf("PWD: %s\nOLDPWD: %s\n", newpath, pwdir);
	if (chdir(newpath) == -1)
	{
		printf("%s: cd: %s: No such file or directory\n", "./concha", get_current(newpath));
		return (-1);
	}
	newpwd[0] = '\0';
	str_cpy("PWD=", newpwd);
	str_concat(newpwd, newpath);
	printf("newPwd: %s\n", newpwd);
	_setenv("PWD", envp, newpwd);
	(void) envp;
	return (1);
	
}

int _cd(char *path, char **envp)
{
	printf("starting cd\n");
	int varname_len = string_len("PWD");
	int evc = 0;
      	char *pwdir = malloc(sizeof(char) * 200);
	char *newpath = malloc(sizeof(char) * 200);
	(void) evc;
	(void) varname_len;
	printf("before pwd\n");
	_getenv("PWD", envp, &pwdir);
	printf("before cpy pwd\n");
/*	str_cpy("PWD=", newpath);*/
	printf("starting cd\n");
	if (path == NULL)
	{
		printf("No path, would go HOME\n");
		return (0);
	}
	if (path[0] != '/' && path[0] != '.')
	{
		str_cpy(pwdir, newpath);
		str_concat(newpath, "/");
		str_concat(newpath, path);
		change_dir(newpath, pwdir, envp);
	}
	else if(path[0] == '.')
	{
		if (path[1] != '.')
			return (0);
		printf("%d\n", __LINE__);
		str_cpy(pwdir, newpath);
		printf("%d %s\n", __LINE__, newpath);
		string_rem(get_current(newpath), newpath);
		printf("%d\n", __LINE__);
		printf("%d %s\n", __LINE__, newpath);
		change_dir(newpath, pwdir, envp);
	}
	else
	{
		str_concat(newpath, path);
		change_dir(newpath, pwdir, envp);
	}
	return (0);
}

char *get_current(char *fullpath)
{
	char *pos = fullpath;
	char *checkp;
	while(*pos != '\0')
	{
		if (*pos == '/')
			checkp = pos;
		if (*(pos + 1) == '\0')
		{
			return (str_dup(checkp));
		}
		pos++;
	}
	return (checkp);
}
