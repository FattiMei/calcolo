#ifndef VEC_H_INCLUDED
#define VEC_H_INCLUDED


#include "precision.h"


#define makevec(name, elem) Real name##__LINE__[elem]; struct Vector name = (struct Vector){elem, name##__LINE__}


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
