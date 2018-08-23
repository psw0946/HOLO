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
	int maxElementCount; // �ִ� ���� ����
	int currentElementCount; // ���� ������ ����
	int front; // ����Ʈ(front) ��ġ
	int rear; // ����(rear) ��ġ
	Node<T> *pElement; // ��� ������ ���� 1���� �迭 ������

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
