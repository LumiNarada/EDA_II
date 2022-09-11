/*
 * 17/02/20
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int max( int list[], size_t elems )
{   
    int max = list[0];
    for(int i = 1; i < elems ; i++){
        max = (max <= list[i] ? list [i] : max);
    }
    return max;
}


int min( int list[], size_t elems )
{
    int min = list[0];
    for(int i = 1; i < elems ; i++){
        min = (min >= list[i] ? list [i] : min);
    }
    return min;
}

/**
 * @brief Imprime una lista de valores enteros.
 *
 * @param list La lista de números enteros.
 * @param tam El número de elementos en la lista.
 * @param msg Un mensaje de texto explicativo.
 */
void print( int* list, size_t tam, char* msg )
{
	printf( "%s", msg );
	for( size_t i = 0; i < tam; ++i ){
		printf( "%d, ", list[ i ] );
	}
	printf( "\n" );
}

/**
 * @brief Ordena en forma ascendente una lista de valores enteros utilizando al algoritmo counting sort.
 *
 * @param list[] La lista de números enteros
 * @param elems  El número de elementos en la lista.
 * @param low    Índice al primer elemento de la lista.
 * @param high   Índice al último elemento de la lista.
 */
void counting_sort( int list[], size_t elems, size_t low, size_t high )
{
    int capacity = high + 1;
    int aux[capacity];
    
    for( size_t i = 0; i < capacity; i++){
		aux[i]=0;
	}
    //int output[elems];
    
    for (size_t i = 0; i <= elems-1; i++)
    {
        int pos = list[ i ];
        aux[ pos ]++;
    }
    int j = 0;
    
    for (size_t value = 0; value <= capacity-1; value++){
        for (size_t reps = aux[value]; reps >= 1; reps--){
            list [j] = value;
            ++ j;
        }
    }
    // Codigo para tipos compuestos 
    /**for ( ccxzt i = 1, i <= capacity-1; ++1)
    {
        aux[ i ] += aux[ i - 1 ];
    }
    
    for (size_t i = elems-1; i > 0; --i)
    {
        int j = key( list[ i ] );
        aux[ j ] -= 1;
        output[ aux[ j ] x|] = list[ i ];
    }**/
}

#define NUM_ELEMS 7

int main()
{
	int list[ NUM_ELEMS ] = {1, 4, 1, 2, 7, 5, 2};

	print( list, NUM_ELEMS, "Antes: " );

	counting_sort(list, NUM_ELEMS, min(list, NUM_ELEMS), max(list, NUM_ELEMS));

	print( list, NUM_ELEMS, "Después: " );
}