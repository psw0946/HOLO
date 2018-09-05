#include <iostream>
#include "linkedlist.h"


LinkedList* createLinkedList() {
	LinkedList *pReturn = NULL;
	int i = 0;
	
	pReturn = new LinkedList();
	if (pReturn == NULL) { // �޸� �Ҵ�� ����
		printf("�޸� �Ҵ� ���� createLinkedList()\n");
		return NULL;
	}
	
	return pReturn;
}


int LinkedList::addLLElement(int position, ListNode element) {
	int ret = FALSE;
	int i = 0;
	ListNode* pPreNode = NULL;
	ListNode* pNewNode = NULL;
	
	if (this != NULL) {
		if (position >= 0 && position <= this->currentElementCount) {
			pNewNode = new ListNode();
			if (pNewNode != NULL) {
				// ��� �� ������ ��ũ �ʱ�ȭ
				*pNewNode = element;
				pNewNode->pLink = NULL;

				pPreNode = &(this->headerNode);
				for (i = 0; i < position; i++) {
					pPreNode = pPreNode->pLink;
				} // ��尡 �߰��� ��ġ�� �̵�
				
				pNewNode->pLink = pPreNode->pLink;
				pPreNode->pLink = pNewNode; // �߰��� ���� ���� ��� ������ ��ũ �缳��

				this->currentElementCount++;

				ret = TRUE;
			}
			else {
				printf("�޸� �Ҵ� ���� addLLElement()\n");
				return ret;
			}
		}
		else {
			printf("��ġ �ε��� ���� [%d], addLLElement()\n", position);
		}
	}
	return ret;
}


int LinkedList::removeLLElement(int position) {
	int ret = FALSE;
	int i = 0;
	int listCount = 0;
	ListNode* pNode = NULL;
	ListNode* pDelNode = NULL;
	if (this != NULL) {
		listCount = getLinkedListLength();
		if (position >= 0 && position < listCount) {
			pNode = &(this->headerNode);
			for (i = 0; i < position; i++) {
				pNode = pNode->pLink;
			} // ���ŵ� ��� ��ġ�� �̵�

			pDelNode = pNode->pLink;
			pNode->pLink = pDelNode->pLink; // ���ŵ� ���� ���� ��� ������ ��ũ �缳��

			delete pDelNode;
			this->currentElementCount--;
			ret = TRUE;
		}
		else {
			printf("��ġ �ε��� ���� [%d] removeLLElement()\n", position);
		}
	}
	return ret;
}


ListNode* LinkedList::getLLElement(int position) {
	ListNode* pReturn = NULL;
	int i = 0;
	ListNode* pNode = NULL;
	if (this != NULL) {
		if (position >= 0 && position < this->currentElementCount) {
			pNode = &(this->headerNode);
			for (i = 0; i <= position; i++) {
				pNode = pNode->pLink;
			}
			pReturn = pNode;
		}
	}
	return pNode;
}


void LinkedList::deleteLinkedList() {
	int i = 0;
	if (this != NULL) {
		clearLinkedList();
		delete this;
	}
}


void LinkedList::clearLinkedList() {
	if (this != NULL) {
		while (this->currentElementCount > 0) {
			removeLLElement(0);
		}
	}
}


int LinkedList::getLinkedListLength() {
	int ret = 0;
	
	if (this != NULL) {
		ret = this->currentElementCount;
	}

	return ret;
}


int LinkedList::isEmpty() {
	int ret = FALSE;

	if (this != NULL) {
		if (this->currentElementCount == 0) {
			ret = TRUE;
		}
	}

	return ret;
}


void LinkedList::displayLinkedList() {
	int i = 0;
	if (this != NULL) {
		for (i = 0; i < this->currentElementCount; i++) {
			ListNode* temp = getLLElement(i);
			printf("<%d, %d> ", temp->data.vertexID, temp->data.weight);
		}
	}
}

int LinkedList::addLLElementForVertex(int position, GraphVertex vertex) {
	ListNode node = { 0 , };
	node.data = vertex;
	return addLLElement(position, node);
}

void LinkedList::deleteGraphNode(int delVertexID) {
	int i = 0, position = 0;
	ListNode* pNode = NULL;

	position = findGraphNodePosition(delVertexID);
	if (position >= 0) {
		removeLLElement(position);
	}
}

int LinkedList::findGraphNodePosition(int vertexID) {
	int i = 0, position = 0;
	ListNode* pNode = NULL;

	if (this != NULL) {
		pNode = this->headerNode.pLink;
		while (pNode != NULL) {
			if (pNode->data.vertexID == vertexID) {
				return position;
			}

			pNode = pNode->pLink;
			position++;
		}
	}

	return -1;
}