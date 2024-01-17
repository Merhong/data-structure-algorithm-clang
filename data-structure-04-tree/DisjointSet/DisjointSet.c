#include "DisjointSet.h"

// 합집합 연산
void DS_UnionSet(DisjointSet *Set1, DisjointSet *Set2) {
    Set2 = DS_FindSet(Set2);
    Set2->Parent = Set1;
}

// 집합 탐색 연산
DisjointSet *DS_FindSet(DisjointSet *Set) {
    while (Set->Parent != NULL) {
        Set = Set->Parent;
    }

    return Set;
}

// 분리 집합 생성
DisjointSet *DS_MakeSet(void *NewData) {
    // 노드 Heap 메모리 할당 및 초기화
    DisjointSet *NewNode = (DisjointSet *) malloc(sizeof(DisjointSet));
    NewNode->Data = NewData;
    NewNode->Parent = NULL;

    return NewNode;
}

// 집합 소멸(메모리 할당 해제)
void DS_DestroySet(DisjointSet *Set) {
    free(Set);
}
