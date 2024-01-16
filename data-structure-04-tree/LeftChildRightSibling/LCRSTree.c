#include "LCRSTree.h"

// 노드 생성
LCRSNode *LCRS_CreateNode(ElementType NewData) {
    // 노드를 Heap 메모리에 할당 및 초기화
    LCRSNode *NewNode = (LCRSNode *) malloc(sizeof(LCRSNode));
    NewNode->LeftChild = NULL;
    NewNode->RightSibling = NULL;
    NewNode->Data = NewData;

    return NewNode;
}

// 노드 소멸(메모리 할당 해제)
void LCRS_DestroyNode(LCRSNode *Node) {
    free(Node);
}

// 트리 소멸
void LCRS_DestroyTree(LCRSNode *Root) {
    // 형제 노드가 있으면 형제 노드 제거
    if (Root->RightSibling != NULL)
        LCRS_DestroyTree(Root->RightSibling);

    // 자식 노드가 있으면 자식 노드 제거
    if (Root->LeftChild != NULL)
        LCRS_DestroyTree(Root->LeftChild);

    Root->LeftChild = NULL;
    Root->RightSibling = NULL;

    // 메모리 할당 해제
    LCRS_DestroyNode(Root);
}

// 자식 노드 연결(추가)
void LCRS_AddChildNode(LCRSNode *Parent, LCRSNode *Child) {
    // 자식이 하나도 없는 경우 바로 부모 노드의 LC에 연결
    if (Parent->LeftChild == NULL) {
        Parent->LeftChild = Child;
    }
    // 자식이 하나 이상일 경우
    else {
        // 임시 노드에 LC노드를 저장하고
        LCRSNode *TempNode = Parent->LeftChild;
        // 가장 오른쪽 자식의 RS 포인터에 새 자식 노드를 연결한다.
        while (TempNode->RightSibling != NULL)
            TempNode = TempNode->RightSibling;

        TempNode->RightSibling = Child;
    }
}

// 트리 출력
void LCRS_PrintTree(LCRSNode *Node, int Depth) {
    // 들여쓰기
    for (int i = 0; i < Depth - 1; i++)
        printf("   "); // 공백 3칸

    if (Depth > 0) // 자식 노드 여부 표시
        printf("+--");

    // 노드 데이터 출력
    printf("%c\n", Node->Data);

    if (Node->LeftChild != NULL)
        LCRS_PrintTree(Node->LeftChild, Depth + 1);

    if (Node->RightSibling != NULL)
        LCRS_PrintTree(Node->RightSibling, Depth);
}
