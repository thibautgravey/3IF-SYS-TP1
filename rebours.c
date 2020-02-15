#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    int pid = getpid();
    printf("Bonjour je suis '%s'\n",argv[0]);
    assert(argc==2);

    int duree = atoi(argv[1]);

    assert(duree>0);

    printf("%d: debut\n",pid);
    while(duree>0)
    {
        printf("%d: %d\n",pid,duree);
        duree--;
        sleep(1);
    }
    printf("%d: fin\n",pid);
    return 0;
}
