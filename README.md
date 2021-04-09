Name: Chetan Tutika<br/>

List of surce file:
1) Makefile
2) penn-shredder.c
3) penn-shredder.h

Compilation Instructions
1) unzip the homework file
2) change directory to HW0
3) type 'make' in the console
4) type './penn-shredder <args>'
    args - time before the child process is killed

Overview of the work
1) penn-shredder takes in a single integer argument. The argument is used to time and  kill the child process if the execution  of the command in the child process takes more than the specified time argument

2) Once we run the program, the program enters a consile mode which reads input from the user and executes user input. On invalid input the program throws an error and prompts for new user input.

3) the program runs in an infine while loop with ctrl C and ctrl D as exit prompts. ctrl C exits the current running child process and ctrl D exits the program.

4) on entering a negative time the clock is set to infinite. That is the command might run for infinte time without being killed. Which is also true if no arguments supplied to the penn-shredder. 

5) While in the program console, only the input command by the user is executed and none of the arguments supplied will be taken to consideration. Before execution of the command, the leading and ending white spaces are trimmed.

6) The maximum string lenght for the user command is 1023 bytes.

Code Layout
1) The main function 'penn-shredder.c' is where the child and parent are forked. The main function also calls various helper functions to read and execute the user prompt.

2) The helper function file 'penn-shredder.h' contains the helper functions to help run the program

