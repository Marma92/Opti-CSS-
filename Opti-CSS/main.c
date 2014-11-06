/* 
 * File:   main.c
 * Author: Arnaud
 
 * Created on 26 octobre 2014, 14:41
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct elements_list {
        char * name;
        char  properties;
        int max=0;
    } css_elems_list;
    
int is_css_file (char * file_input);

int main(int argc, char** argv) {

   if (3 > argc) {
        printf("Nombre de parametres insuffisant\n");
        return (1);
    }
    
    int i_files=1;
    char lecture;
    const char * css_file_input,* css_file_output;
    
    argc = 4;
    argv[1,1] = "style.css";
    argv[1,2] = "style2.css";
    argv[1,3] = "result.css";
    
    FILE *file_input,*file_output;
    
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

/*css_elems_list * list_create(int length_name,int length_properties) {
    css_elems_list * list = malloc(sizeof(css_elems_list));
    list->name = malloc(length_name*sizeof(char));
    list->properties = malloc(length_properties*sizeof(char));
    return (list);
}*/

int is_css_file (char * file_input) {
    int i = 0;
    while (file_input[i] != '\0') {
        i++;
    }
    if (file_input[i-1]=='s' && file_input[i-2]=='s' && file_input[i-3]=='c' && file_input[i-4]=='.' ) {
        return (1);
    }
    else {
        return (0);
    }
}