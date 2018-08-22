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
			// front, rear 위치 초기화
			pReturn->front = -1;
			pReturn->rear = -1;
		}
		else {
			printf("메모리 할당 오류, createArrayQueue()\n");
			return NULL;
		}
	}
	else {
		printf("오류, 큐 크기는 0보다 커야 합니다\n");
		return NULL;
	}
	pReturn->pElement = new Node<T>[maxElementCount];

	if (pReturn->pElement != NULL) {
		memset(pReturn->pElement, 0, sizeof(Node<T>)*maxElementCount);
	}
	else {
		printf("메모리 할당 오류 2, createArrayQueue()\n");
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
			printf("오류, 큐가 가득 찼습니다, enqueueAQ()\n");
		}
	}

	return ret;
}

template <typename T>
Node<T>* ArrayQueue<T>::dequeueAQ() {
	Node<T>* pReturn = NULL;
	if (this != NULL) {
		if (isArrayQueueEmpty() == FALSE) {
			pReturn = new Node<T>(); // peek과 달리 새로운 메모리 할당
			if (pReturn != NULL) {
				this->front++;
				pReturn->data = this->pElement[this->front].data;
				this->currentElementCount--;
			}
			else {
				printf("메모리 할당 오류, dequeueAQ()\n");
			}
		}
	}
	
	return pReturn; // 다 사용하고 나서 꼭 해제해줘야 함.
}
// dequeue는 메모리를 반환
// peek은 단순히 포인터만 반환
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
			// dequeue로 인해 현재 개수가 얼마 없다면 rear 위치로 판단해야 함.
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