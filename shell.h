#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <signal.h>
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"
extern char **environ;
void handle_signal(int signal);
int *_error(char *argv, int count, char *args);
int func_exit(char **args);
void func_printenv(char **env);
char **_which(char *foundpath);
char *_getenv(char *name, char **env);
char *search_func(char **dir, char *cmd);
int child_process(char **av, char **args, char **environ, int st, int countt);
int _access(char *filename);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
char *_strstr(char *str1, char *str2);
char *_strdup(char *str);
char *_itoa(int num, int base);
char *read_input(void);
char **sparse_str(char *line, char **env);
int execute(char **args, char **argv, int count, char *line, char **env);
void prompt(void);
void *_realloc(void *ptr, unsigned int new_size);
int _count_point(char *buffer);
void *_calloc(unsigned int nmemb, unsigned int size);
char **search_path(char **environ);
int _stat(char **cmd, char **path);
char *str_concat(char *s1, char *s2);
void _puts(char *str);
int _putchar(char c);

#endif
