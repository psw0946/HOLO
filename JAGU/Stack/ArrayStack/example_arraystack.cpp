#include <iostream>
#include "arraystack.cpp"
using namespace std;

template <typename T>
void displayArrayStack(ArrayStack<T> *pStack) {
	int i = 0;
	if (pStack != NULL) {
		int size = pStack->maxElementCount;
		int top = pStack->currentElementCount;

		printf("���� ũ��: %d, ���� ��� ����: %d\n", pStack->maxElementCount, pStack->currentElementCount);

		for (i = size - 1; i >= top; i--) {
			printf("[%d] - [Empty]\n", i);
		}

		for (i = top - 1; i >= 0; i--) {
			printf("[%d] - [%c]\n", i, pStack->pElement[i].data); // �ϴ� data�� char ��� �����ϰ�...
		}
	}
}

int main() {
	ArrayStack<char> *pStack = NULL;
	Node<char> *pNode = NULL;
	char value = 0;

	pStack = pStack->createArrayStack(6);
	if (pStack != NULL) {
		Node<char> node1 = { 'A' };
		Node<char> node2 = { 'B' };
		Node<char> node3 = { 'C' };
		Node<char> node4 = { 'D' };
		pStack->pushAS(node1);
		pStack->pushAS(node2);
		pStack->pushAS(node3);
		pStack->pushAS(node4);
		displayArrayStack(pStack);

		pNode = pStack->popAS();
		if (pNode != NULL) {
			printf("Pop �� - [%c]\n", pNode->data);
			delete pNode;
		}
		else {
			printf("����(Empty) ����\n");
		}
		displayArrayStack(pStack);

		pNode = pStack->peekAS();
		if (pNode != NULL) {
			printf("Peek �� - [%c]\n", pNode->data);
		}
		else {
			printf("����(Empty) ����\n");
		}
		displayArrayStack(pStack);
	}
	return 0;
}