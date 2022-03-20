#include "vec.h"
#include "precision.h"
#include <math.h>
#include <stdlib.h>
#include <assert.h>


struct Matrix vec_to_mat(struct Vector V){
    return (struct Matrix){V.elem, 1, V.data};
}


Real norm2(struct Vector V){
    assert(V.data != NULL);


    Real result = 0.0;

    for(unsigned int i = 0; i < V.elem; ++i){
        result += V.data[i] * V.data[i];
    }


    return sqrt(result);
}
