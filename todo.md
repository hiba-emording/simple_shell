# DONE:
- handle printing env like normal sh { check exec_cmd.c}
- Implement the setenv and unsetenv builtin commands (added and tested)

# UNDER PROCESS:
- write our own getline function											<!-- Daniel -->
- write our own strtok <!-- HIBA -->


# NOT DONE YET:

### Builtins:
- Implement the builtin command cd
- Implement the alias builtin command

# NOT DONE YET:
- use perror for all error calls
- fix exit calls skiping all frees at end of main { pass valgrind test }

### Fixes:
- use perror for all error calls
- fix exit calls skiping all frees at end of main { pass valgrind test }

### Advanced shell managment:
- Handle the commands separator ;
- Handle the && and || shell logical operators
* Handle variables replacement, Handle the $? variable, Handle the $$ variable
- Handle comments (#)

### LATER ON:
* File as input
* Update readme.md <!-- HIBA -->
