#include "MyMatrix.h"

typedef MyMatrix Matrix;

int main(){

    // 建立一個 2x3 矩陣 A
    Matrix *A = createMatrix(2, 3);
    for(int i=0; i<6; i++) A->data[i] = i + 1; // [1,2,3], [4,5,6]

    // 建立一個 3x2 矩陣 B
    Matrix *B = createMatrix(3, 2);
    for(int i=0; i<6; i++) B->data[i] = i + 1; // [1,2], [3,4], [5,6]

    // 結果矩陣 C 應該是 2x2
    Matrix *C = createMatrix(2, 2);

    if (Matrix_dot(A, B, C) == 0) {
        printf("Matrix A * B Result:\n");
        Matrix_print(C);
    }

    freeMatrix(A);
    freeMatrix(B);
    freeMatrix(C);
    return 0;

}