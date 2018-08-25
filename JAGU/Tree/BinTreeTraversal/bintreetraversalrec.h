#ifndef _BIN_TREE_TRAVERSAL_RECURSIVE_
#define _BIN_TREE_TRAVERSAL_RECURSIVE_
#include "bintree.h"

template <typename T>
void preorderTraversalRecursiveBinTree(BinTree<T> *pBinTree);
template <typename T>
void preorderTraversalRecursiveBinTreeNode(Node<T> *pRootNode);
template <typename T>
void inorderTraversalRecursiveBinTree(BinTree<T>* pBinTree);
template <typename T>
void inorderTraversalRecursiveBinTreeNode(Node<T>* pRootNode);
template <typename T>
void postorderTraversalRecursiveBinTree(BinTree<T>* pBinTree);
template <typename T>
void postorderTraversalRecursiveBinTreeNode(Node<T>* pRootNode);

#endif
