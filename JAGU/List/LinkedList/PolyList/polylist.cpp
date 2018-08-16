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
			printf("�޸� �Ҵ� ����, polyAdd()\n");
			return NULL;
		}

		pNodeA = pListA->headerNode.pLink;
		pNodeB = pListB->headerNode.pLink;
		while (pNodeA != NULL && pNodeB != NULL) { // ���׽� A �Ǵ� ���׽� B�� ������ ������ �̵��ϸ� ������ �������´�.
			int degreeA = pNodeA->degree;
			int degreeB = pNodeB->degree;
			if (degreeA > degreeB) {
				/*
				 * A�� ���� > B�� ����
				 * ���׽� A�� ���� �̿��Ͽ� ��� ���׽Ŀ� ���ο� ���� �߰�
				 * ���׽� A�� ���� ������ �̵�
				 */
				coefSum = pNodeA->coef;
				addPolyNodeLast(pReturn, coefSum, degreeA);
				pNodeA = pNodeA->pLink;
			}
			else if (degreeA == degreeB) {
				/*
				 * A�� ���� == B�� ����
				 * ���׽� A�� B�� ����� ���Ͽ� ��� ���׽Ŀ� ���ο� �� �߰�
				 * ���׽� A�� B ��� ���� ������ �̵�
				 */
				coefSum = pNodeA->coef + pNodeB->coef;
				addPolyNodeLast(pReturn, coefSum, degreeA);
				pNodeA = pNodeA->pLink;
				pNodeB = pNodeB->pLink;
			}
			else {
				/*
				 * A�� ���� < B�� ����
				 * ���׽� B�� ���� �̿��Ͽ� ��� ���׽Ŀ� ���ο� ���� �߰�
				 * ���׽� B�� ���� ������ �̵�
				 */
				coefSum = pNodeB->coef;
				addPolyNodeLast(pReturn, coefSum, degreeB);
				pNodeB = pNodeB->pLink;
			}
		}
		
		while (pNodeA != NULL) { // ���׽� A�� ���� ���� �ִٸ� ���� ������ ��� ���׽Ŀ� ���ο� �� �߰�
			coefSum = pNodeA->coef;
			addPolyNodeLast(pReturn, coefSum, pNodeA->degree);
			pNodeA = pNodeA->pLink;
		}

		while (pNodeB != NULL) { // ���׽� B�� ���� ���� �ִٸ� ���� ������ ��� ���׽Ŀ� ���ο� �� �߰�
			coefSum = pNodeB->coef;
			addPolyNodeLast(pReturn, coefSum, pNodeB->degree);
			pNodeB = pNodeB->pLink;
		}
	}
	else {
		printf("����, NULL ���׽��� ���޵Ǿ����ϴ�. polyAdd()\n");
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
		printf("�� ���׽��Դϴ�.\n");
	}
}