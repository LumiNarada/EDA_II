#include <stdio.h>
#include <stdlib.h>

#include "Book.h"

typedef struct Node_LB{

    Book* book;
    struct Node_LB* next;
    struct Node_LB* prev;

} NodeLB;

NodeLB* NLB_Create(char name[], char ctg[], char FN[], char LN[], int stock)
{
    NodeLB* nlb = (NodeLB*) malloc(sizeof(NodeLB));

    if(nlb != NULL){
        Book* b = Book_Create(name,ctg,FN,LN,stock);
        if(b!= NULL){
            nlb->book = b;
        }else{
            printf("error con el libro");
        }
    }

    nlb -> next = NULL;
    nlb -> prev = NULL;

    return nlb;
}

void NLB_print(NodeLB* n){
    printf("%s - ", n->book->Name);
    printf("%s - ", n->book->Category);
    printf("%s - ", n->book->F_name);
    printf("%s - ", n->book->L_name);
    printf("%d\n", n->book->stock);

    if(n->next != NULL){
        NLB_print(n->next);
    }

}
