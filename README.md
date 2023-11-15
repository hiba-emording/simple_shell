# 🐚 Simple Shell 🐚

![Shell Logo](https://res.cloudinary.com/practicaldev/image/fetch/s--8BwquDfS--/c_imagga_scale,f_auto,fl_progressive,h_420,q_66,w_1000/https://thepracticaldev.s3.amazonaws.com/i/y6apvdfg3nzt3tvk5oth.gif)


Welcome to Simple Shell, a basic UNIX command line interpreter created by [Daniel Sarpong](https://github.com/dansarpong) and [Hiba A. Mohamed](https://github.com/hiba-emording). (⌐■_■)

## 💡 Overview 💡

The Simple Shell is a minimalist UNIX command line interpreter designed for simplicity and ease of use.
This shell project includes a collection of C functions to implement a basic shell.
The functions are organized into different files based on their functionality.

## 👨‍💻 Basic Usage 👨‍💻

The shell displays a prompt and waits for the user to type a command. A command line ends with a new line.

```bash
$ simple_shell
```

## ✍🏻 Command Lines with Arguments ✍🏻

The shell can handle command lines with arguments. Arguments should be separated by spaces.

```bash
$ command arg1 arg2
```

## 🎯 Handling PATH 🎯

The shell handles the `PATH` environment variable to locate executable commands.

## 📋 Built-in Commands 📋

| Command     | Description                                   |
|-------------|-----------------------------------------------|
| `exit`      | Terminates the shell.                         |
| `env`       | Prints the current environment.               |
| `setenv`    | Initializes or modifies an environment variable. |
| `unsetenv`  | Removes an environment variable.              |
| `cd`        | Changes the current directory of the process. |
| `alias`     | Prints a list of all aliases or defines new aliases. |


## 🦾 Advanced Features 🦾

- **Commands Separator**: The shell can handle the `;` separator to execute multiple commands.

- **Logical Operators**: The shell can handle the `&&` and `||` logical operators.

- **Variables Replacement**: The shell handles variable replacement for `$?` and `$$`.

- **Comments**: The shell can handle comments denoted by `#`.

- **File Mode**: The shell can take a file as a command line argument, executing commands from the file.

  ```bash
  $ simple_shell script.txt

## 🗃️ Files and Functions 🗃️

## `main.h` Header File

| Function               | Purpose                                                  |
|------------------------|----------------------------------------------------------|
| Header Guards          | Ensures single inclusion in the code.                    |
| Included Libraries     | Standard C libraries for various functionalities.        |
| Macros                 | Defines `BUFFER_SIZE` for input buffer size.             |
| Global Variable        | `extern char **environ` for environment variables.       |
| Data Structures        | Linked lists for paths, commands, and aliases.           |
| Helper Functions       | String manipulation, conversion, tokenization, printing. |
| Function Prototypes    | Declarations for shell functionalities.                 |

**Usage:**
- Provides a structured foundation for the Simple Shell program, encompassing declarations, macros, and function prototypes.

---

## `main.c` Main File

| Function               | Purpose                                                  |
|------------------------|----------------------------------------------------------|
| `main`                 | Entry point for the Simple Shell program.                |
| `execute interactively`| Enters an infinite loop for interactive mode.            |
| `execute batch_file`   | Executes commands from a batch file.                     |
| `init path`            | Initializes the path linked list.                        |
| `init commands`        | Initializes the command linked list.                     |
| `cleanup`              | Frees allocated memory before exiting.                   |

**Usage:**
- Handles both interactive and batch modes, parsing and executing commands using the Simple Shell infrastructure.

---

## `display_prompt.c` Prompt Function

| Function             | Purpose                                       |
|----------------------|-----------------------------------------------|
| `display_prompt`    | Displays the command prompt (`$ `).           |

**Usage:**
- Called to show the prompt for the user to input commands in interactive mode.

---

## `reader.c` Reading Input Function

| Function         | Purpose                                                   | Return                                            |
|------------------|-----------------------------------------------------------|---------------------------------------------------|
| `reader`         | Reads user input and removes the trailing newline character. | Number of bytes read. -1 on failure.              |

**Usage:**
- Utilized to read user input in interactive mode, ensuring a clean input buffer.

---

## `_getline.c` Custom Getline Function

| Function       | Purpose                                                           | Parameters                                           | Return                                              |
|----------------|-------------------------------------------------------------------|------------------------------------------------------|-----------------------------------------------------|
| `_getline`     | Reads characters from the specified stream until a newline character is encountered. Dynamically allocates memory for the line buffer. | `lineptr`: Pointer to the buffer containing the read bytes. `n`: Number of bytes read and stored in `lineptr`. `stream`: Source to read from (usually `stdin`). | Number of characters read, including the delimiting character but excluding the terminating null byte. -1 on failure. |

**Usage:**
- Utilized to read user input, ensuring dynamic allocation of memory for the line buffer to accommodate varying input lengths.

---

## `tokenize.c` Tokenization Functions

| Function          | Purpose                                                       | Parameters            | Return                                               |
|-------------------|---------------------------------------------------------------|-----------------------|------------------------------------------------------|
| `tokenize`        | Tokenizes a string into separate arguments dynamically.       | `input`: The string to tokenize. | A pointer to an array of tokenized arguments. `NULL` on failure. |
| `free_tokenargs`  | Frees memory allocated for tokenized arguments.                | `args`: The array of tokenized arguments. |

**Usage:**
- `tokenize`: Utilized for parsing and tokenizing input strings, handling comments denoted by `#`.
- `free_tokenargs`: Called to free the memory allocated for the array of tokenized arguments.

---

## `parse_commands.c` Command Parsing Functions

| Function           | Purpose                                                    | Parameters                                           | Return                                              |
|---------------------|------------------------------------------------------------|------------------------------------------------------|-----------------------------------------------------|
| `parse_commands`    | Parses a line into a linked list of commands, considering command separators. | `line`: The line to parse.                            | Pointer to the first command in the linked list.     |
| `parse_vector`      | Parses a vector of commands into a linked list of commands. | `argv`: The vector of arguments.                      | Pointer to the first command in the linked list.     |
| `create_command`    | Creates a command and adds it to the linked list of commands. | `line`: The command string.                           | Pointer to the header of the linked list.             |
| `add_command`       | Adds a command to a linked list of commands.                | `new`: The command to add.                            | Pointer to the header of the linked list.             |
| `free_commands`     | Frees a linked list of commands and associated memory.      | `cmd`: Pointer to the linked list.                   |                                                     |

**Usage:**
These functions collectively handle the parsing, creation, addition, and freeing of command structures in the Simple Shell project.

---

## `_strtok.c` Custom Strtok Function

| Function       | Purpose                                                           | Parameters                                                   | Return                                                      |
|----------------|-------------------------------------------------------------------|--------------------------------------------------------------|-------------------------------------------------------------|
| `_strtok`      | Tokenizes an input string based on a set of delimiter characters. Maintains state between calls to extract subsequent tokens. | `s`: The input string to be tokenized. `d`: A string containing delimiter characters. | Returns a pointer to the next token in the string. Returns NULL if no more tokens are found. |

**Usage:**
- Used for parsing strings and extracting tokens based on specified delimiters.
- Maintains state to allow multiple calls for extracting subsequent tokens.

---


## `switch_vars.c` Variable Switching Function

| Function        | Purpose                                                           | Parameters                                         | Return                                             |
|-----------------|-------------------------------------------------------------------|----------------------------------------------------|----------------------------------------------------|
| `switch_vars`   | Switches variables in a tokenized string, replacing certain patterns with their corresponding values. | `args`: Array of tokenized command-line arguments. <br> `last_exit_status`: Pointer to the last exit status variable. | Returns 1 if replacements are made, 0 otherwise.    |

**Usage:**
- Utilized for switching variables in command-line arguments.

---

## `find_separator.c` Function

| Function         | Purpose                                                              | Parameters                                          | Return                                             |
|------------------|----------------------------------------------------------------------|-----------------------------------------------------|----------------------------------------------------|
| `find_separator` | Locates the next command separator in a given string.                | `line`: Pointer to the string to search.            | Flag indicating the corresponding separator type. 0 if none, 1 for `#`, 2 for `;`, `\n`, or `\0`, 3 for `||`, 4 for `&&`. |

**Usage:**
- Used during command parsing to identify and handle different types of separators.
- Modifies the input string, replacing the found separator with a null terminator.

---

## `path_functions.c` Path Management Functions

| Function        | Purpose                                                     | Parameters            | Return               |
|-----------------|-------------------------------------------------------------|-----------------------|----------------------|
| `create_paths`  | Creates a linked list of all paths from the `PATH` environment variable. | `path`: Pointer to the head of the paths linked list. | 0 on success, 1 on failure. |
| `free_paths`    | Frees a linked list of paths.                                | `path`: Pointer to the head of the paths linked list. |                      |
| `add_path`      | Adds a path to a linked list of paths.                       | `path`: String of the path to be added. <br> `head`: Pointer to the head of the paths linked list. | 0 on success, 1 on failure. |
| `find_path`     | Checks the `PATH` for the existence of the first argument's executable. | `args`: Pointer to parsed arguments. <br> `path`: Pointer to the head of the paths linked list. | 0 on success, 1 on failure. |

**Usage:**
- `create_paths` initializes the path linked list from the `PATH` environment variable.
- `free_paths` releases the memory allocated for the path linked list.
- `add_path` adds a new path to the linked list.
- `find_path` checks for the existence of the executable in the specified paths.

---

## `execute_functions.c` Command Execution Functions

| Function           | Purpose                                                     | Parameters                                          | Return                                             |
|--------------------|-------------------------------------------------------------|-----------------------------------------------------|----------------------------------------------------|
| `execute`          | Execute a linked list of commands sequentially. Handle command separators like `;`, `||`, and `&&`. | `cmd`: Pointer to the linked list of commands. <br> `path`: Pointer to the linked list of paths. <br> `last_exit_status`: Pointer to the exit status of the last command. | Exit status of the last command.                     |
| `exec_cmd`         | Execute a single command with arguments. Handle built-in commands, executable files, and custom functions. | `cmd`: Pointer to the command structure. <br> `path`: Pointer to the linked list of paths. <br> `last_exit_status`: Pointer to the exit status of the last command. | Exit status of the executed command.                 |
| `exec_builtin`     | Execute built-in commands like `exit`, `env`, `setenv`, `unsetenv`, and `cd`. | `cmd`: Pointer to the command structure. <br> `path`: Pointer to the linked list of paths. | 0 on success, -1 for non-built-in commands.         |
| `exec_file`        | Execute commands from a file.                               | `args`: Pointer to the command arguments. <br> `path`: Pointer to the linked list of paths. <br> `last_exit_status`: Pointer to the exit status of the last command. | Exit status of the last command.                     |
| `_fgetline`        | Reads an entire line from a file descriptor.                | `lineptr`: Pointer to the buffer containing the read bytes. <br> `fd`: File descriptor to read from. | Number of characters read.                           |
| `fork_exec`        | Creates a fork and executes a command.                      | `args`: Pointer to the command arguments.            | 0 on success.                                       |
| `exit_state`       | Exits the shell in a specified state (with an optional exit code). | `cmd`: Pointer to the command structure. <br> `path`: Pointer to the linked list of paths. |                                                    |

**Usage:**
- `execute` processes a linked list of commands with separators.
- `exec_cmd` executes a single command with arguments.
- `exec_builtin` handles execution of built-in commands.
- `exec_file` executes commands from a file.
- `_fgetline` reads a line from a file descriptor.
- `fork_exec` creates a fork and executes a command.
- `exit_state` exits the shell in a specified state.

---

## `env.c` Environment Functions

| Function          | Purpose                                                               | Parameters                                      | Return                           |
|-------------------|-----------------------------------------------------------------------|-------------------------------------------------|----------------------------------|
| `_setenv`         | Set a new environment variable or modify an existing one.             | `var`: Name of the environment variable. <br> `value`: Value to set. | Returns 0 on success, 1 on failure. |
| `_unsetenv`       | Remove an environment variable.                                       | `var`: Name of the environment variable.        | Returns 0 on success, 1 on failure. |
| `print_env`       | Print environment variables.                                          | None                                            | No return value.                 |
| `update_path`     | Update the linked list of paths from the `PATH` environment variable. | `path`: Pointer to the head of the paths linked list. | Returns 0 on success, 1 on failure. |

**Usage:**

- **`_setenv` Function:**
  - Utilized to set or modify environment variables.
    ```c
    _setenv("MY_VARIABLE", "my_value");
    ```

- **`_unsetenv` Function:**
  - Used to remove an environment variable.
    ```c
    _unsetenv("MY_VARIABLE");
    ```

- **`print_env` Function:**
  - Called to print all environment variables.
    ```c
    print_env();
    ```

- **`update_path` Function:**
  - Updates the linked list of paths from the `PATH` environment variable.
    ```c
    update_path(&path);
    ```
    
---

## `_getenv.c` Function

| Function     | Purpose                                           | Parameters       | Return                                       | Notes                                                          |
|--------------|---------------------------------------------------|-------------------|----------------------------------------------|----------------------------------------------------------------|
| `_getenv`    | Get the value of an environment variable.         | `name`: Name of the environment variable. | Value of the environment variable, or `NULL`. | Iterates through environment variables, compares names, extracts values, and allocates memory for the result. |

**Usage:**
- Used to retrieve the value of a specified environment variable.

---

## `cd` Function

| Function | Purpose                                      | Parameters                                      | Return                            |
|----------|----------------------------------------------|-------------------------------------------------|-----------------------------------|
| `_cd`    | Change the current working directory.        | `args`: Array of arguments containing the new directory. | Returns 0 on success, 1 on failure. |

**Usage:**
- Command syntax: cd [DIRECTORY]
- Change the current working directory using various cases:
  - If the second argument is not provided or is "~", it changes the directory to the home directory.
  - If the second argument is "-", it changes the directory to the previous working directory.
  - Otherwise, it changes the directory to the specified path.
- Uses `_getenv` to retrieve environment variables for handling "~" and "-" cases.
- Updates the `OLDPWD` and `PWD` environment variables after a successful directory change.

---

## `alias_functions.c` Alias Management Functions

| Function       | Purpose                                      | Parameters                                     | Return                         | Notes                                           |
|----------------|----------------------------------------------|------------------------------------------------|--------------------------------|-------------------------------------------------|
| `print_all`    | Print all aliases to stdout.                 | `alias`: Head of the linked list of aliases.   | None                           | Iterates through the linked list and prints each alias name and value. |
| `print_spec`   | Print specific aliases to stdout.            | `alias`: Head of the linked list of aliases.   | `alias_names`: Array of alias names to print. | Iterates through the linked list and prints aliases whose names match the specified array. |
| `define_alias` | Define or update an alias.                   | `alias`: Head of the linked list of aliases.   | `name`: Name of the alias. `value`: Value associated with the alias. | Checks if the alias with the given name exists; if yes, updates its value; otherwise, creates a new alias. |
| `unset_alias`  | Unset an alias.                              | `alias`: Head of the linked list of aliases.   | `name`: Name of the alias.    | Returns 0 for success, 1 if the alias is not found. Removes the alias with the specified name from the linked list. |
| `free_aliases` | Free allocated memory for aliases.           | `alias`: Head of the linked list of aliases.   | None                           | Frees memory for all nodes in the linked list, including name and value strings. |

**Usage**
- `alias [name[='value'] ...]`: Prints a list of all aliases, one per line, in the form name='value'.
- `alias name [name2 ...]`: Prints the aliases name, name2, etc., one per line, in the form name='value'.
- `alias name='value' [...]`: Defines an alias for each name whose value is given. If name is already an alias, replaces its value with value.
- These functions collectively handle the management, printing, definition, and removal of aliases in the Simple Shell.

---

## `_dircat.c` Function

| Function       | Purpose                                       | Parameters                      | Return                                     | Notes                                                |
|----------------|-----------------------------------------------|---------------------------------|--------------------------------------------|------------------------------------------------------|
| `_dircat`      | Concatenate a directory pathname to a filename. | `dir`: Directory path. `filename`: Filename. | New pointer to the resulting string.       | Calculates lengths, checks for a middle slash, allocates memory, and concatenates the directory path and filename. Returns the resulting string. |

**Usage:**
- Utilized for concatenating a directory path to a filename, creating a new string pointer.

---

## Printing Functions

| File         | Function      | Purpose                                  | Parameters                | Return                  | Details                                       |
|--------------|---------------|------------------------------------------|---------------------------|-------------------------|-----------------------------------------------|
| `_print.c` | `_print`    | Print a string to standard output.       | `str`: The string to be printed. | N/A                     | Uses `_strlen` to determine the string length, writes to standard output using `write`. |
|`_printchar.c`| `_printchar`  | Prints a character.                      | `c`: The character to be printed. | Always returns 1 (success). | Writes the character to standard output using `write`. |

**Usage:**

- **`_print` Function:**
  - Utilized to print strings to standard output.
    ```c
    _print("Hello, World!\n");
    ```

- **`_printchar` Function:**
  - Used to print individual characters.
    ```c
    _printchar('A');
    ```
    
---

## String Manipulation Functions

| File        | Function   | Purpose                                | Parameters                                     | Return                                     | Details                                          |
|-------------|------------|----------------------------------------|------------------------------------------------|--------------------------------------------|--------------------------------------------------|
| `_strcat.c` | `_strcat`  | Concatenate two strings.               | `dest`: Destination string. <br> `src`: Source string to append. | A pointer to the resulting string.        | Appends characters of `src` to the end of `dest`. |
| `_strchr.c` | `_strchr`  | Locates a character in a string.       | `s`: Pointer to the string. <br> `c`: Character to find. | A pointer to the first occurrence or NULL. | Finds the first occurrence of `c` in the string. |
| `_strstr.c` | `_strstr`  | Locates a substring in a string.       | `haystack`: String to search. <br> `needle`: Substring to find. | Returns 0 if substring found, 1 otherwise. | Searches for `needle` in `haystack`.               |
| `_strlen.c` | `_strlen`  | Calculate the length of a string.      | `str`: Input string.                          | The length of the string.                 | Counts characters in `str` until the null terminator. |
|`_strncmp.c` | `_strncmp` | Compare 'n' characters of two strings. | `s1`: First string. <br> `s2`: Second string. <br> `n`: Number of characters to compare. | 0 if equal, negative if s1<s2, positive if s1>s2. | Compares first `n` characters of `s1` and `s2`.    |
| `_strcmp.c` | `_strcmp`  | Compare two strings.                   | `s1`: First string. <br> `s2`: Second string. | 0 if equal, negative if s1<s2, positive if s1>s2. | Compares all characters of `s1` and `s2`.         |
|`_cstrcmp.c` | `_cstrcmp` | Compare two strings.                   | `str1`: First string. <br> `str2`: Second string. | 0 if equal, negative if str1<str2, positive if str1>str2. | Case-sensitive comparison of `str1` and `str2`. |
| `_strcpy.c` | `_strcpy`  | Copy a string from source to destination. | `dest`: Destination string. <br> `src`: Source string. | A pointer to the destination string.    | Copies characters from `src` to `dest` until null terminator. |
| `_strdup.c` | `_strdup`  | Duplicates a string.                   | `src`: Pointer to the source string.         | A pointer to the duplicated string.     | Allocates memory and copies content of `src`.     |
|  `_itoa.c`  | `_itoa`    | Converts an integer to a string.       | `n`: Integer to be converted. <br> `base`: The base for conversion. <br> `uppercase`: Flag for uppercase format. | A pointer to the resulting string.       | Converts `n` to a string with the specified base and case. |
|  `_sstr.c`  |  `_sstr`   | Switches two strings.                  | `dest`: Address of the string to be replaced. <br> `src`: String to replace the old one. | Returns 0 on success, 1 on failure. | N/A                                           |
|  `_atoi.c`  |  `_atoi`   | Converts a string to an integer.       | `s`: Pointer to the string to be converted. | The integer value of the string. | Handles negative numbers. Skips leading non-numeric characters. Stops conversion at the first non-numeric character after encountering a digit. |


**Usage:**

These functions collectively aid in manipulating strings, comparing their contents, and converting between different data types, making them valuable helper functions for various operations within the shell implementation.

- `_strcat`: Concatenate two strings.
- `_strchr`: Locate a character in a string.
- `_strstr`: Locate a substring in a string.
- `_strlen`: Calculate the length of a string.
- `_strncmp`: Compare 'n' characters of two strings.
- `_strcmp`: Compare two strings.
- `_cstrcmp`: Case-sensitive comparison of two strings.
- `_strcpy`: Copy a string from source to destination.
- `_strdup`: Duplicate a string.
- `_itoa`: Convert an integer to a string.
- `_sstr`: Switch two strings.
- `_atoi`: Convert a string to an integer.

---


## 🚚 Installation 🚚

1. Clone the repository:

```bash
git@github.com:hiba-emording/simple_shell.git
```

2. Compile the shell:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
```


3. Run the shell:

```bash
./simple_shell
```


## ✨ Fun Facts ✨

- The concept of a shell in computing dates back to the early days of Unix in the 1970s.

- The term "shell" comes from the idea that it is the outer layer surrounding the operating system's kernel, providing an interface for users to interact with the system.

- The oldest known shell command is likely the `ls` command, used for listing directory contents.

- The shell plays a crucial role in the "pipe and filter" philosophy of Unix, allowing commands to be chained together to perform complex operations.

- The design of shells has inspired various scripting languages, including the creation of the widely used Bash scripting language.

- Did you know? The first Unix shell was the Thompson shell, written by Ken Thompson.

- The shell provides a powerful and flexible environment for automation, scripting, and system administration tasks.

- The use of emojis in the command-line interface is a lighthearted way for developers to express themselves in a traditionally text-based environment.


🔁 Share your favorite fun shell fact with the community and let's celebrate the world of command-line interfaces! 🚀
*Happy coding!* 🌟
