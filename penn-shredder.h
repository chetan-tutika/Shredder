#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h> 
#include <signal.h>
#include <ctype.h>


char *removeSpace(char *myStr)
{
  char *end;

  while(isspace((unsigned char)*myStr)) myStr++;

  if(*myStr == 0)  
    return myStr;

  end = myStr + strlen(myStr) - 1;
  while(end > myStr && isspace((unsigned char)*end)) end--;

  end[1] = '\0';

  return myStr;
}


char *parseInput(char *input)
{   
    char *token = strtok(input, " ");
    char *out = removeSpace(token);

    return out;
}

char *getInput()
{   
    int buf_size = 1023;
    char *read_message;

    
    char *args = (char*)malloc(sizeof(char) * buf_size);
    read_message = "penn-shredder# ";

    int write_error = write(STDOUT_FILENO, read_message, 15);

    if (write_error == -1)
    {
        perror("Write Error: ");
    }
    
    int read_return = read(STDIN_FILENO, args, buf_size);

    if (read_return == 0)
    {
        exit(0);
    }

    if (read_return == -1)
    {
        perror("Read Error: ");
    }

    args[strlen(args)-1] = 0;
    args = parseInput(args);

    return args;
}



void execCommand(char *command, int timer)
{
    int execve_error;
    char *argp[] = {command, NULL};

    
    execve_error = execve(command, argp, NULL);

    if (execve_error == -1)
    {   
        perror("Execve Error: ");
        exit(0);
    }

}

int getTime(int n_args, char **all_args)
{
    if (n_args <= 1)
    {
        char *no_args_message = "No arguments passes, setting infinite time\n";
        write(STDOUT_FILENO, no_args_message, strlen(no_args_message));
        return 0;    
    }
    else
    {
        int time = atoi(all_args[1]);
        
        if (time <= 0)
        {   
            char *invalid_time_message = "Invalid time, setting infinite time\n";
            write(STDOUT_FILENO, invalid_time_message, strlen(invalid_time_message));
            return 0;
        }

        else
        {
            return time;
        }
        
    }
    
}
