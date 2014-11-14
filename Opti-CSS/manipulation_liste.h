/*--------------------------------------------------\*
 declaration des prototypes de manipulation_liste.c
\*--------------------------------------------------*/
t_list* list_create( int max);
list_display( t_list* list);
list_append( t_list* list, int value );
list_insert( t_list* list, unsigned int index, int value );
void list_remove_index( t_list* list, unsigned index);
t_list* list_copy( t_list* src);
t_list* list_concat( t_list* list ...);
t_list* revert_copy( t_list* list );
void revert_inside( t_list* list );
