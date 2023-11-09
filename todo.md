# DONE:
- handle printing env like normal sh { check exec_cmd.c}
- Implement the setenv and unsetenv builtin commands (added and tested)
- Implement the builtin command cd (Done and working fine but I have another approach may try it later!)
- write our own strtok
- use perror for all error calls 
- Handle comments (# { check tokenize.c })

# UNDER PROCESS:
- write our own getline function											<!-- Daniel -->

# NOT DONE YET:

### Builtins:
- Implement the alias builtin command

### Fixes:
- fix exit calls skiping all frees at end of main { pass valgrind test }
- Add built ins function to avoid bettymax lines in exec_cmd.c / va list.

### Advanced shell managment:
- Handle the commands separator ;
- Handle the && and || shell logical operators
- Handle variables replacement, Handle the $? variable, Handle the $$ variable

### LATER ON:
* File as input
* Update readme.md <!-- HIBA -->
