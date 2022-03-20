#include "problemi_modello.h"
#include "mat_modello.h"


#include <stdlib.h>
#include <assert.h>


void dati_12(struct Matrix U, Real *t, Real *T){
    assert(t != NULL);
    assert(T != NULL);
    assert(U.data != NULL);


    *t = 0;
    *T = 2;
    IDX(U, 0, 0) = 1;
}


void problema_12(struct Matrix F, Real t, struct Matrix U){
    assert(F.data != NULL);
    assert(U.data != NULL);
    assert(are_equal_size(F, U));


    zeros(F);
    IDX(F, 0, 0) = -2.0 * t * IDX(U, 0, 0) * IDX(U, 0, 0);
}


void dati_22(struct Matrix U, Real *t, Real *T){
    assert(t != NULL);
    assert(T != NULL);
    assert(U.data != NULL);
    assert(U.rows > 1);


    *t = 0.0;
    *T = 2 * PI;

    IDX(U, 0, 0) = 1.0;
    IDX(U, 1, 0) = 0.0;
}


void problema_22(struct Matrix deriv, Real t, struct Matrix U){
    assert(deriv.data != NULL);
    assert(U.data != NULL);
    assert(are_equal_size(deriv, U));
    assert(U.rows > 1);


    IDX(deriv, 0, 0) = -IDX(U, 1, 0);
    IDX(deriv, 1, 0) = IDX(U, 0, 0);
}
