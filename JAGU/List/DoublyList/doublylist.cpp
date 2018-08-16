#include <iostream>
#include "doublylist.h"

template <typename T>
DoublyList<T>* DoublyList<T>::createDoublyList() {
	DoublyList<T>* pReturn = NULL;
	int i = 0;

	pReturn = new DoublyList<T>();
	if (pReturn != NULL) {
		pReturn->headerNode.pLLink = &(pReturn->headerNode);
		pReturn->headerNode.pRLink = &(pReturn->headerNode);
	}
	else {
		printf("메모리할당 오류 createDoublyList()\n");
	}
	return pReturn;
}

template <typename T>
int DoublyList<T>::addDLElement(int position, Node<T> element) {
	int ret = FALSE;
	int i = 0;
	Node<T>* pPreNode = NULL;
	Node<T>* pNewNode = NULL;
	Node<T>* pTempNode = NULL;
	if (this != NULL) {
		if (position >= 0 && position <= this->currentElementCount) {
			pNewNode = new Node<T>();
			if (pNewNode == NULL) {
				printf("메모리 할당 오류 addDLElement()\n");
				return ret;
			}
			*pNewNode = element;
			pNewNode->pLLink = NULL;
			pNewNode->pRLink = NULL;

			pPreNode = &(this->headerNode);
			for (i = 0; i < position; i++) {
				pPreNode = pPreNode->pRLink;
			}

			pNewNode->pLLink = pPreNode;
			pNewNode->pRLink = pPreNode->pRLink;
			pPreNode->pRLink = pNewNode;
			pNewNode->pRLink->pLLink = pNewNode;

			this->currentElementCount++;
			ret = TRUE;
		}
		else {
			printf("위치 인덱스 오류 [%d] addDLElement()\n", position);
		}
	}
	return ret;
}

template <typename T>
int DoublyList<T>::removeDLElement(int position) {
	int ret = FALSE;
	int i = 0, listCount = 0;
	Node<T>* pPreNode = NULL;
	Node<T>* pDelNode = NULL;
	Node<T>* pTempNode = NULL;

	if (this != NULL) {
		listCount = getDoublyListLength();
		if (position >= 0 && position < listCount) {
			pPreNode = &(this->headerNode);
			for (i = 0; i < position; i++) {
				pPreNode = pPreNode->pRLink;
			}
			pDelNode = pPreNode->pRLink;

			pPreNode->pRLink = pDelNode->pRLink;
			pDelNode->pRLink->pLLink = pPreNode;
			delete pDelNode;

			this->currentElementCount--;
			ret = TRUE;
		}
		else {
			printf("위치 인덱스 오류 [%d] removeDLElement()\n", position);
		}
	}
	return ret;
}

template <typename T>
Node<T>* DoublyList<T>::getDLElement(int position) {
	Node<T>* pReturn = NULL;
	int i = 0;
	Node<T>* pNode = NULL;
	if (this != NULL) {
		if (position >= 0 && position < this->currentElementCount) {
			pNode = this->headerNode.pRLink;
			for (i = 0; i < position; i++) {
				pNode = pNode->pRLink;
			}
			pReturn = pNode;
		}
		else {
			printf("위치 인덱스 오류 [%d] getDLElement()\n", position);
		}
	}
	return pReturn;
}

template <typename T>
void DoublyList<T>::displayDoublyList() {
	int i = 0;
	if (this != NULL) {
		printf("현재 노드 개수: %d\n", this->currentElementCount);

		for (i = 0; i < this->currentElementCount; i++) {
			printf("[%d], %d\n", i, getDLElement(i)->data); // T에 따라 다르게 출력하려면 cout 으로 하면 되긴 될듯
		}
	}
	else {
		printf("원소가 없습니다.\n");
	}
}

template <typename T>
void DoublyList<T>::deleteDoublyList() {
	if (this != NULL) {
		clearDoublyList();
		delete this;
	}
}

template <typename T>
void DoublyList<T>::clearDoublyList() {
	if (this != NULL) {
		while (this->currentElementCount > 0) {
			removeDLElement(0);
		}
	}
}

template <typename T>
int DoublyList<T>::getDoublyListLength() {
	int ret = 0;
	if (this != NULL) {
		ret = this->currentElementCount;
	}
	return ret;
}