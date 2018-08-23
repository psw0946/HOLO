#include "arrayqueue.cpp"
using namespace std;

void displayArrayQueue(ArrayQueue<char> *pQueue) {
	int i = 0, maxElementIndex = 0, pos = 0;
	if (pQueue != NULL) {
		printf("ť�� ũ��: %d, ���� ��� ����: %d\n", pQueue->maxElementCount, pQueue->currentElementCount);

		// ���� ť �ٲ� �κ�
		maxElementIndex = pQueue->front + pQueue->currentElementCount;
		for (i = pQueue->front + 1; i <= maxElementIndex; i++) {
			pos = i % pQueue->maxElementCount;
			printf("[%d] - [%c]\n", pos, pQueue->pElement[pos].data);
		}
	}
}

int enqueueAQchar(ArrayQueue<char>* pQueue, char data) {
	Node<char> node = { 0, };
	node.data = data;
	return pQueue->enqueueAQ(node);
}

int main() {
	ArrayQueue<char> *pQueue = NULL;
	Node<char> *pNode = NULL;
	char value = 0;

	pQueue = pQueue->createArrayQueue(4);
	if (pQueue != NULL) {
		// ť �ʱ�ȭ: 'A', 'B', 'C', 'D' �߰�.
		enqueueAQchar(pQueue, 'A');
		enqueueAQchar(pQueue, 'B');
		enqueueAQchar(pQueue, 'C');
		enqueueAQchar(pQueue, 'D');
		displayArrayQueue(pQueue);

		pNode = pQueue->dequeueAQ();
		if (pNode != NULL) {
			printf("Dequeue Value - [%c]\n", pNode->data);
			delete pNode;
		}
		displayArrayQueue(pQueue);
		
		pNode = pQueue->peekAQ();
		if (pNode != NULL) {
			printf("Peek Value - [%c]\n", pNode->data);
		}
		displayArrayQueue(pQueue);

		enqueueAQchar(pQueue, 'E');

		displayArrayQueue(pQueue);
	}
	return 0;
}
