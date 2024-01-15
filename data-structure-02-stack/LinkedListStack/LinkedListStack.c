//
// Created by Merhong on 1/15/24.
//
#include "LinkedListStack.h"

// 스택 생성
void LLS_CreateStack(LinkedListStack **Stack) {
    //  스택을 Heap에 생성
    (*Stack) = (LinkedListStack *) malloc(sizeof(LinkedListStack)); // LLS 스택 Heap에 할당
    (*Stack)->List = NULL; // 초기화
    (*Stack)->Top = NULL; // 초기화
}

// 스택 제거
void LLS_DestroyStack(LinkedListStack *Stack) {
    while (!LLS_IsEmpty(Stack)) { // 스택이 비어있지않다면 실행
        Node *Popped = LLS_Pop(Stack); // 스택의 최상위 노드를 Pop
        LLS_DestroyNode(Popped); // Pop된 노드를 제거
    }

    //  스택을 Heap에서 해제
    free(Stack);
}

// 노드 생성
Node *LLS_CreateNode(char *NewData) {
    Node *NewNode = (Node *) malloc(sizeof(Node)); // 노드(포인터) Heap에 할당
    NewNode->Data = (char *) malloc(strlen(NewData) + 1); // 문자열(데이터) Heap에 할당

    strcpy(NewNode->Data, NewData); // 데이터를 저장한다.

    NewNode->NextNode = NULL; // 다음 노드에 대한 포인터는 NULL로 초기화한다.

    return NewNode; // 노드의 주소를 반환한다.
}

// 노드 제거
void LLS_DestroyNode(Node *_Node) {
    free(_Node->Data); // Heap 메모리에서 데이터 제거
    free(_Node); // Heap 메모리에서 노드 제거
}

// 노드 Push
void LLS_Push(LinkedListStack *Stack, Node *NewNode) {
    // 만약 스택이 비어있다면 -> 새로운 노드
    if (Stack->List == NULL) {
        Stack->List = NewNode;
    } else {
        //  스택의 Top에 신규 노드를 연결한다.
        Stack->Top->NextNode = NewNode;
    }

    //  스택의 Top 필드에 새 노드의 주소를 등록한다.
    Stack->Top = NewNode;
}

// 노드 Pop
Node *LLS_Pop(LinkedListStack *Stack) {
    //  LLS_Pop() 함수가 반환할 최상위 노드 저장
    Node *TopNode = Stack->Top;

    // 리스트 포인터가 탑(테일) 포인터를 가리킬 경우
    // 스택에 노드가 하나만 있는 경우를 말함. (Pop되면 빈 스택)
    if (Stack->List == Stack->Top) {
        Stack->List = NULL;
        Stack->Top = NULL;
    } else {
        // Top 아래에 있던 노드를 새로운 CurrentTop에 저장
        Node *CurrentTop = Stack->List;
        while (CurrentTop != NULL && CurrentTop->NextNode != Stack->Top) {
            CurrentTop = CurrentTop->NextNode;
        }

        // CurrentTop을 Top에 저장
        Stack->Top = CurrentTop;
        Stack->Top->NextNode = NULL;
    }

    return TopNode;
}

Node *LLS_Top(LinkedListStack *Stack) {
    return Stack->Top;
}

int LLS_GetSize(LinkedListStack *Stack) {
    int Count = 0;
    Node *Current = Stack->List;

    while (Current != NULL) {
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}

int LLS_IsEmpty(LinkedListStack *Stack) {
    return (Stack->List == NULL);
}
