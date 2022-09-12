/*
 * 17/02/20
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int g_contador = 0;

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
void counting_sort( int list[], size_t elems, int low, int high )
{
    size_t capacity = high - low + 1;
    int aux[capacity];
    
    for( size_t i = 0; i < capacity; i++){
		aux[i]=0;
	}
    
    for (size_t i = 0; i <= elems-1; i++)
    {
        int pos = list[ i ]-low;
        aux[ pos ]++;
        ++g_contador;
    }

    int j = 0;
    
    for (size_t value = 0; value <= capacity-1; value++){
        for (size_t reps = aux[value]; reps >= 1; reps--){
            list [j] = value+low;
            ++ j;
            ++g_contador;
        }
    }
}

void CountingSort( int list[], size_t elems ){
    counting_sort(list, elems, min(list, elems), max(list, elems));
}

#define NUM_ELEMS 5000

int main()
{
	int list[ NUM_ELEMS ];

    for( size_t i = 0; i < NUM_ELEMS; ++i ){
    	//numeros negativos
        list[ i ] = (rand()%(21))+5;
	}


	print( list, NUM_ELEMS, "Antes: " );

	CountingSort(list, NUM_ELEMS);

	print( list, NUM_ELEMS, "Después: " );

    printf("Contador: %d", g_contador);
}