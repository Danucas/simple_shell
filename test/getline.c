#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int string_len(char *s);
int string_cmp(char *s1, char *s2);
char *str_concat(char *s1, char *s2);
void get_env(char *var, char **envp, char **str);

int _getchar(void)
{
	char buff[1];

	if ((read(STDIN_FILENO, buff, 1)) > 0)
	{
		return (buff[0]);
	}
	return (-1);
}

size_t _getline(char **line)
{
	size_t count = 0;
	char c;

	while (1)
	{
		fflush(stdout);
		c = _getchar();
		(*line)[count] = c;
		count++;
		if(c == '\n')
			break;
	}
	return (count);
}

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

int main(int argc, char **argv, char **envp)
{
	char *line, *prompt;
	prompt = "\033[32;1m";
	size_t cch;
	line = malloc(1024);
	get_env("USER", envp, &prompt);
	prompt = str_concat(prompt, "@ubuntu:~\033[35m");
	get_env("PWD", envp, &prompt);
	prompt = str_concat(prompt, "\033[0m");

	while (1)
	{
		printf("%s", prompt);
		printf("$ ");
		fflush(stdout);
		cch = _getline(&line);
		if (cch > 1)
		{
			printf("%s", line);
		}
	}
	return (0);
}

void get_env(char *var, char **envp, char **str)
{
	char *res;
	int var_len = string_len(var), env_len = 0, counter = 0;
	int envc = 0;
	int res_len;

	while (envp[envc] != NULL)
	{
		int te = string_cmp(var, envp[envc]);
		if (te == var_len)
		{
			res_len = string_len(envp[envc]) - var_len;
			res = malloc(sizeof(char) * (res_len));
			printf("%d\n", res_len);
			env_len = var_len + 1;
			while (envp[envc][env_len] != '\0')
			{
				printf("%c", envp[envc][env_len]);
				res[counter] = envp[envc][env_len];
				env_len++;
				counter++;
			}
			res[counter] = '\0';
			printf("\n%d: %s\n", __LINE__, res);
			*str =  str_concat(*str, res);
			free(res);
			break;
		}
/*		if ((string_cmp(var, envp[envc])) == )*/
		envc++;
	}
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
