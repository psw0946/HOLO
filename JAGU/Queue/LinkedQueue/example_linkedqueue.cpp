#include "linkedqueue.cpp"
using namespace std;

void displayLinkedQueue(LinkedQueue<char> *pQueue) {
	Node<char> *pNode = NULL;
	int i = 0;
	if (pQueue != NULL) {
		printf("���� ��� ����: %d\n", pQueue->currentElementCount);
		pNode = pQueue->pFrontNode;
		while (pNode != NULL) {
			printf("[%d] - [%c]\n", i, pNode->data);
			i++;
			pNode = pNode->pLink;
		}
	}
}

int enqueueLQchar(LinkedQueue<char>* pQueue, char data) {
	Node<char> node = { 0, };
	node.data = data;
	return pQueue->enqueueLQ(node);
}

int main() {
	LinkedQueue<char> *pQueue = NULL;
	Node<char> *pNode = NULL;
	char value = 0;

	pQueue = pQueue->createLinkedQueue();
	if (pQueue != NULL) {
		// ť �ʱ�ȭ: 'A', 'B', 'C', 'D' �߰�.
		enqueueLQchar(pQueue, 'A');
		enqueueLQchar(pQueue, 'B');
		enqueueLQchar(pQueue, 'C');
		enqueueLQchar(pQueue, 'D');
		displayLinkedQueue(pQueue);

		pNode = pQueue->dequeueLQ();
		if (pNode != NULL) {
			printf("Dequeue Value - [%c]\n", pNode->data);
			delete pNode;
		}
		displayLinkedQueue(pQueue);

		pNode = pQueue->peekLQ();
		if (pNode != NULL) {
			printf("Peek Value - [%c]\n", pNode->data);
		}
		displayLinkedQueue(pQueue);

		enqueueLQchar(pQueue, 'E');

		displayLinkedQueue(pQueue);
	}
	return 0;
}