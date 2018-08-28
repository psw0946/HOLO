#include "bintree.h"
#include <iostream>
#include "bintreeop.h"

template <typename T>
BinTree<T>* copyBinTree(BinTree<T>* pSource) {
	BinTree<T>* pReturn = NULL;
	if (pSource != NULL) {
		pReturn = new BinTree<T>();
		if (pReturn != NULL) {
			// Preorder 방식으로 트리 복사. 단, 이진 트리의 루트 노드가 시작 노드
			pReturn->pRootNode = copyBinTreeNode(pSource->pRootNode);
		}
		else {
			printf("메모리 할당 오류, copyBinTree()\n");
		}
	}
	return pReturn;
}

template <typename T>
Node<T>* copyBinTreeNode(Node<T>* pSourceNode) {
	Node<T>* pReturn = NULL;
	if (pSourceNode != NULL) {
		pReturn = new Node<T>();
		if (pReturn != NULL) {
			*pReturn = *pSourceNode;
			pReturn->pLeftChild = copyBinTreeNode(pSourceNode->pLeftChild);
			pReturn->pRightChild = copyBinTreeNode(pSourceNode->pRightChild);
		}
		else {
			printf("메모리 할당 오류, copyBinTreeNode()\n");
		}
	}
	return pReturn;
}

template <typename T>
int equalBinTree(BinTree<T>* pFirst, BinTree<T>* pSecond) {
	int ret = FALSE;

	if (pFirst == NULL && pSecond == NULL) {
		// 두 트리가 모두 NULL 이면 동일
		ret = TRUE;
	}
	else if (pFirst != NULL && pSecond != NULL && equalBinTreeNode(pFirst->pRootNode, pSecond->pRootNode) == TRUE) {
		// 두 트리가 모두 NULL이 아니면, 두 트리의 루트 노드를 시작 노드로 하여 Preorder를 통해 트리 비교
		ret = TRUE;
	}

	return ret;
}

template <typename T>
int equalBinTreeNode(Node<T>* pFirst, Node<T>* pSecond) {
	int ret = FALSE;

	if (pFirst == NULL && pSecond == NULL) {
		ret = TRUE;
	}
	else if (pFirst != NULL && pSecond != NULL && pFirst->data == pSecond->data &&
		equalBinTreeNode(pFirst->pLeftChild, pSecond->pLeftChild) == TRUE && equalBinTreeNode(pFirst->pRightChild, pSecond->pRightChild) == TRUE) {
		ret = TRUE;
	}

	return ret;
}

template <typename T>
int getNodeCountBT(BinTree<T>* pSource) {
	// Postorder를 이용하여 노드 개수를 구한다.
	// 왼쪽 서브트리의 노드 개수 + 오른쪽 서브트리의 노드 개수 + 나(1개)
	int ret = 0;
	if (pSource != NULL) {
		ret = getNodeCountBTNode(pSource->pRootNode);
	}
	return ret;
}

template <typename T>
int getNodeCountBTNode(Node<T>* pSource) {
	int ret = 0;
	if (pSource != NULL) {
		ret = getNodeCountBTNode(pSource->pLeftChild) + getNodeCountBTNode(pSource->pRightChild) + 1;
	}

	return ret;
}

template <typename T>
int getLeafNodeCountBT(BinTree<T>* pSource) {
	int ret = 0;
	if (pSource != NULL) {
		ret = getLeafNodeCountBTNode(pSource->pRootNode);
	}

	return ret;
}

template <typename T>
int getLeafNodeCountBTNode(Node<T>* pSource) {
	int ret = 0;
	if (pSource != NULL) {
		if (pSource->pLeftChild == NULL && pSource->pRightChild == NULL) {
			return 1;
		}
		else {
			ret = getLeafNodeCountBTNode(pSource->pLeftChild) + getLeafNodeCountBTNode(pSource->pRightChild);
		}
	}

	return ret;
}

template <typename T>
int getHeightBT(BinTree<T>* pSource) {
	int ret = 0;
	if (pSource != NULL) {
		ret = getHeightBTNode(pSource->pRootNode);
	}

	return ret;
}

template <typename T>
int getHeightBTNode(Node<T>* pSource) {
	int ret = 0;
	if (pSource != NULL) {
		if (pSource->pLeftChild == NULL && pSource->pRightChild == NULL) {
			// 단말 노드라면 높이 1 반환
			ret = 1;
		}
		else {
			// 단말 노드가 아니라면 두 개의 서브트리 높이 중 큰 값을 구하고 구한 서브트리 높이에 1을 더한다.
			int leftChildHeight = getHeightBTNode(pSource->pLeftChild);
			int rightChildHeight = getHeightBTNode(pSource->pRightChild);
			if (leftChildHeight >= rightChildHeight) {
				ret = 1 + leftChildHeight;
			}
			else {
				ret = 1 + rightChildHeight;
			}
		}
	}

	return ret;
}

template <typename T>
void displayBinTree(BinTree<T>* pTree) {
	if (pTree != NULL) {
		displayBinTreeNode(pTree->pRootNode, 0, 'O');
	}
	else {
		printf("트리가 NULL입니다.\n");
	}
}

template <typename T>
void displayBinTreeNode(Node<T>* pNode, int level, char type) {
	int i = 0;
	for (i = 0; i < level; i++) {
		printf("    ");
	}
	
	if (pNode != NULL) {
		printf("-[%i, %c] %c\n", level, type, pNode->data);

		displayBinTreeNode(pNode->pLeftChild, level + 1, 'L');
		displayBinTreeNode(pNode->pRightChild, level + 1, 'R');
	}
	else {
		printf("NULL\n");
	}
}