#include <stdio.h>
#include <stdlib.h>

typedef struct s_list_chain {
    char* balise;
    char* property;
    char* value;
    struct s_list_chain* next;
}t_list_chain;

#include "fonctions.h"
#include "manipulation_liste.h"
#define OPTION_BEAUTIFUL 0
#define TRUE 1
#define FALSE 0


int main(int argc, char** argv) {

    int option_beautiful = OPTION_BEAUTIFUL;
    int i;
    t_list_chain * list = NULL;


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
        return (-1);
    }

    //file in
    while(i=0 >= argc-2){
        
        //si fichier css, on le stocke dans le tableau file
        if ( is_css_file(argv[i]) == TRUE && file_exist(argv[i])){
            FILE* file_input = fopen(argv[i], "r");
            if( NULL == file_input){
                printf("Cannot read from file: %s.\n", argv[i]);
                fclose(argv[i]);
                exit(-1);
            }
            else{
                while ((lecture=fgetc(file_input))!= EOF) {
                    switch (lecture) {
                        case '{' : 
                            word[i_word]='\0';
                            balise = word_copy(word);
                            word[0]='\0';
                            i_word=0;
                            break;
                        case ':' : 
                            word[i_word]='\0';
                            property = word_copy(word);
                            word[0]='\0';
                            i_word=0;
                            break;
                        case ';' : 
                            word[i_word]='\0';
                            value = word_copy(word);
                            word[0]='\0';
                            i_word=0;
                            list = list_chain_append(list,balise,property,value);
                            break;
                        case '}' : 
                            word[i_word]='\0';
                            word[0]='\0';
                            i_word=0;
                            break;
                        case 32 : 
                            break;
                        case 9 : 
                            break;
                        case '\n' : 
                            break;
                        default : 
                            word[i_word]=lecture;
                            i_word++; 
                            break;
                    }
                }
            }
            fclose(file_input);
        }
        else{
            printf("Error this file: %c is not a CSS file", argv[i]);
            exit(-1);
        }
        i++;
    }

    //file result out
    FILE* file_result = fopen(argv[argc-1], "w+");
    
    if(is_css_file(file_result)){
        if (file_result(file_result) == NULL){
            printf("Error open file result.\n");
            exit(-1);
        }
        /* write(file_result, chaine);
        list->balise
        list->property
        list->value
        */
        
        while(list->next == NULL){
            write(file_result, list->balise);
            if (TRUE == option_beautiful)
                write(file_result, "{\n\t");
            write(file_result, list->property);
            if (TRUE == option_beautiful)
                write(file_result, "\n");
            write(file_result, list->property);
            list = list->next;
        }
       
    }
    return (EXIT_SUCCESS);
}
