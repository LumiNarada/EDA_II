#include <stdlib.h>
#include <stdio.h>
#include "Hash_P.h"

typedef struct Library{

    struct List_NB* LNB;
    struct Prime_Hash* PHT;
} Library;

Library* Lib_New(){

    Library* lib = (Library*) malloc(sizeof(Library));

    if(lib != NULL){

        ListNB* listNB = LNB_create();

        if(listNB != NULL){
            lib->LNB = listNB;
        }else{
            printf("error creando la lista");
        }

        Prime_Hash* PHT = PHT_Create();

        if(PHT != NULL){
            lib->PHT = PHT;
        }else{
            printf("error creando la lista");
        }

        printf("Tabla creada");

    }
    return lib;
}

void Library_add_book(Library* lib, char name[], char ctg[], char FN[], char LN[], int stock){
    NodeLB* nlb = LNB_add(lib->LNB, name, ctg, FN, LN, stock);
    PHT_add(lib->PHT, nlb);
    printf("libro agregado\n");
}

void library_print_LNB(Library* lib){
    LNB_print(lib->LNB);
}

void Library_serialize(Library* lib){
    YamlB_serialize(lib->LNB);
}

void Library_unserialize(Library* lib){
    lib->LNB = YamlB_unSerialize();
}

