#include <stdio.h>
#include <stdlib.h>

#include "fonctions.c"
#include "manipulation_liste.c"

//nom du fichier par defaut
const char* FILE_OUT = "a_out.css";

/*--------------------------------------------------\*
 declaration des prototypes de fonction.c
\*--------------------------------------------------*/
void file_exist(const char * name_file);
int is_css_file (const char * file_input);
void print_help();
//void write( char out_file, t_list_chain* liste );
//FILE* file_open(char* file_open);


/*--------------------------------------------------\*
 declaration des prototypes de manipulation_liste.c
\*--------------------------------------------------*/
/*
t_list_chain* list_chain_new(char balise, char value);
t_list_chain* list_chain_append(t_list_chain* list, char balise, char value);
t_list_chain* list_chain_remove(t_list_chain* list, int index);
t_list_chain* list_chain_display(t_list_chain* list);
*/