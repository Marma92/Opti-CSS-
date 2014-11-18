#include "manipulation_liste.h"

#include <stdio.h>
#include <stdlib.h>

// creation d une nouvelle liste
t_list_chain * list_chain_new(const char * balise){
    t_list_chain * list = (t_list_chain *)malloc(sizeof(t_list_chain));    
    list->balise = balise;
    list->node = NULL;
    list->next = NULL;
    return list;
}

t_list_node* list_node_new(const char* property, const char* value){
    t_list_node* node = (t_list_node*)malloc(sizeof(t_list_node));
    node->property = property;
    node->value = value;
    node->next = NULL;
    return node;
}


// rajoute un element a la fin de la liste
t_list_chain * list_chain_append(t_list_chain*  list, const char* balise, const char* property, const char* value){
    
    if(!list)
        list_chain_new(balise);
    //test si balise existe deja
    while(list != NULL){
        if(list->balise == balise){
           do{
                if(list->node->property == property && list->node->value == value){
                    continue;
                }else{
                    list_node_new(property, value);
                }
                list->node = list->node->next;
            }while(list->node != NULL);
        }else{
            list_chain_new(balise);
        }
        list = list->next;
    }
    return list;
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
void list_chain_display(t_list_chain* list){
    if(list){
        while(list != NULL){
            printf("Balise %s\n",list->balise);
            while (list->node!=NULL){
                printf("Propriété %s Valeur %s\n");
                list->node = list->node->next;
            }
            list = list->next;
        }
    }
}


// Copie un mot,une propriété ou une valeur
char * word_copy (char * word) {
    int i=0;
    char * word_copy;
    word_copy = (char *)malloc(sizeof(word));

    for (i=0;word[i] != '\0';i++){      
        
    } 
    int longueur = i;
	
    for (i=0;i<=longueur;i++) {
        word_copy[i] = word[i];
        if (word[i]=='\0') { word_copy[i] = '\0';}
    }
    
    return (word_copy);
}
