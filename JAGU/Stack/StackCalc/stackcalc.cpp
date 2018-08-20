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
 * 1. �ǿ����ڸ� ������ ���ÿ� Ǫ���Ѵ�.
 * 2. �����ڸ� ������ ���꿡 �ʿ��� ������ŭ (���� 2��) �ǿ����ڸ� ���ÿ��� ���Ѵ�.
 * 3. ������ ����� �ٽ� ���ÿ� Ǫ���Ѵ�.
 */
void calcExpr(ExprToken *pExprTokens, int tokenCount) { // ����ǥ����� �޾� ���ó��
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

			if (tokenType == operand) { // �ǿ����ڸ� ������ ���ÿ� Ǫ���Ѵ�.
				pushLSExprToken(pStack, pExprTokens[i]);
			}
			else {
				pNode2 = pStack->popLS();
				if (pNode2 != NULL) { // ���꿡 �ʿ��� ������ŭ 2���� �ǿ����ڸ� ���ÿ��� ���Ѵ�.
					pNode1 = pStack->popLS();
					if (pNode1 != NULL) {
						float op1 = pNode1->data.value;
						float op2 = pNode2->data.value;

						ExprToken newToken;
						newToken.type = operand;
						switch (tokenType) { // ������ ������ ���� ������ �ǽ��Ѵ�. ���� ����� ���ο� ��ū newToken�� ����ȴ�.
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

						pushLSExprToken(pStack, newToken); // ������ ����� �ٽ� ���ÿ� Ǫ���Ѵ�.
						
						delete pNode1;
					}
					delete pNode2;
				}
			} // end-of-else
		}

		pNode1 = pStack->popLS(); // ������ ���� ó�� ��� ���� ���ÿ��� ���Ѵ�.
		if (pNode1 != NULL) {
			printf("���� ��� ��� [%f]\n", pNode1->data.value);
			delete pNode1;
		}
		else {
			printf("���Ŀ� ������ �ֽ��ϴ�.\n");
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
			case operand: // �ǿ����ڸ� ������ �ٷ� ���
				printf("%f\n", pExprTokens[i].value);
				break;
			case rparen: // �ݴ� ��ȣ ) �����ڸ� ���� ��� ó��. ��, ���� ��ȣ ( �����ڸ� ���� ������ while ������ ���鼭, ���� ���� �����ڵ��� ���ϰ� ����Ѵ�.
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
				 * �ݴ� ��ȣ ) ������ �̿��� �������� ��� ó��
				 * ���� ���� ����� �����ڵ� �� ���� �����ں��� �켱������ ���� �����ڴ� ��(pop) & ����Ѵ�.
				 * �׸��� ����, ���� �����ڸ� ���ÿ� Ǫ��
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

		while (pStack->isLinkedStackEmpty() == FALSE) { // ���ÿ� ���� �����ڵ��� ���ϰ� ����Ѵ�.
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
 *                      ������ �켱����
 * 
 *  ������      (   |   )   |   *   |   /   |   +   |   -   |
 * ----------------------------------------------------------
 * ���� ����	0	|	4	|	2	|	2	|	1	|	1	|
 * ----------------------------------------------------------
 * ���� �ܺ�	5	|	4	|	2	|	2	|	1	|	1	|
 * ----------------------------------------------------------
 *
 * ���� ��ȣ�� ..
 * ���� �ܺο����� ��ȣ�μ� �켱������ ���� ���� �߰� ��� ���ÿ� ���� �Ѵ�.
 * �ݸ�, ���� ���ο����� ���� ��ȣ�� �ݴ� ��ȣ�� ���� ������ ���ÿ��� ���ŵ� �� �ֱ� ������ �켱 ������ ���� ���ƾ� �Ѵ�.
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