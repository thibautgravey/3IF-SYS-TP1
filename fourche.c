#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    int pid = getpid();
    assert(argc==1);
    printf("Bonjour je suis '%s'\n",argv[0]);
    printf("%d: hello world\n",pid);
    int f = fork();

    pid=getpid();

    if(f)
    {
        printf("%d: je suis le parent\n",pid);
    }
    else
    {
        printf("%d: je suis l'enfant\n",pid);
    }

    return 0;
}
