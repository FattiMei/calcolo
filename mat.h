#ifndef MAT_H_INCLUDED
#define MAT_H_INCLUDED


#include "precision.h"
#include "vec.h"
#include <alloca.h>


#define makemat(name, rows, cols) Real name##__LINE__[rows * cols]; struct Matrix name = (struct Matrix){rows, cols, name##__LINE__}


#define create_mat(N, M) ({                                     \
    unsigned int _n_ = (N), _m_ = (M);                          \
    (struct Matrix){_n_, _m_, alloca(sizeof(Real) * _n_ * _m_)}; \
})


#define IDX(A, i, j) (A.data[i * A.cols + j])


struct Matrix{
	unsigned int rows, cols;
	Real* data;
};


unsigned int size(struct Matrix);
unsigned int are_equal_size(struct Matrix, struct Matrix);


void swap_rows(struct Matrix A, unsigned int i, unsigned int j);


void set    (struct Matrix, Real);
void copy   (struct Matrix, struct Matrix);
void sum    (struct Matrix, struct Matrix, struct Matrix);
void mult   (struct Matrix, struct Matrix, struct Matrix);
void smult  (struct Matrix, struct Matrix, Real);
void multvec(struct Vector, struct Matrix, struct Vector);


#endif // MAT_H_INCLUDED
