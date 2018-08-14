#include <iostream>
#include "linkedlist.h"
#include "linkedlistop.h"

template <typename T>
void iterateLinkedList(LinkedList<T>* pList) { // displayLinkedList ���� �� ȿ��������
	ListNode<T>* pNode = NULL;
	int count = 0;
	if (pList != NULL) {
		pNode = pList->headerNode.pLink;
		while (pNode != NULL) {
			printf("[%d], %d\n", count, pNode->data);
			count++;

			pNode = pNode->pLink;
		}
		printf("��� ����: %d\n", count);
	}
	else {
		printf("���� ����Ʈ�Դϴ�.");
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
		} // ���� ����Ʈ A�� ������ ��� ã��
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
			 * ���� ���� ���� ����� ���� ��尡 �ִٸ� ���� ����� ���� ������ ��ũ�� ���� ������ ��ũ�� �缳�����ְ� ���� ���� ����� ���� ���� �̵��Ѵ�.
			 */
			pPrevNode = pCurrentNode;
			pCurrentNode = pNode;
			pNode = pNode->pLink;
			pCurrentNode->pLink = pPrevNode;
		}
	}
	pList->headerNode.pLink = pCurrentNode;
}