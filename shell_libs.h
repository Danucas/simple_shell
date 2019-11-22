#ifndef _SHELL_LIBS_
#define _SHELL_LIBS_
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
/**
 *struct Strings - simple string struct for a linked list
 *@arg:  the string
 *@next: the pointer to the next node
 *Description: node for a string linked list
 */
typedef struct Strings
{
	char *arg;
	struct Strings *next;
} line_t;

/*String manipulation functions*/
int string_len(char *s);
int string_cmp(char *s1, char *s2);
char *str_concat(char *s1, char *s2);
void str_cpy(char *from, char *to);
char *str_dup(char *from);
char **_strtok(char *line, char *token);
char *string_rem(char *s1, char *s2);

/*Printing functions*/
void printl(line_t *list);
void printargs(char **args);

/*Environment process*/
char *_getenv(char *var, char **envp, char **str);
int _setenv(char *var, char **envp, char *value);

/*Lexic analizer*/
int check_paths(char **paths, char **args, char **envp);
int write_alias(char **argv, char **envp);
int _getchar(void);
size_t _getline(char **line);
void free_args(char **args);
int _gethostname(char *buff, int size);
void getprompt(char **env, char *prompt);
void exit_shell(char **prompt);
int prompt_loop(char **argv, char **envp);
int runchildproc(char **process, int time, char *context, char **env);
int run_command(char **list, char *context, char **env);
int run_multiprocess(char **list, char *context, char **env);
/*Built in functions*/
int _cd(char *path, char **envp);
int check_builtin(char *command, char **args, char **envp);
int parse_alias(char **args, char **envp);
#endif
