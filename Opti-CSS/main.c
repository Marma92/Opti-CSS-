#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    char balise;
    char propertie;
    char value;
    struct s_list_chain* next;
};
    
int is_css_file (char * file_input); // Prototype de la fonction qui vérifie que le fichier est bien un fichier .css

int main(int argc, char** argv) {

   
    
    int i_files=1; // Variable incrémentée à chaque fois qu'on ouvre un nouveau fichier
    char lecture; // Caractère lu par la fonction fgetc, cela permet d'afficher le contenu du fichier
    const char * css_file_input,* css_file_output; // Respectivement les variables qui vont contenir les noms des fichiers 
                                                   // d'entrée et de sortie
    FILE *file_input,*file_output;
    
    argc = 4; // Comme le fait d'aller chercher la console à chaque fois
              // pour éxécuter le programme est long,je passe les noms des fichiers en paramètres de cette façon
    argv[1,1] = "style.css"; // Fichier d'entrée
    argv[1,2] = "style23.css"; // Fichier d'entrée
    argv[1,3] = "result.css"; // Fichier de sortie
    
    if (3 > argc) { // On vérifie qu'on a bien au moins un fichier entrée et un fichier sortie en paramètres
        printf("Not enough parameters.\n");
        return (1);
    }
    
    for (i_files=1;i_files<argc-1;i_files++) {
        css_file_input = argv[1,i_files];
        file_exist(css_file_input);
        !is_css_file(css_file_input);
    }
    
    
    /*
    for (i_files=1;i_files<argc-1;i_files++) { // Pour chaque fichier passé en paramètre (jusqu'à l'avant dernier qui sera le fichier de sortie)
        css_file_input = argv[1,i_files]; // On vérifie que ce soit bien un fichier .css
        if (NULL == (file_input = fopen(css_file_input,"r")) || !is_css_file(css_file_input)) { // Et on vérifie si il existe
            fprintf(stderr,"File %s is either not existing or has an incorrect extension.\n",css_file_input);
            exit(1); // Sinon on s'arrête
        }
        else {
            printf ("Le fichier %s a bien été ouvert \n",css_file_input);
            int i =0;
            while ((lecture= fgetc(file_input))!= EOF) { // On affiche son contenu
                printf("mot %c \n",lecture);
            }
            fclose(file_input);
        }  
    }
    
    css_file_output = argv[1,i_files]; // Le dernier fichier passé en paramètre est le fichier de sortie
    if (NULL == (fopen(css_file_output,"r")) ) {
        file_output = fopen(css_file_output,"w");
    }
    else {
        printf("Fichier %s existant, copie impossible\n",file_output);
        exit(1);
    }
    */
    
    return (EXIT_SUCCESS);
}