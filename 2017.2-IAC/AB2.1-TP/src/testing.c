/*
 * =====================================================================================
 *
 *       Filename:  code.c
 *
 *    Description: Testing C++ stuff in C
 *
 *        Version:  0.1
 *        Created:  05/20/2018 07:21:42 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Matheus Artur Cabral Costa (MACC), macc@ic.ufal.br
 *   Organization:  UFAL
 *
 * =====================================================================================
 */
#include    <sys/times.h>
#include    <sys/vtimes.h>
#include    <unistd.h>
#include    <sys/types.h>
#include    <sys/sysinfo.h>
#include    <sys/wait.h>
#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>
#include    <time.h>
#include    <signal.h>

int pid = -1;
struct sysinfo memInfo;

static clock_t lastCPU, lastSysCPU, lastUserCPU;
static int numProcessors;

void init()
{
    FILE* file;

    struct tms timeSample;
    char line[128];

    lastCPU = times(&timeSample);
    lastSysCPU = timeSample.tms_stime;
    lastUserCPU = timeSample.tms_utime;

    file = fopen("/proc/cpuinfo", "r");
    numProcessors = 0;

    while(fgets(line, 128, file) != NULL)
    {
        if (strncmp(line, "processor", 9) == 0) numProcessors++;
    }

    fclose(file);
}

double getCurrentValue()
{
    struct tms timeSample;
    clock_t now;
    double percent;
    now = times(&timeSample);

    if (now <= lastCPU || timeSample.tms_stime < lastSysCPU || timeSample.tms_utime < lastUserCPU)
    {
        percent = -1.0;
    }
    else
    {
        percent = (timeSample.tms_stime - lastSysCPU) + (timeSample.tms_utime - lastUserCPU);
        percent /= (now - lastCPU);
        percent /= numProcessors;
        percent *= 100;
    }

    lastCPU = now;
    lastSysCPU = timeSample.tms_stime;
    lastUserCPU = timeSample.tms_utime;

    return percent;
}


void finish(int sig)
{
    kill(pid,SIGKILL);
}


int main(int argc, char *argv[], char *envp[])
{

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
            for(;;){
                double v;
                v = getCurrentValue();
                printf("%lf", v);
            }
        }
        if( strcmp(argv[1], "ucp-mem") == 0 )
        {
            for(;;)
            {
                malloc(1024*sizeof(int));
            }
        }
    }


    return 0;
}				/* ----------  end of function main  ---------- */
