#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// int WIFEXITED (int status)
/* This macro returns a nonzero value if the child process terminated normally with exit or _exit.*/

int main(int argc, char** argv)
{
    assert(argc>4);
    printf("Bonjour je suis '%s'\n",argv[0]);

    int statusChecker;
    int indicePid = 0;
    int needKill = 0;
    int NbProcessMax = atoi(argv[2]);
    assert(NbProcessMax>0);
    int NbProcessAct=0;

    int nbExec = argc-3;

    int * PID_LIST = malloc(sizeof(int)*nbExec);

    for(int i = 0; i<nbExec;++i)
    {
        if(NbProcessAct==NbProcessMax)
        {
            wait(&statusChecker);
            --NbProcessAct;

            if(!WIFEXITED(statusChecker))
            {
                needKill=1;
                break;
            }
        }

        int pid = fork();
        ++NbProcessAct;
        PID_LIST[indicePid]=pid;
        indicePid++;

        if(pid==0) //enfant
        {
            execl(argv[1],argv[1],argv[i+3],NULL);
        }
    }

    if(needKill)
    {
        for(int i = 0; i<indicePid;i++)
        {
            kill(PID_LIST[indicePid],15);
        }
    }
    else
    {
        for(int i = 0; i<NbProcessAct;i++)
        {
            wait(&statusChecker);
            if(!WIFEXITED(statusChecker))
            {
                for(int i = 0; i<indicePid;i++)
                {
                    kill(PID_LIST[indicePid],15);
                }

                break;

            }
        }
    }

    free(PID_LIST);

    return 0;
}
