#include "shell_libs.h"
line_t *add_node(char *s, line_t **head);
/**
 *_strtok - Separate a line and return a list.
 *
 *Return: Pointer the first item os a list string.
 */
line_t *_strtok(char *line, line_t **list, char *token)
{
	char buff[100];
	int cont = 0;

	while (*line != '\0')
	{
		if (*line == *token || *(line + 1) == '\0')
		{

			if (*(line + 1) == '\0')
			{
				buff[cont] = *line;
				buff[cont+1] = '\0';
			}
			else
				buff[cont] = '\0';
			add_node(buff, list);
			cont = 0;
		}
		else
		{
			buff[cont] = *line;
			cont++;
		}
		line++;
	}
	return (*list);
}

line_t *add_node(char *s, line_t **head)
{
	line_t *l = *head , * new_node;
	int count = 0, strlen;
	char *new_string;
	(void) count;
	strlen = string_len(s);
	new_node = malloc(sizeof(line_t));
	new_string = malloc(sizeof(char) * (strlen + 1));
	str_cpy(s, new_string);

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
