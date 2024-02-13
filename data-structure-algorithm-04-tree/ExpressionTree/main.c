#include "ExpressionTree.h"

int main(void) {
    ETNode *Root = NULL;

    // 후위 표기법 수식
    char PostfixExpression[20] = "71*52-/";

    // 수식 트리 빌드
    ET_BuildExpressionTree(PostfixExpression, &Root);

    //  트리 출력
    printf("Preorder ...\n");
    ET_PreorderPrintTree(Root);
    printf("\n\n");

    printf("Inorder ... \n");
    ET_InorderPrintTree(Root);
    printf("\n\n");

    printf("Postorder ... \n");
    ET_PostorderPrintTree(Root);
    printf("\n");

    // 계산 결과
    printf("Evaulation Result : %f \n", ET_Evaluate(Root));

    //  트리 소멸
    ET_DestroyTree(Root);

    return 0;
}
