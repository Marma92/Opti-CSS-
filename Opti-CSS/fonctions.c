#include "fonctions.h"

//permet de verifier si le fichier cible exist.

void file_exist(const char * name_file) {
    FILE* fp;
    fp = fopen(name_file,"r");
    if(NULL == fp ){
        printf("File %s does not exists.\n",name_file);
        fclose(fp);
        exit(1);
    }
}

//permet de verifier si le fichier en entree est bien de type .css

void is_css_file (const char * file_input) {
    int i = 0;
    while (file_input[i] != '\0') {
        i++;
    }
    if (file_input[i-1]!='s' || file_input[i-2]!='s' || file_input[i-3]!='c' || file_input[i-4]!='.' ) {
        printf("File %s isn't a css file.\n",file_input);
        exit(1);
    }
}

/*
	ouverture du fichier cible

FILE* file_open(char* file_open){
	file_exist(out_file);
	is_css_file(file_open);
	//obliger de passer l'option w+, pb de droit sous linux
	FILE* fichier = NULL;

    fichier = fopen( out_file, "r+");

    if (fichier != NULL)
        return fichier;
    else
    {
        printf("Impossible d'ouvrir le fichier %c", file_open);
        exit(1);
    }
}


char* get_line(FILE* file_open){
	file_open(file_open);
}





	Fonction permettant, l'ecriture dans un fichier	et il le creer s'il nexiste pas.

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


void print_help(){
	printf("Voici la liste des options disponnible pour l application\n");
	printf("\t-h\tpermet dáfficher le message du helper\n");
	printf("\t-b\tpermet de mettre en forme le texte de sortie\n");
}


void get_line
 */
