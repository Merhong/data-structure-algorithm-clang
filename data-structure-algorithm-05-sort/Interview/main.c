#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Point.h"

// 내림차순 정렬
//  리턴값이
//  < 0 이면, _elem1이 _elem2보다 크다.
//  = 0   이면, _elem1이 _elem2와 같다.
//  > 0 이면, _elem1이 _elem2보다 작다.
int ComparePoint(const void *_elem1, const void *_elem2) {
    // 포인터 형변환을 Point 구조체 포인터로 수정합니다.
    Point *elem1 = (Point *) _elem1;
    Point *elem2 = (Point *) _elem2;

    // point 값을 비교하여 정렬 순서를 결정합니다.
    if (elem1->point > elem2->point)
        return -1;
    else if (elem1->point < elem2->point)
        return 1;
    else
        return 0;
}

int main() {
    // 1. 데이터를 구매포인트 내림차순으로 정렬(qsort() 라이브러리 함수 사용)
    // qsort() 함수의 매개변수
    // 첫 번째 매개변수: 정렬할 배열의 포인터, 이 경우 (void *) DataSet.
    // 두 번째 매개변수: 배열의 요소 수, 이 경우 sizeof(DataSet) / sizeof(DataSet[0]).
    int Length = sizeof DataSet / sizeof DataSet[0];
    // 세 번째 매개변수: 배열의 각 요소의 크기, 이 경우 sizeof(Point).
    // 네 번째 매개변수: 비교 함수의 포인터. 이 함수는 두 Point 구조체를 비교하여 정렬 순서를 결정합니다.
    qsort((void *) DataSet, Length, sizeof(Point), ComparePoint);

    // 2. 정렬된 데이터에서 14,142번째 고객을 찾아서 ID와 점수를 출력
    for (int i = 0; i < Length; i++) {
        printf(("%d번째 고객 ID : %d \t포인트 점수 : %.2f\n"), i + 1, DataSet[i].id, DataSet[i].point);
    }

    printf("=========\n");
    // 인덱스는 0부터 시작하니 14141이 실제로는 14142번째 고객이다.
    printf(("14142번째 고객 ID : %d \t포인트 점수 : %.2f\n"), DataSet[14141].id, DataSet[14141].point);

    return 0;
}
