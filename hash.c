#define TAMANIO_INICIAL 7
#define FACTOR_DE_CARGA 

typedef struct nodo {
	void* elemento;
	struct nodo* siguiente;
	char clave[MAX_CLAVE];
} nodo_t;

typedef struct hash{
	lista_t ** lista;
	size_t cantidad_elementos;
	size_t tamanio;
	hash_destruir_dato_t destructor;
}hash_t;

hash_t *hash_crear(hash_destruir_dato_t destruir_dato){
	hash_t * hash = malloc(sizeof(hash_t));
	if (!hash){
		return NULL;
	}
	hash->lista = calloc(TAMANIO_INICIAL, sizeof(lista_t));
	if (!hash->lista){
		free(hash);
		return NULL;
	}
	hash->destructor = destruir_dato;
	hash->tamanio = TAMANIO_INICIAL;
	hash->cantidad_elementos = 0;
	return hash;
}

bool redimensionar_hash(hash_t * hash){
	hash->tamanio = hash->tamanio * 2;
	hash->lista = realloc(hash->lista, hash->tamanio);// REVISAR
	if(!hash->lista){
		return false;
	}
	size_t posicion;
	for (int i = 0; i < hash->tamanio ; i++){
		if (!hash->lista[i]){
			nodo_t *nodo = hash->lista[i]->nodo_inicio;
			for (int j = 0; j < hash->lista[i]->cantidad; j++){
				posicion = funcion_hash(nodo->clave) % hash->tamanio;
				if(lista[posicion] == NULL){
					lista[posicion] = lista_crear();
					if(lista[posicion] == NULL){
						return false;
					}
				}
			}
		}
	}


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



