#include <iostream>
#include "linkedlist.cpp"
#include "polylist.cpp"
using namespace std;

int main() {
	LinkedList<int>* pListA = NULL;
	LinkedList<int>* pListB = NULL;
	LinkedList<int>* pListC = NULL;

	pListA = pListA->createLinkedList();
	pListB = pListB->createLinkedList();
	if (pListA != NULL && pListB != NULL) {
		// ���׽� �ʱ�ȭ
		// pListA: 6x^6 + 4x^5 + 2x^2
		// pListB: 1x^5 + 2x^4 + 3x^2 + 4x^0
		addPolyNodeLast(pListA, 6, 6);
		addPolyNodeLast(pListA, 4, 5);
		addPolyNodeLast(pListA, 2, 2);
		displayPolyList(pListA);

		addPolyNodeLast(pListB, 1, 5);
		addPolyNodeLast(pListB, 2, 4);
		addPolyNodeLast(pListB, 3, 2);
		addPolyNodeLast(pListB, 4, 0);
		displayPolyList(pListB);

		pListC = polyAdd(pListA, pListB);
		if (pListC != NULL) {
			displayPolyList(pListC);
			pListC->deleteLinkedList();
		}

		pListA->deleteLinkedList();
		pListB->deleteLinkedList();
	}
	return 0;
}