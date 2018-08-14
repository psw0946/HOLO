#include "linkedlist.h"
#ifndef _POLYLIST_
#define _POLYLIST_

template <typename T>
int addPolyNodeLast(LinkedList<T>* pList, float coef, int degree);
template <typename T>
LinkedList<T>* polyAdd(LinkedList<T>* pListA, LinkedList<T>* pListB);
template <typename T>
void displayPolyList(LinkedList<T>* pList);

#endif