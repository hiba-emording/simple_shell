# DONE:
- handle printing env like normal sh { check exec_cmd.c}


# UNDER PROCESS:
- write our own getline function											<!-- Daniel -->
<<<<<<< HEAD
- write our own strtok <!-- HIBA -->


# NOT DONE YET:

### Builtins:
- Implement the setenv and unsetenv builtin commands <!-- HIBA -->
=======

# NOT DONE YET:
- use perror for all error calls
- fix exit calls skiping all frees at end of main { pass valgrind test }
- write our own strtok
- Implement the setenv and unsetenv builtin commands
>>>>>>> 458440c5255c1d23f4889a3f64b2dddecb0c16d8
- Implement the builtin command cd
- Implement the alias builtin command

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
