#include "shell_libs.h"
/**
 *from_backup_to_conf - coipes conf file to a backup
 *@argv: configuration file descriptor
 *@envp: configuration file descriptor
 *@match: configuration file descriptor
 *Return: 0 if success
 */
int from_backup_to_conf(char **argv, line_t **envp, size_t  match)
{
	int backup_fd, conf_fd, rd_size;
	size_t line_t = 0;
	char *conf_filename = malloc(100), *buff = malloc(1024), **lines;

	backup_fd = open("/tmp/.concharc", O_RDONLY);
	printf("backup stat: %d\n", backup_fd);
	_getenv("HOME", envp, &conf_filename);
	str_concat(conf_filename, "/.concharc");
	conf_fd = open(conf_filename, O_WRONLY | O_CREAT | O_TRUNC, 0755);
	printf("conf stat: %d\n", conf_fd);
	rd_size = read(backup_fd, buff, 1024);
	while (rd_size > 0)
	{
		lines = _strtok(buff, "\n");
		for (int i = 0; lines[i] != NULL; i++, line_t++)
		{
			if (line_t == match)
			{
				for (int j = 0; argv[j] != NULL; j++)
				{
					write(conf_fd, argv[j], string_len(argv[j]));
					if (argv[j + 1] != NULL)
						write(conf_fd, " ", 1);
				}
			}
			else
				write(conf_fd, lines[i], string_len(lines[i]));
			if (lines[i + 1] != NULL)
				write(conf_fd, "\n", 1);
		}
		free_args(lines);
		rd_size = read(backup_fd, buff, 1024);
	}
	free(buff);
	free(conf_filename);
	close(backup_fd);
	close(conf_fd);
	return (0);
}

/**
 *print_alias - coipes conf file to a backup
 *@envp: configuration file descriptor
 *Return: 0 if success
 */
int print_alias(line_t **envp)
{
	int rd_alias, fd_alias;
	char *config_file_path = malloc(100);
	char *content = malloc(1024);
	char **lines;

	_getenv("HOME", envp, &config_file_path);
	str_concat(config_file_path, "/.concharc");
	fd_alias = open(config_file_path, O_RDONLY);
	rd_alias = read(fd_alias, content, 1024);
	while (rd_alias > 0)
	{
		fflush(stdout);
		lines = _strtok(content, "\n");
		for (int i = 0; lines[i] != NULL; i++)
		{
			if (string_cmp("alias ", lines[i]) == 6)
			{
				printf("%s\n", lines[i]);
				fflush(stdout);
			}
		}
		free_args(lines);
		rd_alias = read(fd_alias, content, 1024);
	}
	free(content);
	free(config_file_path);
	close(fd_alias);
	return (0);
}

/**
 *print_alias_match - coipes conf file to a backup
 *@argv: configuration file descriptor
 *@envp: configuration file descriptor
 *@match_string: configuration file descriptor
 *Return: 0 if success
 */
int print_alias_match(char **argv, line_t **envp, char *match_string)
{
	int rd_alias, fd_alias, ret = 0;
	char *config_file_path = malloc(100);
	char *content = malloc(1024);
	char **lines;

	(void) argv;
	_getenv("HOME", envp, &config_file_path);
	str_concat(config_file_path, "/.concharc");
	fd_alias = open(config_file_path, O_RDONLY);
	rd_alias = read(fd_alias, content, 1024);
	while (rd_alias > 0)
	{
		fflush(stdout);
		lines = _strtok(content, "\n");
		for (int i = 0; lines[i] != NULL; i++)
		{
			if (string_cmp(match_string, lines[i]) == string_len(match_string))
			{
				printf("%s\n", lines[i]);
				fflush(stdout);
				ret = 2;
			}
		}
		free_args(lines);
		rd_alias = read(fd_alias, content, 1024);
	}
	free(content);
	free(config_file_path);
	close(fd_alias);
	return (ret);
}

/**
 *rd_assgn - Read or asign an alias.
 *@argv: Argument's list.
 *@comp_line: Alias line.
 *Return: 1 if read.
 */
int rd_assgn(char **argv, char *comp_line)
{
	int comp_len = 6;
	int counter = 0;
	int res = 1;

	while (argv[1][counter] != '\0')
	{
		comp_line[comp_len] = argv[1][counter];
		counter++;
		comp_len++;
		if (argv[1][counter] == '=')
		{
			res = 0;
			break;
		}
	}
	return (res);
}
