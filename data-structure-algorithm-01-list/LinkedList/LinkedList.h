//
// Created by daeho on 2024-01-08.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode {
    ElementType Data; // 데이터 필드
    struct tagNode *NextNode; // 다음 노드를 가리키는 포인터
} Node;

// 함수 원형 선언
Node *SLL_CreateNode(ElementType NewData); // 노드 생성

void SLL_DestroyNode(Node *Node); // 노드 삭제

void SLL_AppendNode(Node **Head, Node *NewNode); // 노드 추가

void SLL_InsertAfter(Node *Current, Node *NewNode); // 노드 삽입

void SLL_InsertNewHead(Node **Head, Node *NewHead); // 노드 삽입

void SLL_RemoveNode(Node **Head, Node *Remove); // 노드 삭제

Node *SLL_GetNodeAt(Node *Head, int Location); // 노드 탐색

int SLL_GetNodeCount(Node *Head); // 노드 탐색


#endif //LINKEDLIST_H
