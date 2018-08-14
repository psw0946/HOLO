#include <iostream>
#include "linkedlist.h"

template <typename T>
LinkedList<T>* LinkedList<T>::createLinkedList() {
	LinkedList<T> *pReturn = NULL;
	int i = 0;

	pReturn = new LinkedList<T>();
	if (pReturn == NULL) { // �޸� �Ҵ�� ����
		printf("�޸� �Ҵ� ���� createLinkedList()\n");
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
				// ��� �� ������ ��ũ �ʱ�ȭ
				*pNewNode = element;
				pNewNode->pLink = NULL;

				pPreNode = &(this->headerNode);
				for (i = 0; i < position; i++) {
					pPreNode = pPreNode->pLink;
				} // ��尡 �߰��� ��ġ�� �̵�

				pNewNode->pLink = pPreNode->pLink;
				pPreNode->pLink = pNewNode; // �߰��� ���� ���� ��� ������ ��ũ �缳��

				this->currentElementCount++;

				ret = TRUE;
			}
			else {
				printf("�޸� �Ҵ� ���� addLLElement()\n");
				return ret;
			}
		}
		else {
			printf("��ġ �ε��� ���� [%d], addLLElement()\n", position);
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
			} // ���ŵ� ��� ��ġ�� �̵�

			pDelNode = pNode->pLink;
			pNode->pLink = pDelNode->pLink; // ���ŵ� ���� ���� ��� ������ ��ũ �缳��

			delete pDelNode;
			this->currentElementCount--;
			ret = TRUE;
		}
		else {
			printf("��ġ �ε��� ���� [%d] removeLLElement()\n", position);
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
		printf("���� ���� ����: %d\n", this->currentElementCount);

		for (i = 0; i < this->currentElementCount; i++) {
			printf("[%d], %d\n", i, getLLElement(i)->data);
		}
	}
	else {
		printf("���Ұ� �����ϴ�.\n");
	}
}