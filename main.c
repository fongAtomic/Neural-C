#include "matrix.c"

typedef MyMatrix Matrix;

int main(){

    // 建立一個 2x3 矩陣 A
    Matrix *A = matrix_create(2, 3);
    for(int i=0; i<6; i++) A->data[i] = i + 1; // [1,2,3], [4,5,6]

    // 建立一個 3x2 矩陣 B
    Matrix *B = matrix_create(3, 2);
    for(int i=0; i<6; i++) B->data[i] = i + 1; // [1,2], [3,4], [5,6]

    // 結果矩陣 C 應該是 2x2
    Matrix *C = matrix_create(2, 2);

    if (matrix_dot(A, B, C) == 0) {
        printf("Matrix A * B Result:\n");
        matrix_print(C);
    }

    matrix_free(A);
    matrix_free(B);
    matrix_free(C);
    return 0;

}