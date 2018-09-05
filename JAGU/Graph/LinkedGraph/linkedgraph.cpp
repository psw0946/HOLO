#include <iostream>
#include <string.h>
#include "linkedgraph.h"

LinkedGraph* createLinkedGraph(int maxVertexCount) {
	int i = 0, j = 0;
	LinkedGraph *pReturn = NULL;

	if (maxVertexCount > 0) {
		pReturn = new LinkedGraph();
		if (pReturn == NULL) {
			printf("오류, 메모리할당(1), in createLinkedGraph()\n");
			return NULL;
		}
		pReturn->graphType = GRAPH_UNDIRECTED;
		pReturn->maxVertexCount = maxVertexCount;
		pReturn->currentEdgeCount = 0;
		pReturn->currentVertexCount = 0;
	}
	else {
		printf("오류, 최대 노드 개수는 0보다 커야합니다\n");
		return NULL;
	}

	pReturn->pVertex = new int[maxVertexCount];
	if (pReturn->pVertex == NULL) {
		printf("오류, 메모리 할당(2), in createArrayGraph()\n");
		return NULL;
	}
	memset(pReturn->pVertex, NOT_USED, sizeof(int)*maxVertexCount);

	pReturn->ppAdjEdge = new LinkedList*[maxVertexCount];
	if (pReturn->ppAdjEdge == NULL) {
		printf("오류, 메모리 할당(3), in createLinkedGraph()\n");
		return NULL;
	}
	for (i = 0; i < maxVertexCount; i++) {
		pReturn->ppAdjEdge[i] = createLinkedList();
		if (pReturn->ppAdjEdge[i] == NULL) {
			printf("오류, 메모리할당(4), in createLinkedGraph()\n");
			return NULL;
		}
	}

	return pReturn;
}

LinkedGraph* createLinkedDirectedGraph(int maxVertexCount) {
	LinkedGraph* pReturn = NULL;

	pReturn = createLinkedGraph(maxVertexCount);
	if (pReturn != NULL) {
		pReturn->graphType = GRAPH_DIRECTED;
	}

	return pReturn;
}

int LinkedGraph::addVertexLG(int vertexID) {
	int ret = SUCCESS;

	if (this != NULL) {
		if (vertexID < this->maxVertexCount) {
			if (this->pVertex[vertexID] == NOT_USED) {
				// 추가하려는 노드가 이미 존재하는 노드인지 여부를 점검
				this->pVertex[vertexID] = USED;
				this->currentVertexCount++;
			}
			else {
				printf("오류, 노드 ID(1) [%d], in addVertexLG()\n", vertexID);
				ret = FAIL;
			}
		}
		else {
			printf("오류, 최대 노드 ID (%d) 보다 큰 숫자 (%d) 입니다, in addVertexLG()\n", vertexID, this->maxVertexCount);
			ret = FAIL;
		}
	}

	return ret;
}

int LinkedGraph::addEdgewithWeightLG(int fromVertexID, int toVertexID, int weight) {
	int ret = SUCCESS;
	GraphVertex toNode = { 0, };

	if (this != NULL) {
		if (checkVertexValid(fromVertexID) != SUCCESS) {
			ret = FAIL;
			return ret;
		}
		if (checkVertexValid(toVertexID) != SUCCESS) {
			ret = FAIL;
			return ret;
		}

		toNode.vertexID = toVertexID;
		toNode.weight = weight;
		this->ppAdjEdge[fromVertexID]->addLLElementForVertex(0, toNode);
		this->currentEdgeCount++;

		// 무방향 그래프의 대칭성 처리
		if (this->graphType == GRAPH_UNDIRECTED) {
			GraphVertex fromNode;
			fromNode.vertexID = fromVertexID;
			fromNode.weight = weight;
			this->ppAdjEdge[toVertexID]->addLLElementForVertex(0, fromNode);
			this->currentEdgeCount++;
		}
	}

	return ret;
}

int LinkedGraph::addEdgeLG(int fromVertexID, int toVertexID) {
	return addEdgewithWeightLG(fromVertexID, toVertexID, USED);
}

int LinkedGraph::checkVertexValid(int vertexID) {
	int ret = SUCCESS;

	if (vertexID >= this->maxVertexCount || this->pVertex[vertexID] == NOT_USED) {
		ret = FAIL;
	}

	return ret;
}

int LinkedGraph::removeVertexLG(int vertexID) {
	int ret = SUCCESS;
	int i = 0;

	if (this != NULL) {
		if (checkVertexValid(vertexID) != SUCCESS) {
			ret = FAIL;
			return ret;
		}
		for (i = 0; i < this->maxVertexCount; i++) {
			removeEdgeLG(vertexID, i);
			removeEdgeLG(i, vertexID);
		}
		this->pVertex[vertexID] = NOT_USED;
	}

	return ret;
}

int LinkedGraph::removeEdgeLG(int fromVertexID, int toVertexID) {
	int ret = SUCCESS;

	if (this != NULL) {
		if (checkVertexValid(fromVertexID) != SUCCESS) {
			ret = FAIL;
			return ret;
		}
		if (checkVertexValid(toVertexID) != SUCCESS) {
			ret = FAIL;
			return ret;
		}

		this->ppAdjEdge[fromVertexID]->deleteGraphNode(toVertexID);

		if (this->graphType == GRAPH_UNDIRECTED) {
			this->ppAdjEdge[toVertexID]->deleteGraphNode(fromVertexID);
		}
	}

	return ret;
}

int LinkedGraph::isEmptyLG() {
	if (this == NULL)
		return FAIL;
	if (this->currentVertexCount == 0)
		return SUCCESS;
	return FAIL;
}

void LinkedGraph::deleteLinkedGraph() {
	int i = 0;
	if (this == NULL)
		return;
	for (i = 0; i < this->maxVertexCount; i++)
		delete this->ppAdjEdge[i];
	delete this->ppAdjEdge;
	delete this->pVertex;
	delete this;
}

void LinkedGraph::displayLinkedGraph() {
	int i = 0, j = 0;
	if (this == NULL)
		return;
	for (i = 0; i < this->maxVertexCount; i++) {
		printf("%d ", i);
		this->ppAdjEdge[i]->displayLinkedList();
		printf("\n");
	}
}