/* 
 * File:   main.c
 * Author: Arnaud
 
 * Created on 26 octobre 2014, 14:41
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    if (4 > argc) {
        printf("Nombre de parametres insuffisant\n");
        return (1);
    }
    
    FILE *finput1, *finput2, *foutput;
    
    // On rentre en paramètres trois fichiers, les deux premiers sont censés exister, le troisième est le fichier CSS final a créer.
    const char * fichier1 = argv[1,1];
    const char * fichier2 = argv[1,2];
    const char * fichier_result = argv[1,3]; 
    
    // Si le fichier de sortie existe déjà,on renvoie un message d'erreur.
    if (NULL == (fopen(fichier_result,"r")) ) {
        foutput = fopen(fichier_result,"w");
    }
    else {
        printf("Fichier %s existant, copie impossible\n",fichier_result);
        exit(1);
    }
    
    // On vérifie que chacun des deux fichiers passés en paramètres existent bien.
    if (NULL == (finput1 = fopen(fichier1,"r"))) {
        fprintf(stderr,"I\n");
        exit(1);
    }
    
    if (NULL == (finput2 = fopen(fichier2,"r"))) {
        fprintf(stderr,"I\n");
        exit(1);
    }
    
    // On ferme tous les fichiers.
    fclose(finput1);
    fclose(finput2);
    fclose(foutput);
    
    return (EXIT_SUCCESS);
}

