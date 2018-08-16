#include <iostream>
#include "linkedlist.h"
#include "polylist.h"

template <typename T>
int addPolyNodeLast(LinkedList<T>* pList, float coef, int degree) {
	int ret = FALSE, i = 0;

	ListNode<T> node = { 0, };
	node.coef = coef;
	node.degree = degree;

	if (pList != NULL) {
		int length = pList->getLinkedListLength();
		ret = pList->addLLElement(length, node);
	}

	return ret;
}

template <typename T>
LinkedList<T>* polyAdd(LinkedList<T>* pListA, LinkedList<T>* pListB) {
	LinkedList<T>* pReturn = NULL;
	ListNode<T> *pNodeA = NULL, *pNodeB = NULL;
	float coefSum = 0;

	if (pListA != NULL && pListB != NULL) {
		pReturn = pReturn->createLinkedList();
		if (pReturn == NULL) {
			printf("메모리 할당 오류, polyAdd()\n");
			return NULL;
		}

		pNodeA = pListA->headerNode.pLink;
		pNodeB = pListB->headerNode.pLink;
		while (pNodeA != NULL && pNodeB != NULL) { // 다항식 A 또는 다항식 B의 마지막 노드까지 이동하면 루프를 빠져나온다.
			int degreeA = pNodeA->degree;
			int degreeB = pNodeB->degree;
			if (degreeA > degreeB) {
				/*
				 * A의 차수 > B의 차수
				 * 다항식 A의 항을 이용하여 결과 다항식에 새로운 항을 추가
				 * 다항식 A의 다음 항으로 이동
				 */
				coefSum = pNodeA->coef;
				addPolyNodeLast(pReturn, coefSum, degreeA);
				pNodeA = pNodeA->pLink;
			}
			else if (degreeA == degreeB) {
				/*
				 * A의 차수 == B의 차수
				 * 다항식 A와 B의 계수를 더하여 결과 다항식에 새로운 항 추가
				 * 다항식 A와 B 모두 다음 항으로 이동
				 */
				coefSum = pNodeA->coef + pNodeB->coef;
				addPolyNodeLast(pReturn, coefSum, degreeA);
				pNodeA = pNodeA->pLink;
				pNodeB = pNodeB->pLink;
			}
			else {
				/*
				 * A의 차수 < B의 차수
				 * 다항식 B의 항을 이용하여 결과 다항식에 새로운 항을 추가
				 * 다항식 B의 다음 항으로 이동
				 */
				coefSum = pNodeB->coef;
				addPolyNodeLast(pReturn, coefSum, degreeB);
				pNodeB = pNodeB->pLink;
			}
		}
		
		while (pNodeA != NULL) { // 다항식 A에 남은 항이 있다면 남은 항으로 결과 다항식에 새로운 항 추가
			coefSum = pNodeA->coef;
			addPolyNodeLast(pReturn, coefSum, pNodeA->degree);
			pNodeA = pNodeA->pLink;
		}

		while (pNodeB != NULL) { // 다항식 B에 남은 항이 있다면 남은 항으로 결과 다항식에 새로운 항 추가
			coefSum = pNodeB->coef;
			addPolyNodeLast(pReturn, coefSum, pNodeB->degree);
			pNodeB = pNodeB->pLink;
		}
	}
	else {
		printf("오류, NULL 다항식이 전달되었습니다. polyAdd()\n");
	}
	
	return pReturn;
}

template <typename T>
void displayPolyList(LinkedList<T>* pList) {
	int i = 0;
	if (pList != NULL) {
		for (i = 0; i < pList->currentElementCount; i++) {
			ListNode<T>* pNode = pList->getLLElement(i);
			if (pNode != NULL) {
				printf("%4.1fx^%d", pNode->coef, pNode->degree);

				if (i == pList->currentElementCount - 1) {
					printf("\n");
				}
				else {
					printf(" + ");
				}
			}
		}
	}
	else {
		printf("빈 다항식입니다.\n");
	}
}