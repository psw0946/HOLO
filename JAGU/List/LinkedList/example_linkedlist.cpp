#include <iostream>
#include "linkedlist.cpp"
using namespace std;

int main() {
	int i = 0;
	int listCount = 0;
	LinkedList<int>* pList = NULL;
	ListNode<int>* pNode = NULL;
	ListNode<int> node;

	pList = pList->createLinkedList();
	if (pList != NULL) {
		node.data = 1;
		pList->addLLElement(0, node);

		node.data = 3;
		pList->addLLElement(1, node);

		node.data = 5;
		pList->addLLElement(2, node);

		pList->displayLinkedList();

		pList->removeLLElement(0);
		pList->displayLinkedList();

		pList->deleteLinkedList();
	}
	return 0;
}