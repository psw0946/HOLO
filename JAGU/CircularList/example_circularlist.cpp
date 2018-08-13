#include <iostream>
#include "circularlist.cpp"
using namespace std;

int main() {
	int i = 0;
	int listCount = 0;
	CircularList<int>* pList = NULL;
	Node<int>* pNode = NULL;
	Node<int> node;

	pList = pList->createCircularList();
	if (pList != NULL) {
		node.data = 1;
		pList->addCLElement(0, node);

		node.data = 3;
		pList->addCLElement(1, node);

		node.data = 5;
		pList->addCLElement(2, node);

		pList->displayCircularList();

		pList->removeCLElement(0);
		pList->displayCircularList();

		pList->deleteCircularList();
	}
	return 0;
}