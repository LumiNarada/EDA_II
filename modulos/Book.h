#include <stdio.h>
#include <stdlib.h>

typedef struct {

    char* Name;
    char* Category;
    char* F_name;
    char* L_name;
    int stock;

} Book;

Book* Book_Create(char name[], char ctg[], char FN[], char LN[], int stock)
{
    Book* book = (Book*) malloc(sizeof(Book));

    if(book != NULL){
        (*book).Name = name;
        (*book).Category = ctg;
        (*book).F_name = FN;
        (*book).L_name = LN;
        (*book).stock = stock;
    }

    return book;
}
