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
CFLAGS= 
#-W -Wall -ansi -pedantic
#regroupe  les options d edition de liens
LDFLAGS=
#nom de l executable a generer
EXEC=OptiCSS


#regroupe dans ces dépendances l'ensemble des exécutables à produire
all: $(EXEC)


$(EXEC): main.o fonctions.o  manipulation_liste.o
	$(CC) -o $(EXEC) main.o fonctions.o  manipulation_liste.o $(LDFLAGS)

fonctions.o : fonctions.c
	$(CC) -o fonctions.o -c fonctions.c $(CFLAGS)

main.o : main.c
	$(CC) -o main.o -c main.c $(CFLAGS)

manipulation_liste.o : manipulation_liste.c
	$(CC) -o manipulation_liste.o -c manipulation_liste.c $(CFLAGS)


#permet de supprimer tout les fichiers intermediaires
clean: 
	rm -rf *.o

#permet de supprime tout ce qui peut être régénéré et permet une reconstruction complète du projet.
mrproper: clean
	rm -rf $(EXEC)
