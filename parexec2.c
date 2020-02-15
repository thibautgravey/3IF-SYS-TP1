#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    assert(argc>4);
    printf("Bonjour je suis '%s'\n",argv[0]);

    int NbProcessMax = atoi(argv[2]);
    assert(NbProcessMax>0);
    int NbProcessAct=0;

    int nbExec = argc-3;

    for(int i = 0; i<nbExec;i++)
    {
        if(NbProcessAct==NbProcessMax)
        {
            wait(NULL);
            --NbProcessAct;
        }

        int pid = fork();
        ++NbProcessAct;

        if(pid==0) //enfant
        {
            execl(argv[1],argv[1],argv[i+3],NULL);
        }
    }

    for(int i = 0; i<NbProcessAct;i++)
    {
        wait(NULL);
    }

    return 0;
}
