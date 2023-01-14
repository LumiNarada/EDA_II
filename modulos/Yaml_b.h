#include <stdio.h>
#include <stdbool.h>

#include "List_NB.h"

void YamlB_serialize(ListNB* lnb){

    NodeLB* n;
    int cont = 0;

    FILE* output = fopen("Data/List_Books.yml", "w");
    fprintf(output, "---\n");

    n = lnb->Start;

    while(n!=NULL){
        cont++;
        n = n->next;
    }

    fprintf(output, "...");

    fclose(output);

}

ListNB* YamlB_unSerialize(){

    ListNB* lnb = LNB_create();
    int cont = 0;
    char line[100], name[30], ctg[20], fn[15], ln[15], stock[3];

    FILE* input = fopen("Data/List_Books.yml", "r");

    fgets(line,100,input);

    while(cont < 5){

        fgets(line,100,input);
        strncpy(name,line,strlen(line)-1);

        fgets(line,100,input);
        strncpy(ctg,line+10,strlen(line)-1);

        fgets(line,100,input);
        strncpy(fn,line+10,strlen(line)-1);

        fgets(line,100,input);
        strncpy(ln,line+12,strlen(line)-1);

        fgets(line,100,input);
        strncpy(stock,line+9,strlen(line)-1);

        fgets(line,100,input);

        LNB_add(lnb,name,ctg,fn,ln,stock);
        cont++;
    }

    fclose(input);

    return lnb;

}
