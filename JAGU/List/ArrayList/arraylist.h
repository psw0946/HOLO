#ifndef _ARRAYLIST_
#define _ARRAYLIST_

template <typename T>
class ArrayList {
public:
	int maxElementCount; // 최대 원소 개수
	int currentElementCount; // 현재 원소의 개수
	T *pElement; // 원소 저장을 위한 1차원 배열

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