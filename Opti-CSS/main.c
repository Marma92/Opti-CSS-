#include "fonction.h"

/*--------------------------------------------------\*
 declaration de la structure pour la liste
\*--------------------------------------------------*/
typedef struct s_list
{
    char balise;
    char propertie;
    char value;
    struct s_list_chain* next;
};

/*--------------------------------------------------\*
 declaration des variables utiles
\*--------------------------------------------------*/
FILE *finput1, *finput2, *foutput;
FILE *file_input,*file_output;
char lecture;
const char * css_file_input,* css_file_output;




int main(int argc, char** argv) {

    //tmp variables
    argc = 4;
    argv[1,1] = "style.css";
    argv[1,2] = "style2.css";
    argv[1,3] = "result.css";



   if (3 > argc) {
        printf("Nombre de parametres insuffisant\n");
        return (1);
    }    
    
    if( argv[1,1]) == "-b"  ){

    }
    //donc par defaut il n y a pas d option
    else{
        
    }

    // On rentre en paramètres trois fichiers, les deux premiers sont censés exister, le troisième est le fichier CSS final a créer.
    const char * fichier1 = argv[1,1];
    const char * fichier2 = argv[1,2];
    const char * fichier_result = argv[1,3]; 
    
    
    // On vérifie que chacun des deux fichiers passés en paramètres existent bien && des *.css
    file_exist( fichier1 );
    is_css_file (fichier1);
    file_exist( fichier2 );
    is_css_file (fichier2);

    //test si le fichier en sortie exist
    file_exist( fichier_result );
    file_output = file_open(char* file_open);

    ///// CONTINUER ICI LE CODE ??????
    int i_files=1;
    for (i_files=1;i_files<argc-1;i_files++) {
        css_file_input = argv[1,i_files];
        if (NULL == (file_input = fopen(css_file_input,"r")) || !is_css_file(css_file_input)) {
            fprintf(stderr,"File %s is either not existing or has an incorrect extension.\n",css_file_input);
            exit(1);
        }
        else {
            printf ("Le fichier %s a bien été ouvert \n",css_file_input);
            int i =0;
            while ((lecture= fgetc(file_input))!= EOF) {
                printf("mot %c \n",lecture);
            }
            fclose(file_input);
        }  
    }
    
    css_file_output = argv[1,i_files];
    if (NULL == (fopen(css_file_output,"r")) ) {
        file_output = fopen(css_file_output,"w");
    }
    else {
        printf("Fichier %s existant, copie impossible\n",file_output);
        exit(1);
    }
    

    return (EXIT_SUCCESS);
}

/*
css_elems_list * list_create(int length_name,int length_properties) {
    css_elems_list * list = malloc(sizeof(css_elems_list));
    list->name = malloc(length_name*sizeof(char));
    list->properties = malloc(length_properties*sizeof(char));
    return (list);
}
*/