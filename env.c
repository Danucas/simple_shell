#include "shell_libs.h"
/**
 *get_env - Get the value of a environment variable.
 *@var: Variable to get.
 *@envp: Environmet variable's list.
 *@str: Pointer where the result is contained.
 *Return: The variable value.
 */
char *get_env(char *var, char **envp, char **str)
{
	char *res = *str;
	int var_len = string_len(var), env_len = 0, counter = 0;
	int envc = 0;/*Iterate envp.*/
	int te;/*Contain coincidences betwen var and envp.*/
	while (envp[envc] != NULL)
	{
		te = string_cmp(var, envp[envc]);
		if (te == var_len)
		{
			env_len = var_len;/*Get the variable value.*/
			while (envp[envc][env_len] != '\0')
			{
				res[counter] = envp[envc][env_len];
				env_len++;
				counter++;
			}
			res[counter] = '\0';
			return (res);
		}
		envc++;
	}
	return (NULL);
}
