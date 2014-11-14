#include "fonctions.h"


/*/ --------------------------------------\*\
	permet de verifier si le fichier cible 
	exist.

\*\---------------------------------------/*/
void file_exist( char name_file ) {
	FILE* fp;
	fp = fopen( name_file, "r");
	if( NULL == fp ){
		printf("Abandon: le fichier %s exist deja\n", name_file );
		fclose( fp );
		exit(1);
	}
	else{
		fclose( fp );
		return 0;
	}
}


/*/ --------------------------------------\*\
	permet de verifier si le fichier en 
	entree est bien de type .css

\*\---------------------------------------/*/
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


/*/ --------------------------------------\*\
	Fonction permettant, l'ecriture dans un 
	fichier	et il le creer s'il nexiste pas.

\*\---------------------------------------/*/
void write( char out_file, t_list* liste ){
	//FILE* fw;
	file_exist(out_file);
	//obliger de passer l'option w+, pb de droit sous linux
	fw = fopen( out_file, "w+"); 
	if( NULL == fw ){
		printf("erreur lors de la creation du fichier %s\n", out_file);
		return 1;
	}

	int tampon = 0;
	while
}


/*/ --------------------------------------\*\
	ouverture du fichier cible

\*\---------------------------------------/*/
FILE* file_open(char* file_open){
	file_exist(out_file);
	//obliger de passer l'option w+, pb de droit sous linux
	FILE* fichier = NULL;

    fichier = fopen( out_file, "r+");

    if (fichier != NULL)
    {
        //le fichier est correctement ouvert
        return fichier;
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier test.txt");
        exit(1);
    }
}




void print_help(){

}