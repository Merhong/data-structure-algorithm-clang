#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

// 원형큐 노드 구조체
typedef struct tagNode {
    ElementType Data;
} Node;

// 원형큐 구조체
typedef struct tagCircularQueue {
    int Capacity;
    int Front;
    int Rear;

    Node *Nodes;
} CircularQueue;

/*함수 원형부*/
void CQ_CreateQueue(CircularQueue **Queue, int Capacity);

void CQ_DestroyQueue(CircularQueue *Queue);

void CQ_Enqueue(CircularQueue *Queue, ElementType Data);

ElementType CQ_Dequeue(CircularQueue *Queue);

int CQ_GetSize(CircularQueue *Queue);

int CQ_IsEmpty(CircularQueue *Queue);

int CQ_IsFull(CircularQueue *Queue);

#endif
