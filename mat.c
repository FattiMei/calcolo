#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>


#include "mat.h"
#include "mat_modello.h"


unsigned int size(struct Matrix A){
	return A.rows * A.cols;
}


unsigned int are_equal_size(struct Matrix A, struct Matrix B){
    return A.rows == B.rows && A.cols == B.cols;
}


void set(struct Matrix A, Real scalar){
    assert(A.data != NULL);

    for(unsigned int i = 0; i < size(A); ++i)
        A.data[i] = scalar;
}


void swap_rows(struct Matrix A, unsigned int i, unsigned int j){
    assert(A.data != NULL);
    assert(i < A.rows && j < A.rows);


    if(i != j){
    	Real tmp = 0.0;

        for(unsigned int k = 0; k < A.cols; ++k){
            tmp = IDX(A, i, k);
            IDX(A, i, k) = IDX(A, j, k);
            IDX(A, j, k) = tmp;
        }
    }
}


void copy(struct Matrix A, struct Matrix B){
	assert(A.data != NULL);
	assert(B.data != NULL);
	assert(are_equal_size(A, B));


    for(unsigned int i = 0; i < size(A); ++i)
            A.data[i] = B.data[i];
}


void sum(struct Matrix A, struct Matrix B, struct Matrix C){
	assert(A.data != NULL);
	assert(B.data != NULL);
	assert(C.data != NULL);
	assert(are_equal_size(A, B) && are_equal_size(B, C));


    for(size_t i = 0; i < size(A); ++i)
        A.data[i] = B.data[i] + C.data[i];
}


void mult(struct Matrix A, struct Matrix B, struct Matrix C){
	assert(A.data != NULL);
	assert(B.data != NULL);
	assert(C.data != NULL);
	assert(B.cols == C.rows);
	assert(A.rows == B.rows && A.cols == C.cols);


    zeros(A);

    for(unsigned int i = 0; i < A.rows; ++i){
        for(unsigned int j = 0; j < A.cols; ++j){
            for(unsigned int k = 0; k < B.cols; ++k){
                IDX(A, i, j) += IDX(B, i, k) * IDX(C, k, j);
            }
        }
    }
}


void smult(struct Matrix A, struct Matrix B, Real r){
    assert(A.data != NULL);
    assert(B.data != NULL);
    assert(are_equal_size(A, B));


    for(unsigned int i = 0; i < size(A); ++i)
        A.data[i] = B.data[i] * r;
}


void multvec(struct Vector V, struct Matrix A, struct Vector W){
    mult(vec_to_mat(V), A, vec_to_mat(W));
}
