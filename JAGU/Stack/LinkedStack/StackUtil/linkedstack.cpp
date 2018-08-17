#include <iostream>
#include "linkedstack.h"

template <typename T>
LinkedStack<T>* LinkedStack<T>::createLinekdStack() {
	LinkedStack<T> *pReturn = NULL;
	int i = 0;
	pReturn = new LinkedStack<T>();
	if (pReturn == NULL) {
		printf("메모리 할당 오류 createLinkedStack()\n");
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
			*pNode = element; // 노드에 자료의 값 할당
			pNode->pLink = this->pTopElement; // 기존 탑 노드를 새로 추가된 노드의 다음 노드로 링크 설정

			this->pTopElement = pNode; // 새로운 탑 노드로 링크 변경
			
			this->currentElementCount++;
			ret = TRUE;
		}
		else {
			printf("메모리 할당 오류, pushLS()\n");
		}
	}

	return ret;
}

template <typename T>
Node<T>* LinkedStack<T>::popLS() {
	Node<T>* pReturn = NULL;
	if (this != NULL) {
		if (isLinkedStackEmpty() == FALSE) {
			pReturn = this->pTopElement; // 반환 노드 설정
			this->pTopElement = pReturn->pLink; // 탑 노드 변경, 반환되는 노드의 다음 노드가 새로운 탑 노드가 된다.
			pReturn->pLink = NULL; // 반환 노드의 다음 노드로 NULL 설정
			this->currentElementCount--;
		}
	}
	return pReturn;
	// pop을 사용한 후에 반드시 delete 해주어야 한다.
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