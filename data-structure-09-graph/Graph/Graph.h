#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

enum VisitMode { Visited, NotVisited };

typedef int VElementType;

// 정점 구조체
typedef struct tagVertex
{
    VElementType Data; // 데이터를 담는 필드
    int Visited; // 방문 여부(그래프 순회 알고리즘에서 사용)
    int Index; // 정점의 인덱스
    struct tagVertex* Next; // 다음 정점을 가리키는 포인터
    struct tagEdge* AdjacencyList;
} Vertex;

// 간선 구조체
typedef struct tagEdge
{
    int Weight; // 비용(최소 신장 트리 or 최단 경로 탐색에서 사용)
    struct tagEdge* Next; // 다음 간선을 가리키는 포인터
    Vertex* From; // 간선의 시작 정점
    Vertex* Target; // 간선의 끝 정점
} Edge;

// 그래프 구조체
typedef struct tagGraph
{
    Vertex* Vertices; // 정점 목록에 대한 포인터
    int VertexCount; // 정점 수
} Graph;

/* 함수 원형부 */
Graph* CreateGraph();

void DestroyGraph(Graph* G);

Vertex* CreateVertex(VElementType Data);

void DestroyVertex(Vertex* V);

Edge* CreateEdge(Vertex* From, Vertex* Target, int Weight);

void DestroyEdge(Edge* E);

void AddVertex(Graph* G, Vertex* V);

void AddEdge(Vertex* V, Edge* E);

void PrintGraph(Graph* G);

#endif
