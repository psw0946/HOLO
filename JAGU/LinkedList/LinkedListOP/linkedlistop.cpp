#include <iostream>
#include "linkedlist.h"
#include "linkedlistop.h"

template <typename T>
void iterateLinkedList(LinkedList<T>* pList) { // displayLinkedList 보다 더 효율적으로
	ListNode<T>* pNode = NULL;
	int count = 0;
	if (pList != NULL) {
		pNode = pList->headerNode.pLink;
		while (pNode != NULL) {
			printf("[%d], %d\n", count, pNode->data);
			count++;

			pNode = pNode->pLink;
		}
		printf("노드 개수: %d\n", count);
	}
	else {
		printf("공백 리스트입니다.");
	}
}

template <typename T>
void concatLinkedList(LinkedList<T>* pListA, LinkedList<T>* pListB) {
	ListNode<T>* pNodeA = NULL;
	ListNode<T>* pNodeB = NULL;

	if (pListA != NULL && pListB != NULL) {
		pNodeA = pListA->headerNode.pLink;
		while (pNodeA->pLink != NULL) {
			pNodeA = pNodeA->pLink;
		} // 연결 리스트 A의 마지막 노드 찾기
		pNodeA->pLink = pListB->headerNode.pLink;
		pListA->currentElementCount += pListB->currentElementCount;

		pListB->headerNode.pLink = NULL;
		pListB->currentElementCount = 0;
	}
}

template <typename T>
void reverseLinkedList(LinkedList<T>* pList) {
	ListNode<T> *pNode = NULL, *pCurrentNode = NULL, *pPrevNode = NULL;

	if (pList != NULL) {
		pNode = pList->headerNode.pLink;
		while (pNode != NULL) {
			/*
			 * 현재 노드와 현재 노드의 이전 노드가 있다면 현재 노드의 다음 노드로의 링크를 이전 노드로의 링크로 재설정해주고 나서 현재 노드의 다음 노드로 이동한다.
			 */
			pPrevNode = pCurrentNode;
			pCurrentNode = pNode;
			pNode = pNode->pLink;
			pCurrentNode->pLink = pPrevNode;
		}
	}
	pList->headerNode.pLink = pCurrentNode;
}