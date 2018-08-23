#include <iostream>
#include <string.h>
#include "linkeddeque.h"

template <typename T>
LinkedDeque<T>* LinkedDeque<T>::createLinkedQueue() {
	LinkedDeque<T> *pReturn = NULL;
	int i = 0;

	pReturn = new LinkedDeque<T>();
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(LinkedDeque<T>));
	}
	else {
		printf("메모리 할당 오류, createLinkedDeque()\n");
		return NULL;
	}

	return pReturn;
}

template <typename T>
int LinkedDeque<T>::insertFrontLD(Node<T> element) {
	int ret = FALSE;
	Node<T> *pNode = NULL;

	if (this != NULL) {
		pNode = new Node<T>();
		if (pNode != NULL) {
			*pNode = element;
			pNode->pLLink = NULL;
			pNode->pRLink = NULL;

			if (isLinkedDequeEmpty() == TRUE) {
				this->pFrontNode = pNode;
				this->pRearNode = pNode;
			}
			else {
				this->pFrontNode->pLLink = pNode;
				pNode->pRLink = this->pFrontNode;
				this->pFrontNode = pNode;
			}

			this->currentElementCount++;
			ret = TRUE;
		}
		else {
			printf("메모리 할당 오류, insertFrontLD()\n");
		}
	}

	return ret;
}

template <typename T>
int LinkedDeque<T>::insertRearLD(Node<T> element) {
	int ret = FALSE;
	Node<T> *pNode = NULL;

	if (this != NULL) {
		pNode = new Node<T>();
		if (pNode != NULL) {
			*pNode = element;
			pNode->pLLink = NULL;
			pNode->pRLink = NULL;

			if (isLinkedDequeEmpty() == TRUE) {
				this->pFrontNode = pNode;
				this->pRearNode = pNode;
			}
			else {
				this->pRearNode->pRLink = pNode;
				pNode->pLLink = this->pRearNode;
				this->pRearNode = pNode;
			}

			this->currentElementCount++;
			ret = TRUE;
		}
		else {
			printf("메모리 할당 오류, insertRearLD()\n");
		}
	}

	return ret;
}

template <typename T>
Node<T>* LinkedDeque<T>::deleteFrontLD() {
	Node<T>* pReturn = NULL;
	if (this != NULL) {
		if (isLinkedDequeEmpty() == FALSE) {
			pReturn = this->pFrontNode;
			this->pFrontNode = this->pFrontNode->pRLink;
			pReturn->pRLink = NULL;

			this->currentElementCount--;
			if (isLinkedDequeEmpty() == TRUE) { // 덱에 노드가 1개 남아 있었던 경우
				this->pRearNode = NULL;
			}
			else {
				this->pFrontNode->pLLink = NULL;
			}
		}
	}

	return pReturn;
}

template <typename T>
Node<T>* LinkedDeque<T>::peekFrontLD() {
	Node<T>* pReturn = NULL;
	if (this != NULL) {
		if (isLinkedDequeEmpty() == FALSE) {
			pReturn = this->pFrontNode;
		}
	}

	return pReturn;
}

template <typename T>
Node<T>* LinkedDeque<T>::deleteRearLD() {
	Node<T>* pReturn = NULL;
	if (this != NULL) {
		if (isLinkedDequeEmpty() == FALSE) {
			pReturn = this->pRearNode;
			this->pRearNode = this->pRearNode->pLLink;
			pReturn->pLLink = NULL;

			this->currentElementCount--;
			if (isLinkedDequeEmpty() == TRUE) {
				this->pFrontNode = NULL;
			}
			else {
				this->pRearNode->pRLink = NULL;
			}
		}
	}

	return pReturn;
}

template <typename T>
Node<T>* LinkedDeque<T>::peekRearLD() {
	Node<T>* pReturn = NULL;
	if (this != NULL) {
		if (isLinkedDequeEmpty() == FALSE) {
			pReturn = this->pRearNode;
		}
	}
	return pReturn;
}

template <typename T>
void LinkedDeque<T>::deleteLinkedDeque() {
	Node<T> *pNode = NULL;
	Node<T> *pDelNode = NULL;

	if (this != NULL) {
		pNode = this->pFrontNode;
		while (pNode != NULL) {
			pDelNode = pNode;
			pNode = pNode->pRLink;
			delete pNode;
		}
		delete this;
	}
}

template <typename T>
int LinkedDeque<T>::isLinkedDequeFull() {
	int ret = FALSE;
	return ret;
}

template <typename T>
int LinkedDeque<T>::isLinkedDequeEmpty() {
	int ret = FALSE;
	if (this != NULL) {
		if (this->currentElementCount == 0) {
			ret = TRUE;
		}
	}

	return ret;
}