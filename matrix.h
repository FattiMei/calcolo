#pragma once

#include "precision.h"


// dimensioni massime accettate per una matrice
#define MAX_ROWS 100
#define MAX_COLS 100


#define INVALID_MATRIX (struct Matrix){0}


struct Matrix{
	unsigned int rows, cols;
	REAL* data;

	unsigned char is_static;
};


void copy				(struct Matrix, struct Matrix);
void set				(struct Matrix, REAL);
void multiply_by_scalar	(struct Matrix, REAL);
void sum				(struct Matrix, struct Matrix);
void multiply			(struct Matrix, struct Matrix, struct Matrix);


// funzioni per allocare e distruggere matrici in heap
struct Matrix create			(unsigned int, unsigned int);
struct Matrix create_static		(unsigned int, unsigned int, REAL*);
struct Matrix create_and_init	(unsigned int, unsigned int, REAL);
struct Matrix clone				(struct Matrix);

void destroy(struct Matrix *);


// funzioni per riempire le matrici
void zeros		(struct Matrix);
void ones		(struct Matrix);
void eyes		(struct Matrix);
void hilbert	(struct Matrix);


// funzioni per la stampa delle matrici, forse le metterò in un altro file
void print		(struct Matrix);
