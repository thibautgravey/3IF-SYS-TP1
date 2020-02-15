#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    assert(argc>2);
    printf("Bonjour je suis '%s'\n",argv[0]);

    int nbExec = argc-2;
    printf("NbExec = %d\n",nbExec);

    for(int i = 0; i<nbExec;i++)
    {
        int pid = fork();

        if(pid==0) //enfant
        {
            execl(argv[1],argv[1],argv[i+2],NULL);
        }
    }

    for(int i =0; i<nbExec;i++)
    {
        wait(NULL);
    }

    return 0;
}
