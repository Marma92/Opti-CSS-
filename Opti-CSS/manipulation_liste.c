#include "manipulation_liste.h"
#include <stdio.h>

typedef struct s_list_chain
{
    char balise;
    char value;
    struct s_list_chain* next;
}t_list_chain;

/*utilisation de liste chaine et nom contigue
// car on doit connaitre la taille final pour
// l allocation memoire.
		typedef struct s_list
		{
			char balise;
			char value;
			struct s_list_chain* next;
		};
*/

// creation d une nouvelle liste
t_list_chain* list_chain_new(char balise, char value){
	t_list_chain* list = ( t_list_chain*)malloc(sizeof(t_list_chain));
	list->balise = balise;
	list->value = value;
	list->next = NULL;
	return list;
}


// rajoute un element a la fin de la liste
t_list_chain* list_chain_append(t_list_chain* list, char balise, char value){
	if(!list)
		return list_chain_new(balise, value);
	t_list_chain* save = list;
	while(save->next != NULL){
		save = save->next;
	}
	save->next = list_chain_new(balise, value);
	return save;
}

//supprime la value a la position donnee
t_list_chain* list_chain_remove(t_list_chain* list, int index){
	if(list && 0 == index){
		t_list_chain* save = list->next;
		free(list);
		return save;
	}
	t_list_chain* save = list;
	while(--index && list){
		list = list->next;
		if(0 == index){
			t_list_chain* node = list->next;
			if(node)
				list->next = node->next;
			free(node);
		}
	}
	return save;
}


//affiche la liste en cas de debog
t_list_chain* list_chain_display(t_list_chain* list){
	if(list)
		while(list->next != NULL){
			printf("%d -> ", list->value);
			list = list->next;
		}
		printf("%d\n", list->value);
}