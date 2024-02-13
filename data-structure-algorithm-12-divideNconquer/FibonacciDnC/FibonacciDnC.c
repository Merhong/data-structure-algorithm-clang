#include <stdio.h>

typedef unsigned long ULONG; // 64 bit

typedef struct tagMatrix2x2 {
    ULONG Data[2][2];
} Matrix2x2;

Matrix2x2 Matrix2x2_Multiply(Matrix2x2 A, Matrix2x2 B) {
    Matrix2x2 C;

    C.Data[0][0] = A.Data[0][0] * B.Data[0][0] + A.Data[0][1] * B.Data[1][0];
    C.Data[0][1] = A.Data[0][0] * B.Data[1][0] + A.Data[0][1] * B.Data[1][1];

    C.Data[1][0] = A.Data[1][0] * B.Data[0][0] + A.Data[1][1] * B.Data[1][0];
    C.Data[1][1] = A.Data[1][0] * B.Data[1][0] + A.Data[1][1] * B.Data[1][1];

    return C;
}

Matrix2x2 Matrix2x2_Power(Matrix2x2 A, int n) {
    if (n > 1) {
        A = Matrix2x2_Power(A, n / 2); // 제곱수를 반으로 나눠 다시 Matrix2x2_Power( ) 함수를 재귀 호출합니다.
        A = Matrix2x2_Multiply(A, A);
        if (n & 1) {
            Matrix2x2 B;
            B.Data[0][0] = 1;
            B.Data[0][1] = 1;
            B.Data[1][0] = 1;
            B.Data[1][1] = 0;
            A = Matrix2x2_Multiply(A, B); // 제곱수 n이 홀수인 경우 n/2을 수행할 때 / 연산자에 의해 나머지 1이 버려집니다. 따라서 A에
            // [1 1]
            // [1 0]을 곱하여 버려진 나머지를 보완합니다
        }
    }
    return A;
}

ULONG Fibonacci(int N) {
    Matrix2x2 A;
    A.Data[0][0] = 1;
    A.Data[0][1] = 1;
    A.Data[1][0] = 1;
    A.Data[1][1] = 0;

    A = Matrix2x2_Power(A, N);

    return A.Data[0][1];
}

int main(void) {
    int N = 46;
    ULONG Result = Fibonacci(N);

    printf("Fibonacci(%d) = %lu\n", N, Result);

    return 0;
}
