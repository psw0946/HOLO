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
				printf("메모리 할당 오류 addCLElement()\n");
				return ret;
			}

			// 노드 정보 초기화
			*pNewNode = element;
			pNewNode->pLink = NULL;

			if (position == 0) {
				if (this->currentElementCount == 0) {
					/*
					 * (Case 1-1) 공백 리스트에서 첫 번째 노드를 추가하는 경우
					 */
					this->pLink = pNewNode;
					pNewNode->pLink = pNewNode;
				}
				else {
					/*
					 * (Case 1-2) 공백 리스트가 아닌 원형 연결 리스트에서 첫 번째 노드를 추가하는 경우
					 */
					pLastNode = this->pLink;
					while (pLastNode->pLink != this->pLink) {
						pLastNode = pLastNode->pLink;
					} // 마지막 노드를 찾을 때까지 이동
					this->pLink = pNewNode;
					pNewNode->pLink = pLastNode->pLink;
					pLastNode->pLink = pNewNode;
				}
			}
			else {
				/*
				 * (Case 2) 중간에 노드를 추가하는 경우
				 */
				pPreNode = this->pLink; // pPreNode의 처음 위치가 position 1이기 때문에 for 문에서 '<'를 쓴듯
				for (i = 0; i < position - 1; i++) {
					pPreNode = pPreNode->pLink;
				} // 추가하려는 위치의 이전 노드를 찾을 때까지 이동
				pNewNode->pLink = pPreNode->pLink;
				pPreNode->pLink = pNewNode;
			}
			this->currentElementCount++;
			ret = TRUE;
		}
		else {
			printf("위치 인덱스 오류 [%d] addCLElement()\n", position);
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
					 * (Case 1-1) 마지막 노드이면서 동시에 첫 번째 노드를 제거하는 경우...(원소가 1개인 경우)
					 */
					delete pDelNode;
					this->pLink = NULL;
				}
				else {
					/*
					 * (Case 1-2) 마지막 노드가 아닌 첫 번째 노드를 제거하는 경우
					 */
					pLastNode = this->pLink;
					while (pLastNode->pLink != this->pLink) {
						pLastNode = pLastNode->pLink;
					} // 마지막 노드 찾을 때까지 이동
					pLastNode->pLink = pDelNode->pLink;
					this->pLink = pDelNode->pLink;
					delete pDelNode;
				}
			}
			else {
				/*
				 * (Case 2) 리스트의 중간 노드를 삭제하는 경우
				 */
				pPreNode = this->pLink;
				for (i = 0; i < position - 1; i++) { // LinkedList에서는 headerNode부터 시작하였고, CircularList에서는 시작점이 첫 번째 데이터가 저장되어 있는 노드이기 때문에 for 문의 비교가 살짝 다르다.
					pPreNode = pPreNode->pLink;
				} // 위치 인덱스가 position - 1인 노드까지 이동
				pDelNode = pPreNode->pLink;
				pPreNode->pLink = pDelNode->pLink;
				delete pDelNode;
			}
			this->currentElementCount--;
			ret = TRUE;
		}
		else {
			printf("위치 인덱스 오류 [%d] removeCLElement()\n", position);
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
		printf("메모리할당 오류 createCircularList()\n");
	}
	return pReturn;
}

template <typename T>
void CircularList<T>::displayCircularList() {
	int i = 0;
	if (this != NULL) {
		printf("현재 원소 개수: %d\n", this->currentElementCount);
		for (i = 0; i < this->currentElementCount; i++) {
			printf("[%d], %d\n", i, getCLElement(i)->data);
		}
	}
	else {
		printf("원소가 없습니다.\n");
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