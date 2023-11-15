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
	* struct cmd_link - a linked list for commands
	* @command: string for command
	* @strict: flag for strict mode
	* @next: pointer to next command
	*/
typedef struct cmd_link
{
	char **command;
	int strict;
	struct cmd_link *next;
} cmd_link;

/**
 * struct Alias - Structure to represent an alias
 * @name: Name of alias
 * @value: Value associated with alias
 * @next: Pointer to the next alias in the list
 */
typedef struct Alias
{
	char *name;
	char *value;
	struct Alias *next;
} Alias;


/* Helper functions */
int _atoi(char *p, int *n);
int _printchar(char c);
int _sstr(char **dest, char *src);
int _strcmp(char *s1, char *s2);
int _cstrcmp(const char *str1, const char *str2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strstr(const char *haystack, const char *needle);
char *_dircat(char *dir, char *filename);
char *_itoa(int n, int base, int uppercase);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *src);
size_t _strlen(const char *str);
void _print(const char *str);
void _printerr(const char *str, ...);

/* protypes */
int _alias(Alias **alias, char **args);
int _cd(char **args);
int _cpycustom(char *args, char **name, char **value);
int _setenv(const char *var, const char *value);
int _unsetenv(const char *var);
int display_prompt(char **line);
int execute(cmd_link **cmd, Alias **aliases, int *last_exit_status);
int exec_builtin(cmd_link *cmd, Alias **aliases, int *last_exit_status);
int exec_cmd(cmd_link *cmd, Alias **aliases, int *last_exit_status);
int exec_file(char **args, int *last_exit_status);
int exit_state(cmd_link *cmd, Alias **aliases, int *last_exit_status);
int find_path(char **args);
int find_separator(char **line);
int fork_exec(char **args);
int path_env(void);
int reader(char **input);
int switch_vars(char **args, int *last_exit_status);
int unset_alias(Alias **alias, const char *name);
char *_getenv(const char *name);
char *_strtok(char *s, const char *d);
char **run_non(char **argv);
char **run_pipe(void);
char **tokenize(char *input);
ssize_t _fgetline(char **lineptr, int fd);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
cmd_link *add_command(cmd_link *new, cmd_link *cmds);
cmd_link *create_command(char *line, int strict, cmd_link *cmds);
cmd_link *parse_commands(char *line);
cmd_link *parse_vector(char **argv);
void clean_quit(int status, Alias **aliases);
void define_alias(Alias **alias, const char *name, const char *value);
void free_aliases(Alias **alias);
void free_commands(cmd_link **cmds);
void free_tokenargs(char **args);
void print_alias_all(Alias *alias);
void print_alias_one(Alias *alias, char *name);
void print_env(void);
void sigint_handler(int sig);

#endif
