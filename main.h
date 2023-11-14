#ifndef MAIN_H
#define MAIN_H

#include <fcntl.h>
#include <limits.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

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

/**
  * struct cmd_link - a linked list for commands
  * @command: string for command
  * @next: pointer to next command
  */
typedef struct cmd_link
{
  char **command;
  int strict;
  struct cmd_link *next;
} cmd_link;

/* Helper functions */
int _atoi(char *s);
int _printchar(char c);
int _sstr(char **dest, char *src);
int _strcmp(char *str1, char *str2);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strstr(const char *haystack, const char *needle);
char *_dircat(char *dir, char *filename);
char *_itoa(int n, int base, int uppercase);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *src);
size_t _strlen(const char *str);
void _printer(const char *str);

/* protypes */
int _cd(char **args);
int _setenv(const char *var, const char *value);
int _unsetenv(const char *var);
int add_path(char *path, path_link **head);
int create_paths(path_link **path);
int execute(cmd_link **cmd, path_link *path, int *last_exit_status);
int exec_builtin(cmd_link *cmd, path_link *path);
int exec_cmd(cmd_link *cmd, path_link *path, int *last_exit_status);
int exec_file(char **args, path_link *path, int *last_exit_status);
int find_path(char **args, path_link *path);
int find_separator(char **line);
int fork_exec(char **args);
int switch_vars(char **args, int *last_exit_status);
char **run_non(char **argv);
char **run_pipe(void);
char **tokenize(char *input);
char *_getenv(const char *name);
char *_strtok(char *s, const char *d);
int reader(char **input);
ssize_t _fgetline(char **lineptr, int fd);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
cmd_link *add_command(cmd_link *new, cmd_link *cmds);
cmd_link *create_command(char *line, int strict, cmd_link *cmds);
cmd_link *parse_commands(char *line);
cmd_link *parse_vector(char **argv);
void display_prompt(void);
void exit_state(cmd_link *cmd, path_link *path);
void free_commands(cmd_link *cmds);
void free_paths(path_link **path);
void free_tokenargs(char **args);
void print_env(void);
void print_paths(path_link *path);

#endif
