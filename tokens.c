#include "shell_libs.h"
line_t *add_node(char *s, line_t **head);
/**
 *_strtok - Separate a line and return a list.
 *@line: line to break
 *@token: delimitator
 *Return: Pointer the first item os a list string.
 */
char **_strtok(char *line, char *token)
{
	char buff[100];
	int cont = 0, lc = 0, argc = 0;
	char **args;

	while (line[lc] != '\0')
	{
		if (line[lc] == *token || line[lc + 1] == '\n')
		{
			argc++;
			if (line[lc + 1] == '\n')
				break;
		}
		lc++;

	}
	lc = 0;
	args = malloc(sizeof(char *) * (argc + 1));
	argc = 0;
	while (line[lc] != '\0')
	{
		if (line[lc] == *token || line[lc + 1] == '\n')
		{

			if ((line[lc + 1]) == '\n')
			{
				buff[cont] = line[lc];
				buff[cont + 1] = '\0';
			}
			else
				buff[cont] = '\0';
			/*printf("%s\n", str_cpy(buff));/*/
			args[argc] = str_dup(buff);
			argc++;
/*			add_node(buff, list);*/
			cont = 0;
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
