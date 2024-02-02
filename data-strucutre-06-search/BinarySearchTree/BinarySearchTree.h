#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

// 이진 탐색 트리의 노드 구조체
typedef struct tagBSTNode {
    struct tagBSTNode *Left;
    struct tagBSTNode *Right;

    ElementType Data;
} BSTNode;

/* 함수 원형부 */
BSTNode *BST_CreateNode(ElementType NewData);

void BST_DestroyNode(BSTNode *Node);

void BST_DestroyTree(BSTNode *Tree);

BSTNode *BST_SearchNode(BSTNode *Tree, ElementType Target);

BSTNode *BST_SearchMinNode(BSTNode *Tree);

void BST_InsertNode(BSTNode *Tree, BSTNode *Child);

BSTNode *BST_RemoveNode(BSTNode *Tree, BSTNode *Parent, ElementType Target);

void BST_InorderPrintTree(BSTNode *Node);

#endif
