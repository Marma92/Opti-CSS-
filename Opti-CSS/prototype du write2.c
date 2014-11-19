#include <stdio.h>
#include <stdlib.h>

struct final_file {
    struct elements* e;
};

struct elements {
	char* nomElement
    struct properties* p;
    struct elements* next;
};

struct properties {
    char* propname;
    char* value;
    struct properties* next;
};

final_file* int_final_file(element* e){
    final_file* ff = (t_list_chain *)malloc(sizeof(final_file));    
    ff->e = e;
    return ff;
}

elements* element_new(char* nom, properties* p){
    element_new* elem = (t_list_chain *)malloc(sizeof(element_new));    
    elem->nomElement = nom
    elem->p = p;
    elem->next = NULL;
    return elem;
}

properties* prop_new(char* propName, char* value){
    properties* prop = (t_list_chain *)malloc(sizeof(properties));    
    prop->propName = propName;
    prop->value = value;
    prop->next = NULL;
    return prop;
}

elements* elements_append(elements* list, properties* p){
    if(!list) {
        return element_new(char* nom, properties* p);
    }
    elements* save = list;
    while(save->next != NULL){
        save = save->next;
    }
    save->next = element_new(char* nom, properties* p);
    return list;
}

properties* properties_append(properties* list, char* propName, char* value){
    if(!list) {
        return prop_new(char* propName, char* value);
    }
    properties* save = list;
    while(save->next != NULL){
        save = save->next;
    }
    save->next = prop_new(char* propName, char* value);
    return list;
}

void write_to_file(final_file* ff){
	elements* e = ff->e
	while(e->next != NULL){
		file_append(f, e->nom)
		file_append(f, "{")
		properties* p = e->p
		while(p->next != NULL){
			file_append(f, p->propName)
			file_append(f, " : ")
			file_append(f, p->value)
			file_append(f, ";")
		}
		file_append(f, e->nom)
		file_append(f, "}")
	}
}

void file_append(char* fileName, char* toWrite){
	FILE *f;
	f = fopen(fileName, "a");
	while(!feof(f)) { //1
        while(fgets(toWrite, sizeof(toWrite), f)) { //2
        	fprintf(f, "%s", toWrite);
    	}
    }
}




