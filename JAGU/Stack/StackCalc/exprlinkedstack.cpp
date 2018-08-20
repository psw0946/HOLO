#include <iostream>
#include "exprdef.h"
#include "exprlinkedstack.h"

LinkedStack* LinkedStack::createLinekdStack() {
	LinkedStack *pReturn = NULL;
	int i = 0;
	pReturn = new LinkedStack();
	if (pReturn == NULL) {
		printf("�޸� �Ҵ� ���� createLinkedStack()\n");
	}
	
	return pReturn;
}

int LinkedStack::pushLS(Node element) {
	int ret = FALSE;
	Node *pNode = NULL;

	if (this != NULL) {
		pNode = new Node();

		if (pNode != NULL) {
			*pNode = element; // ��忡 �ڷ��� �� �Ҵ�
			pNode->pLink = this->pTopElement; // ���� ž ��带 ���� �߰��� ����� ���� ���� ��ũ ����

			this->pTopElement = pNode; // ���ο� ž ���� ��ũ ����
			
			this->currentElementCount++;
			ret = TRUE;
		}
		else {
			printf("�޸� �Ҵ� ����, pushLS()\n");
		}
	}

	return ret;
}

Node* LinkedStack::popLS() {
	Node* pReturn = NULL;
	if (this != NULL) {
		if (isLinkedStackEmpty() == FALSE) {
			pReturn = this->pTopElement; // ��ȯ ��� ����
			this->pTopElement = pReturn->pLink; // ž ��� ����, ��ȯ�Ǵ� ����� ���� ��尡 ���ο� ž ��尡 �ȴ�.
			pReturn->pLink = NULL; // ��ȯ ����� ���� ���� NULL ����
			this->currentElementCount--;
		}
	}
	return pReturn;
	// pop�� ����� �Ŀ� �ݵ�� delete ���־�� �Ѵ�.
}

Node* LinkedStack::peekLS() {
	Node* pReturn = NULL;
	if (this != NULL) {
		if (isLinkedStackEmpty() == FALSE) {
			pReturn = this->pTopElement;
		}
	}

	return pReturn;
}

void LinkedStack::deleteLinkedStack() {
	Node *pNode = NULL;
	Node *pDelNode = NULL;

	if (this != NULL) {
		pNode = this->pTopElement;
		while (pNode != NULL) {
			pDelNode = pNode;
			pNode = pNode->pLink;
			delete pDelNode;
		}
		delete this;
	}
}

int LinkedStack::isLinkedStackFull() {
	int ret = FALSE;
	return ret;
}

int LinkedStack::isLinkedStackEmpty() {
	int ret = FALSE;

	if (this != NULL) {
		if (this->currentElementCount == 0) {
			ret = TRUE;
		}
	}

	return ret;
}