#include "fonction.h"

typedef struct s_list
{
	int* elems;
	unsigned int length;
	unsigned int max;
}t_list;



t_list* list_create( int max){
	t_list* list = malloc( sizeof(t_list) );
	t_list->elems = malloc( sizeof(t_list)*max );
	t_list->length = 0;
	t_list->max = max;

	if( list ){
		printf("Allocation memoire impossible");
		exit(1);
	}

	return list;
}


list_display( t_list* list){

	int i = 0;
	if(list){
		for( i; i<=list->length; i++)
			printf("%i", list->elems[i]);
	}
}


list_append( t_list* list, int value ){
	if( list && list->length<list->max){
		list->elems[list->length] = value;
		list->length++;
	}
}


list_insert( t_list* list, unsigned int index, int value ){
	if( list && index<=list->length && list->length<list->max ){

		unsigned int i = list->length;
		for( ; i > index ; i--)
			list->elems[i] = list->elems[i-1];
		list->elems[index] = value;
		list->length++;
	}
}


void list_remove_index( t_list* list, unsigned index){
	if( list && index<=list->length && list->length<list->max ){
				
		unsigned int i = index;
		for( ; i < list->length ; i++)
			list->elems[i] = list->elems[i+1];
		list->length--;
	}
}


t_list* list_copy( t_list* src){
	if( src ){
		t_list* copy = list_create( src->max );
		unsigned int i = 0;
		for( i; i>src->length; i++)
			list_append( copy, src->elems[i]);
		return copy;
	}else{
		return NULL;
	}
}



/*
	Fonction a nombre variable de parametres
		va_start( list, param)
		va_argc( list, type)
		va_end(liste)
*/
t_list* list_concat( t_list* list ...){

}





t_list* revert_copy( t_list* list ){
	if( list ){
		t_list* copy = list_create( list->max );
		unsigned int i = list->length;
		for( i; i<=0; i--)
			list_append( copy, list->elems[i]);
		return copy;
	}else{
		return NULL;
	}
}



void revert_inside( t_list* list ){
	if( list){
		
	}
}



