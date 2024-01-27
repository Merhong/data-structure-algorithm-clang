#include <stdio.h>

// 교환
void Swap(int *A, int *B) {
    int Temp = *A;
    *A = *B;
    *B = Temp;
}

// 분할
int Partition(int DataSet[], int Left, int Right) {
    int First = Left;
    int Pivot = DataSet[First]; // Pivot, 기준 요소

    ++Left;

    // 왼쪽과 오른쪽이 만날때까지 반복
    while (Left <= Right) {
        // 왼쪽 그룹에서 Pivot 보다 작은값이고 L < R 이면 ++L
        while (DataSet[Left] <= Pivot && Left < Right)
            ++Left;

        // 오른쪽 그룹에서 Pivot보다 크거나 같고 L <= R이면 --R
        while (DataSet[Right] >= Pivot && Left <= Right)
            --Right;

        // 만약 L < R 이면 교환 아니면 종료
        if (Left < Right)
            Swap(&DataSet[Left], &DataSet[Right]);
        else
            break;
    }

    // 자료구조의 첫 데이터와 오른쪽 데이터를 교환
    Swap(&DataSet[First], &DataSet[Right]);

    return Right;
}

// 퀵 정렬
void QuickSort(int DataSet[], int Left, int Right) {
    // 만약 L < R이면
    if (Left < Right) {
        // 인덱스로 분할
        int Index = Partition(DataSet, Left, Right);

        // 퀵정렬 재귀호출
        QuickSort(DataSet, Left, Index - 1);
        QuickSort(DataSet, Index + 1, Right);
    }
}

int main(void) {
    int DataSet[] = {6, 4, 2, 3, 1, 5};
    int Length = sizeof DataSet / sizeof DataSet[0];
    int i = 0;

    QuickSort(DataSet, 0, Length - 1);

    for (i = 0; i < Length; i++) {
        printf("%d ", DataSet[i]);
    }

    printf("\n");

    return 0;
}
