#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int rows;
    int cols;
    double *data;
}MyMatrix;


MyMatrix *createMatrix(int rows , int cols);
void *freeMatrix(MyMatrix* matrix);
void fillMatrix(MyMatrix* matrix , double val);
int Matrix_dot(MyMatrix* a , MyMatrix* b , MyMatrix* c); // c = a * b
void matrix_print(MyMatrix *m);

#endif