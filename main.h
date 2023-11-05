#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Global variables */
extern char **environ;

/* Helper functions */
void _printer(const char *str);
int _printchar(char c);
size_t _strlen(const char *str);
char *_strdup(const char *src);
char *_strcpy(char *dest, const char *src);
int _strcmp(char *str1, char *str2);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);

/* protypes */
void display_prompt(void);
char *reader(char *input);
void handle_env(void);
char **tokenize(char *input);
void exec_cmd(char **args);
void free_tokenargs(char **args);

#endif
