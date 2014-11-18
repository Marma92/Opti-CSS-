#ifndef H_GOBAL
#define H_GLOBAL
    #include <stdio.h>
    #include <stdlib.h>
#endif

#ifndef H_FUNCTIONS
#define H_FUNCTIONS
    #include "fonctions.h"
#endif

//permet de verifier si le fichier cible exist.
int file_exist(const char * name_file) {
    FILE* fp;
    fp = fopen(name_file,"r");
    if(NULL == fp ){
        printf("File %s does not exists.\n",name_file);
        fclose(fp);
        return 0;
    }
    return 1;
}


//permet de verifier si le fichier en entree est bien de type .css
int is_css_file (const char * file_input) {
    int i = 0;
    while (file_input[i] != '\0') {
        i++;
    }
    if (file_input[i-1]!='s' || file_input[i-2]!='s' || file_input[i-3]!='c' || file_input[i-4]!='.' ) {
        printf("File %s isn't a css file.\n",file_input);
        return 0;
    }
    return 1;
}

 
//ouverture du fichier cible
FILE* file_open(char* file_open){
	file_exist(file_open);
	is_css_file(file_open);
	//obliger de passer l'option w+, pb de droit sous linux
	FILE* file = NULL;

    file = fopen( file_open, "r+");

    if (file != NULL)
        return file;
    else
    {
        printf("Error open file: %c", file_open);
        exit(1);
    }
}


/*
//Fonction permettant, l'ecriture dans un fichier	et il le creer s'il nexiste pas.
void write( FILE* file_result, const char* chaine, int option ){	
	
	if( NULL == file_result ){
		printf("erreur lors de la creation du fichier %s\n", file_result);
		exit(-1);
	}
    else{
        if('EOF' == fputs(chaine, file_result)){
            printf("Error write file result. \n");
            exit(-1);
        }
    }	
}
*/

void print_help(){
	printf("Voici la liste des options disponnible pour l application\n");
	printf("\t-h\tpermet dáfficher le message du helper\n");
	printf("\t-b\tpermet de mettre en forme le texte de sortie\n");
}



//fonction pour le strlen
int length( const char* s1){
    int j = 0;
    while( s1[j])
        j++;
    return j;
}

//recherche l'occurence en argv1 et argv2 et retourne la position de curceur
int str_search( char *string, char *pattern){
    
    int i = 0, j = 0;
    int cpt = length( pattern );
    while( string[i] != '\0' ){
        if( string[i] == pattern[j] ){
            if( j == cpt - 1 )
                return i - j;
            j++;
        }
        else
            j = 0;
        i++;
    }
    return -1;
}


int my_strlen(char** word){
    return length(word[1]);
}

/*
//Permet de suprimer les caracteres inutile dans le fichier
unsigned char remove_unsual_caractere(char name_file){
    
    FILE* file = fopen(name_file,"r");
    unsigned int nb_letter = 0, i = 0;

    if ((file == NULL){
        printf("Error open file %s", name_file);
        return EOF;
    }
    while( word = fgetc(name_file))!= EOF ){
        nb_letter ++;
    }

    i = nb_letter;
    unsigned char letter_tmp[i] = NULL;
    word = fgetc(name_file);
    while( word != EOF ){
        switch(word){
            case '\n':
            case '\t':
            case ' ':
                i++;
                break;
            default:
                letter_tmp[i] = word;
                break;
        }
    }
    return letter_tmp;
}
*/