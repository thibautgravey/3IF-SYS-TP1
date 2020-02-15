

# si on tape "make" sans préciser de cible, make va chercher à
# construire la *première* cible du Makefile.
default: all

all: rebours parexec

##########################################
# compilation des programmes

rebours: rebours.c
	gcc -Wall -Werror -o rebours   rebours.c 

fourche: fourche.c
	gcc -Wall -Werror -o fourche fourche.c

doublerebours: doublerebours.c
	gcc -Wall -Werror -o doublerebours   doublerebours.c 

parexec: parexec.c
	gcc -Wall -Werror -o parexec   parexec.c

parexec1: parexec1.c
	gcc -Wall -Werror -o parexec1   parexec1.c

parexec2: parexec2.c
	gcc -Wall -Werror -o parexec2   parexec2.c


##########################################
# nettoyage des fichiers générés

clean:
	rm -f *.o parexec parexec1 parexec2 parexec3 rebours fourche doublerebours
