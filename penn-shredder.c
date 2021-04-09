#include "penn-shredder.h"

pid_t child_pid = -1;

void sigintHandler(int sig_)

{  
    if (child_pid > 0)
    {   
        kill(child_pid,SIGKILL);
    }
}

void timeHandler(int sig_)
{   
    char *catch_phrase = "Bwahaha ... tonight I dine on turtle soup\n";
    
    if (child_pid > 0){kill(child_pid,SIGKILL);}

    write(STDOUT_FILENO, catch_phrase, strlen(catch_phrase));
    
}

int main(int argc, char **argv)
{   
    char *exec_;
    int wstatus;
    int w;
    // int pid;
    
    int timer = getTime(argc, argv);
    signal(SIGALRM, timeHandler); 
    signal(SIGINT, sigintHandler);
       
    while (1)
    {         
        exec_ = getInput();
        child_pid = fork();
        if (child_pid == 0) // child process
        {   
            execCommand(exec_, timer);

        }

        else if(child_pid > 0) // parent process
        {   
            alarm(timer);
            w = wait(&wstatus);

            if (WIFEXITED(wstatus))
            {
                alarm(0);
            }

            alarm(0);
        }

        else
        {
            printf("pid fail");
        }
        
        
    }

}

// int main() 
// {
//         char *args = (char*)malloc(sizeof(char) * 1024);
        
//         // signal(SIGINT, sigintHandler);
//         read(0, args, 1024);

//         printf("my input %s\n", args);

        
        
// }
