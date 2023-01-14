#include <stdio.h>
#include <stdlib.h>
#include "Yaml_b.h"

typedef struct{

    int key;
    char* value;
    ListNB* listNB;

}Ele_list;

Ele_list* ELT_Create(char* value){

    Ele_list* elt = (Ele_list* ) malloc(sizeof(Ele_list));

    if(elt != NULL){
        elt->value = value;
        elt->listNB = LNB_create();
        elt->key;
    }
}

void ELT_add(Ele_list* elt, NodeLB* n){
    LNB_add(elt->listNB, n->book->Name, n->book->Category, n->book->F_name, n->book->L_name, n->book->stock);
}
