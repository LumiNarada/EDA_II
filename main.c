#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Modulos/Library.h"


int main(){
    Library* ada = Lib_New();
    Library_serialize(ada);

    int n, opcion;
    do
    {
        printf( "\n\n \t   Biblioteca 'Ada Lovelace'");
        printf( "\n \n   Bienvenido." );
        printf( "\n \n   Seleccione una opción (1-4). \n" );
        printf( "\n   1. Buscar un libro por nombre." );
        printf( "\n   2. Buscar un libro por autor." );
        printf( "\n   3. Buscar un libro por categoría." );
        printf( "\n   4. Salir. \n\n" );

        scanf( "%d", &opcion );

        switch ( opcion )
        {
            case 1: 
                    printf( "\nOpción no disponible ");
                    break;

            case 2: 
                    printf( "\nOpción no disponible ");
                    break;

            case 3: printf( "\nOpción no disponible ");

         }
    } while ( opcion != 4 );
    Library_unserialize(ada);
    return 0;
}

//gcc -Wall -std=c99 -o salida.out main.c