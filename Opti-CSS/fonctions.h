#include <stdio.h>
#include <stdlib.h>

/*--------------------------------------------------\*
 declaration des prototypes de fonctions.c
\*--------------------------------------------------*/
 
int file_exist(const char * name_file);
int is_css_file (const char * file_input);
//void write( char out_file, t_list_chain* liste );
//FILE* file_open(char* file_open);
void print_help();
int length( const char* s1);
int str_search( char *string, char *pattern);
int my_strlen(char** word);