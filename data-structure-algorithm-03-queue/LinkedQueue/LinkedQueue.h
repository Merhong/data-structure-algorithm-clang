#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tagNode {
    char *Data; // 데이터
    struct tagNode *NextNode; // 다음 노드를 가리키는 포인터
} Node;

typedef struct tagLinkedQueue {
    Node *Front; // 전단을 가리키는 포인터
    Node *Rear; // 후단을 가리키는 포인터
    int Count; // 노드의 개수를 나타내는 변수
} LinkedQueue;

void LQ_CreateQueue(LinkedQueue **Queue);

void LQ_DestroyQueue(LinkedQueue *Queue);

Node *LQ_CreateNode(char *Data);

void LQ_DestroyNode(Node *_Node);

void LQ_Enqueue(LinkedQueue *Queue, Node *NewNode);

Node *LQ_Dequeue(LinkedQueue *Queue);

int LQ_IsEmpty(LinkedQueue *Queue);

#endif
