#include <iostream>
#include "linkedlist.h"


LinkedList* createLinkedList() {
	LinkedList *pReturn = NULL;
	int i = 0;
	
	pReturn = new LinkedList();
	if (pReturn == NULL) { // 메모리 할당과 점검
		printf("메모리 할당 오류 createLinkedList()\n");
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
				// 노드 값 설정과 링크 초기화
				*pNewNode = element;
				pNewNode->pLink = NULL;

				pPreNode = &(this->headerNode);
				for (i = 0; i < position; i++) {
					pPreNode = pPreNode->pLink;
				} // 노드가 추가될 위치로 이동
				
				pNewNode->pLink = pPreNode->pLink;
				pPreNode->pLink = pNewNode; // 추가된 노드와 기존 노드 사이의 링크 재설정

				this->currentElementCount++;

				ret = TRUE;
			}
			else {
				printf("메모리 할당 오류 addLLElement()\n");
				return ret;
			}
		}
		else {
			printf("위치 인덱스 오류 [%d], addLLElement()\n", position);
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
			} // 제거될 노드 위치로 이동

			pDelNode = pNode->pLink;
			pNode->pLink = pDelNode->pLink; // 제거될 노드와 기존 노드 사이의 링크 재설정

			delete pDelNode;
			this->currentElementCount--;
			ret = TRUE;
		}
		else {
			printf("위치 인덱스 오류 [%d] removeLLElement()\n", position);
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