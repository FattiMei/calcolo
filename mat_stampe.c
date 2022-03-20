#include "mat_stampe.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void print_for_matlab(struct Matrix A, const char *label){
    assert(A.data != NULL);


    printf("%s = [", label);

    for(unsigned int i = 0; i < A.rows; ++i){
        for(unsigned int j = 0; j < A.cols; ++j){
            if(j > 0)
                printf(", ");


            print(A.data[i * A.cols + j]);
        }

        if(i != A.rows - 1)
            putchar(';');
    }

    printf("]\n\n");
}


void print_for_term(struct Matrix A, const char *label){
    assert(A.data != NULL);


    printf("%s = \n", label);

    for(unsigned int i = 0; i < A.rows; ++i){
        for(unsigned int j = 0; j < A.cols; ++j){
            putchar('\t');
            print(A.data[i * A.cols + j]);
            putchar('\t');
        }

        putchar('\n');
    }

    putchar('\n');
}
