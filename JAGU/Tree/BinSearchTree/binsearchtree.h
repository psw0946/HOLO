#ifndef _BIN_SEARCH_TREE_
#define _BIN_SEARCH_TREE_

template <typename T>
class Node {
public:
	int key;
	T value;

	Node* pLeftChild;
	Node* pRightChild;

	Node* searchInternalRecursiveBST(int key);
	void deleteBinSearchTreeInternal();
};

template <typename T>
class BinSearchTree {
public:
	Node<T> *pRootNode;

	BinSearchTree* createBinSearchTree();
	int insertElementBST(Node<T> element);
	int deleteElementBST(int key);
	Node<T>* searchRecursiveBST(int key);
	Node<T>* searchBST(int key);
	void deleteBinSearchTree();
};

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE 1
#define FALSE 0

#endif