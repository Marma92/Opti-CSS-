#include "manipulation_liste.h"


//utilisation de liste chaine et nom contigue
// car on doit connaitre la taille final pour
// l allocation memoire.

#include <stdio.h>
#include <stdlib.h>




// creation d une nouvelle liste
t_list_chain * list_chain_new(char * balise, char * property, char * value){
    t_list_chain * list = (t_list_chain *)malloc(sizeof(t_list_chain));    
    list->balise = balise;
    list->property = property;
    list->value = value;
    list->next = NULL;
    return list;
}

// rajoute un element a la fin de la liste
t_list_chain * list_chain_append(t_list_chain *  list, char * balise, char * property, char * value){
    if(!list) {
        return list_chain_new(balise,property,value);
    }
    t_list_chain* save = list;
    while(save->next != NULL){
        save = save->next;
    }
    save->next = list_chain_new(balise, property, value);
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
        while(list->next != NULL){
            printf("Balise %s Propriété %s Valeur %s\n",list->balise,list->property,list->value);
            list = list->next;
        }
        printf("Balise %s Propriété %s Valeur %s\n",list->balise,list->property,list->value);
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
