#include "shell_libs.h"

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
		envc++;
	}
}
