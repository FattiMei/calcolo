#ifndef MAT_STAMPE_H_INCLUDED
#define MAT_STAMPE_H_INCLUDED


#include "precision.h"
#include "mat.h"
#include "vec.h"


void print_for_matlab   (struct Matrix, const char *);
void print_for_term     (struct Matrix, const char *);
void print_solution		(Real, struct Matrix);


#endif // MAT_STAMPE_H_INCLUDED
