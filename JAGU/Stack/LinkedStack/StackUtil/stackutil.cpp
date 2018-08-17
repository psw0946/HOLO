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
		printf("메모리 할당 오류, reverseString()\n");
		return NULL;
	}

	pStack = pStack->createLinekdStack();
	if (pStack != NULL) {
		Node<char> node;
		for (i = 0; i < size; i++) {
			node.data = pSource[i];
			pStack->pushLS(node);
		} // 문자열의 문자들을 스택에 푸시

		for (i = 0; i < size; i++) {
			pNode = pStack->popLS();
			if (pNode != NULL) {
				pReturn[i] = pNode->data;
				delete pNode;
			}
		} // 스택에서 팝을 하여 역순 문자열 생성
		pReturn[i] = '\0'; // 결과 문자열의 제일 마지막에 널 문자 삽입

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
		} // 스택에 남아 있는 노드가 있으면 오류.
		pStack->deleteLinkedStack();
	}
	else {
		printf("오류, LinkedStack이 NULL입니다. checkBracketMatching()\n");
		ret = FALSE;
	}

	return ret;
}