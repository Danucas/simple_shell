#include "shell_libs.h"
/**
 *_getenv - Get the value of a environment variable.
 *@var: Variable to get.
 *@envp: Environmet variable's list.
 *@res: Pointer where the result is contained.
 *Return: The variable value.
 */
char *_getenv(char *var, line_t **envp, char **res)
{
	line_t *env = *envp;
	int var_len, env_len = 0, counter = 0;
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
			while (*(env->string + env_len) != '\0')
			{
				(*res)[counter] = *(env->string + env_len);
				env_len++;
				counter++;
			}
			(*res)[counter] = '\0';
			return (*res);
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
	int len;
	char *cop = malloc(200);
	line_t *env = *envp, *new_node, *next = *envp;
	_printf(__FILE__);
	print_dec(__LINE__);
	str_cpy(var, cop);
	str_concat(cop, "=");
	len = string_len(cop);
/*	_printf("Var name: %s\n", cop);*/
	while (next != NULL)
	{
		if (string_cmp(cop, next->string) == len)
		{
/*			_printf("match old: %s new: %s\n", envp[pos], value);*/
			new_node = malloc(sizeof(line_t));
			new_node->string = str_dup(value);
			new_node->next = next->next;
			env->next = new_node;
			free(next->string);
			free(next);
			break;

		}
		env = next;
		next = env->next;
	}
	free(cop);
	free(value);
	(void) envp;
	(void) len;
	(void) value;
	return (0);
}
/**
 *add_node - Add a node.
 *@s: String to add.
 *@head: Head of node.
 *Return: New node.
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
/**
 *get_env_array - Get the value of a environment variable.
 *@envp: Environmet variable's list.
 *Return: 1 if success.
 */
char **get_env_array(line_t **envp)
{
	line_t *env = *envp;
	char **new_env;
	int size = 0, pos = 0;

	while (env != NULL)
	{
		size++;
		env = env->next;
	}
	new_env = malloc(sizeof(char *) * (size + 1));
	env = *envp;
	while (env != NULL)
	{
		new_env[pos] = env->string;
		pos++;
		env = env->next;
	}
	new_env[pos] = NULL;
	return (new_env);
}
