#include "main.h"

/**
 * _exit - Handles the "exit" builtin command.
 * @args: Array of tokenized command-line args.
 * @path: Pointer to the head of the path list.
 */

void exits(char **args, path_link *path)
{
int code;

code = (args[1]) ? _atoi(args[1]) : 0;
exit_state(args, path, code);
}
