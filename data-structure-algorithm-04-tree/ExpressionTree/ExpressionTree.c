#include "ExpressionTree.h"

// 수식 트리 노드 생성
ETNode *ET_CreateNode(ElementType NewData) {
    // 노드를 Heap 메모리에 할당 및 초기화
    ETNode *NewNode = (ETNode *) malloc(sizeof(ETNode));
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Data = NewData;

    return NewNode;
}

// 노드 소멸(메모리 할당 해제)
void ET_DestroyNode(ETNode *Node) {
    free(Node);
}

// 수식 트리 소멸
void ET_DestroyTree(ETNode *Root) {
    if (Root == NULL)
        return;

    // 후위 순회 방식(Left -> Right -> Root)
    ET_DestroyTree(Root->Left);
    ET_DestroyTree(Root->Right);
    ET_DestroyNode(Root);
}

// 전위 순회 방식 트리 출력(Root -> Left -> Right)
void ET_PreorderPrintTree(ETNode *Node) {
    if (Node == NULL)
        return;

    printf(" %c", Node->Data);

    ET_PreorderPrintTree(Node->Left);
    ET_PreorderPrintTree(Node->Right);
}

// 중위 순회 방식 트리 출력(Left -> Root -> Right)
void ET_InorderPrintTree(ETNode *Node) {
    if (Node == NULL)
        return;

    printf("(");
    ET_InorderPrintTree(Node->Left);

    printf("%c", Node->Data);

    ET_InorderPrintTree(Node->Right);
    printf(")");
}

// 후위 순회 방식 트리 출력(Left -> Right -> Right)
void ET_PostorderPrintTree(ETNode *Node) {
    if (Node == NULL)
        return;

    ET_PostorderPrintTree(Node->Left);
    ET_PostorderPrintTree(Node->Right);
    printf(" %c", Node->Data);
}

// 수식 트리 빌드
void ET_BuildExpressionTree(char *PostfixExpression, ETNode **Node) {
    int len = strlen(PostfixExpression); // 후위 표기식 길이
    char Token = PostfixExpression[len - 1]; // 후위 표기식의 토큰
    PostfixExpression[len - 1] = '\0';

    switch (Token) {
        // 연산자인 경우
        // 2개의 피연산자가 뒤따라오기 때문에
        case '+':
        case '-':
        case '*':
        case '/':
            // 방금 읽어낸 연산자 토큰을 노드에 연결
            (*Node) = ET_CreateNode(Token);

        // 바로 피연산자 둘을 연산자 노드의 양쪽 자식으로 연결
            ET_BuildExpressionTree(PostfixExpression, &(*Node)->Right);
            ET_BuildExpressionTree(PostfixExpression, &(*Node)->Left);
            break;

        // 피연산자인 경우
        default:
            // 해당 토큰을 노드에 입력하고 함수를 반환
            (*Node) = ET_CreateNode(Token);
            break;
    }
}

double ET_Evaluate(ETNode *Tree) {
    char Temp[2];

    double Left = 0;
    double Right = 0;
    double Result = 0;

    if (Tree == NULL)
        return 0;

    switch (Tree->Data) {
        // 연산자인 경우
        // 트리의 바닥(잎)부터 계산 결과를 병합하여 올라가도록
        // 노드의 양쪽 자식에 대하여 재귀 호출
        case '+':
        case '-':
        case '*':
        case '/':
            // 재귀 호출후 값을 반환하면
            Left = ET_Evaluate(Tree->Left); // 왼쪽 수식의 트리의 계산 결과는 Left 변수에
            Right = ET_Evaluate(Tree->Right); // 오른쪽 수식의 트리의 계산 결과는 Right 변수에 저장

        // 그 후 연산자의 종류에 따라 계산
            if (Tree->Data == '+') Result = Left + Right;
            else if (Tree->Data == '-') Result = Left - Right;
            else if (Tree->Data == '*') Result = Left * Right;
            else if (Tree->Data == '/') Result = Left / Right;
            break;

        // 피연산자인 경우
        // 그냥 토큰에 담겨 있던 값을 수로 변환해서 반환
        default:
            memset(Temp, 0, sizeof(Temp));
            Temp[0] = Tree->Data;
            Result = atof(Temp);
            break;
    }

    return Result;
}
