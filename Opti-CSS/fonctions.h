

/*--------------------------------------------------\*
 declaration des prototypes de fonction.c
\*--------------------------------------------------*/
void file_exist(const char * name_file);
int is_css_file (const char * file_input);
//void write( char out_file, t_list_chain* liste );			// a reecrire
void file_open(FILE* fichier, char* file_open);							// appeler la fonction tel-que =>   FILE* fichier = NULL;   file_open(fichier, "toto");
void print_help();