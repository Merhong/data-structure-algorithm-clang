#include "CircularQueue.h"

void CQ_CreateQueue(CircularQueue **Queue, int Capacity) {
    //  큐를 자유 저장소에 생성 
    (*Queue) = (CircularQueue *) malloc(sizeof(CircularQueue));

    //  입력된 Capacity+1 만큼의 노드를 자유 저장소에 생성 
    (*Queue)->Nodes = (Node *) malloc(sizeof(Node) * (Capacity + 1));

    (*Queue)->Capacity = Capacity;
    (*Queue)->Front = 0;
    (*Queue)->Rear = 0;
}

void CQ_DestroyQueue(CircularQueue *Queue) {
    free(Queue->Nodes);
    free(Queue);
}

// 원형큐 삽입
void CQ_Enqueue(CircularQueue *Queue, ElementType Data) {
    int Position = 0;

    if (Queue->Rear == Queue->Capacity) {
        Position = Queue->Rear;
        Queue->Rear = 0;
    } else
        Position = Queue->Rear++;

    Queue->Nodes[Position].Data = Data;
}

// 원형큐 삭제
ElementType CQ_Dequeue(CircularQueue *Queue) {
    int Position = Queue->Front;

    if (Queue->Front == Queue->Capacity)
        Queue->Front = 0;
    else
        Queue->Front++;

    return Queue->Nodes[Position].Data;
}

// 원형큐 개수 세기
int CQ_GetSize(CircularQueue *Queue) {
    if (Queue->Front <= Queue->Rear)
        return Queue->Rear - Queue->Front;
    else
        return Queue->Rear + (Queue->Capacity - Queue->Front) + 1;
}

// 공백상태 확인
int CQ_IsEmpty(CircularQueue *Queue) {
    return (Queue->Front == Queue->Rear);
}

// 포화상태 확인
int CQ_IsFull(CircularQueue *Queue) {
    if ((Queue->Rear + 1) % Queue->Capacity == Queue->Front) {
        // Rear 다음 위치가 Front와 같다면 큐는 포화 상태입니다.
        return 1;
    } else {
        // 아니면 포화 상태가 아닙니다.
        return 0;
    }
}
