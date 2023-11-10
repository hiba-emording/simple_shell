# DONE:
- handle printing env like normal sh { check exec_cmd.c}
- Implement the setenv and unsetenv builtin commands (added and tested)
- Implement the builtin command cd (Done and working fine but I have another approach may try it later!)
- write our own strtok
- use perror for all error calls 
- Handle comments (# { check tokenize.c })
- write our own getline function
- pass valgrind memory leaks test (a lot of calls fail this apparently)

# UNDER PROCESS:
- Implement the alias builtin command <!-- Daniel -->
- implement non-interactive mode for shell <!-- Daniel -->

# NOT DONE YET:

### Builtins:
+ recreate paths when PATH env is modified? { just free paths and re-call create paths }

### Fixes:
- Add built ins function to avoid bettymax lines in exec_cmd.c / va list.

### Advanced shell managment:
- Handle the commands separator ;
- Handle the && and || shell logical operators
- Handle variables replacement, Handle the $? variable, Handle the $$ variable

### LATER ON:
* File as input
* Update readme.md <!-- HIBA -->
