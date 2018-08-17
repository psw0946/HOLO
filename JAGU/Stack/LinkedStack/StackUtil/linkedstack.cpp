#include <iostream>
#include "linkedstack.h"

template <typename T>
LinkedStack<T>* LinkedStack<T>::createLinekdStack() {
	LinkedStack<T> *pReturn = NULL;
	int i = 0;
	pReturn = new LinkedStack<T>();
	if (pReturn == NULL) {
		printf("�޸� �Ҵ� ���� createLinkedStack()\n");
	}
	
	return pReturn;
}

template <typename T>
int LinkedStack<T>::pushLS(Node<T> element) {
	int ret = FALSE;
	Node<T> *pNode = NULL;

	if (this != NULL) {
		pNode = new Node<T>();

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

template <typename T>
Node<T>* LinkedStack<T>::popLS() {
	Node<T>* pReturn = NULL;
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

template <typename T>
Node<T>* LinkedStack<T>::peekLS() {
	Node<T>* pReturn = NULL;
	if (this != NULL) {
		if (isLinkedStackEmpty() == FALSE) {
			pReturn = this->pTopElement;
		}
	}

	return pReturn;
}

template <typename T>
void LinkedStack<T>::deleteLinkedStack() {
	Node<T> *pNode = NULL;
	Node<T> *pDelNode = NULL;

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

template <typename T>
int LinkedStack<T>::isLinkedStackFull() {
	int ret = FALSE;
	return ret;
}

template <typename T>
int LinkedStack<T>::isLinkedStackEmpty() {
	int ret = FALSE;

	if (this != NULL) {
		if (this->currentElementCount == 0) {
			ret = TRUE;
		}
	}

	return ret;
}