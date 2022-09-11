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
 * francisco dot rodriguez at ingenieria dot unam dot edu
 */



#include "Queue.h"


/**
 * @brief Crea una cola nueva.
 */
Queue* Queue_New()
{
	Queue* p = malloc( sizeof( Queue ) );
	
	if( NULL != p ){
		p->queue = DLL_New();
	}

	return p;
}

/**
 * @brief Destruye una cola existente.
 *
 * @param this Referencia a un objeto Queue
 */
void Queue_Delete( Queue* this )
{
	DLL_Delete( this->queue );
}

/**
 * @brief Inserta un elemento en la cola.
 *
 * @param this Referencia a un objeto Queue.
 * @param value El valor a insertar.
 *
 * @return false si se agotó la memoria y el valor no se pudo insertar. true en
 * caso contrario.
 */
bool Queue_Enqueue( Queue* this, Item value )
{
	return DLL_InsertBack( this->queue, value );
}

/**
 * @brief Extrae un elemento de la cola.
 *
 * @param this Referencia a un objeto Queue.
 * @param value Receptáculo para el valor extraído.
 *
 * @return false si la cola está vacía. true en caso contrario.
 */
bool Queue_Dequeue( Queue* this, Item* value )
{
	return DLL_RemoveFront( this->queue, value );
}

/**
 * @brief Indica si la cola está vacía o no.
 *
 * @param this Referencia a un objeto Queue.
 *
 * @return true si la cola está vacía. false en caso contrario.
 */
bool Queue_IsEmpty( Queue* this )
{
	return DLL_IsEmpty( this->queue );
}

/**
 * @brief Indica el número de elementos actuales en la cola.
 *
 * @param this Referencia a un objeto Queue.
 *
 * @return El número de elementos actualmente en la cola.
 */
size_t Queue_Len( Queue* this )
{
	return DLL_Len( this->queue );
}

/**
 * @brief Vacía la cola, pero no la destruye.
 *
 * @param this Referencia a un objeto Queue.
 */
void Queue_MakeEmpty( Queue* this )
{
	DLL_Purge( this->queue );
}

