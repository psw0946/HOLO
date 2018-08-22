#include <iostream>
#include <string.h>
#include "arrayqueue.h"

template <typename T>
ArrayQueue<T>* ArrayQueue<T>::createArrayQueue(int maxElementCount) {
	ArrayQueue<T> *pReturn = NULL;
	int i = 0;

	if (maxElementCount > 0) {
		pReturn = new ArrayQueue<T>();
		if (pReturn != NULL) {
			memset(pReturn, 0, sizeof(pReturn));
			pReturn->maxElementCount = maxElementCount;
			// front, rear ��ġ �ʱ�ȭ
			pReturn->front = -1;
			pReturn->rear = -1;
		}
		else {
			printf("�޸� �Ҵ� ����, createArrayQueue()\n");
			return NULL;
		}
	}
	else {
		printf("����, ť ũ��� 0���� Ŀ�� �մϴ�\n");
		return NULL;
	}
	pReturn->pElement = new Node<T>[maxElementCount];

	if (pReturn->pElement != NULL) {
		memset(pReturn->pElement, 0, sizeof(Node<T>)*maxElementCount);
	}
	else {
		printf("�޸� �Ҵ� ���� 2, createArrayQueue()\n");
		delete pReturn;
		return NULL;
	}
	return pReturn;
}

template <typename T>
int ArrayQueue<T>::enqueueAQ(Node<T> element) {
	int ret = FALSE;
	int i = 0;

	if (this != NULL) {
		if (isArrayQueueFull() == FALSE) {
			this->rear++;
			this->pElement[this->rear] = element;
			this->currentElementCount++;
			ret = TRUE;
		}
		else {
			printf("����, ť�� ���� á���ϴ�, enqueueAQ()\n");
		}
	}

	return ret;
}

template <typename T>
Node<T>* ArrayQueue<T>::dequeueAQ() {
	Node<T>* pReturn = NULL;
	if (this != NULL) {
		if (isArrayQueueEmpty() == FALSE) {
			pReturn = new Node<T>(); // peek�� �޸� ���ο� �޸� �Ҵ�
			if (pReturn != NULL) {
				this->front++;
				pReturn->data = this->pElement[this->front].data;
				this->currentElementCount--;
			}
			else {
				printf("�޸� �Ҵ� ����, dequeueAQ()\n");
			}
		}
	}
	
	return pReturn; // �� ����ϰ� ���� �� ��������� ��.
}
// dequeue�� �޸𸮸� ��ȯ
// peek�� �ܼ��� �����͸� ��ȯ
template <typename T>
Node<T>* ArrayQueue<T>::peekAQ() {
	Node<T> *pReturn = NULL;
	if (this != NULL) {
		if (isArrayQueueEmpty() == FALSE) {
			pReturn = &(this->pElement[this->front + 1]);
		}
	}

	return pReturn;
}

template <typename T>
void ArrayQueue<T>::deleteArrayQueue() {
	if (this != NULL) {
		if (this->pElement != NULL) {
			delete this->pElement;
		}
		delete this;
	}
}

template <typename T>
int ArrayQueue<T>::isArrayQueueFull() {
	int ret = FALSE;

	if (this != NULL) {
		if (this->currentElementCount == this->maxElementCount || this->rear == this->maxElementCount - 1) {
			// dequeue�� ���� ���� ������ �� ���ٸ� rear ��ġ�� �Ǵ��ؾ� ��.
			ret = TRUE;
		}
	}

	return ret;
}

template <typename T>
int ArrayQueue<T>::isArrayQueueEmpty() {
	int ret = FALSE;

	if (this != NULL) {
		if (this->currentElementCount == 0) {
			ret = TRUE;
		}
	}

	return ret;
}