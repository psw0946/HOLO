#include <iostream>
#include "linkedstack.cpp"
using namespace std;

template <typename T>
void displayLinkedStack(LinkedStack<T> *pStack) {
	Node<T> *pNode = NULL;
	int i = 1;
	if (pStack != NULL) {
		printf("현재 노드 개수: %d\n", pStack->currentElementCount);

		pNode = pStack->pTopElement;
		while (pNode != NULL) {
			printf("[%d] - [%c]\n", pStack->currentElementCount - i, pNode->data);
			i++;
			pNode = pNode->pLink;
		}
	}
}

int main() {
	LinkedStack<char> *pStack = NULL;
	Node<char> *pNode = NULL;

	pStack = pStack->createLinekdStack();
	if (pStack != NULL) {
		Node<char> node1 = { 'A' };
		Node<char> node2 = { 'B' };
		Node<char> node3 = { 'C' };
		Node<char> node4 = { 'D' };

		pStack->pushLS(node1);
		pStack->pushLS(node2);
		pStack->pushLS(node3);
		pStack->pushLS(node4);
		displayLinkedStack(pStack);

		pNode = pStack->popLS();
		if (pNode != NULL) {
			printf("Pop - [%c]\n", pNode->data);
			delete pNode;
		}
		else {
			printf("Pop - NULL\n");
		}
		displayLinkedStack(pStack);

		pNode = pStack->peekLS();
		if (pNode != NULL) {
			printf("Peek - [%c]\n", pNode->data);
		}
		else {
			printf("Peek - NULL\n");
		}
		displayLinkedStack(pStack);

		pStack->deleteLinkedStack();
	}
	return 0;
}