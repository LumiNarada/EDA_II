#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "Ele_list.h"

#define MAX_SIZE_L 29
#define MAX_SIZE_G 13

typedef struct {
    Ele_list** elements;
    int Max_size;
    int len;
} Hash_Table;

int h_g(int key){
    return key % MAX_SIZE_G;
}

int h_l(int key){
    return key % MAX_SIZE_L;
}


void HTB_addElemnt(Hash_Table* htb, int key, NodeLB* n, int Clas, char value){

    int hv,c;
    Ele_list* aux;

    if(Clas <= 1){
        hv = h_l(key);
    }else{
        hv = h_g(key);
    }

    for(c = 0; c < htb->len; c++){
        aux = htb->elements+c;
        if(aux->value == value){
            ELT_add(aux,n);
        }
    }

}

void HTB_setEltValues(Hash_Table* htb, int MS){

    int i, Ia;
    Ele_list* aux;

    for(i = 0; i < MS; i++){
        aux = htb->elements+i;
        aux->value = (char*)97+i;
        htb->len++;
    }
}

Hash_Table* HTB_Create(int max_s){

    Hash_Table* htb = (Hash_Table*) malloc(sizeof(Hash_Table));

    if(htb != NULL){
        htb->elements = (Ele_list*) malloc(sizeof(Ele_list)*max_s);
        htb->Max_size = max_s;
        htb->len = 0;
    }

    HTB_setEltValues(htb, max_s);

    return htb;
}





