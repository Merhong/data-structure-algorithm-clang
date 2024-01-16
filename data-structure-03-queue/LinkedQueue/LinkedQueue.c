#include "LinkedQueue.h"

// 링크드 큐 생성
void LQ_CreateQueue(LinkedQueue **Queue) {
    //  큐를 Heap 메모리에 할당 및 초기화
    (*Queue) = (LinkedQueue *) malloc(sizeof(LinkedQueue));
    (*Queue)->Front = NULL;
    (*Queue)->Rear = NULL;
    (*Queue)->Count = 0;
}

// 링크드 큐 소멸
void LQ_DestroyQueue(LinkedQueue *Queue) {
    while (!LQ_IsEmpty(Queue)) {
        Node *Popped = LQ_Dequeue(Queue);
        LQ_DestroyNode(Popped);
    }

    //  큐를 Heap에서 할당 해제
    free(Queue);
}

// 링크드 큐의 노드 생성
Node *LQ_CreateNode(char *NewData) {
    // 노드를 Heap 메모리에 할당
    Node *NewNode = (Node *) malloc(sizeof(Node));
    NewNode->Data = (char *) malloc(strlen(NewData) + 1);

    strcpy(NewNode->Data, NewData); //  데이터를 저장한다. 

    NewNode->NextNode = NULL; //  다음 노드에 대한 포인터는 NULL로 초기화한다. 

    return NewNode; //  노드의 주소를 반환한다. 
}

// 노드 및 데이터 메모리에서 할당 해제
void LQ_DestroyNode(Node *_Node) {
    free(_Node->Data); // 노드에 저장된 데이터 메모리 해제
    free(_Node); // 노드 메모리 해제
}


// 노드 삽입
// 후단에 새로운 노드를 붙이는 것으로 구현
void LQ_Enqueue(LinkedQueue *Queue, Node *NewNode) {
    if (Queue->Front == NULL) {
        Queue->Front = NewNode;
        Queue->Rear = NewNode;
        Queue->Count++;
    } else {
        Queue->Rear->NextNode = NewNode;
        Queue->Rear = NewNode;
        Queue->Count++;
    }
}

// 노드 제거
/* 전단 뒤에 있는 노드를 새로운 전단으로 만들고
 * 전단이었던 노드의 포인터를 호출자에게 반환 */
Node *LQ_Dequeue(LinkedQueue *Queue) {
    //  LQ_Dequeue() 함수가 반환할 최상위 노드 
    Node *Front = Queue->Front;

    // 만약 다음 노드가 없다면 전,후단 NULL
    if (Queue->Front->NextNode == NULL) {
        Queue->Front = NULL;
        Queue->Rear = NULL;
    }
    // 다음 노드가 있다면
    // 제거하는 노드 뒤에 있던 노드를 새로운 노드로 만들고
    else {
        Queue->Front = Queue->Front->NextNode;
    }

    Queue->Count--; // 개수를 1개 감소

    return Front; // 전단이었떤 노드의 포인터를 호출자에게 반환
}

// 링크드 큐가 비어있는지 확인
int LQ_IsEmpty(LinkedQueue *Queue) {
    return (Queue->Front == NULL);
}
