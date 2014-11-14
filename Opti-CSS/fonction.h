#include <stdio.h>
#include <stdlib.h>



/*--------------------------------------------------\*
 declaration des prototypes de fonction.c
\*--------------------------------------------------*/
void file_exist( char name_file );
int is_css_file (char * file_input);
void write( char out_file, t_list* liste );
FILE* file_open(char* file_open);


/*--------------------------------------------------\*
 declaration des prototypes de manipulation.c
\*--------------------------------------------------*/



/*--------------------------------------------------\*
 declaration des prototypes de manipulation_liste.c
\*--------------------------------------------------*/
t_list_chain* list_chain_new(char balise, char value);
t_list_chain* list_chain_append(t_list_chain* list, char balise, char value);
t_list_chain* list_chain_remove(t_list_chain* list, int index);
t_list_chain* list_chain_display(t_list_chain* list);
