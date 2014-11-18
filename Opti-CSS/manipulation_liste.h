#include <stdlib.h>
#include <stdio.h>

typedef struct s_list_chain {
    char* balise;
    struct t_list_node * node;
    struct s_list_chain * next;
}t_list_chain;

typedef struct s_list_node {
    char * property;
    char * value;
    struct s_list_node * next;
};



/*--------------------------------------------------\*
 declaration des prototypes de manipulation_liste.c
\*--------------------------------------------------*/

/* A retravailler */t_list_chain * list_chain_new(char * balise,char * property,char * value);
/* A retravailler */ t_list_chain * list_chain_append(t_list_chain* list,char * balise,char * property,char * value);
/*A retravailler */ t_list_chain * list_chain_remove(t_list_chain* list, int index);
/*A retravailler */t_list_chain * list_sort (t_list_chain * list);
void list_chain_display(t_list_chain* list);
char * concat(char *chaine1,char *chaine2);
char * word_copy (char * word);
