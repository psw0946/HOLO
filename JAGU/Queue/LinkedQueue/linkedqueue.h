#ifndef _LINKED_QUEUE_
#define _LINKED_QUEUE_

template <typename T>
class Node {
public:
	T data;
	Node* pLink;
};

template <typename T>
class LinkedQueue {
public:
	int currentElementCount; // 현재 원소의 개수
	Node<T>* pFrontNode; // Front 노드의 포인터
	Node<T>* pRearNode; // Rear 노드의 포인터

	LinkedQueue* createLinkedQueue();
	int enqueueLQ(Node<T> element);
	Node<T>* dequeueLQ();
	Node<T>* peekLQ();
	void deleteLinkedQueue();
	int isLinkedQueueFull();
	int isLinkedQueueEmpty();
};

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE 1
#define FALSE 0

#endif