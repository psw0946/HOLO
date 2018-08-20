#include <iostream>
#include "exprdef.h"
#include "exprlinkedstack.h"
#include "stackcalc.h"

int pushLSExprToken(LinkedStack* pStack, ExprToken data) {
	Node node = { 0 , };
	node.data = data;
	return pStack->pushLS(node);
}

/*
 * 1. 피연산자를 만나면 스택에 푸시한다.
 * 2. 연산자를 만나면 연산에 필요한 개수만큼 (보통 2개) 피연산자를 스택에서 팝한다.
 * 3. 연산한 결과는 다시 스택에 푸시한다.
 */
void calcExpr(ExprToken *pExprTokens, int tokenCount) { // 후위표기식을 받아 계산처리
	LinkedStack *pStack = NULL;
	Node *pNode1 = NULL, *pNode2 = NULL;
	Precedence tokenType;
	int i = 0;
	if (pExprTokens == NULL) {
		return;
	}

	pStack = pStack->createLinekdStack();
	if (pStack != NULL) {
		for (i = 0; i < tokenCount; i++) {
			tokenType = pExprTokens[i].type;

			if (tokenType == operand) { // 피연산자를 만나면 스택에 푸시한다.
				pushLSExprToken(pStack, pExprTokens[i]);
			}
			else {
				pNode2 = pStack->popLS();
				if (pNode2 != NULL) { // 연산에 필요한 개수만큼 2개의 피연산자를 스택에서 팝한다.
					pNode1 = pStack->popLS();
					if (pNode1 != NULL) {
						float op1 = pNode1->data.value;
						float op2 = pNode2->data.value;

						ExprToken newToken;
						newToken.type = operand;
						switch (tokenType) { // 연산의 종류에 따라 연산을 실시한다. 연산 결과는 새로운 토큰 newToken에 저장된다.
						case PLUS:
							newToken.value = op1 + op2;
							break;
						case MINUS:
							newToken.value = op1 - op2;
							break;
						case times:
							newToken.value = op1 * op2;
							break;
						case divide:
							newToken.value = op1 / op2;
							break;
						}

						pushLSExprToken(pStack, newToken); // 연산한 결과는 다시 스택에 푸시한다.
						
						delete pNode1;
					}
					delete pNode2;
				}
			} // end-of-else
		}

		pNode1 = pStack->popLS(); // 수식의 최종 처리 결과 값을 스택에서 팝한다.
		if (pNode1 != NULL) {
			printf("수식 계산 결과 [%f]\n", pNode1->data.value);
			delete pNode1;
		}
		else {
			printf("수식에 오류가 있습니다.\n");
		}
		pStack->deleteLinkedStack();
	}
}

void convertInfixToPostfix(ExprToken *pExprTokens, int tokenCount) {
	LinkedStack *pStack = NULL;
	Node *pNode = NULL;
	Precedence tokenType;
	Precedence inStackTokenType;
	int i = 0;

	if (pExprTokens == NULL) return;

	pStack = pStack->createLinekdStack();
	if (pStack != NULL) {
		for (i = 0; i < tokenCount; i++) {
			tokenType = pExprTokens[i].type;
			switch (tokenType) {
			case operand: // 피연산자를 만나면 바로 출력
				printf("%f\n", pExprTokens[i].value);
				break;
			case rparen: // 닫는 괄호 ) 연산자를 만난 경우 처리. 즉, 여는 괄호 ( 연산자를 만날 때까지 while 루프를 돌면서, 스택 안의 연산자들을 팝하고 출력한다.
				pNode = pStack->popLS();
				while (pNode != NULL && pNode->data.type != lparen) {
					printToken(pNode->data);
					delete pNode;

					pNode = pStack->popLS();
				}
				if (pNode != NULL)
					delete pNode;
				break;
			default:
				/*
				 * 닫는 괄호 ) 연산자 이외의 연산자인 경우 처리
				 * 스택 내에 저장된 연산자들 중 현재 연산자보다 우선순위가 높은 연산자는 팝(pop) & 출력한다.
				 * 그리고 나서, 현재 연산자를 스택에 푸시
				 */
				while (pStack->isLinkedStackEmpty() == FALSE) {
					inStackTokenType = pStack->peekLS()->data.type;
					if (outStackPrecedence(tokenType) <= inStackPrecedence(inStackTokenType)) {
						pNode = pStack->popLS();
						if (pNode != NULL) {
							printToken(pNode->data);
							delete pNode;
						}
					}
					else {
						break;
					}
				}
				pushLSExprToken(pStack, pExprTokens[i]);
				break;
			} // end-of-switch
		} // end-of-for

		while (pStack->isLinkedStackEmpty() == FALSE) { // 스택에 남은 연산자들을 팝하고 출력한다.
			pNode = pStack->popLS();
			if (pNode != NULL) {
				printToken(pNode->data);
				delete pNode;
			}
		}
		pStack->deleteLinkedStack();
	}
}

int inStackPrecedence(Precedence oper) {
	switch (oper) {
	case lparen:
		return 0;
	case rparen:
		return 4;
	case times:
	case divide:
		return 2;
	case PLUS:
	case MINUS:
		return 1;
	}
	return -1;
}

int outStackPrecedence(Precedence oper) {
	switch (oper) {
	case lparen:
		return 5;
	case rparen:
		return 4;
	case times:
	case divide:
		return 2;
	case PLUS:
	case MINUS:
		return 1;
	}
	return -1;
}

/*
 *                      연산자 우선순위
 * 
 *  연산자      (   |   )   |   *   |   /   |   +   |   -   |
 * ----------------------------------------------------------
 * 스택 내부	0	|	4	|	2	|	2	|	1	|	1	|
 * ----------------------------------------------------------
 * 스택 외부	5	|	4	|	2	|	2	|	1	|	1	|
 * ----------------------------------------------------------
 *
 * 여는 괄호는 ..
 * 스택 외부에서는 괄호로서 우선순위가 가장 높아 발견 즉시 스택에 들어가야 한다.
 * 반면, 스택 내부에서의 여는 괄호는 닫는 괄호가 나올 때에만 스택에서 제거될 수 있기 때문에 우선 순위가 가장 낮아야 한다.
 */

void printToken(ExprToken element) {
	switch (element.type) {
	case lparen:
		printf("(\n");
		break;
	case rparen:
		printf(")\n");
		break;
	case PLUS:
		printf("+\n");
		break;
	case MINUS:
		printf("-\n");
		break;
	case times:
		printf("*\n");
		break;
	case divide:
		printf("/\n");
		break;
	case operand:
		printf("%f\n", element.value);
		break;
	}
}