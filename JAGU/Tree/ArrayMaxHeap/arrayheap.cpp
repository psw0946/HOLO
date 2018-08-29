#include "arrayheap.h"
#include <string.h>
#include <iostream>

ArrayMaxHeap* ArrayMaxHeap::createArrayMaxHeap(int maxElementCount) {
	ArrayMaxHeap *pReturn = NULL;
	int i = 0;

	if (maxElementCount > 0) {
		pReturn = new ArrayMaxHeap();
		if (pReturn != NULL) {
			pReturn->maxElementCount = maxElementCount;
			pReturn->currentElementCount = 0;
			pReturn->pElement = new Node[maxElementCount + 1]; // 위치 인덱스 0번은 사용하지 않음.

			if (pReturn->pElement == NULL) {
				printf("메모리 할당 오류2, createArrayList()\n");
				delete pReturn;
				return NULL;
			}

			memset(pReturn->pElement, 0, sizeof(Node)*(maxElementCount + 1));
		}
		else {
			printf("메모리 할당 오류, createArrayList()\n");
		}
	}
	else {
		printf("최대 원소 개수는 0보다 커야 합니다.\n");
	}

	return pReturn;
}

void ArrayMaxHeap::insertMaxHeapAH(Node element) {
	int i = 0;

	if (this != NULL) {
		if (this->currentElementCount == this->maxElementCount) {
			printf("히프가 가득 찼습니다. [%d], insertMaxHeapAH()\n", this->maxElementCount);
			return;
		}

		this->currentElementCount++;
		i = this->currentElementCount;
		while ((i != 1) && (element.key > this->pElement[i / 2].key)) {
			// 부모 노드와 키 값 비교하면서 이동
			this->pElement[i] = this->pElement[i / 2];
			i /= 2;
		}
		this->pElement[i] = element;
	}
}

// 반환되는 노드 Node의 메모리를 할당하여 전달하기 때문에, 반환된 노드의 사용이 끝난 다음에는 반드시 메모리를 해제시켜야 한다.
Node* ArrayMaxHeap::deleteMaxHeapAH() {
	Node* pReturn = NULL;
	Node* pTemp = NULL;

	int i = 0;
	int parent = 0, child = 0;

	if (this != NULL && this->currentElementCount > 0) {
		pReturn = new Node();
		if (pReturn == NULL) {
			printf("메모리 할당 오류, deleteMaxHeapAH()\n");
			return NULL;
		}
		*pReturn = this->pElement[1]; // 루트 노드가 반환되는 노드. 반환되는 노드의 값으로 기존 루트 노드의 값을 대입

		i = this->currentElementCount; // 히프의 제일 마지막 위치 인덱스
		pTemp = &(this->pElement[i]); // 히프의 제일 마지막 노드를 가리킴.
		this->currentElementCount--;

		// 루프가 시작되는 곳은 루트 노드(인덱스 1)와 루트 노드의 왼쪽 자식 노드(인덱스 2)
		parent = 1;
		child = 2;
		while (child <= this->currentElementCount) {
			// 히프의 제일 마지막 위치에 있는 노드를 만날 때까지 루프
			if ((child < this->currentElementCount) && this->pElement[child].key < this->pElement[child + 1].key) {
				// 왼쪽 자식 노드보다 오른쪽 자식 노드의 키 값이 더 크다면,
				// 오른쪽 자식 노드가 비교 대상이 되도록 위치 인덱스 child를 수정한다.
				child++;
			}
			if (pTemp->key >= this->pElement[child].key) {
				// 앞서 설정한 히프의 제일 마지막 노드와 현재 노드의 키 값을 비교
				// 만약, 마지막 노드의 키 값이 현재 노드 보다 더 크거나 같다면, 루프를 빠져 나온다.
				// 바로 이 위치에서 삽입하면 된다.
				break;
			}
			this->pElement[parent] = this->pElement[child];
			parent = child;
			child *= 2;
		}
		this->pElement[parent] = *pTemp;
	}

	return pReturn;
}

void ArrayMaxHeap::deleteArrayMaxHeap() {
	if (this != NULL) {
		if (this->pElement != NULL) {
			delete this->pElement;
		}
		delete this;
	}
}