#ifndef VEC_H_INCLUDED
#define VEC_H_INCLUDED


#include <alloca.h>
#include "precision.h"


#define create_vec(N) ({                              \
    unsigned int _n_ = (N);                           \
    (struct Vector){_n_, alloca(sizeof(Real) * _n_)}; \
})


struct Vector{
    unsigned int elem;
    Real *data;
};


#include "mat.h"


struct Matrix vec_to_mat(struct Vector);


Real norm2(struct Vector);


#endif // VEC_H_INCLUDED