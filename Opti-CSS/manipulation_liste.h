
/*
typedef struct s_list_chain	{
	char balise;
	char propertie;
	char value;
	struct s_list_chain* next;
}t_list_chain;
*/

/*--------------------------------------------------\*
 declaration des prototypes de manipulation_liste.c
\*--------------------------------------------------*/

t_list_chain* list_chain_new(char balise, char value);
t_list_chain* list_chain_append(t_list_chain* list, char balise, char value);
t_list_chain* list_chain_remove(t_list_chain* list, int index);
t_list_chain* list_chain_display(t_list_chain* list);

