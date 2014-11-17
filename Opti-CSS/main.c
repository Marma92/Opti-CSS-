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
    
    int i_files=1; // Variable incrémentée à chaque fois qu'on ouvre un nouveau fichier
    char lecture,*balise,*property,*value,word[256]; // Caractère lu par la fonction fgetc, cela permet d'afficher le contenu du fichier
    const char *filename,* css_file_input,* css_file_output; // Respectivement les variables qui vont contenir les noms des fichiers 
                                                   // d'entrée et de sortie
    FILE *file_input,*file_output;
    t_list_chain * list = NULL;
    argc = 4; // Comme le fait d'aller chercher la console à chaque fois
              // pour éxécuter le programme est long,je passe les noms des fichiers en paramètres de cette façon
    argv[1,1] = "style.css"; // Fichier d'entrée
    argv[1,2] = "style2.css"; // Fichier d'entrée
    argv[1,3] = "result.css"; // Fichier de sortie
    
    if (3 > argc) { // On vérifie qu'on a bien au moins un fichier entrée et un fichier sortie en paramètres
        printf("Not enough parameters.\n");
        return (1);
    }
    
    while (i_files<argc-1) {
        filename = argv[1,i_files];
        file_exist(filename);
        is_css_file(filename);                
        i_files++;
    }
    
    filename = argv[1,i_files];
    if (NULL != (file_output = fopen(filename,"r"))) {
        printf("Output file %s already exists.\n",filename);
        fclose(file_output);
    }
    else {
        css_file_output = filename;
        fclose(file_output);
    }
    for (i_files=1;i_files<argc-1;i_files++) {
        css_file_input = argv[1,i_files];
        file_input = fopen(css_file_input,"r");
        if (NULL == file_input) {
            printf("Cannot read from file %s.\n",css_file_input);
            fclose(file_input);
            return (1);
        }
        else {
            int i_word = 0;
            while ((lecture=fgetc(file_input))!= EOF) {
                switch (lecture) {
                    case '{' : word[i_word]='\0';balise = word_copy(word);word[0]='\0';i_word=0;break;
                    case ':' : word[i_word]='\0';property = word_copy(word);word[0]='\0';i_word=0;break;
                    case ';' : word[i_word]='\0';value = word_copy(word);word[0]='\0';i_word=0;
                                list = list_chain_append(list,balise,property,value);
                                break;
                    case '}' : word[i_word]='\0';word[0]='\0';i_word=0;break;
                    case 32 : break;
                    case 9 : break;
                    case '\n' : break;
                    default : word[i_word]=lecture;i_word++; break;
                }  
            }
            fclose(file_input);
        }
    }
    list_chain_display(list);
    return (EXIT_SUCCESS);
}