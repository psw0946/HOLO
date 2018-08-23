#include "linkeddeque.cpp"
using namespace std;

int insertFrontLDChar(LinkedDeque<char>* pDeque, char data) {
	Node<char> node = { 0, };
	node.data = data;
	return pDeque->insertFrontLD(node);
}

int insertRearLDChar(LinkedDeque<char>* pDeque, char data) {
	Node<char> node = { 0, };
	node.data = data;
	return pDeque->insertRearLD(node);
}

void displayLinkedDeque(LinkedDeque<char> *pDeque) {
	Node<char> *pNode = NULL;
	int i = 0;

	if (pDeque != NULL) {
		printf("현재 노드 개수: %d\n", pDeque->currentElementCount);
		pNode = pDeque->pFrontNode;
		while (pNode != NULL) {
			printf("[%d] - [%c]\n", i, pNode->data);
			i++;
			pNode = pNode->pRLink;
		}
	}
}

int main() {
	LinkedDeque<char> *pDeque = NULL;
	Node<char> *pNode = NULL;

	pDeque = pDeque->createLinkedQueue();
	if (pDeque != NULL) {
		insertFrontLDChar(pDeque, 'A');
		insertFrontLDChar(pDeque, 'B');
		insertRearLDChar(pDeque, 'C');
		insertRearLDChar(pDeque, 'D');
		displayLinkedDeque(pDeque);

		pNode = pDeque->deleteRearLD();
		if (pNode != NULL) {
			printf("deleteRearLD Value - [%c]\n", pNode->data);
			delete pNode;
		}
		displayLinkedDeque(pDeque);

		pNode = pDeque->deleteFrontLD();
		if (pNode != NULL) {
			printf("deleteFrontLD Value - [%c]\n", pNode->data);
			delete pNode;
		}
		displayLinkedDeque(pDeque);

		pDeque->deleteLinkedDeque();
	}
	return 0;
}