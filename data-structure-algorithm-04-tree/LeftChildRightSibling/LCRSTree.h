#ifndef LCRS_TREE_H
#define LCRS_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

// LeftChild-RightSibling 트리 노드 선언
typedef struct tagLCRSNode {
    struct tagLCRSNode *LeftChild; // 자식 포인터
    struct tagLCRSNode *RightSibling; // 형제 포인터
    ElementType Data; // 데이터
} LCRSNode;


LCRSNode *LCRS_CreateNode(ElementType NewData);

void LCRS_DestroyNode(LCRSNode *Node);

void LCRS_DestroyTree(LCRSNode *Root);

void LCRS_AddChildNode(LCRSNode *ParentNode, LCRSNode *ChildNode);

void LCRS_PrintTree(LCRSNode *Node, int Depth);

#endif
