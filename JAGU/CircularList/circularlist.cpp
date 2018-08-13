#include <iostream>
#include "circularlist.h"
using namespace std;

template <typename T>
T CircularList<T>::addCLElement(int position, Node<T> element) {
	int ret = FALSE;
	int i = 0;
	Node<T>* pPreNode = NULL;
	Node<T>* pNewNode = NULL;
	Node<T>* pLastNode = NULL;
	if (this != NULL) {
		if (position >= 0 && position <= this->currentElementCount) {
			pNewNode = new Node<T>();
			if (pNewNode == NULL) {
				printf("�޸� �Ҵ� ���� addCLElement()\n");
				return ret;
			}

			// ��� ���� �ʱ�ȭ
			*pNewNode = element;
			pNewNode->pLink = NULL;

			if (position == 0) {
				if (this->currentElementCount == 0) {
					/*
					 * (Case 1-1) ���� ����Ʈ���� ù ��° ��带 �߰��ϴ� ���
					 */
					this->pLink = pNewNode;
					pNewNode->pLink = pNewNode;
				}
				else {
					/*
					 * (Case 1-2) ���� ����Ʈ�� �ƴ� ���� ���� ����Ʈ���� ù ��° ��带 �߰��ϴ� ���
					 */
					pLastNode = this->pLink;
					while (pLastNode->pLink != this->pLink) {
						pLastNode = pLastNode->pLink;
					} // ������ ��带 ã�� ������ �̵�
					this->pLink = pNewNode;
					pNewNode->pLink = pLastNode->pLink;
					pLastNode->pLink = pNewNode;
				}
			}
			else {
				/*
				 * (Case 2) �߰��� ��带 �߰��ϴ� ���
				 */
				pPreNode = this->pLink; // pPreNode�� ó�� ��ġ�� position 1�̱� ������ for ������ '<'�� ����
				for (i = 0; i < position - 1; i++) {
					pPreNode = pPreNode->pLink;
				} // �߰��Ϸ��� ��ġ�� ���� ��带 ã�� ������ �̵�
				pNewNode->pLink = pPreNode->pLink;
				pPreNode->pLink = pNewNode;
			}
			this->currentElementCount++;
			ret = TRUE;
		}
		else {
			printf("��ġ �ε��� ���� [%d] addCLElement()\n", position);
		}
	}
	return ret;
}

template <typename T>
T CircularList<T>::removeCLElement(int position) {
	int ret = FALSE;
	int i = 0, listCount = 0;
	Node<T>* pPreNode = NULL;
	Node<T>* pDelNode = NULL;
	Node<T>* pLastNode = NULL;

	if (this != NULL) {
		listCount = getCircularListLength();
		if (position >= 0 && position < listCount) {
			if (position == 0) {
				pDelNode = this->pLink;
				if (listCount == 1) {
					/*
					 * (Case 1-1) ������ ����̸鼭 ���ÿ� ù ��° ��带 �����ϴ� ���...(���Ұ� 1���� ���)
					 */
					delete pDelNode;
					this->pLink = NULL;
				}
				else {
					/*
					 * (Case 1-2) ������ ��尡 �ƴ� ù ��° ��带 �����ϴ� ���
					 */
					pLastNode = this->pLink;
					while (pLastNode->pLink != this->pLink) {
						pLastNode = pLastNode->pLink;
					} // ������ ��� ã�� ������ �̵�
					pLastNode->pLink = pDelNode->pLink;
					this->pLink = pDelNode->pLink;
					delete pDelNode;
				}
			}
			else {
				/*
				 * (Case 2) ����Ʈ�� �߰� ��带 �����ϴ� ���
				 */
				pPreNode = this->pLink;
				for (i = 0; i < position - 1; i++) { // LinkedList������ headerNode���� �����Ͽ���, CircularList������ �������� ù ��° �����Ͱ� ����Ǿ� �ִ� ����̱� ������ for ���� �񱳰� ��¦ �ٸ���.
					pPreNode = pPreNode->pLink;
				} // ��ġ �ε����� position - 1�� ������ �̵�
				pDelNode = pPreNode->pLink;
				pPreNode->pLink = pDelNode->pLink;
				delete pDelNode;
			}
			this->currentElementCount--;
			ret = TRUE;
		}
		else {
			printf("��ġ �ε��� ���� [%d] removeCLElement()\n", position);
		}
	}
	return ret;
}

template <typename T>
Node<T>* CircularList<T>::getCLElement(int position) {
	int i = 0;
	Node<T>* pNode = NULL;
	if (this != NULL) {
		if (position >= 0 && position < this->currentElementCount) {
			pNode = this->pLink;
			for (i = 0; i < position; i++) {
				pNode = pNode->pLink;
			}
		}
	}
	return pNode;
}

template <typename T>
CircularList<T>* CircularList<T>::createCircularList() {
	CircularList<T>* pReturn = NULL;
	int i = 0;

	pReturn = new CircularList<T>();
	if (pReturn == NULL) {
		printf("�޸��Ҵ� ���� createCircularList()\n");
	}
	return pReturn;
}

template <typename T>
void CircularList<T>::displayCircularList() {
	int i = 0;
	if (this != NULL) {
		printf("���� ���� ����: %d\n", this->currentElementCount);
		for (i = 0; i < this->currentElementCount; i++) {
			printf("[%d], %d\n", i, getCLElement(i)->data);
		}
	}
	else {
		printf("���Ұ� �����ϴ�.\n");
	}
}

template <typename T>
T CircularList<T>::getCircularListLength() {
	int ret = 0;
	if (this != NULL) {
		ret = this->currentElementCount;
	}
	return ret;
}

template <typename T>
void CircularList<T>::deleteCircularList() {
	int i = 0;
	if (this != NULL) {
		clearCircularList();
		delete this;
	}
}

template <typename T>
void CircularList<T>::clearCircularList() {
	if (this != NULL) {
		while (this->currentElementCount > 0) {
			removeCLElement(0);
		}
	}
}