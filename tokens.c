#include "shell_libs.h"
line_t *add_node(char *s, line_t **head);
/**
 *_strtok - Separate a line and return a list.
 *
 *Return: Pointer the first item os a list string.
 */
char **_strtok(char *line, char *token)
{
	char buff[100];
	int cont = 0, lcount = 0, argc = 0;
	char **args;
	while (line[lcount] != '\0')
	{
		if (line[lcount] == *token || line[lcount + 1] == '\n')
		     argc++;
		lcount++;

	}
	args = malloc(sizeof(char*) * (argc + 1));
	argc = 0;
	while (*line != '\0')
	{
		if (*line == *token || *(line + 1) == '\n')
		{

			if (*(line + 1) == '\n')
			{
				buff[cont] = *line;
				buff[cont+1] = '\0';
			}
			else
				buff[cont] = '\0';
			/*printf("%s\n", str_cpy(buff));/*/
			args[argc] = str_cpy(buff);
			argc++;
/*			add_node(buff, list);*/
			cont = 0;
		}
		else
		{
			buff[cont] = *line;
			cont++;
		}
		line++;
	}
	args[argc] = NULL;
	return (args);
}