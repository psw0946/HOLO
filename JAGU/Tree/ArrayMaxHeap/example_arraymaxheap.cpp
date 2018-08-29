#include "arrayheap.h"
#include <iostream>
using namespace std;

void displayArrayMaxHeap(ArrayMaxHeap* pHeap) {
	int i = 0;
	if (pHeap != NULL) {
		for (i = 1; i <= pHeap->currentElementCount; i++) {
			printf("[%d], %d\n", i, pHeap->pElement[i]);
		}
	}
}

int main() {
	int maxHeapSize = 20;

	ArrayMaxHeap *pHeap1 = NULL;

	Node *pNode = NULL;
	Node e1 = { 10 };
	Node e2 = { 20 };
	Node e3 = { 30 };
	Node e4 = { 40 };
	Node e5 = { 50 };

	pHeap1 = pHeap1->createArrayMaxHeap(maxHeapSize);
	if (pHeap1 != NULL) {
		pHeap1->insertMaxHeapAH(e1);
		pHeap1->insertMaxHeapAH(e2);
		pHeap1->insertMaxHeapAH(e3);
		pHeap1->insertMaxHeapAH(e4);
		pHeap1->insertMaxHeapAH(e5);

		printf("Max Heap:\n");
		displayArrayMaxHeap(pHeap1);

		pNode = pHeap1->deleteMaxHeapAH();
		if (pNode != NULL) {
			printf("deleteMaxheapAH() - [%d]\n", pNode->key);
			delete pNode;
		}

		printf("Max Heap:\n");
		displayArrayMaxHeap(pHeap1);

		pHeap1->deleteArrayMaxHeap();
	}

	return 0;
}