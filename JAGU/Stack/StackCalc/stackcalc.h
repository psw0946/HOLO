#ifndef _STACK_CALC_
#define _STACK_CALC_
// 헤더 파일에 include 하지 않아도 .cpp 파일에 include 하면 오류 안 나는 거 처음 알음.

void calcExpr(ExprToken *pExprTokens, int tokenCount);
int pushLSExprToken(LinkedStack* pStack, ExprToken data);
void convertInfixToPostfix(ExprToken *pExprTokens, int tokenCount);
int inStackPrecedence(Precedence oper);
int outStackPrecedence(Precedence oper);
void printToken(ExprToken element);

#endif