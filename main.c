#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Modulos/Library.h"


int main(){
    Library* nunkini = Lib_New();
    Library_serialize(nunkini);

    /**int n, opcion;
    do
    {
        printf( "\n \t   Biblioteca 'NUNKINÍ'");
        printf( "\n \n   Bienvenido." );
        printf( "\n \n   Seleccione una opción (1-2). \n" );
        printf( "\n   1. Buscar un libro por nombre." );
        printf( "\n   2. Buscar un libro por autor." );
        printf( "\n   3. Buscar un libro por categoría." );
        printf( "\n   4. Salir." );

        scanf( "%d", &opcion );

        switch ( opcion )
        {
            case 1: 
                    
                    break;

            case 2: 
                    break;

            case 3: printf( "\n   Pupu? ");

         }
    } while ( opcion != 4 );
    return 0;**/
}

//gcc -Wall -std=c99 -o salida.out main.c