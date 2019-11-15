#include "shell_libs.h"
/**
 *str_concat - Adds two different strings.
 *@s1: 1st string.
 *@s2: 2nd string.
 *Return: A pointer to the new string.
 */
char *str_concat(char *s1, char *s2)
{
	int len1 = string_len(s1);/*Get space to the new string.*/
	int len2 = string_len(s2);
	int counter = 0, new_count = 0;/*Iterate each string and new string.*/
	char *new;/*The new resulting string.*/

	new = malloc(sizeof(char) * (len1 + len2 + 1));
	while(s1[counter] != '\0')/*Iterate s1 till NULL.*/
	{
		new[new_count] = s1[counter];
		new_count++;
		counter++;/*Adding s1's info to new string.*/
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
 *string_rem - Take n chars and erase it from the string.(Promt).
 *Description - Remove s1 from s2 and return a pointer to the new string.
 *@s1: String path to remove.
 *@s2: String from where s1 it's going to be removed.
 *Return: Pointer to the new string.
 */
char *string_rem(char *s1, char *s2)
{
	int len1 = string_len(s1);/*Get the size of the strings.*/
	int len2 = string_len(s2);/*Get the size of the second string.*/
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
/**
 *strin_len - Obtain the lenght of the string.
 *@s: String to get lenght.
 *Return: The lenght of the string.
 */
int string_len(char *s)
{
	int count = 0;

	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}
/**
 *string_cmp - Compare two strings.
 *@s1: String for campare (Path).
 *@s2: String to compare.
 *Return: Number of coincidences.
 */
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

void str_cpy(char *from, char *to)
{
	int cont = 0;
	while (*from != '\0')
	{
		to[cont] = *from;
		from++;
		cont++;
	}
}
