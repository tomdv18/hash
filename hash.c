#include "lista.h"
#include <stdio.h>

#define TAMANIO_INICIAL 7
#define FACTOR_DE_CARGA 
//agrego este comment

typedef struct nodo {
	void* dato;
	struct nodo* siguiente;
	char clave[MAX_CLAVE];
} nodo_t;

typedef struct lista{
	nodo_t* primero;
	nodo_t* ultimo;
	size_t largo;
}lista_t;

typedef struct iter{
	lista_t * lista;
	nodo_t * nodo_actual;
	nodo_t * nodo_anterior;
}lista_iter_t;

typedef struct hash{
	lista_t ** lista;
	size_t cantidad_elementos;
	size_t tamanio;
	hash_destruir_dato_t destructor;
}hash_t;

//====================================================================================================//

hash_t *hash_crear(hash_destruir_dato_t destruir_dato){
	hash_t * hash = malloc(sizeof(hash_t));
	if (!hash){
		return NULL;
	}
	hash->lista = calloc(TAMANIO_INICIAL, sizeof(lista_t*));
	if (!hash->lista){
		free(hash);
		return NULL;
	}
	hash->destructor = destruir_dato;
	hash->tamanio = TAMANIO_INICIAL;
	hash->cantidad_elementos = 0;
	return hash;
}


// Recibe un hash entero
// Destruye todas sus listas interiores 
// Libera la memoria asociada al vector de listas
void vaciar_hash_anterior(hash_t * hash){
	int i = 0;
	while(i < (hash->tamanio)){
		if(hash->lista[i] != NULL){
			lista_destruir(hash->lista[i], hash->destructor);
		}
	}
	free(hash->lista);
}

// Recibe un hash inicializado
// Devuelve verdadero si se pudo redimensionarlo
// No se pudo redimensionar si no existe memoria suficiente para 
// un nuevo arreglo, para una nueva lista o si no se pudo insertar en una lista.
bool redimensionar_hash(hash_t * hash){
	hash->tamanio = hash->tamanio * 2;
	lista_t** nueva_lista = calloc(hash->tamanio, sizeof(lista_t*));// REVISAR
	if(!nueva_lista){
		return false;
	}
	size_t posicion = 0;
	bool se_pudo = true;
	for (int i = 0; i < hash->tamanio; i++){
		if (!hash->lista[i]){
			nodo_t *nodo = hash->lista[i]->nodo_inicio;
			for (int j = 0; j < hash->lista[i]->cantidad; j++){
				posicion = funcion_hash(nodo->clave) % hash->tamanio;
				if(lista[posicion] == NULL){
					lista[posicion] = lista_crear();
					if(lista[posicion] == NULL){
						free(nueva_lista);
					}
					se_pudo = lista_insertar_ultimo(lista[posicion], nodo->dato);
					if (!se_pudo){
						free(nueva_lista);
						return false;
					}
					strcpy(lista[posicion]->nodo_fin->clave, nodo->clave);
					nodo = nodo->siguiente;
				}
			}
		}
	}
	vaciar_hash_anterior(hash);
	hash->lista = nueva_lista;
	return true;
}

/* Guarda un elemento en el hash, si la clave ya se encuentra en la
 * estructura, la reemplaza. De no poder guardarlo devuelve false.
 * Pre: La estructura hash fue inicializada
 * Post: Se almacenó el par (clave, dato)
 */
bool hash_guardar(hash_t *hash, const char *clave, void *dato){
	if (!dato || !clave){
	return false;
	}
	char *copia = strdup(clave);
	if (!copia){
		return false;
	}
	if ((hash->cantidad_elementos/hash->tamanio) => FACTOR_DE_CARGA){
		redimensionar_hash(hash);
	}
	size_t nueva_posicion = funcion_hash(copia) % hash->tamanio;
	if (hash->lista[nueva_posicion] == NULL){
		lista_t * nueva_lista = lista_crear();
		if (!nueva_lista){
			return false;
		}
	}
	bool existe = hash_pertenece(hash, copia);
	if (existe){
	// SEGUIR TRABAJANDO, TIENE QUE HABER UNA FUNCION QUE SE PUEDA 
		// USAR TAMBIEN EN HASH_ PERTENECE QUE DEVUELVA LA POSICION

	}




}

/* Borra un elemento del hash y devuelve el dato asociado.  Devuelve
 * NULL si el dato no estaba.
 * Pre: La estructura hash fue inicializada
 * Post: El elemento fue borrado de la estructura y se lo devolvió,
 * en el caso de que estuviera guardado.
 */
void *hash_borrar(hash_t *hash, const char *clave){

}

/* Obtiene el valor de un elemento del hash, si la clave no se encuentra
 * devuelve NULL.
 * Pre: La estructura hash fue inicializada
 */
void *hash_obtener(const hash_t *hash, const char *clave){

}

/* Determina si clave pertenece o no al hash.
 * Pre: La estructura hash fue inicializada
 */
bool hash_pertenece(const hash_t *hash, const char *clave){
	
}

/* Devuelve la cantidad de elementos del hash.
 * Pre: La estructura hash fue inicializada
 */
size_t hash_cantidad(const hash_t *hash){
	return(hash->cantidad_elementos);
}

/* Destruye la estructura liberando la memoria pedida y llamando a la función
 * destruir para cada par (clave, dato).
 * Pre: La estructura hash fue inicializada
 * Post: La estructura hash fue destruida
 */
void hash_destruir(hash_t *hash){

}





/* Iterador del hash */

// Crea iterador
hash_iter_t *hash_iter_crear(const hash_t *hash){

}

// Avanza iterador
bool hash_iter_avanzar(hash_iter_t *iter){

}

// Devuelve clave actual, esa clave no se puede modificar ni liberar.
const char *hash_iter_ver_actual(const hash_iter_t *iter){

}

// Comprueba si terminó la iteración
bool hash_iter_al_final(const hash_iter_t *iter){

}

// Destruye iterador
void hash_iter_destruir(hash_iter_t *iter){

}



