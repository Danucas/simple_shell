#include <stdio.h>
#include <string.h>
char *_strtok(char *line, char *delim)
{
	static char *ptr;
	char *it;
	char *tail;
	if (line != NULL)
		ptr = line;
	it = ptr;
	while (*it != '\0')
	{
		/*	delimit = comp_delim(buffer[counter]);*/
		if (*it == *delim || *it == '\n')
		{
			*it = '\0';
			tail = it + 1;
			it = ptr;
			ptr = tail;
			return (it);
		}
		it++;
		
	}
	return (NULL);
}

int comp_delim(char *letter)
{
	int value = 0, i;
	char delimit[2] = { ' ', '\n' };

	for (i = 0; i < 2; i++)
	{
		if (delimit[i] == *letter)
			value = 1;
	}
	return (value);		
}

int main()
{
	char *line, *tok;
	size_t size = 0;

	getline(&line, &size, stdin);
	tok = _strtok(line, " ");
	while (tok)
	{
		printf("%s\n", tok);
		tok = _strtok(NULL, " ");
	}
	return (0);
}
