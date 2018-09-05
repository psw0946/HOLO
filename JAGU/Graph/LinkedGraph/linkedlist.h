#ifndef _LINKEDLIST_
#define _LINKEDLIST_

class GraphVertex {
public:
	int vertexID;
	int weight;
};

class ListNode {
public:
	GraphVertex data;
	ListNode* pLink; // pointer to next node
};

class LinkedList {
public:
	int currentElementCount; // 현재 저장된 원소의 개수
	ListNode headerNode; // 헤더 노드 (Header Node)

	int addLLElement(int position, ListNode element);
	int removeLLElement(int position);
	ListNode* getLLElement(int position);

	void clearLinkedList(); // 이건 왜 있는지 모르겠음...
	int getLinkedListLength();
	void deleteLinkedList();
	int isEmpty();
	void displayLinkedList();

	int addLLElementForVertex(int position, GraphVertex vertex);
	void deleteGraphNode(int delVertexID);
	int findGraphNodePosition(int vertexID);
};

LinkedList* createLinkedList();

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif
