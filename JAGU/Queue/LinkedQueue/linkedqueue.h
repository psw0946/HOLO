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
	int currentElementCount; // ���� ������ ����
	Node<T>* pFrontNode; // Front ����� ������
	Node<T>* pRearNode; // Rear ����� ������

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