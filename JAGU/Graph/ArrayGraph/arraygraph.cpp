#include <iostream>
#include <string.h>
#include "arraygraph.h"

ArrayGraph* createArrayGraph(int maxVertexCount) {
	int i = 0, j = 0;
	ArrayGraph *pReturn = NULL;
	
	if (maxVertexCount > 0) {
		pReturn = new ArrayGraph();
		if (pReturn == NULL) {
			printf("오류, 메모리 할당(1), in createArrayGraph()\n");
			return NULL;
		}
		// 초기화 실시, 그래프 종류를 무방향 그래프로 설정하고 최대 노드 개수를 설정
		pReturn->graphType = GRAPH_UNDIRECTED;
		pReturn->maxVertexCount = maxVertexCount;
	}
	else {
		printf("오류, 최대 노드 개수는 0보다 커야 합니다\n");
		return NULL;
	}

	pReturn->pVertex = new int[maxVertexCount];
	if (pReturn->pVertex == NULL) {
		printf("오류, 메모리 할당(2), in createArrayGraph()\n");
		if (pReturn != NULL)
			delete pReturn;
		return NULL;
	}

	pReturn->ppAdjEdge = new int*[maxVertexCount];
	if (pReturn->ppAdjEdge == NULL) {
		printf("오류, 메모리 할당(3), in createArrayGraph()\n");
		if (pReturn->pVertex != NULL)
			delete pReturn->pVertex;
		if (pReturn != NULL)
			delete pReturn;
		return NULL;
	}

	for (i = 0; i < maxVertexCount; i++) {
		pReturn->ppAdjEdge[i] = new int[maxVertexCount];
		if (pReturn->ppAdjEdge[i] == NULL) {
			printf("오류, 메모리 할당(4), in createArrayGraph()\n");
			for (j = 0; j < i; j++)
				if (pReturn->ppAdjEdge[j] != NULL)
					delete pReturn->ppAdjEdge[j];
			if (pReturn->ppAdjEdge != NULL)
				delete pReturn->ppAdjEdge;
			if (pReturn->pVertex != NULL)
				delete pReturn->pVertex;
			if (pReturn != NULL)
				delete pReturn;
			return NULL;
		}
	}

	// 노드 생성 여부를 저장하는 변수 pReturn->pVertex와 간선의 정보를 저장하는 각 pReturn->ppAdjEdge[i]에 대한 메모리 값 초기화
	memset(pReturn->pVertex, NOT_USED, sizeof(int) * maxVertexCount);
	for (i = 0; i < maxVertexCount; i++)
		memset(pReturn->ppAdjEdge[i], 0, sizeof(int) * maxVertexCount);

	return pReturn;
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount) {
	ArrayGraph* pReturn = NULL;

	pReturn = createArrayGraph(maxVertexCount);
	if (pReturn != NULL)
		pReturn->graphType = GRAPH_DIRECTED;

	return pReturn;
}

int ArrayGraph::addVertexAG(int vertexID) {
	int ret = SUCCESS;

	if (this != NULL) {
		if (vertexID < this->maxVertexCount) {
			if (this->pVertex[vertexID] == NOT_USED) {
				// 노드의 id가 유효한 범위인지, 추가하려는 노드가 이미 존재하는 노드인지를 점검
				this->pVertex[vertexID] = USED;
				this->currentVertextCount++;
			}
			else {
				printf("오류, 이미 존재하는 노드 [%d], in addVertexAG()\n", vertexID);
				ret = FAIL;
			}
		}
		else {
			printf("오류, 최대 노드 개수 초과 [%d], in addVertexAG()\n", this->maxVertexCount);
			ret = FAIL;
		}
	}

	return ret;
}

int ArrayGraph::addEdgewithWeightAG(int fromVertexID, int toVertexID, int weight) {
	int ret = SUCCESS;

	if (this != NULL) {
		if (!checkVertexValid(fromVertexID)) {
			// 시작 노드가 유효한 노드인지 점검
			ret = FAIL;
			return ret;
		}
		if (!checkVertexValid(toVertexID)) {
			// 종료 노드가 유효한 노드인지 점검
			ret = FAIL;
			return ret;
		}
		this->ppAdjEdge[fromVertexID][toVertexID] = weight;

		if (this->graphType == GRAPH_UNDIRECTED) {
			// 무방향 그래프인 경우 대칭성을 처리 : 대칭되는 위치의 간선 정보도 같이 변경
			this->ppAdjEdge[toVertexID][fromVertexID] = weight;
		}
	}

	return ret;
}

int ArrayGraph::checkVertexValid(int vertexID) {
	int ret = SUCCESS;

	if (vertexID >= this->maxVertexCount || this->pVertex[vertexID] == NOT_USED) {
		printf("오류, 노드 정보 [%d]\n", vertexID);
		ret = FAIL;
	}

	return ret;
}

int ArrayGraph::addEdgeAG(int fromVertexID, int toVertexID) {
	return addEdgewithWeightAG(fromVertexID, toVertexID, USED);
}

int ArrayGraph::removeEdgeAG(int fromVertexID, int toVertexID) {
	int ret = SUCCESS;

	if (this != NULL) {
		if (!checkVertexValid(fromVertexID)) {
			// 시작 노드가 유효한 노드인지 점검
			ret = FAIL;
			return ret;
		}
		if (!checkVertexValid(toVertexID)) {
			// 종료 노드가 유효한 노드인지 점검
			ret = FAIL;
			return ret;
		}
		this->ppAdjEdge[fromVertexID][toVertexID] = 0;

		if (this->graphType == GRAPH_UNDIRECTED) {
			this->ppAdjEdge[toVertexID][fromVertexID] = 0;
		}
	}

	return ret;
}

int ArrayGraph::removeVertexAG(int vertexID) {
	int ret = SUCCESS;
	int i = 0;

	if (this != NULL) {
		if (checkVertexValid(vertexID) != SUCCESS) {
			ret = FAIL;
			return ret;
		}
		// 제거하려는 노드에 부속된 간선 정보를 먼저 제거
		for (i = 0; i < this->maxVertexCount; i++) {
			removeEdgeAG(vertexID, i);
			removeEdgeAG(i, vertexID);
		}

		this->pVertex[vertexID] = NOT_USED;
	}

	return ret;
}

int ArrayGraph::isEmptyAG() {
	if (this == NULL)
		return FAIL;
	if (this->currentVertextCount == 0)
		return SUCCESS;
	return FAIL;
}

void ArrayGraph::deleteArrayGraph() {
	int i = 0;
	if (this == NULL)
		return;
	for (i = 0; i < this->maxVertexCount; i++)
		delete this->ppAdjEdge[i];
	delete this->ppAdjEdge;
	delete this->pVertex;
	delete this;
}

void ArrayGraph::displayArrayGraph() {
	int i = 0, j = 0;
	if (this == NULL)
		return;
	for (i = 0; i < this->maxVertexCount; i++) {
		for (j = 0; j < this->maxVertexCount; j++) {
			printf("%d ", this->ppAdjEdge[i][j]);
		}
		printf("\n");
	}
}