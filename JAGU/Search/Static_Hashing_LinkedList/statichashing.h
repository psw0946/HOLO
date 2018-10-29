#ifndef STATIC_HASHING_LIST_STATICHASHING_H
#define STATIC_HASHING_LIST_STATICHASHING_H

#define TRUE 1
#define FALSE 0

#include "hashingdef.h"
#include "hashinglinkedlist.h"

class HashTable {
public:
	int bucketSize;
	int currentElementCount;
	LinkedList **ppElement;
};

HashTable *createHashTable(int bucketSize);
int addLLElementLast(LinkedList *pList, HashElement element);
int addSHT(HashTable *pHashTable, HashElement element);
int deleteElementHT(HashTable *pHashTable, char *key);
int hashFunction(char *pKey, int bucketSize);
unsigned int stringToInt(char *pKey);
HashElement* searchHT(HashTable *pHashTable, char *key);
LinkedList* searchBucket(HashTable *pHashTable, char *key);
HashElement* searchSlot(LinkedList *pList, char *key, int *pPosition);
void deleteHashTable(HashTable *pHashTable);
void displayHashTable(HashTable *pHashTable);

#endif