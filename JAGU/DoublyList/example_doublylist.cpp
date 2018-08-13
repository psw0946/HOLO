#include <iostream>
#include "doublylist.cpp"
using namespace std;

int main() {
	int i = 0;
	int listCount = 0;
	DoublyList<int>* pList = NULL;
	Node<int>* pNode = NULL;
	Node<int> node;

	pList = pList->createDoublyList();
	if (pList != NULL) {
		node.data = 1;
		pList->addDLElement(0, node);

		node.data = 3;
		pList->addDLElement(1, node);

		node.data = 5;
		pList->addDLElement(2, node);

		pList->displayDoublyList();

		pList->removeDLElement(0);
		pList->displayDoublyList();

		pList->deleteDoublyList();
	}
	return 0;
}