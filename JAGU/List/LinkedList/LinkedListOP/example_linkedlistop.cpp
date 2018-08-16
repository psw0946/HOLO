#include <iostream>
#include "linkedlist.cpp"
#include "linkedlistop.cpp"
using namespace std;

int main() {
	int i = 0, listCount = 0;
	LinkedList<int> *pListA = NULL, *pListB = NULL;
	ListNode<int> node;

	pListA = pListA->createLinkedList();
	pListB = pListB->createLinkedList();
	if (pListA != NULL && pListB != NULL) {
		node.data = 1;
		pListA->addLLElement(0, node);
		node.data = 2;
		pListA->addLLElement(1, node);
		node.data = 3;
		pListA->addLLElement(2, node);
		node.data = 4;
		pListB->addLLElement(0, node);
		node.data = 5;
		pListB->addLLElement(1, node);

		iterateLinkedList(pListA);
		iterateLinkedList(pListB);

		// ����Ʈ B�� ����Ʈ A�� �����̱�
		concatLinkedList(pListA, pListB);

		printf("After concatLinkedList()\n");
		iterateLinkedList(pListA);
		iterateLinkedList(pListB);

		// ����Ʈ A�� �������� �����
		reverseLinkedList(pListA);
		printf("After reverseLinkedList()\n");
		iterateLinkedList(pListA);

		pListA->deleteLinkedList();
		pListB->deleteLinkedList();
	}
	return 0;
}