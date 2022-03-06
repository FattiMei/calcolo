#include <stdio.h>
#include <stdlib.h>


#include "utils.h"
#include "matrix.h"


void copy(struct Matrix A, struct Matrix B){
	// A = B
	if(A.rows == B.rows && A.cols == B.cols){
		if(A.data != NULL && B.data != NULL)
			for(size_t i = 0; i < A.rows * A.cols; ++i)
				A.data[i] = B.data[i];
	}
	else{
		printf("Fatal error: attempting to copy two matrices of different dimensions (%ux%u) (%ux%u)", A.rows, A.cols, B.rows, B.cols);
		exit(1);
	}
}


void set(struct Matrix A, REAL scalar){
	if(A.data != NULL){
		for(size_t i = 0; i < A.rows * A.cols; ++i)
			A.data[i] = scalar;
	}
}


void sum(struct Matrix A, struct Matrix B){
	// A = A + B
	if(A.rows == B.rows && A.cols == B.cols){
		if(A.data != NULL && B.data != NULL){
			for(size_t i = 0; i < A.rows * A.cols; ++i)
				A.data[i] += B.data[i];
		}
	}
	else{
		printf("Fatal error: matrix dimensions don't match (%ux%u) (%ux%u)", A.rows, A.cols, B.rows, B.cols);
		exit(1);
	}
}


void multiply_by_scalar(struct Matrix A, REAL scalar){
	// A = k * A
	if(A.data != NULL){
		for(size_t i = 0; i < A.rows * A.cols; ++i)
			A.data[i] *= scalar;
	}
}


void multiply(struct Matrix A, struct Matrix B, struct Matrix C){
	// C = A * B
	if(C.rows == A.rows && A.cols == B.rows && C.cols == B.cols){
		if(A.data != NULL && B.data != NULL && C.data != NULL){
			zeros(C);

			for(unsigned int i = 0; i < C.rows; ++i){
				for(unsigned int j = 0; j < C.cols; ++j){
					for(unsigned int k = 0; k < A.cols; ++k){
						C.data[i * C.rows + j] += A.data[i * A.rows + k] * B.data[k * B.rows + j];
					}
				}
			}
		}
	}
	else{
		printf("Fatal error: invalid matrix dimensions (%ux%u) (%ux%u)", A.rows, A.cols, B.rows, B.cols);
		exit(1);
	}
}


struct Matrix create(unsigned int rows, unsigned int cols){
	struct Matrix result = INVALID_MATRIX;

	// controllo dei limiti di grandezza della matrice
	if(rows > 0 && rows < MAX_ROWS && cols > 0 && cols < MAX_COLS){
		size_t requested_bytes = sizeof(REAL) * rows * cols;
		REAL *ptr = (REAL *)malloc(requested_bytes);

		if(ptr == NULL){
			printf("Fatal error: memory allocation of %ld bytes failed ... aborting\n", requested_bytes);
			exit(1);
		}
		else{
			result = (struct Matrix){rows, cols, ptr, 0};
		}
	}

	return result;
}


struct Matrix create_static(unsigned int rows, unsigned int cols, REAL* mem){
	struct Matrix result = INVALID_MATRIX;

	// controllo dei limiti di grandezza della matrice
	if(rows > 0 && rows < MAX_ROWS && cols > 0 && cols < MAX_COLS)
		if(mem != NULL)
			// si assume che mem punti ad una zona di memoria sufficientemente grande
			result = (struct Matrix){rows, cols, mem, 1};

	return result;
	
}


struct Matrix create_and_init(unsigned int rows, unsigned int cols, REAL scalar){
	struct Matrix A = create(rows, cols);
	set(A, scalar);

	return A;
}


void destroy(struct Matrix *A){
	if(A != NULL){
		if(!A->is_static){
			free(A->data);
			*A = INVALID_MATRIX;
		}
	}
}


struct Matrix clone(struct Matrix A){
	struct Matrix result = INVALID_MATRIX;

	if(A.data != NULL){
		result = create(A.rows, A.cols);
		copy(result, A);
	}

	return result;
}


void zeros(struct Matrix A){
	if(A.data != NULL)
		set(A, 0.0);
}


void ones(struct Matrix A){
	if(A.data != NULL)
		set(A, 1.0);
}


void eyes(struct Matrix A){
	if(A.data != NULL){
		zeros(A);

		for(unsigned int i = 0; i < min_unsigned(A.rows, A.cols); ++i)
			A.data[A.rows * i + i] = 1.0;
	}
}


void hilbert(struct Matrix A){
	if(A.data != NULL){
		for(unsigned int i = 0; i < A.rows; ++i)
			for(unsigned int j = 0; j < A.cols; ++j)
				A.data[i * A.rows + j] = 1.0 / (i + j + 1.0);
	}
}


void print(struct Matrix A){
	// da aggiungere il controllo sulle cifre significative
	if(A.data != NULL){
		for(unsigned int i = 0; i < A.rows; ++i){
			for(unsigned int j = 0; j < A.cols; ++j){
				printf("%.2f\t", A.data[i * A.rows + j]);
			}

			printf("\n");
		}
	}
}
