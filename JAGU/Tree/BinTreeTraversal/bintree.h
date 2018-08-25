#ifndef _BIN_TREE_
#define _BIN_TREE_

template <typename T>
class Node {
public:
	T data;

	Node* pLeftChild;
	Node* pRightChild;
};

template <typename T>
class BinTree {
public:
	Node<T>* pRootNode;

	BinTree* makeBinTree(Node<T> rootNode);
	Node<T>* getRootNodeBT();
	Node<T>* insertLeftChildNodeBT(Node<T>* pParentNode, Node<T> element);
	Node<T>* insertRightChildNodeBT(Node<T>* pParentNode, Node<T> element);
	Node<T>* getLeftChildNodeBT(Node<T>* pNode);
	Node<T>* getRightChildNodeBT(Node<T>* pNode);
	void deleteBinTree();
	void deleteBinTreeNode(Node<T>* pNode);
};

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE 1
#define FALSE 0

#endif