#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    assert(argc==1);
    printf("Bonjour je suis '%s'\n",argv[0]);
    if(fork())
    {
        execl("./rebours","./rebours","5",NULL);
    }
    else
    {
        execl("./rebours","./rebours","1",NULL);
    }
    return 0;
}
