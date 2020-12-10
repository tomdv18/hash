#define CORRECTOR

#include "testing.h"

#include <stdio.h>
#include <stdlib.h>

/* ******************************************************************
 *                        PROGRAMA PRINCIPAL
 * *****************************************************************/

void pruebas_hash_catedra(void);
void pruebas_volumen_catedra(size_t);

int main(int argc, char *argv[]) {
#ifdef CORRECTOR
    printf("\n~~~ PRUEBAS CÁTEDRA ~~~\n");
    pruebas_hash_catedra();
#endif

    return failure_count() > 0;
}
// HOY NO ES 25 DE MAYO