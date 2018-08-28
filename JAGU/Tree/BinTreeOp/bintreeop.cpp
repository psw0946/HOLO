#include "bintree.h"
#include <iostream>
#include "bintreeop.h"

template <typename T>
BinTree<T>* copyBinTree(BinTree<T>* pSource) {
	BinTree<T>* pReturn = NULL;
	if (pSource != NULL) {
		pReturn = new BinTree<T>();
		if (pReturn != NULL) {
			// Preorder ������� Ʈ�� ����. ��, ���� Ʈ���� ��Ʈ ��尡 ���� ���
			pReturn->pRootNode = copyBinTreeNode(pSource->pRootNode);
		}
		else {
			printf("�޸� �Ҵ� ����, copyBinTree()\n");
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
			printf("�޸� �Ҵ� ����, copyBinTreeNode()\n");
		}
	}
	return pReturn;
}

template <typename T>
int equalBinTree(BinTree<T>* pFirst, BinTree<T>* pSecond) {
	int ret = FALSE;

	if (pFirst == NULL && pSecond == NULL) {
		// �� Ʈ���� ��� NULL �̸� ����
		ret = TRUE;
	}
	else if (pFirst != NULL && pSecond != NULL && equalBinTreeNode(pFirst->pRootNode, pSecond->pRootNode) == TRUE) {
		// �� Ʈ���� ��� NULL�� �ƴϸ�, �� Ʈ���� ��Ʈ ��带 ���� ���� �Ͽ� Preorder�� ���� Ʈ�� ��
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
	// Postorder�� �̿��Ͽ� ��� ������ ���Ѵ�.
	// ���� ����Ʈ���� ��� ���� + ������ ����Ʈ���� ��� ���� + ��(1��)
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
			// �ܸ� ����� ���� 1 ��ȯ
			ret = 1;
		}
		else {
			// �ܸ� ��尡 �ƴ϶�� �� ���� ����Ʈ�� ���� �� ū ���� ���ϰ� ���� ����Ʈ�� ���̿� 1�� ���Ѵ�.
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
		printf("Ʈ���� NULL�Դϴ�.\n");
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