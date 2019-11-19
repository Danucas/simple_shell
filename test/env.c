#include "shell_libs.h"
/**
 *_getenv - Get the value of a environment variable.
 *@var: Variable to get.
 *@envp: Environmet variable's list.
 *@str: Pointer where the result is contained.
 *Return: The variable value.
 */
char *_getenv(char *var, char **envp, char **str)
{
	char *res = *str;
	int var_len, env_len = 0, counter = 0;
	int envc = 0;/*Iterate envp.*/
	int te, comp_l = 0;/*Contain coincidences betwen var and envp.*/
	char comp[100];

	while (*var != '\0')
	{
		comp[comp_l] = *var;
		comp_l++;
		var++;
	}
	comp[comp_l] = '=';
	comp[comp_l + 1] = '\0';
	var_len = string_len(comp);
	while (envp[envc] != NULL)
	{
		te = string_cmp(comp, envp[envc]);
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
/**
 *_getenv - Get the value of a environment variable.
 *@var: Variable to get.
 *@envp: Environmet variable's list.
 *@str: Pointer where the result is contained.
 *Return: The variable value.
 */
int _setenv(char *var, char **envp, char *value)
{
	int pos = 0;
	int len;
	char *cop = malloc(100);
	str_cpy(var, cop);
	str_concat(cop, "=");
	len = string_len(cop);
	printf("Var name: %s\n", cop);
	while (envp[pos] != NULL)
	{
		if (string_cmp(cop, envp[pos]) == len)
		{
			printf("match old: %s new: %s\n", envp[pos], value);
			envp[pos] = str_dup(value);
		}
		pos++;
	}
	(void) envp;
	(void) len;
	(void) value;
	return (0);
}
