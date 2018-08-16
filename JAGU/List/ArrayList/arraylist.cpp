#include <iostream>
#include "arraylist.h"

template <typename T>
ArrayList<T>* ArrayList<T> :: createArrayList(int maxElementCount) {
	ArrayList<T> *pReturn = NULL;
	int i = 0;

	if (maxElementCount > 0) { // 입력 파라미터 유효성 점검
		pReturn = new ArrayList<T>(); // 메모리 할당 == (ArrayList<T> *)malloc(sizeof(ArrayList<T>));

		if (pReturn != NULL) { // 메모리 할당 점검
			pReturn->maxElementCount = maxElementCount;
			pReturn->currentElementCount = 0;
			pReturn->pElement = NULL;
		}
		else {
			printf("메모리 할당 오류... createArrayList()\n");
			return NULL;
		}
	}
	else {
		printf("최대 원소 개수는 0보다 커야 합니다.\n");
		return NULL;
	}
	
	pReturn->pElement = new T[maxElementCount]; // (T *)malloc(sizeof(T)*maxElementCount);

	if (pReturn->pElement == NULL) { // 원소를 저장하는 배열 메모리 할당 및 점검
		printf("원소 배열 메모리 할당 오류... createArrayList()\n");
		delete pReturn; // == free(pReturn)
		return NULL;
	}
	// memset(pReturn->pElement, 0, sizeof(ArrayListNode) * maxElementCount);

	return pReturn;
}

template <typename T>
int ArrayList<T>::addALElement(int position, T element) {
	int ret = FALSE;
	int i = 0;

	// 입력 파라미터에 대한 유효성 점검
	if (this != NULL) { // 메모리 NULL 여부
		if (isArrayListFull() != TRUE) { // 배열에 새로운 원소 추가 가능 여부
			if (position >= 0 && position <= this->currentElementCount) { // 추가하려는 위치의 인덱스
				for (i = this->currentElementCount - 1; i >= position; i--) {
					this->pElement[i + 1] = this->pElement[i]; // 기존 원소들을 오른쪽으로 한 칸씩 이동시키기
				}
				this->pElement[position] = element; // 새로운 원소 추가 (값 대입)
				this->currentElementCount++;
				ret = TRUE;
			}
			else {
				printf("위치 인덱스 [%d] 범위 초과, addALElement()\n", position);
			}
		}
		else {
			printf("리스트 용량 초과 [%d]/[%d]\n", position, this->maxElementCount);
		}
	}
	return ret;
}

template <typename T>
int ArrayList<T>::removeALElement(int position) {
	int ret = FALSE;
	int i = 0;

	// 입력 파라미터에 대한 유효성 점검
	if (this != NULL) { // 메모리 NULL 여부
		if (position >= 0 && position < this->currentElementCount) { // 제거하려는 위치의 인덱스
			for (i = position; i < this->currentElementCount - 1; i++) {
				this->pElement[i] = this->pElement[i + 1]; // 기존 원소들을 왼쪽으로 한 칸씩 이동
			}
			this->currentElementCount--;
			ret = TRUE;
		}
		else {
			printf("위치 인덱스 [%d] 범위 초과, removeALElement()\n", position);
		}
	}

	return ret;
}

template <typename T>
T ArrayList<T>::getALElement(int position) {
	T* pReturn = NULL;
	
	// 입력 파라미터에 대한 유효성 점검
	if (this != NULL) { // 메모리 NULL 여부
		if (position >= 0 && position < getArrayListLength()) {
			pReturn = &(this->pElement[position]);
		}
		else {
			printf("위치 인덱스 [%d] 범위 초과, getALElement()\n", position);
		}
	}

	return *pReturn;
}

template <typename T>
void ArrayList<T>::displayArrayList() {
	int i = 0;
	if (this != NULL) {
		printf("최대 원소 개수: %d\n", this->maxElementCount);
		printf("현재 원소 개수: %d\n", this->currentElementCount);

		for (i = 0; i < this->currentElementCount; i++) {
			printf("[%d], %d\n", i, getALElement(i));
		} // 현재 저장된 원소의 값을 출력

		i = this->currentElementCount;
		for (; i < this->maxElementCount; i++) {
			printf("[%d], Empty\n", i);
		}
	}
	else {
		printf("ArrayList is NULL\n");
	}
}

template <typename T>
int ArrayList<T>::isArrayListFull() {
	int ret = FALSE;

	if (this != NULL) {
		if (this->currentElementCount == this->maxElementCount) {
			ret = TRUE;
		}
	}
	
	return ret;
}

template <typename T>
int ArrayList<T>::getArrayListLength() {
	int ret = 0;

	if (this != NULL) {
		ret = this->currentElementCount;
	}

	return ret;
}

template <typename T>
void ArrayList<T>::deleteArrayList() {
	int i = 0;
	if (this != NULL) {
		delete this->pElement;
		delete this;
	}
}

template <typename T>
int ArrayList<T>::addALElementFirst(int element) {
	int position = 0;
	return addALElement(position, element);
}

template <typename T>
int ArrayList<T>::addALElementLast(int element) {
	int ret = FALSE;
	int position = 0;
	if (this != NULL) {
		position = getArrayListLength(this);
		ret = addALElement(this, position, element);
	}
	return ret;
}