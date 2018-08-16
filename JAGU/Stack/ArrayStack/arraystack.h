#ifndef _ARRAY_STACK_
#define _ARRAY_STACK_

template <typename T>
class Node {
public:
	T data;
};

template <typename T>
class ArrayStack {
public:
	int maxElementCount; // 최대 원소 개수
	int currentElementCount; // 현재 원소의 개수
	Node<T> *pElement; // 노드 저장을 위한 1차원 array

	ArrayStack* createArrayStack(int maxElementCount);
	int pushAS(Node<T> element);
	Node<T>* popAS();
	Node<T>* peekAS();
	void deleteArrayStack();
	int isArrayStackFull();
	int isArrayStackEmpty();
};

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE 1
#define FALSE 0

#endif
