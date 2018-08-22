#ifndef _ARRAY_QUEUE_
#define _ARRAY_QUEUE_

template <typename T>
class Node {
public:
	T data;
};

template <typename T>
class ArrayQueue {
public:
	int maxElementCount; // 최대 원소 개수
	int currentElementCount; // 현재 원소의 개수
	int front; // 프런트(front) 위치
	int rear; // 리어(rear) 위치
	Node<T> *pElement; // 노드 저장을 위한 1차원 배열 포인터

	ArrayQueue* createArrayQueue(int maxElementCount);
	int enqueueAQ(Node<T> element);
	Node<T> *dequeueAQ();
	Node<T> *peekAQ();
	void deleteArrayQueue();
	int isArrayQueueFull();
	int isArrayQueueEmpty();
};
#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE 1
#define FALSE 0

#endif
