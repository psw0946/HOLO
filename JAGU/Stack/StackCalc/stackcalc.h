#ifndef _STACK_CALC_
#define _STACK_CALC_
// ��� ���Ͽ� include ���� �ʾƵ� .cpp ���Ͽ� include �ϸ� ���� �� ���� �� ó�� ����.

void calcExpr(ExprToken *pExprTokens, int tokenCount);
int pushLSExprToken(LinkedStack* pStack, ExprToken data);
void convertInfixToPostfix(ExprToken *pExprTokens, int tokenCount);
int inStackPrecedence(Precedence oper);
int outStackPrecedence(Precedence oper);
void printToken(ExprToken element);

#endif