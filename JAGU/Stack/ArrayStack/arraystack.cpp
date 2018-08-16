#include <iostream>
#include "arraystack.h"
using namespace std;

template <typename T>
ArrayStack<T>* ArrayStack<T>::createArrayStack(int size) {
	ArrayStack<T> *pReturn = NULL;
	int i = 0;

	if (size > 0) {
		pReturn = new ArrayStack<T>();
		if (pReturn != NULL) {
			pReturn->maxElementCount = size;
		}
		else {
			printf("�޸� �Ҵ� ���� createArrayStack()\n");
			return NULL;
		}

		pReturn->pElement = new Node<T>[size]; // ��ü ���� �迭 ���� �̷��� �Ѵ�.

		if (pReturn->pElement == NULL) {
			printf("�޸� �Ҵ� ����2 createArrayStack()\n");
			delete pReturn;
			return NULL;
		}
	}
	else {
		printf("����, ������ ũ��� 0 �̻��̾�� �մϴ�\n");
		return NULL;
	}
	return pReturn;
}

template <typename T>
int ArrayStack<T>::pushAS(Node<T> element) {
	int ret = FALSE, i = 0;

	if (this != NULL) {
		if (isArrayStackFull() == FALSE) {
			this->pElement[this->currentElementCount] = element; // �迭�� ���ο� ���� �߰�
			this->currentElementCount++; // ž�� ��ġ�� ����
			ret = TRUE;
		}
	}
	else {
		printf("����, ������ ���� á���ϴ�. pushAS()\n");
	}

	return ret;
}

template <typename T>
Node<T>* ArrayStack<T>::popAS() {
	Node<T>* pReturn = NULL;
	if (this != NULL) {
		if (isArrayStackEmpty() == FALSE) {
			pReturn = new Node<T>();
			if (pReturn != NULL) {
				*pReturn = this->pElement[this->currentElementCount - 1]; // ��� ���� ����
				this->currentElementCount--; // ž ����
			}
			else {
				printf("�޸� �Ҵ� ����, popAS()\n");
			}
		}
	}

	return pReturn;
}

template <typename T>
Node<T>* ArrayStack<T>::peekAS() {
	Node<T>* pReturn = NULL;
	if (this != NULL) {
		if (isArrayStackEmpty() == FALSE) {
			pReturn = &(this->pElement[this->currentElementCount - 1]);
		}
	}
	
	return pReturn;
}

template <typename T>
void ArrayStack<T>::deleteArrayStack() {
	if (this != NULL) {
		if (this->pElement != NULL) {
			delete this->pElement;
		}
		delete this;
	}
}

template <typename T>
int ArrayStack<T>::isArrayStackFull() {
	int ret = FALSE;

	if (this != NULL) {
		if (this->currentElementCount == this->maxElementCount) {
			ret = TRUE;
		}
	}

	return ret;
}

template <typename T>
int ArrayStack<T>::isArrayStackEmpty() {
	int ret = FALSE;

	if (this != NULL) {
		if (this->currentElementCount == 0) {
			ret = TRUE;
		}
	}

	return ret;
}