#include "MyMatrix.h"
#include <time.h>

// 將矩陣隨機初始化為 -1.0 到 1.0 之間的數值
void matrix_randomize(MyMatrix *m) {
    for (int i = 0; i < m->rows * m->cols; i++) {
        // 產生 -1.0 到 1.0 的浮點數
        m->data[i] = ((double)rand() / (double)RAND_MAX) * 2.0f - 1.0f;
    }
}

MyMatrix* createMatrix(int rows , int cols){
    MyMatrix* matrix = (MyMatrix*)malloc(sizeof(MyMatrix));
    matrix->cols = cols;
    matrix->rows = rows;
    matrix->data = (double*)malloc(rows*cols*sizeof(double));

    return matrix;
}

void *freeMatrix(MyMatrix* matrix){
    if(matrix){
        free(matrix->data);
        free(matrix);
    }
}

void fillMatrix(MyMatrix* m , double val){

    int size = m->rows * m->cols;
    for (int i = 0; i < size; i++) {
        m->data[i] = val;
    }

}

int Matrix_dot(MyMatrix* A , MyMatrix* B , MyMatrix* C){
    if (A->cols != B->rows || C->rows != A->rows || C->cols != B->cols) {
        return -1; // 維度不匹配
    }

    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->cols; j++) {
            float sum = 0.0f;
            for (int k = 0; k < A->cols; k++) {
                // index = row * total_cols + col
                sum += A->data[i * A->cols + k] * B->data[k * B->cols + j];
            }
            C->data[i * C->cols + j] = sum;
        }
    }
    return 0;
}

void Matrix_print(MyMatrix *m){
    int i , j;
    for(i = 0 ; i < m->rows ; i++){
        for(j = 0 ; j < m->cols ; j++){
            printf("%0.2f ", m->data[i * m->cols + j]);
        }
        printf("\n");
    }

}
