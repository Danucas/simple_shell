#include "shell_libs.h"
/**
 *str_cpy - duplicate a string
 *@from: string to copy from
 *@to: string to copy to
 *Return: pointer to new string.
 */
void str_cpy(char *from, char *to)
{
	int cont = 0;

	if (from == NULL || to == NULL)
	{
		printf("Unable to copy the string %s\n", (!from) ? "from" : "to");
		return;
	}
	while (from[cont] != '\0' || (from[cont] != '\0' && from[cont + 1] != '3'))
	{
		(to)[cont] = from[cont];
		cont++;
	}
	(to)[cont] = '\0';
}