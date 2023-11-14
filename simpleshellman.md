SIMPLE SHELL(1)                 User Commands                 SIMPLE SHELL(1)

NAME
       simple_shell - a simple UNIX command line interpreter

SYNOPSIS
       simple_shell

DESCRIPTION
       The  simple_shell  is  a basic UNIX command line interpreter that allows
       users to execute simple commands.

BASIC USAGE
       The shell displays a prompt and waits for the user to type a command.  A
       command line ends with a new line.

       $ simple_shell

COMMAND LINES WITH ARGUMENTS
       The  shell  can handle command lines with arguments. Arguments should be
       separated by spaces.

       $ command arg1 arg2

HANDLING PATH
       The shell handles the PATH environment variable to locate executable com-
       mands.

EXIT BUILTIN COMMAND
       The  shell  implements  the  built-in exit command. The usage is as fol-
       lows:

       $ exit

       The exit command terminates the shell.

ENV BUILTIN COMMAND
       The shell implements the built-in env command. The usage is as follows:

       $ env

       The env command prints the current environment.

SETENV BUILTIN COMMAND
       The shell implements the built-in setenv command. The usage is as fol-
       lows:

       $ setenv VARIABLE VALUE

       The setenv command initializes a new environment variable or modifies an
       existing one.

UNSETENV BUILTIN COMMAND
       The shell implements the built-in unsetenv command. The usage is as fol-
       lows:

       $ unsetenv VARIABLE

       The unsetenv command removes an environment variable.

CD BUILTIN COMMAND
       The shell implements the built-in cd command. The usage is as follows:

       $ cd [DIRECTORY]

       If no argument is given, the command is interpreted as cd $HOME. The cd
       command changes the current directory of the process.

COMMANDS SEPARATOR
       The shell can handle the ; separator to execute multiple commands.

LOGICAL OPERATORS
       The shell can handle the && and || logical operators.

ALIAS BUILTIN COMMAND
       The  shell  implements  the built-in alias command. The usage is as fol-
       lows:

       $ alias [name[='value'] ...]

       The alias command prints a list of all aliases or defines new aliases.

VARIABLES REPLACEMENT
       The shell handles variable replacement for $? and $$.

COMMENTS
       The shell can handle comments denoted by #.

FILE MODE
       The shell can take a file as a command line argument. The file contains
       commands to run, with one command per line.

       $ simple_shell script.txt

       In file mode, the shell does not print a prompt or read from stdin.

