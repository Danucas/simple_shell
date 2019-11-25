#include "shell_libs.h"
line_t *add_node(char *s, line_t **head);
/**
 *check_token - check if the char is equal to any of the tokens
 *@line: line to break
 *@token: delimitator
 *Return: 0 if it not exists
 */
int check_token(char *line, char *token)
{
	int pos = 0;

	while (token[pos] != '\0')
	{
		if (*line == token[pos])
			return (1);
		pos++;
	}
	return (0);
}
/**
 *_get_list_len - Separate a line and return a list.
 *@line: line to break
 *@token: delimitator
 *Return: Pointer the first item os a list string.
 */
size_t _get_list_len(char *line, char *token)
{
	size_t lc = 0, argc = 0;

	while (line[lc] != '\0')
	{
		if (check_token(&(line[lc]), token) || line[lc + 1] == '\0')
		{
			if (!check_token(&(line[lc + 1]), token))
			{
				argc++;
				if (line[lc + 1] == '\0')
				{
					break;
				}
			}
		}
		lc++;

	}
	return (argc);
}
/**
 *_strtok - Separate a line and return a list.
 *@line: line to break
 *@token: delimitator
 *Return: Pointer the first item os a list string.
 */
char **_strtok(char *line, char *token)
{
	char buff[100];
	size_t cont = 0, lc = 0, argc = 0;
	char **args;
	int end = 0;

	if (line == NULL || token == NULL)
		return (NULL);
	argc = _get_list_len(line, token);
	args = malloc(sizeof(char *) * (argc + 1));
	argc = 0;
	while (line[lc] != '\0')
	{
		if (line[lc] == '"')
			lc++;
		if (check_token(&(line[lc]), token) || line[lc + 1] == '\0')
		{
			if (!check_token(&(line[lc + 1]), token))
			{
				if (line[lc + 1] == '\0')
				{
					buff[cont] = line[lc];
					buff[cont + 1] = '\0';
					end = 1;
				}
				else
					buff[cont] = '\0';
				cont = 0;
				while (buff[cont] != '\0')
				{
					if (buff[cont] == *token)
					{
						buff[cont] = '\0';
						break;
					}
					cont++;
				}
				args[argc] = str_dup(buff);
				argc++;
				cont = 0;
				if (end == 1)
					break;
			}
		}
		else
		{
			buff[cont] = line[lc];
			cont++;
		}
		lc++;
	}
	args[argc] = NULL;
	return (args);
}
