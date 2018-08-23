#include <iostream>
#include <string.h>
#include "linkedqueue.h"

template <typename T>
LinkedQueue<T>* LinkedQueue<T>::createLinkedQueue() {
	LinkedQueue<T> *pReturn = NULL;
	int i = 0;

	pReturn = new LinkedQueue<T>();
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(LinkedQueue<T>));
	}
	else {
		printf("메모리 할당 오류, createLinkedQueue()\n");
	}
	return pReturn;
}

template <typename T>
int LinkedQueue<T>::enqueueLQ(Node<T> element) {
	int ret = FALSE;
	Node<T> *pNode = NULL;

	if (this != NULL) {
		pNode = new Node<T>();
		if (pNode != NULL) {
			*pNode = element; // 새로운 자료값 대입
			pNode->pLink = NULL; // 다음 노드링크를 NULL로 설정

			if (isLinkedQueueEmpty() == TRUE) {
				this->pFrontNode = pNode;
				this->pRearNode = pNode;
			}
			else {
				this->pRearNode->pLink = pNode;
				this->pRearNode = pNode;
			}

			this->currentElementCount++;
			ret = TRUE;
		}
		else {
			printf("메모리 할당 오류, enqueueLQ()\n");
		}
	}

	return ret;
}

template <typename T>
Node<T>* LinkedQueue<T>::dequeueLQ() {
	Node<T>* pReturn = NULL;
	if (this != NULL) {
		if (isLinkedQueueEmpty() == FALSE) {
			pReturn = this->pFrontNode;
			this->pFrontNode = this->pFrontNode->pLink;
			pReturn->pLink = NULL;

			this->currentElementCount--;
			if (isLinkedQueueEmpty() == TRUE) { // 남은 노드가 1개였던 경우
				this->pRearNode = NULL;
			}
		}
	}

	return pReturn;
}

template <typename T>
Node<T>* LinkedQueue<T>::peekLQ() {
	Node<T>* pReturn = NULL;
	if (this != NULL) {
		if (isLinkedQueueEmpty() == FALSE) {
			pReturn = this->pFrontNode;
		}
	}
	return pReturn;
}

template <typename T>
void LinkedQueue<T>::deleteLinkedQueue() {
	Node<T> *pNode = NULL;
	Node<T> *pDelNode = NULL;

	if (this != NULL) {
		pNode = this->pFrontNode;
		while (pNode != NULL) {
			pDelNode = pNode;
			pNode = pNode->pLink;

			delete pDelNode;
		}
		delete pQeuue;
	}
}

template <typename T>
int LinkedQueue<T>::isLinkedQueueFull() {
	int ret = FALSE;
	return ret;
}

template <typename T>
int LinkedQueue<T>::isLinkedQueueEmpty() {
	int ret = FALSE;

	if (this != NULL) {
		if (this->currentElementCount == 0) {
			ret = TRUE;
		}
	}

	return ret;
}