#include "shell_libs.h"
/**
 *from_conf_to_backup - coipes conf file to a backup
 *@argv: configuration file descriptor
 *@envp: configuration file descriptor
 *@match: configuration file descriptor
 *Return: 0 if success
 */
int from_conf_to_backup(char **argv, line_t **envp, size_t  match)
{
	int backup_fd, conf_fd, rd_size, i, j;
	size_t line_t = 0;
	char *conf_filename = malloc(100), *buff = malloc(1024), **lines;

	backup_fd = open("/tmp/.concharc",  O_WRONLY | O_CREAT | O_TRUNC, 0755);
	_printf("backup stat: ");
	print_dec(backup_fd);
	_printf("\n");
	_getenv("HOME", envp, &conf_filename);
	str_concat(conf_filename, "/.concharc");
	conf_fd = open(conf_filename, O_RDONLY);
	_printf("conf stat: ");
	print_dec(conf_fd);
	_printf("\n");
	rd_size = read(conf_fd, buff, 1024);
	while (rd_size > 0)
	{
		lines = _strtok(buff, "\n");
		for (i = 0; lines[i] != NULL; i++, line_t++)
		{
			if (line_t == match)
			{
				for (j = 0; argv[j] != NULL; j++)
				{
					write(backup_fd, argv[j], string_len(argv[j]));
					if (argv[j + 1] != NULL)
						write(backup_fd, " ", 1);
				}
			}
			else
				write(backup_fd, lines[i], string_len(lines[i]));
			if (lines[i + 1] != NULL)
				write(backup_fd, "\n", 1);
		}
		free_args(lines);
		rd_size = read(conf_fd, buff, 1024);
	}
	free(buff);
	close_two(backup_fd, conf_fd);
	return (0);
}
/**
 *rep_alias - alias
 *@al_fd: Alias file descriptor
 *@argv: new alias arguments
 *@envp: environment variables
 *@match: matching line index to replace
 *Return: 0 if success
 */
int rep_alias(int *al_fd, char **argv, line_t **envp, size_t match)
{

	close(*al_fd);
	from_conf_to_backup(argv, envp, match);
	from_backup_to_conf(argv, envp, match);
	return (0);
}
/**
 *check_existing_alias - alias
 *@alias_fd: File descriptor.
 *@argv: Key and value for the alias.
 *@envp: Key and value for the alias.
 *Return: 0 if success
 */
int check_existing_alias(int *alias_fd, char **argv, line_t **envp)
{
	int line_n = 0, comp_len = 6, ret = 0, i;
	int bufsize = -1;
	char *buf = malloc(1024);
	char **lines;
	char *comp_line = malloc(100);
	int just_print = 1;

	str_cpy("alias ", comp_line);
	just_print = rd_assgn(argv, comp_line);
	if (just_print)
	{
		str_concat(comp_line, "=");
		return (print_alias_match(argv, envp, comp_line));
	}
	comp_len = string_len(comp_line);
	bufsize = read(*alias_fd, buf, 1024);
	while (bufsize > 0)
	{
		buf[bufsize] = '\0';
		lines = _strtok(buf, "\n");
		for (i = 0; lines[i] != NULL; i++, line_n++)
		{
			if (string_cmp(comp_line, lines[i]) == comp_len)
			{
				rep_alias(alias_fd, argv, envp, line_n);
				ret = line_n;
				break;
			}
		}
		free_args(lines);
		bufsize = read(*alias_fd, buf, 1024);
	}
	free_two(buf, comp_line);
	(void) envp;
	return (ret);
}
/**
 *write_alias - alias
 *@argv: key and value for the alias
 *@envp: key and value for the alias
 *Return: 0 if success
 */
int write_alias(char **argv, line_t **envp)
{
	int alias_fd, wr, count = 0, stat = 0, exists = 0, i;
	char *config_file_path = malloc(100);

	_getenv("HOME", envp, &config_file_path);
	str_concat(config_file_path, "/.concharc");
	alias_fd = open(config_file_path, O_RDWR | O_APPEND);
	if (alias_fd > 2)
		exists = 1;
	if (alias_fd == -1)
	{
		alias_fd = open(config_file_path, O_WRONLY | O_APPEND | O_CREAT, 0755);
		if (alias_fd < 0)
			_printf("Error: Can't open file\n");
		wr = write(alias_fd, "#concha shell configuration file\n", 33);
		write(alias_fd, "echo config done", 16);
		if (wr < 0)
			_printf("Can't write to the file\n");
	}
	if (exists)
		exists = check_existing_alias(&alias_fd, argv, envp);

	if (exists == 0)
	{
		wr = write(alias_fd, "\n", 1);
		for (i = 0; argv[i] != NULL; i++)
		{
/*			_printf("args: %s\n", argv[i]);*/
			wr = write(alias_fd, argv[i], string_len(argv[i]));
			if (argv[i + 1] != NULL)
				write(alias_fd, " ", 1);
		}
	}
	if (exists == 2)
		return (-1);
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
int parse_alias(char **argv, line_t **envp)
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
		_printf(content);
		fflush(stdout);
	}
	_printf("\n");
	fflush(stdout);
	(void) argv;
	(void) envp;
	return (0);
}
