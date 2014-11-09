#
#		Makefile permettant de 
#		générer l executable
#

#compilateur utilise
CC=gcc
#regroupe les options de compilation
# -W : active les warning suplementaire
# -Wall : active tout les warning possibles :P
# -ansi : force la compalation en ANSI
# -pendantic : affiche les warnings requis par la norme ANSI du langage.
CFLAGS= -W -Wall -ansi -pendantic
#regroupe  les options d edition de liens
LDFLAGS=
#nom de l executable a generer
EXEC=optiCss


#regroupe dans ces dépendances l'ensemble des exécutables à produire
all: $(EXEC)


optiCss: fonction.o main.o manipulation.o manipulation_liste.o
	$(CC) -o $(EXEC) fonction.o main.o manipulation.o manipulation_liste.o $(LDFLAGS)

fonction.o : fonction.c
	$(CC) -o fonction.o -c fonction.c $(CFLAGS)

main.o : main.c
	$(CC) -o main.o -c fonction.c $(CFLAGS)

manipulation.o : manipulation.c
	$(CC) -o manipulation.o -c manipulation.c $(CFLAGS)

manipulation_liste.o : manipulation_liste.c
	$(CC) -o manipulation_liste.o -c manipulation_liste.c $(CFLAGS)


#permet de supprimer tout les fichiers intermediaires
clean: 
	rm -rf *.o

#permet de supprime tout ce qui peut être régénéré et permet une reconstruction complète du projet.
mrproper: clean
	rm -rf optiCss