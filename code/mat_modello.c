#include "mat_modello.h"
#include <stdlib.h>


void zeros(struct Matrix A){
	if(A.data != NULL){
        set(A, 0.0);
	}
}


void ones(struct Matrix A){
	if(A.data != NULL){
		set(A, 1.0);
	}
}


void eye(struct Matrix A){
	if(A.data != NULL){
		zeros(A);

		for(unsigned int i = 0; i < A.rows; ++i)
			A.data[i * A.cols + i] = 1.0;
	}
}


void hilbert(struct Matrix A){
	if(A.data != NULL){
		unsigned int k = 0;

		for(unsigned int i = 0; i < A.rows; ++i)
			for(unsigned int j = 0; j < A.cols; ++j)
				A.data[k++] = 1.0 / (i + j + 1.0);
	}
}
