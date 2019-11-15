#ifndef _SHELL_LIBS_
#define _SHELL_LIBS_
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int string_len(char *s);
int string_cmp(char *s1, char *s2);
char *str_concat(char *s1, char *s2);
int _getchar(void);
size_t _getline(char **line);
char * get_env(char *var, char **envp, char **str);
char *string_rem(char *s1, char *s2);
void check_paths(char *str);
#endif
