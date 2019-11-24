#include "shell_libs.h"
/**
 *from_conf_to_backup - coipes conf file to a backup
 *@argv: configuration file descriptor
 *@envp: configuration file descriptor
 *@match: configuration file descriptor
 *Return: 0 if success
 */
int from_conf_to_backup(char **argv, char **envp, size_t  match)
{
	int backup_fd, conf_fd, rd_size;
	size_t line_t = 0;
	char *conf_filename = malloc(100);
	char *buff = malloc(1024);
	char **lines;

	backup_fd = open("/tmp/.concharc",  O_WRONLY | O_CREAT | O_TRUNC, 0755);
	printf("backup stat: %d\n", backup_fd);
	_getenv("HOME", envp, &conf_filename);
	str_concat(conf_filename, "/.concharc");
	conf_fd = open(conf_filename, O_RDONLY);
	printf("conf stat: %d\n", conf_fd);
	rd_size = read(conf_fd, buff, 1024);
	while (rd_size > 0)
	{
		lines = _strtok(buff, "\n");
		for (int i = 0; lines[i] != NULL; i++, line_t++)
		{
			printf("line %d\n", line_t);
			if (line_t == match)
			{
				for (int j = 0; argv[j] != NULL; j++)
				{
					write(backup_fd, argv[j], string_len(argv[j]));
					if (argv[j + 1] != NULL)
						write(backup_fd, " ", 1);
				}
			}
			else
			{
				write(backup_fd, lines[i], string_len(lines[i]));
			}
			if (lines[i + 1] != NULL)
				write(backup_fd, "\n", 1);
		}
		free_args(lines);
		rd_size = read(conf_fd, buff, 1024);
	}
	free(buff);
	close(backup_fd);
	close(conf_fd);
	return (0);
}
/**
 *replacey_existing_alias - alias
 *@alias_fd: Alias file descriptor
 *@argv: new alias arguments
 *@envp: environment variables
 *@match: matching line index to replace
 *Return: 0 if success
 */
int replace_existing_alias(int *al_fd, char **argv, char **envp, size_t match)
{

	close(*al_fd);
	from_conf_to_backup(argv, envp, match);
	from_backup_to_conf(argv, envp, match);
	return (0);
}
/**
 *check_existing_alias - alias
 *@argv: key and value for the alias
 *@envp: key and value for the alias
 *Return: 0 if success
 */
int check_existing_alias(int *alias_fd, char **argv, char **envp)
{
	int line_n = 0, comp_len = 6, counter = 0, ret = 0;
	int bufsize = -1;
	char *buf = malloc(1024);
	char **lines;
	char *comp_line = malloc(100);
	int just_print = 1;

	str_cpy("alias ", comp_line);
	while (argv[1][counter] != '\0')
	{
		comp_line[comp_len] = argv[1][counter];
		counter++;
		comp_len++;
		if (argv[1][counter] == '=')
		{
			just_print = 0;
			break;
		}
	}
	if (just_print)
	{
		str_concat(comp_line, "=");
		return (print_alias_match(argv, envp, comp_line));
	}
	printf("just: %d\n", just_print);
	comp_len = string_len(comp_line);
	bufsize = read(*alias_fd, buf, 1024);
	while (bufsize > 0)
	{
		buf[bufsize] = '\0';
		lines = _strtok(buf, "\n");
		for (int i = 0; lines[i] != NULL; i++, line_n++)
		{
			printf("line %d:  %s\n", i, lines[i]);
			printf("%d %d\n", string_cmp(comp_line, lines[i]), comp_len);
			if (string_cmp(comp_line, lines[i]) == comp_len)
			{
				printf("match: line %d\n", i);
				replace_existing_alias(alias_fd, argv, envp, line_n);
				ret = line_n;
				break;
			}
		}
		free_args(lines);
		bufsize = read(*alias_fd, buf, 1024);
	}
	free(buf);
	free(comp_line);
	(void) envp;
	return (ret);
}
/**
 *write_alias - alias
 *@argv: key and value for the alias
 *@envp: key and value for the alias
 *Return: 0 if success
 */
int write_alias(char **argv, char **envp)
{
	int alias_fd, wr, count = 0, stat = 0, exists = 0;
	char *config_file_path = malloc(100);

	_getenv("HOME", envp, &config_file_path);
	str_concat(config_file_path, "/.concharc");
	alias_fd = open(config_file_path, O_RDWR | O_APPEND);
	if (alias_fd > 2)
		exists = 1;
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
	if (exists)
		exists = check_existing_alias(&alias_fd, argv, envp);

	if (exists == 0)
	{
		wr = write(alias_fd, "\n", 1);
		for (int i = 0; argv[i] != NULL; i++)
		{
			printf("args: %s\n", argv[i]);
			wr = write(alias_fd, argv[i], string_len(argv[i]));
			if (argv[i + 1] != NULL)
				write(alias_fd, " ", 1);
		}
	}
	if (exists == 2)
	{
		return (-1);
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

	if (argv[1] == NULL)
	{
		print_alias(envp);
		return (0);
	}

	_getenv("HOME", envp, &config_file_path);
	str_concat(config_file_path, "/.concharc");
	fd_alias = open(config_file_path, O_RDONLY);
	while ((rd_alias = read(fd_alias, content, 1024)) > 0)
	{
		content[rd_alias] = '\0';
		printf("%s", content);
		fflush(stdout);
	}
	printf("\n");
	fflush(stdout);

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
