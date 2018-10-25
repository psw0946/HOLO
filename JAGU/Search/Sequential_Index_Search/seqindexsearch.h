#ifndef _SEQUENTIAL_INDEX_SEARCH_
#define _SEQUENTIAL_INDEX_SEARCH_

#define TRUE 1
#define FALSE 0
#define FAIL -1

class IndexTable {
public:
	int position;
	int key;
};

int sequentialIndexSearch(int value[], int size, IndexTable index[], int indexSize, int key);
int sequentialRangeSearchAscendingSorted(int value[], int start, int end, int key);
IndexTable* createIndexTable(int value[], int size, int indexSize);
void showIndexTable(IndexTable *pIndexTable, int indexSize);

#endif
