#include "shell_libs.h"

char *str_concat(char *s1, char *s2)
{
	int len1 = string_len(s1);
	int len2 = string_len(s2);
	int counter = 0, new_count = 0;
	char *new;

	new = malloc(sizeof(char) * (len1 + len2 + 1));
	while(s1[counter] != '\0')
	{
		new[new_count] = s1[counter];
		new_count++;
		counter++;
	}
	counter = 0;
	while(s2[counter] != '\0')
	{
		new[new_count] = s2[counter];
		new_count++;
		counter++;
	}
	new[new_count] = '\0';
	return (new);
}
/**
 *string_rem - something
 *Description - remove s1 from s2 and return a pointer to the new string
 *@s1: string path to remove
 *@s2: string from where s1 it's going to be removed
 *Return: pointer to the new string
 */
char *string_rem(char *s1, char *s2)
{
	int len1 = string_len(s1);
	int len2 = string_len(s2);
	int counter = len1, new_count = 0;

	char *new_s = malloc(sizeof(char) * len2 - len1 + 1);

	while(s2[counter] != '\0')
	{
		new_s[new_count] = s2[counter];
		counter++;
		new_count++;
	}
	new_s[new_count] = '\0';
	return (new_s);

}

int string_len(char *s)
{
	int count = 0;

	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}
int string_cmp(char *s1, char *s2)
{
	int count = 0;
	while (s2[count] != '\0')
	{
		if (s1[count] != s2[count])
			return (count);
		count++;
	}
	return (count);
}
