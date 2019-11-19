#ifndef _SHELL_LIBS_
#define _SHELL_LIBS_
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
typedef struct Strings
{
	char *arg;
	struct Strings *next;
} line_t;

void printl(line_t *list);
void printargs(char **args);
int string_len(char *s);
int string_cmp(char *s1, char *s2);
char *str_concat(char *s1, char *s2);
int _getchar(void);
size_t _getline(char **line);
char * _getenv(char *var, char **envp, char **str);
int _setenv(char *var, char **envp, char *value);
char *string_rem(char *s1, char *s2);
int check_paths(char **paths, char **args, char **envp);
void str_cpy(char *from, char *to);
char *str_dup(char *from);
char **_strtok(char *line, char *token);
void free_args(char **args);
int _gethostname(char *buff, int size);
void getprompt(char **env, char *prompt);
void exit_shell(char **prompt);
int prompt_loop(char **argv, char **envp);
int runchildproc(char **process, int time, char *context, char **env);
int run_command(char **list, char *context, char **env);
int run_multiprocess(char **list, char *context, char **env);
int _cd(char *path, char **envp);
#endif
