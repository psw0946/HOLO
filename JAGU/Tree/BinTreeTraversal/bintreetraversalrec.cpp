#include <iostream>
#include "bintreetraversalrec.h"

template <typename T>
void preorderTraversalRecursiveBinTree(BinTree<T>* pBinTree) {
	if (pBinTree != NULL)
		preorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
}

template <typename T>
void preorderTraversalRecursiveBinTreeNode(Node<T>* pRootNode) {
	if (pRootNode != NULL) {
		cout << pRootNode->data << " ";
		preorderTraversalRecursiveBinTreeNode(pRootNode->pLeftChild);
		preorderTraversalRecursiveBinTreeNode(pRootNode->pRightChild);
	}
}

template <typename T>
void inorderTraversalRecursiveBinTree(BinTree<T>* pBinTree) {
	if (pBinTree != NULL)
		inorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
}

template <typename T>
void inorderTraversalRecursiveBinTreeNode(Node<T>* pRootNode) {
	if (pRootNode != NULL) {
		inorderTraversalRecursiveBinTreeNode(pRootNode->pLeftChild);
		cout << pRootNode->data << " ";
		inorderTraversalRecursiveBinTreeNode(pRootNode->pRightChild);
	}
}

template <typename T>
void postorderTraversalRecursiveBinTree(BinTree<T>* pBinTree) {
	if (pBinTree != NULL)
		postorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
}

template <typename T>
void postorderTraversalRecursiveBinTreeNode(Node<T>* pRootNode) {
	if (pRootNode != NULL) {
		postorderTraversalRecursiveBinTreeNode(pRootNode->pLeftChild);
		postorderTraversalRecursiveBinTreeNode(pRootNode->pRightChild);
		cout << pRootNode->data << " ";
	}
}