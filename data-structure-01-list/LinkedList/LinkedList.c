//
// Created by daeho on 2024-01-08.
//
#include <stdio.h> // 이건 LinkedList 헤더 파일에서 이미 정의하기 때문에 중복?
#include "LinkedList.h"

// 노드 생성 함수 SLL_CreateNode()
Node *SLL_CreateNode(ElementType NewData) {
    Node *NewNode = (Node *) malloc(sizeof(Node));

    NewNode->Data = NewData; // 데이터를 저장한다.
    NewNode->NextNode = NULL; // 다음 노드에 대한 포인터는 NULL로 초기화

    return NewNode; // 노드의 주소를 반환
}

// 노드 소멸 함수 SLL_DestroyNode()
void SLL_DestroyNode(Node *Node) {
    free(Node); // 동적 할당 메모리 해제
}

// 노드 추가 함수 SLL_AppendNode()
void SLL_AppendNode(Node **Head, Node *NewNode) {
    // 헤드 노드가 NULL이면 새로운 노드가 Head가 된다.
    if ((*Head) == NULL) {
        *Head = NewNode;
    } else {
        // 테일을 찾아 NewNode를 연결한다.
        Node *Tail = (*Head);
        while (Tail->NextNode != NULL) {
            Tail = Tail->NextNode;
        }

        Tail->NextNode = NewNode;
    }
}

// 노드 삽입 함수 SLL_InsertAfter()
void SLL_InsertAfter(Node *Current, Node *NewNode) {
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}

// 노드 삽입 함수 SLL_InsertNewHead()
void SLL_InsertNewHead(Node **Head, Node *NewHead) {
    if (Head == NULL) {
        (*Head) = NewHead;
    } else {
        NewHead->NextNode = (*Head);
        (*Head) = NewHead;
    }
}

// 노드 제거 함수 SLL_RemoveNode()
void SLL_RemoveNode(Node **Head, Node *Remove) {
    if (*Head == Remove) {
        *Head = Remove->NextNode;
    } else {
        Node *Current = *Head;
        while (Current != NULL && Current->NextNode != Remove) {
            Current = Current->NextNode;
        }

        if (Current != NULL)
            Current->NextNode = Remove->NextNode;
    }
}


// 노드 탐색 함수 SLL_GetNodeAt()
Node *SLL_GetNodeAt(Node *Head, int Location) {
    Node *Current = Head;

    while (Current != NULL && (--Location) >= 0) {
        Current = Current->NextNode;
    }

    return Current;
}


// 노드 개수 세기 함수 SLL_GetNodeCount()
int SLL_GetNodeCount(Node *Head) {
    int Count = 0;
    Node *Current = Head;

    while (Current != NULL) {
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}
