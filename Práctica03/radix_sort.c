/*Copyright (C) 
 * 2019 - eda1 dot fiunam at yahoo dot com dot mx
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 */


#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
// bool, true, false

#include <iso646.h>
// and, or, not

#include "Queue.h"
// va con comillas porque es nuestro

#include <math.h>

int g_contador = 0;

void print( int* list, size_t tam, char* msg )
{
	printf( "%s", msg );
	for( size_t i = 0; i < tam; ++i ){
		printf( "%d, ", list[ i ] );
	}
	printf( "\n" );
}

int subKey( int val, int pos, int radix )
{
	int divisor = pow(10, pos-1);
	return ( val / divisor) % radix;
}

void collect( int list[], Queue* queues[], int radix )
{
	int index = 0;
	for (size_t i = 0; i < radix; ++i)
	{	
		while (!Queue_IsEmpty( queues[ i ] ) )
		{
			int value;
			Queue_Dequeue( queues[ i ], &value); 
			list[ index ] = value;
			++index;
			++g_contador;
		}
	}
}

void radix_sort( int list[], size_t elems, int pos, int radix )
{
	Queue* queues[radix];
	for( size_t i = 0; i < radix; ++i ){ queues[ i ] = Queue_New(); }
	for (size_t i = 1; i <= pos; ++i)
	{
		for (size_t j = 0; j < elems; ++j)
		{
			int whichQ = subKey( list[ j ], i, radix );
			Queue_Enqueue( queues[ whichQ ], list[ j ] );
			++g_contador;
		}
		collect( list, queues, radix );
	}
}

void radixsort10( int list[], size_t elems ){
	radix_sort(list, elems, 4, 10);
}

#define NUM_ELEMS 5000

int main()
{
	Item list[ NUM_ELEMS ];

	for( size_t i = 0; i < NUM_ELEMS; ++i ){
    	list[ i ] = rand() % 4000;
	}

	print( list, NUM_ELEMS, "Antes: " );

	radixsort10(list, NUM_ELEMS );
	//radix_sort(list, NUM_ELEMS, 4, 10);
	
	print( list, NUM_ELEMS, "\nDespués: " );

	printf("Contador: %d", g_contador);
	
}

/**Comando para consola (ubicarse en esta carpeta)

	gcc -Wall -std=c99 -o radix_sort.out radix_sort.c Queue.c DLL.c
	radix_sort.out

**/