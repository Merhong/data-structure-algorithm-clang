#include "LinkedQueue.h"

int main(void) {
    Node *Popped;
    LinkedQueue *Queue;

    LQ_CreateQueue(&Queue); // 링크드 큐 생성

    // 노드 삽입
    LQ_Enqueue(Queue, LQ_CreateNode("abc"));
    LQ_Enqueue(Queue, LQ_CreateNode("def"));
    LQ_Enqueue(Queue, LQ_CreateNode("efg"));
    LQ_Enqueue(Queue, LQ_CreateNode("hij"));

    // 큐 사이즈(개수) 확인
    printf("Queue Size : %d\n", Queue->Count);

    // 큐의 노드가 없을때까지 제거 연산 반복
    while (LQ_IsEmpty(Queue) == 0) {
        Popped = LQ_Dequeue(Queue); // 노드 제거

        printf("Dequeue: %s \n", Popped->Data); // 제거되는 데이터 출력

        LQ_DestroyNode(Popped); // 노드 및 데이터 메모리 할당 해제
    }

    LQ_DestroyQueue(Queue); // 링크드 큐 소멸

    return 0;
}
