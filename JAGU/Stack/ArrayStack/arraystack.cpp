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
			printf("메모리 할당 오류 createArrayStack()\n");
			return NULL;
		}

		pReturn->pElement = new Node<T>[size]; // 객체 동적 배열 생성 이렇게 한다.

		if (pReturn->pElement == NULL) {
			printf("메모리 할당 오류2 createArrayStack()\n");
			delete pReturn;
			return NULL;
		}
	}
	else {
		printf("오류, 스택의 크기는 0 이상이어야 합니다\n");
		return NULL;
	}
	return pReturn;
}

template <typename T>
int ArrayStack<T>::pushAS(Node<T> element) {
	int ret = FALSE, i = 0;

	if (this != NULL) {
		if (isArrayStackFull() == FALSE) {
			this->pElement[this->currentElementCount] = element; // 배열의 새로운 원소 추가
			this->currentElementCount++; // 탑의 우치ㅣ 변경
			ret = TRUE;
		}
	}
	else {
		printf("오류, 스택이 가득 찼습니다. pushAS()\n");
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
				*pReturn = this->pElement[this->currentElementCount - 1]; // 노드 내용 복사
				this->currentElementCount--; // 탑 변경
			}
			else {
				printf("메모리 할당 오류, popAS()\n");
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