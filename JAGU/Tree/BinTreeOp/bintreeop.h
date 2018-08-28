#ifndef _BIN_TREE_OPERATION_
#define _BIN_TREE_OPERATION_
#include "bintree.h"

template <typename T>
BinTree<T>* copyBinTree(BinTree<T>* pSource);
template <typename T>
Node<T>* copyBinTreeNode(Node<T>* pSourceNode);
template <typename T>
int equalBinTree(BinTree<T>* pFirst, BinTree<T>* pSecond);
template <typename T>
int equalBinTreeNode(Node<T>* pFirst, Node<T>* pSecond);
template <typename T>
int getNodeCountBT(BinTree<T>* pSource);
template <typename T>
int getNodeCountBTNode(Node<T>* pSource);
template <typename T>
int getLeafNodeCountBT(BinTree<T>* pSource);
template <typename T>
int getLeafNodeCountBTNode(Node<T>* pSource);
template <typename T>
int getHeightBT(BinTree<T>* pSource);
template <typename T>
int getHeightBTNode(Node<T>* pSource);
template <typename T>
void displayBinTree(BinTree<T>* pTree);
template <typename T>
void displayBinTreeNode(Node<T>* pNode, int level, char type);

#endif