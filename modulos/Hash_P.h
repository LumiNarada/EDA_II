#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "Hash.h"

#define MAX_SIZE_L 29
#define MAx_SIZE_G 10

typedef struct {

    Hash_Table* hash_T;
    Hash_Table* hash_G;
    Hash_Table* hash_A;

}Prime_Hash;

char String_getFirst(char* s){
    return s[0];
}

Prime_Hash* PHT_Create(){

    Prime_Hash* pht = (Prime_Hash*)malloc(sizeof(Prime_Hash));

    pht->hash_T = HTB_Create(MAX_SIZE_L);
    pht->hash_G = HTB_Create(MAx_SIZE_G);
    pht->hash_A = HTB_Create(MAX_SIZE_L);

    return pht;

}

void PHT_add(Prime_Hash* pht, NodeLB* n){

    HTB_addElemnt(pht->hash_T, String_getFirst(n->book->Name),n,0,String_getFirst(n->book->Name));
    HTB_addElemnt(pht->hash_A, String_getFirst(n->book->L_name),n,1,String_getFirst(n->book->L_name));
    HTB_addElemnt(pht->hash_G, String_getFirst(n->book->Category),n,2,String_getFirst(n->book->Category));

}


