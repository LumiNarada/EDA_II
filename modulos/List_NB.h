#include <stdio.h>
#include <stdlib.h>

#include "Node_LB.h"

typedef struct List_NB{

    struct Node_LB* Start;
    struct Node_LB* Finish;
    int len;

} ListNB;

ListNB* LNB_create(){

    ListNB* listNB = (ListNB*) malloc(sizeof(ListNB));

    if( listNB != NULL){
        listNB->Start = NULL;
        listNB->Finish = NULL;
        listNB->len = 0;
    }else{
        return NULL;
    }

    return listNB;
}

int LNB_getLen(ListNB* this){
    return (*this).len;
}

void LNB_setLen(ListNB* this, int lenN){
    (*this).len = lenN;
}

NodeLB* LNB_add(ListNB* listNB,char name[], char ctg[], char FN[], char LN[], int stock){

    NodeLB* nlb = NLB_Create(name, ctg, FN, LN, stock);

    if(nlb != NULL){
        if(LNB_getLen(listNB) == 0){
            listNB->Start = nlb;
        }else if(LNB_getLen(listNB) == 1){
            listNB->Start->next = nlb;
            nlb->prev = listNB->Start;
            listNB->Finish = nlb;
        }else if(LNB_getLen(listNB) > 1){
            listNB->Finish->next = nlb;
            nlb->prev = listNB->Finish;
            listNB->Finish = nlb;
        }
        LNB_setLen(listNB, LNB_getLen(listNB)+1);
    }else{
        printf("no se puede agregar");
    }

    return nlb;

}

void LNB_print(ListNB* listNB){

    NLB_print(listNB->Start);

}


