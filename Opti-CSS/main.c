#ifndef H_GOBAL
#define H_GLOBAL
    #include <stdio.h>
    #include <stdlib.h>
#endif

#ifndef H_MANIPULATION
#define H_MANIPULATION
    #include "manipulation_liste.h"
#endif

#ifndef H_FUNCTIONS
#define H_FUNCTIONS
    #include "fonctions.h"
#endif

#define OPTION_BEAUTIFUL 0
#define TRUE 1
#define FALSE 0

int main(int argc, char** argv) {

    int option_beautiful = FALSE;
    int i = 0;
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

    if (2 >= argc) {
        if (45== argv[1][0] ){
            switch(argv[1][1]){
                case 104:
                    print_help();
                    return (EXIT_SUCCESS);
                    break;
                case 98:
                    option_beautiful = TRUE;
                default:
                    break;
            }
        }
    }

    if (3 > argc) { // On vérifie qu'on a bien au moins un fichier entrée et un fichier sortie en paramètres
        printf("Not enough parameters.\n");
        return (1);
    }
  // On vérifie l'extension des fichiers et leur existence
    while (i_files<argc-1) {
        filename = argv[1,i_files];
        file_exist(filename);
        is_css_file(filename);
        i_files++;
    }
    // On vérifie si le fichier de sortie existe,si c'est le cas on arrête
    filename = argv[1,i_files];
    if (NULL != (file_output = fopen(filename,"r"))) {
        printf("Output file %s already exists.\n",filename);
        fclose(file_output);
    }
    else {
        css_file_output = filename;
        fclose(file_output);
    }
    for (i_files=1;i_files<argc-1;i_files++) { // On parcourt les fichiers
        css_file_input = argv[1,i_files];
        file_input = fopen(css_file_input,"r");
        if (NULL == file_input) {
            printf("Cannot read from file %s.\n",css_file_input); // Si l'un des fichiers d'entrée n'existe pas,on arrête
            fclose(file_input);
            return (1);
        }
        else {
            int i_word = 0;
            while ((lecture=fgetc(file_input))!= EOF) { // On parse
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
//  list = list_sort(list);
    return (EXIT_SUCCESS);
}
