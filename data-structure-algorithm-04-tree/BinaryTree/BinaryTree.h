#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

// 이진 트리 노드 구조체
typedef struct tagSBTNode {
    struct tagSBTNode *Left;
    struct tagSBTNode *Right;

    ElementType Data;
} SBTNode;

// 함수 원형부
SBTNode *SBT_CreateNode(ElementType NewData);

void SBT_DestroyNode(SBTNode *Node);

void SBT_DestroyTree(SBTNode *Root);

void SBT_PreorderPrintTree(SBTNode *Node);

void SBT_InorderPrintTree(SBTNode *Node);

void SBT_PostorderPrintTree(SBTNode *Node);

#endif
