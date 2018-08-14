#include <iostream>
#include "linkedlist.h"

template <typename T>
LinkedList<T>* LinkedList<T>::createLinkedList() {
	LinkedList<T> *pReturn = NULL;
	int i = 0;

	pReturn = new LinkedList<T>();
	if (pReturn == NULL) { // 메모리 할당과 점검
		printf("메모리 할당 오류 createLinkedList()\n");
		return NULL;
	}

	return pReturn;
}

template <typename T>
T LinkedList<T>::addLLElement(int position, ListNode<T> element) {
	int ret = FALSE;
	int i = 0;
	ListNode<T>* pPreNode = NULL;
	ListNode<T>* pNewNode = NULL;

	if (this != NULL) {
		if (position >= 0 && position <= this->currentElementCount) {
			pNewNode = new ListNode<T>();
			if (pNewNode != NULL) {
				// 노드 값 설정과 링크 초기화
				*pNewNode = element;
				pNewNode->pLink = NULL;

				pPreNode = &(this->headerNode);
				for (i = 0; i < position; i++) {
					pPreNode = pPreNode->pLink;
				} // 노드가 추가될 위치로 이동

				pNewNode->pLink = pPreNode->pLink;
				pPreNode->pLink = pNewNode; // 추가된 노드와 기존 노드 사이의 링크 재설정

				this->currentElementCount++;

				ret = TRUE;
			}
			else {
				printf("메모리 할당 오류 addLLElement()\n");
				return ret;
			}
		}
		else {
			printf("위치 인덱스 오류 [%d], addLLElement()\n", position);
		}
	}
	return ret;
}

template <typename T>
T LinkedList<T>::removeLLElement(int position) {
	int ret = FALSE;
	int i = 0;
	int listCount = 0;
	ListNode<T>* pNode = NULL;
	ListNode<T>* pDelNode = NULL;
	if (this != NULL) {
		listCount = getLinkedListLength();
		if (position >= 0 && position < listCount) {
			pNode = &(this->headerNode);
			for (i = 0; i < position; i++) {
				pNode = pNode->pLink;
			} // 제거될 노드 위치로 이동

			pDelNode = pNode->pLink;
			pNode->pLink = pDelNode->pLink; // 제거될 노드와 기존 노드 사이의 링크 재설정

			delete pDelNode;
			this->currentElementCount--;
			ret = TRUE;
		}
		else {
			printf("위치 인덱스 오류 [%d] removeLLElement()\n", position);
		}
	}
	return ret;
}

template <typename T>
ListNode<T>* LinkedList<T>::getLLElement(int position) {
	ListNode<T>* pReturn = NULL;
	int i = 0;
	ListNode<T>* pNode = NULL;
	if (this != NULL) {
		if (position >= 0 && position < this->currentElementCount) {
			pNode = &(this->headerNode);
			for (i = 0; i <= position; i++) {
				pNode = pNode->pLink;
			}
			pReturn = pNode;
		}
	}
	return pNode;
}

template <typename T>
void LinkedList<T>::deleteLinkedList() {
	int i = 0;
	if (this != NULL) {
		clearLinkedList();
		delete this;
	}
}

template <typename T>
void LinkedList<T>::clearLinkedList() {
	if (this != NULL) {
		while (this->currentElementCount > 0) {
			removeLLElement(0);
		}
	}
}

template <typename T>
T LinkedList<T>::getLinkedListLength() {
	int ret = 0;

	if (this != NULL) {
		ret = this->currentElementCount;
	}

	return ret;
}

template <typename T>
T LinkedList<T>::isEmpty() {
	int ret = FALSE;

	if (this != NULL) {
		if (this->currentElementCount == 0) {
			ret = TRUE;
		}
	}

	return ret;
}

template <typename T>
void LinkedList<T>::displayLinkedList() {
	int i = 0;
	if (this != NULL) {
		printf("현재 원소 개수: %d\n", this->currentElementCount);

		for (i = 0; i < this->currentElementCount; i++) {
			printf("[%d], %d\n", i, getLLElement(i)->data);
		}
	}
	else {
		printf("원소가 없습니다.\n");
	}
}