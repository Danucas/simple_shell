#include "shell_libs.h"
char *get_current(char *fullpath);
/**
 *change_dir - change the directory
 *@newpath: the new path
 *@pwdir: the old dir
 *@envp: env variables
 *Return: 1 if sucess
 */
int change_dir(char *newpath, char *pwdir, char **envp)
{
	char *newpwd = malloc(100);
	char *tmp;
/*	printf("PWD: %s\nOLDPWD: %s\n", newpath, pwdir);*/
	if (chdir(newpath) == -1)
	{
		tmp = get_current(newpath);
		printf("%s: cd: %s: ", "./concha", tmp + 1);
		free(tmp);
		printf("No such file or directory\n");
		free(newpwd);
		return (-1);
	}
	newpwd[0] = '\0';
	str_cpy("PWD=", newpwd);
	str_concat(newpwd, newpath);
/*	printf("newPwd: %s\n", newpwd);*/
	_setenv("PWD", envp, newpwd);
	(void) envp;
	(void) pwdir;
	return (1);
}
/**
 *_cd - handle the cd command
 *@path: the path to change
 *@envp: env variables
 *Return: 1 if sucess
 */
int _cd(char *path, char **envp)
{
/*	printf("starting cd\n");*/
	int varname_len = string_len("PWD");
	int evc = 0;
	char *pwdir = malloc(sizeof(char) * 200);
	char *newpath = malloc(sizeof(char) * 200);
	char *tmp;
	(void) evc;
	(void) varname_len;
/*	printf("before pwd\n");*/
	_getenv("PWD", envp, &pwdir);
/*	printf("before cpy pwd\n");*/
/*	str_cpy("PWD=", newpath);*/
/*	printf("starting cd\n");*/
	if (path == NULL)
	{
		printf("No path, would go HOME\n");
		free(pwdir);
		free(newpath);
		return (0);
	}
	if (path[0] != '/' && path[0] != '.')
	{
		str_cpy(pwdir, newpath);
		str_concat(newpath, "/");
		str_concat(newpath, path);
		change_dir(newpath, pwdir, envp);
	}
	else if (path[0] == '.')
	{
		if (path[1] != '.')
		{
			free(newpath);
			free(pwdir);
			return (0);
		}
/*		printf("%d\n", __LINE__);*/
		str_cpy(pwdir, newpath);
/*		printf("%d %s\n", __LINE__, newpath);*/
		tmp = get_current(newpath);
		string_rem(tmp, newpath);
/*		printf("%d\n", __LINE__);*/
/*		printf("%d %s\n", __LINE__, newpath);*/
		change_dir(newpath, pwdir, envp);
		free(tmp);
	}
	else if (path[0] != '\0' && path[0] != ' ')
	{
		str_concat(newpath, path);
		change_dir(newpath, pwdir, envp);
	}
	free(newpath);
	free(pwdir);
	return (0);
}

/**
 *get_current - get the simgle current dir
 *@fullpath: the PWD variable
 *Return: dup pointer to the current dir
 */
char *get_current(char *fullpath)
{
	char *pos = fullpath;
	char *checkp;

	while (*pos != '\0')
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
