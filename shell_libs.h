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
 *struct Envl - simple string struct for a linked list
 *@arg:  the string
 *@next: the pointer to the next node
 *Description: node for a string linked list
 */
typedef struct String
{
	char *string;
	struct String *next;
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
void printargs(line_t **args);

/*Environment process*/
char *_getenv(char *var, line_t **envp, char **str);
int _setenv(char *var, line_t **envp, char *value);
line_t *get_env_list(char **envp);
char **get_env_array(line_t **envp);
void free_env(line_t **envp);


/*Lexic analizer*/
int check_paths(char **paths, char **args, line_t **envp);
int write_alias(char **argv, line_t **envp);
int _getchar(void);
size_t _getline(char **line);
void free_args(char **args);
int _gethostname(char *buff, int size);
void getprompt(line_t **env, char *prompt);
void exit_shell(char **prompt);
int prompt_loop(char **argv, line_t **envp);
int runchildproc(char **process, int time, char *context, line_t **env);
int run_command(char **list, char *context, line_t **env);
int run_multiprocess(char **list, char *context, line_t **env);
/*Built in functions*/
int _cd(char *path, line_t **envp);
int check_builtin(char *command, char **args, line_t **envp);
int parse_alias(char **args, line_t **envp);
int from_backup_to_conf(char **argv, line_t **envp, size_t match);
int print_alias(line_t **envp);
int print_alias_match(char **argv, line_t **envp, char *match);
int rd_assgn(char **argv, char *comp_line);
#endif
