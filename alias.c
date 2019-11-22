#include "shell_libs.h"
/**
 *write_alias - alias
 *@argv: key and value for the alias
 *@envp: key and value for the alias
 *Return: 0 if success
 */
int write_alias(char **argv, char **envp)
{
	int alias_fd, wr, count = 0, stat = 0;
	char *config_file_path = malloc(100);

	_getenv("HOME", envp, &config_file_path);
	str_concat(config_file_path, "/.concharc");
	alias_fd = open(config_file_path, O_RDWR | O_APPEND);
	if (alias_fd == -1)
	{
		printf("Creating /.concha config file \n");
		alias_fd = open(config_file_path, O_WRONLY | O_APPEND | O_CREAT, 0755);
		if (alias_fd < 0)
			printf("Error: Can't open file\n");
		wr = write(alias_fd, "#concha shell configuration file\n", 33);
		write(alias_fd, "echo config done", 16);
		if (wr < 0)
			printf("Can't write to the file\n");
	}
	wr = write(alias_fd, "\n", 1);
	for (int i = 0; argv[i] != NULL; i++)
	{
		printf("args: %s\n", argv[i]);
		wr = write(alias_fd, argv[i], string_len(argv[i]));
		if (argv[i + 1] != NULL)
			write(alias_fd, " ", 1);
	}
	close(alias_fd);
	(void) stat;
	(void) count;
	return (0);
}
/**
 *parse_alias - alias
 *@argv: key and value for the alias
 *@envp: key and value for the alias
 *Return: 0 if success
 */
int parse_alias(char **argv, char **envp)
{
	int rd_alias, fd_alias;
	char *config_file_path = malloc(100);
	char *content = malloc(1024);

	_getenv("HOME", envp, &config_file_path);
	str_concat(config_file_path, "/.concharc");
	fd_alias = open(config_file_path, O_RDONLY);
	while ((rd_alias = read(fd_alias, content, 1024)) > 0)
	{
		content[rd_alias] = '\0';
		printf("%s", content);
	}

/*	while (*line != '\0')
	{
		if (stat == 0)
		{
			if (*line == '=')
			{
				al[ct + 5] = '\0';
				stat = 1;
			}
			else
			{
				al[ct + 5] = *line;
			}
		}
		else
		{
		int i;
			for (i = 0; *line != '\0'; i++, line++)
			{
				cm[i] = *line;
			}
			cm[i] = '\0';
			break;
		}
		ct++;
		line++;
	}
*/
	(void) argv;
	(void) envp;
	return (0);
}
