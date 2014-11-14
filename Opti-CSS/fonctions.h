#include <stdio.h>
#include <stdlib.h>
#include "manipulation_liste.h"

typedef struct s_list
{
    char balise;
    char propertie;
    char value;
    struct s_list_chain* next;
};
    

/*--------------------------------------------------\*
 declaration des prototypes de fonction.c
\*--------------------------------------------------*/
void file_exist( char name_file );
int is_css_file (char * file_input);
void write( char out_file, t_list_chain* liste );
FILE* file_open(char* file_open);


/*--------------------------------------------------\*
 declaration des prototypes de manipulation_liste.c
\*--------------------------------------------------*/
t_list_chain* list_chain_new(char balise, char value);
t_list_chain* list_chain_append(t_list_chain* list, char balise, char value);
t_list_chain* list_chain_remove(t_list_chain* list, int index);
t_list_chain* list_chain_display(t_list_chain* list);