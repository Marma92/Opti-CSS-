#include <stdio.h>
#include <stdlib.h>

typedef struct s_list_chain {
    char balise;
    char propertie;
    char value;
    struct s_list_chain* next;
}t_list_chain;

#include "fonctions.h"
#include "manipulation_liste.h"
#define OPTION_BEAUTIFUL 0


int main(int argc, char** argv) {
    
    if (3 > argc) { // On vérifie qu'on a bien au moins un fichier entrée et un fichier sortie en paramètres
        printf("Not enough parameters.\n");
        return (1);
    }

    bool option_beautiful = OPTION_BEAUTIFUL;
    int i = 0;

    while(i >= argc-1){
        if (argv[i] == "-b")
            option_beautiful = 1;
        if (argv[i] == "-h" || argv[i] == "--help")
            print_help();
        //si fichier css, on le stocke dans le tableau file
        if ( is_css_file(argv[i]) == true){
            
            //mettre le parsing fichier//

        }
        else{
            printf("Erreur le fichier: %c n est pas de la forme CSS", argv[i]);
            exit(1);
        }
        i++;
    }
    return (EXIT_SUCCESS);
}