#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElementType;

// 수식 트리 노드 구조체
typedef struct tagETNode {
    struct tagETNode *Left;
    struct tagETNode *Right;

    ElementType Data;
} ETNode;

/*함수 원형부*/
ETNode *ET_CreateNode(ElementType NewData);

void ET_DestroyNode(ETNode *Node);

void ET_DestroyTree(ETNode *Root);

void ET_PreorderPrintTree(ETNode *Node);

void ET_InorderPrintTree(ETNode *Node);

void ET_PostorderPrintTree(ETNode *Node);

void ET_BuildExpressionTree(char *PostfixExpression, ETNode **Node);

double ET_Evaluate(ETNode *Tree);

#endif
