#include "shell_libs.h"
/**
 *_getenv - Get the value of a environment variable.
 *@var: Variable to get.
 *@envp: Environmet variable's list.
 *@str: Pointer where the result is contained.
 *Return: The variable value.
 */
char *_getenv(char *var, line_t **envp, char **str)
{
	char *res = *str;
	line_t *env = *envp;
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
	while (env != NULL)
	{
		te = string_cmp(comp, env->string);
		if (te == var_len)
		{
			env_len = var_len;/*Get the variable value.*/
			while ((env->string)[env_len] != '\0')
			{
				res[counter] = (env->string)[env_len];
				env_len++;
				counter++;
			}
			res[counter] = '\0';
			return (res);
		}
		env = env->next;
	}
	return (NULL);
}
/**
 *_setenv - Get the value of a environment variable.
 *@var: Variable to set.
 *@envp: Environmet variable's list.
 *@value: the new value
 *Return: 1 if success
 */
int _setenv(char *var, line_t **envp, char *value)
{
	int pos = 0;
	int len;
	char *cop = malloc(100);

	str_cpy(var, cop);
	str_concat(cop, "=");
	len = string_len(cop);
/*	printf("Var name: %s\n", cop);*/
	while (envp[pos] != NULL)
	{
		if (string_cmp(cop, envp[pos]) == len)
		{
/*			printf("match old: %s new: %s\n", envp[pos], value);*/
			str_cpy(value, envp[pos]);
		}
		pos++;
	}
	free(cop);
	free(value);
	(void) envp;
	(void) len;
	(void) value;
	return (0);
}
/**
 *add_node -Add a node to linked list.
 *@s: String to add.
 *@head: Head of list.
 *Return: Pointer to a new node.
 */
line_t *add_node(char *s, line_t **head)
{
	line_t *l = *head, *new_node;
	int count = 0, strlen;
	char *new_string;

	(void) count;
	strlen = string_len(s);
	new_node = malloc(sizeof(line_t));
	new_string = malloc(sizeof(char) * (strlen + 1));
	str_cpy(s, new_string);
	new_node->string = new_string;
	new_node->next = NULL;
	if (l == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	else
	{
		while (l != NULL)
		{
			if (l->next == NULL)
			{
				l->next = new_node;
				return (new_node);
			}
			l = l->next;
		}
	}
	return (new_node);
}

/**
 *get_env_list - Get the value of a environment variable.
 *@envp: Environmet variable's list.
 *Return: 1 if success
 */
line_t *get_env_list(char **envp)
{
	line_t *env;
	int pos = 0;

	env = NULL;
	while (envp[pos] != NULL)
	{
		add_node(envp[pos], &env);
		pos++;
	}
	return (env);
}
