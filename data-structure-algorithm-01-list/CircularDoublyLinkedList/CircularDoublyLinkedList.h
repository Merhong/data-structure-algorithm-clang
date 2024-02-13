//
// Created by daeho on 2024-01-11.
//

#ifndef CIRCULARDOUBLYLINKEDLISH_H
#define CIRCULARDOUBLYLINKEDLISH_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode {
    ElementType Data; // 노드의 데이터
    struct tagNode *PrevNode; // 이전 노드 포인터
    struct tagNode *NextNode; // 다음 노드 포인터
} Node;

// 함수 원형 선언
Node *CDLL_CreateNode(ElementType NewData);

void CDLL_DestroyNode(Node *Node);

void CDLL_AppendNode(Node **Head, Node *NewNode);

void CDLL_InsertAfter(Node *Current, Node *NewNode);

void CDLL_RemoveNode(Node **Head, Node *Remove);

Node *CDLL_GetNodeAt(Node *Head, int Location);

int CDLL_GetNodeCount(Node *Head);

#endif //CIRCULARDOUBLYLINKEDLISH_H
