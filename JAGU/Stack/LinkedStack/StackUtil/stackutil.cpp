#include <iostream>
#include "linkedstack.cpp"
#include "stackutil.h"
using namespace std;

char* reverseString(char *pSource) {
	char* pReturn = NULL;
	int i = 0, size = 0;
	LinkedStack<char> *pStack = NULL;
	Node<char> *pNode = NULL;

	if (pSource == NULL) {
		return NULL;
	}

	size = strlen(pSource);
	if (size == 0) {
		return NULL;
	}

	pReturn = new char[size + 1];
	if (pReturn == NULL) {
		printf("�޸� �Ҵ� ����, reverseString()\n");
		return NULL;
	}

	pStack = pStack->createLinekdStack();
	if (pStack != NULL) {
		Node<char> node;
		for (i = 0; i < size; i++) {
			node.data = pSource[i];
			pStack->pushLS(node);
		} // ���ڿ��� ���ڵ��� ���ÿ� Ǫ��

		for (i = 0; i < size; i++) {
			pNode = pStack->popLS();
			if (pNode != NULL) {
				pReturn[i] = pNode->data;
				delete pNode;
			}
		} // ���ÿ��� ���� �Ͽ� ���� ���ڿ� ����
		pReturn[i] = '\0'; // ��� ���ڿ��� ���� �������� �� ���� ����

		pStack->deleteLinkedStack();
	}
	else {
		if (pReturn != NULL) {
			delete pReturn;
			pReturn = NULL;
		}
	}

	return pReturn;
}

int checkBracketMatching(char *pSource) {
	int ret = TRUE, i = 0, size = 0;
	char symbol = '\0', checkSymbol = '\0';
	LinkedStack<char> *pStack = NULL;
	Node<char> *pNode = NULL;

	if (pSource == NULL) {
		ret = TRUE;
		return ret;
	}

	size = strlen(pSource);
	if (size == 0) {
		ret = TRUE;
		return ret;
	}

	pStack = pStack->createLinekdStack();
	if (pStack != NULL) {
		Node<char> node;
		for (i = 0; i < size && ret == TRUE; i++) {
			symbol = pSource[i];

			switch (symbol) {
			case '(':
			case '[':
			case '{':
				node.data = symbol;
				pStack->pushLS(node);
				break;
			case ')':
			case ']':
			case '}':
				pNode = pStack->popLS();
				if (pNode == NULL) {
					ret = FALSE;
					break;
				}
				else {
					checkSymbol = pNode->data;
					if ((symbol == ')' && checkSymbol == '(') || (symbol == ']' && checkSymbol == '[') || (symbol == '}' && checkSymbol == '{')) {
						// Right case. Do Nothing.
					}
					else {
						ret = FALSE;
					}
					delete pNode;
				}
				break;
			} // end-of-switch
		} // end-of-for
		if (pStack->isLinkedStackEmpty() == FALSE) {
			ret = FALSE;
		} // ���ÿ� ���� �ִ� ��尡 ������ ����.
		pStack->deleteLinkedStack();
	}
	else {
		printf("����, LinkedStack�� NULL�Դϴ�. checkBracketMatching()\n");
		ret = FALSE;
	}

	return ret;
}