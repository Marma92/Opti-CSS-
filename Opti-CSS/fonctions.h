#include <stdio.h>
#include <stdlib.h>



/*--------------------------------------------------\*
 declaration des prototypes de fonction.c
\*--------------------------------------------------*/
void file_exist( char name_file );
int is_css_file (char * file_input);
void write( char out_file, t_list_chain* liste );
FILE* file_open(char* file_open);