#include <stdlib.h>
#include <stdio.h>

typedef struct s_list_chain {
    char* balise;
    struct s_list_node * node;
    struct s_list_chain * next;
}t_list_chain;

typedef struct s_list_node {
    char * property;
    char * value;
    struct s_list_node * next;
}t_list_node;



/*--------------------------------------------------\*
 declaration des prototypes de manipulation_liste.c
\*--------------------------------------------------*/

t_list_chain * list_chain_new(char * balise);
t_list_chain * list_chain_append(t_list_chain*  list, const char* balise, const char* property, const char* value);
t_list_chain * list_chain_remove(t_list_chain* list, int index);
t_list_chain * list_sort (t_list_chain * list);
void list_chain_display(t_list_chain* list);
char * concat(char *chaine1,char *chaine2);
char * word_copy (char * word);
