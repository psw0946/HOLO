#ifndef STATIC_HASHING_STATICHASHING_H
#define STATIC_HASHING_STATICHASHING_H

#define TRUE 1
#define FALSE 0
#define HASH_KEY_SIZE 30 // ���ڿ� �˻� Ű�� ���̸� ����

// �ؽ� ���̺��� �� ��Ŷ�� ���� ���� ����
enum HashElementStatus { EMPTY = 0, USED, DELETED };

// �ؽ� ���̺��� ��Ŷ�� ���� ����ü ����
class HashElement {
public:
	char key[HASH_KEY_SIZE + 1];
	int value;
	HashElementStatus status;
};

// �ؽ� ���̺� ���� ����ü ����
class HashTable {
public:
	int bucketSize;
	int currentElementCount;
	HashElement *pElement;
};

HashTable* createHashTable(int bucketSize);
int addElementSHT(HashTable* pHashTable, HashElement element);
int deleteElementHT(HashTable* pHashTable, char* key);
int hashFunction(char *pKey, int bucketSize);
unsigned int stringToInt(char *pKey);
int isEmptyBucket(HashElement* pElement);
int isEmptyOrDeletedBucket(HashElement* pElement);
HashElement* searchHT(HashTable* pHashTable, char* key);
void displayHashTable(HashTable* pHashTable);
int getElementCountHT(HashTable* pHashTable);
void deleteHashTable(HashTable* pHashTable);

#endif