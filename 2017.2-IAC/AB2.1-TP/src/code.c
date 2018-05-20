/*
 * =====================================================================================
 *
 *       Filename:  code.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/20/2018 04:14:15 AM
 *       Revision:  none
 *       Compiler:  gcc
 *        License:  GNU
 *
 *         Author:  Matheus Artur Cabral Costa (MACC), macc@ic.ufal.br
 *         Author:  Luis Alberto Pontes Cabus Setton (VIPER), lapcs@ic.ufal.br
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
    kill(pid,SIGKILL);
    return ;
}

int main(int argc, char *argv[], char *envp[])
{
    pid = fork();

    char ucp[256], ucp_mem[256];
    time_t begin, end, track;
    int timer = 0;

    sprintf(ucp, "%s%d%s", "ps -p ", pid, " -o pcpu | sed 1d | tr -d ' '");
    sprintf(ucp_mem, "%s%d%s", "pmap -x ", pid, " | grep total | awk '{print $4}'");

    signal(SIGALRM,(void (*)(int))finish);


    if(pid < 0)
    {
        perror("Error: fork failed");
    }
    else if(pid > 0)
    {
        alarm(10);

        begin = time(NULL);
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

                    if(end + 1 == track)
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
                    if(end + 1 == track)
                    {
                        timer += 1;
                        end = time(NULL);
                        system(ucp);
                        system(ucp_mem);
                    }

                    track = time(NULL);
                }

            }
        }
        wait(NULL);
    }
    else
    {
        if( strcmp(argv[1], "ucp") == 0 )
        {
            for(;;){}
        }
        if( strcmp(argv[1], "ucp-mem") == 0 )
        {
            for(;;)
            {
                malloc(2048*sizeof(int));
            }
        }
    }


    return 0;
}				/* ----------  end of function main  ---------- */
