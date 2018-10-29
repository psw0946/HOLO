#ifndef STATIC_HASHING_STATICHASHING_H
#define STATIC_HASHING_STATICHASHING_H

#define TRUE 1
#define FALSE 0
#define HASH_KEY_SIZE 30 // 문자열 검색 키의 길이를 정의

// 해싱 테이블의 각 버킷에 대한 상태 정의
enum HashElementStatus { EMPTY = 0, USED, DELETED };

// 해싱 테이블의 버킷에 대한 구조체 정의
class HashElement {
public:
	char key[HASH_KEY_SIZE + 1];
	int value;
	HashElementStatus status;
};

// 해싱 테이블에 대한 구조체 정의
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