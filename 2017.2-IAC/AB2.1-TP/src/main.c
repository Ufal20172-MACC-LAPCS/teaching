/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/20/2018 04:14:15 AM
 *       Revision:  none
 *       Compiler:  gcc
 *        License:  GNU
 *
 *         Author(s):  Matheus Artur Cabral Costa (MACC), macc@ic.ufal.br
 *                     Luis Alberto Pontes Cabus Setton (VIPER), lapcs@ic.ufal.br
 *
 *   Organization:  UFAL
 *
 * =====================================================================================
 */

#include    <sys/types.h>
#include    <sys/sysinfo.h>
#include    <unistd.h>
#include    <sys/types.h>
#include    <sys/wait.h>
#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>
#include    <time.h>
#include    <signal.h>

int pid = -1;

void finish(int sig)
{
    kill(pid,SIGKILL); /* Kills the child proccess */
}			/* ----------  end of function finish ---------- */   

int main(int argc, char *argv[], char *envp[])
{
    
    if( argc != 2 )
    {
        printf("Failed, Invalid number of parameters\n");
        return 0;

    }
    if( strcmp(argv[1], "ucp") != 0 && strcmp(argv[1], "ucp-mem") != 0 )
    {
        printf("Failed, you can only use ucp or ucp-mem as parameter\n");
        return 0;
    }

    pid = fork();

    char ucp[256], ucp_mem[256];

    time_t begin, end, track; /* Clock variables */
    int timer = 0;

    sprintf(ucp, "%s%d%s", "ps -p ", pid, " -o pcpu | sed 1d | tr -d ' '"); /* Builds the String to check cpu usage */
    sprintf(ucp_mem, "%s%d%s", "pmap -x ", pid, " | grep total | awk '{print $4}'"); /* Builds the String to check cpu and memory usage */

    signal(SIGALRM,(void (*)(int))finish); /* Flag the function finish to kill the child processes after 10 seconds */

    if(pid < 0)
    {
        perror("Error: ");
        exit(-1);
    }
    else if(pid > 0)
    {
        alarm(10);/* set the time limit */

        begin = time(NULL); /* Record the initial time */
        end = time(NULL);

        for(;;)
        {
            if( strcmp(argv[1], "ucp") == 0 )
            {
                for(;;)
                {
                    if(end == begin + 10)
                    {
                        return 0;
                    }

                    if(end + 1 == track) /* Prints the UCP usage every second */
                    {
                        timer += 1;
                        end = time(NULL);

                        printf("%d Second(s), CPU running at:\n", timer);
                        system(ucp);
                    }

                    track = time(NULL);
                }
            }
            if( strcmp(argv[1], "ucp-mem") == 0 )
            {
                for(;;)
                {
                    if(end == begin + 10)
                    {
                        return 0;
                    }
                    if(end + 1 == track) /* Prints the UCP and memory usage every second */
                    {
                        timer += 1;
                        end = time(NULL);

                        printf("%d Second(s), CPU running at:\n", timer);
                        system(ucp);

                        printf("Memory at running at:\n");
                        system(ucp_mem);
                        printf("\n");
                    }
                    track = time(NULL);
                }
            }
        }
        wait(NULL);
    }
    else
    {
        if( strcmp(argv[1], "ucp") == 0 ) /* Execute the UCP usage loop */
        {
            for(;;){} 
        }
        if( strcmp(argv[1], "ucp-mem") == 0 ) /* Execute the UCP and memory usage loop */
        {
            for(;;)
            {
                malloc(sizeof(100));
            }
        }
    }

    return 0;
}				/* ----------  end of function main  ---------- */
