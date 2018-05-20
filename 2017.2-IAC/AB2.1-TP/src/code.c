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
 *
 *         Author:  Matheus Artur Cabral Costa (MACC), macc@ic.ufal.br
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
}

int main(int argc, char *argv[], char *envp[])
{
    int n;
    n = getpid();

    signal(SIGALRM,(void (*)(int))finish);

    pid = fork();

    if(pid < 0)
    {
        perror("Error: fork failed");
    }
    else if(pid > 0)
    {
        alarm(10);
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
