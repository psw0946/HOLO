#include "arrayqueue.cpp"
using namespace std;

void displayArrayQueue(ArrayQueue<char> *pQueue) {
	int i = 0, maxElementIndex = 0, pos = 0;
	if (pQueue != NULL) {
		printf("큐의 크기: %d, 현재 노드 개수: %d\n", pQueue->maxElementCount, pQueue->currentElementCount);

		// 원형 큐 바뀐 부분
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
		// 큐 초기화: 'A', 'B', 'C', 'D' 추가.
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
