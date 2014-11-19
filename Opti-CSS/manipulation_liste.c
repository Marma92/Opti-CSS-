#ifndef H_GOBAL
#define H_GLOBAL
    #include <stdio.h>
    #include <stdlib.h>
#endif

#ifndef H_MANIPULATION
#define H_MANIPULATION
    #include "manipulation_liste.h"
#endif

// creation d une nouvelle liste
t_list_chain * list_chain_new(const char * balise){
    t_list_chain * list = (t_list_chain *)malloc(sizeof(t_list_chain));
    list->balise = balise;
    list->node = NULL;
    list->next = NULL;
    list_chain_display(list);
    return list;
}

t_list_node* list_node_new(const char* property, const char* value){
    t_list_node* node = (t_list_node*)malloc(sizeof(t_list_node));
    node->property = property;
    node->value = value;
    node->next = NULL;
    return node;
}


int equals (const char * chaine1,const char * chaine2) {

    int i=0;
    while (chaine1[i] != '\0' || chaine2[i]!='\0') {
        printf("%c = %c\n", chaine1[i], chaine2[i]);
        if (chaine1[i] != chaine2[i]) {
            return (0);
        }
        i++;
    }
    return (1);
}


// rajoute un element a la fin de la liste
t_list_chain * list_chain_append(t_list_chain*  list, const char* balise, const char* property, const char* value){

    if(!list) {
        printf("0-\n");
        list = list_chain_new(balise);
    }
    //test si balise existe deja
    do{
        printf("1-\n");
        if( equals( list->balise, balise )){
            printf("2-\n");
            if (!list->node) {
                list->node = list_node_new(property, value);
            }
            do{

                if(!equals(list->node->property, property) && !equals(list->node->value,value)){
                    printf("4-\n");
                    list_node_new(property, value);
                }
                else{
                    printf("3-\n");
                    break;

                }
                list->node = list->node->next;
            }while(list->node != NULL);
        }
        else{
            list_chain_new(balise);
        }
        list = list->next;
    }while(list != NULL);
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
    printf ("1- Dislay\n");
    if(list){
        printf ("2- Dislay\n");
        while(list != NULL){
            printf ("3- Dislay\n");
            printf("Balise %s\n",list->balise);
            while (list->node!=NULL){
                printf("Propriété %s Valeur %s\n",list->node->property,list->node->value);
                list->node = list->node->next;
            }
            list = list->next;
        }
    }
} 


// Copie un mot,une propriété ou une valeur
char * word_copy (const char * word) {
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


/*
void tris_list( t_list_chain* list){
    while( list->next != NULL ){
        if( equals( list->balise, balise)){
            while( list->node->next != NULL){
                if (equals( list->node->property, property) && equals( list->node->value, value))
                {
                    // code for writing file //
                }
            }
        }
    }
}

*/