# DONE:
- handle printing env like normal sh { check exec_cmd.c}
- Implement the setenv and unsetenv builtin commands (added and tested)
- Implement the builtin command cd (Done and working fine but I have another approach may try it later!)

# UNDER PROCESS:
- write our own getline function											<!-- Daniel -->
- write our own strtok <!-- HIBA -->


# NOT DONE YET:

### Builtins:
- Implement the alias builtin command

### Fixes:
- use perror for all error calls <!-- HIBA -->
- fix exit calls skiping all frees at end of main { pass valgrind test }
- Add built ins function to avoid bettymax lines in exec_cmd.c <!-- HIBA -->

### Advanced shell managment:
- Handle the commands separator ;
- Handle the && and || shell logical operators
- Handle variables replacement, Handle the $? variable, Handle the $$ variable
- Handle comments (#)

### LATER ON:
* File as input
* Update readme.md <!-- HIBA -->
