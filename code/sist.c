#include <stdlib.h>
#include <assert.h>
#include <math.h>


#include "mat.h"
#include "mat_modello.h"
#include "sist.h"


void lu(struct Matrix L, struct Matrix U, struct Matrix P, struct Matrix A){
    assert(P.rows == P.cols);
    assert(P.rows == A.cols);
    assert(are_equal_size(L, P));
    assert(are_equal_size(A, U));

    assert(L.data != NULL);
    assert(U.data != NULL);
    assert(P.data != NULL);
    assert(A.data != NULL);


    eye(P);
    eye(L);
    copy(U, A);

    for(unsigned int step = 0; step < (A.rows - 1); ++step){
        // cerco il massimo dei valori assoluti delle step-esime colonne
        Real max = 0.0;
        unsigned int max_pos = 0;

        for(unsigned int j = step; j < A.cols; ++j){
            if(max < fabs(IDX(U, j, step))){
                max = fabs(IDX(U, j, step));
                max_pos = j;
            }
        }


        if(max == 0.0)
            continue;


        // scambio la riga step con la riga j
        swap_rows(U, step, max_pos);
        swap_rows(P, step, max_pos);


        // procedo con l'eliminazione sulle righe successive
        Real m;
        for(unsigned int row = step + 1; row < A.rows; ++row){
            m = IDX(U, row, step) / IDX(U, step, step);
            IDX(L, row, step) = m;


            for(unsigned int col = step; col < A.cols; ++col){
                IDX(U, row, col) -= m * IDX(U, step, col);
            }
        }
    }
}


void risist(struct Vector x, struct Matrix L, struct Matrix U, struct Matrix P, struct Vector b){
	assert(x.elem == b.elem);
	assert(x.data != NULL);
	assert(L.data != NULL);
	assert(U.data != NULL);
	assert(P.data != NULL);
	assert(b.data != NULL);

    multvec(x, P, b);

    // sostituzione in avanti
    for(unsigned int row = 0; row < b.elem; ++row){
        for(unsigned int col = 0; col < row; ++col){
            x.data[row] -= IDX(L, row, col) * x.data[col];
        }
    }

    // sostituzione all'indietro
    for(int row = b.elem - 1; row >= 0; --row){
        for(unsigned int col = U.cols - 1; col > row; --col){
            x.data[row] -= IDX(U, row, col) * x.data[col];
        }

        // il sistema è effettivamente risolvibile?
        assert(fabs(IDX(U, row, row)) > eps || fabs(x.data[row]) < eps);

        x.data[row] /= IDX(U, row, row);
    }
}
