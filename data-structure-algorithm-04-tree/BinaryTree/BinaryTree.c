#include "BinaryTree.h"

// 노드 생성
SBTNode *SBT_CreateNode(ElementType NewData) {
    // 트리 노드 Heap 메모리 할당 및 초기화
    SBTNode *NewNode = (SBTNode *) malloc(sizeof(SBTNode));
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Data = NewData;

    return NewNode;
}

// 노드 소멸(메모리 할당 해제)
void SBT_DestroyNode(SBTNode *Node) {
    free(Node);
}

// 트리 소멸(후위 순회 방식)
// Left - Right - Root 순서
void SBT_DestroyTree(SBTNode *Node) {
    // 노드가 없으면 바로 반환
    if (Node == NULL)
        return;

    //  왼쪽 하위 트리 소멸 
    SBT_DestroyTree(Node->Left);

    //  오른쪽 하위 트리 소멸 
    SBT_DestroyTree(Node->Right);

    //  뿌리 노드 소멸 
    SBT_DestroyNode(Node);
}

// 전위 순회 트리 출력
void SBT_PreorderPrintTree(SBTNode *Node) {
    if (Node == NULL)
        return;

    //  뿌리 노드 출력 
    printf(" %c", Node->Data);

    //  왼쪽 하위 트리 출력 
    SBT_PreorderPrintTree(Node->Left);

    //  오른쪽 하위 트리 출력 
    SBT_PreorderPrintTree(Node->Right);
}

// 중위 순회 트리 출력
void SBT_InorderPrintTree(SBTNode *Node) {
    if (Node == NULL)
        return;

    //  왼쪽 하위 트리 출력 
    SBT_InorderPrintTree(Node->Left);

    //  뿌리 노드 출력 
    printf(" %c", Node->Data);

    //  오른쪽 하위 트리 출력 
    SBT_InorderPrintTree(Node->Right);
}

// 후위 순회 트리 출력
void SBT_PostorderPrintTree(SBTNode *Node) {
    if (Node == NULL)
        return;

    //  왼쪽 하위 트리 출력 
    SBT_PostorderPrintTree(Node->Left);

    //  오른쪽 하위 트리 출력 
    SBT_PostorderPrintTree(Node->Right);

    //  뿌리 노드 출력 
    printf(" %c", Node->Data);
}
