#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Global variables */
extern char **environ;

/**
  * struct path_link - a linked list for paths
  * @dir: string for directory path
  * @next: pointer to next directory
  */
typedef struct path_link
{
	char *dir;
	struct path_link *next;
} path_link;

/* Helper functions */
void _printer(const char *str);
int _printchar(char c);
size_t _strlen(const char *str);
char *_strdup(const char *src);
char *_strcpy(char *dest, const char *src);
int _strcmp(char *str1, char *str2);
char *_strcat(char *dest, char *src);
char *_dircat(char *dir, char *filename);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strstr(const char *haystack, const char *needle);
int _atoi(char *s);

/* protypes */
char **run_non(char **argv);
char **run_pipe(void);
void display_prompt(void);
char *reader(char *input);
void print_env(void);
char *_getenv(const char *name);
char **tokenize(char *input);
int exec_cmd(char **args, path_link *path);
void free_tokenargs(char **args);
int create_paths(path_link **path);
void free_paths(path_link **path);
int find_path(char **args, path_link *path);
int add_path(char *path, path_link **head);
void fork_exec(char **args);
void print_paths(path_link *path);
int _setenv(const char *var, const char *value);
int _unsetenv(const char *var);
void _cd(char **args);
char *_getenv(const char *name);
char *_strtok(char *s, const char *d);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void exit_state(char **args, path_link *path, int code);

#endif
