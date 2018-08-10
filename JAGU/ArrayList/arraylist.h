#ifndef _ARRAYLIST_
#define _ARRAYLIST_

template <typename T>
class ArrayList {
public:
	int maxElementCount; // �ִ� ���� ����
	int currentElementCount; // ���� ������ ����
	T *pElement; // ���� ������ ���� 1���� �迭

	ArrayList<T>* createArrayList(int maxElementCount);
	void deleteArrayList();
	int isArrayListFull();
	int addALElement(int position, T element);
	int addALElementFirst(int element);
	int addALElementLast(int element);
	int removeALElement(int position);
	T getALElement(int position);
	void displayArrayList();
	int getArrayListLength();
};

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif