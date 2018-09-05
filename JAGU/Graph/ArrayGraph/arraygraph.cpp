#include <iostream>
#include <string.h>
#include "arraygraph.h"

ArrayGraph* createArrayGraph(int maxVertexCount) {
	int i = 0, j = 0;
	ArrayGraph *pReturn = NULL;
	
	if (maxVertexCount > 0) {
		pReturn = new ArrayGraph();
		if (pReturn == NULL) {
			printf("����, �޸� �Ҵ�(1), in createArrayGraph()\n");
			return NULL;
		}
		// �ʱ�ȭ �ǽ�, �׷��� ������ ������ �׷����� �����ϰ� �ִ� ��� ������ ����
		pReturn->graphType = GRAPH_UNDIRECTED;
		pReturn->maxVertexCount = maxVertexCount;
	}
	else {
		printf("����, �ִ� ��� ������ 0���� Ŀ�� �մϴ�\n");
		return NULL;
	}

	pReturn->pVertex = new int[maxVertexCount];
	if (pReturn->pVertex == NULL) {
		printf("����, �޸� �Ҵ�(2), in createArrayGraph()\n");
		if (pReturn != NULL)
			delete pReturn;
		return NULL;
	}

	pReturn->ppAdjEdge = new int*[maxVertexCount];
	if (pReturn->ppAdjEdge == NULL) {
		printf("����, �޸� �Ҵ�(3), in createArrayGraph()\n");
		if (pReturn->pVertex != NULL)
			delete pReturn->pVertex;
		if (pReturn != NULL)
			delete pReturn;
		return NULL;
	}

	for (i = 0; i < maxVertexCount; i++) {
		pReturn->ppAdjEdge[i] = new int[maxVertexCount];
		if (pReturn->ppAdjEdge[i] == NULL) {
			printf("����, �޸� �Ҵ�(4), in createArrayGraph()\n");
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

	// ��� ���� ���θ� �����ϴ� ���� pReturn->pVertex�� ������ ������ �����ϴ� �� pReturn->ppAdjEdge[i]�� ���� �޸� �� �ʱ�ȭ
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
				// ����� id�� ��ȿ�� ��������, �߰��Ϸ��� ��尡 �̹� �����ϴ� ��������� ����
				this->pVertex[vertexID] = USED;
				this->currentVertextCount++;
			}
			else {
				printf("����, �̹� �����ϴ� ��� [%d], in addVertexAG()\n", vertexID);
				ret = FAIL;
			}
		}
		else {
			printf("����, �ִ� ��� ���� �ʰ� [%d], in addVertexAG()\n", this->maxVertexCount);
			ret = FAIL;
		}
	}

	return ret;
}

int ArrayGraph::addEdgewithWeightAG(int fromVertexID, int toVertexID, int weight) {
	int ret = SUCCESS;

	if (this != NULL) {
		if (!checkVertexValid(fromVertexID)) {
			// ���� ��尡 ��ȿ�� ������� ����
			ret = FAIL;
			return ret;
		}
		if (!checkVertexValid(toVertexID)) {
			// ���� ��尡 ��ȿ�� ������� ����
			ret = FAIL;
			return ret;
		}
		this->ppAdjEdge[fromVertexID][toVertexID] = weight;

		if (this->graphType == GRAPH_UNDIRECTED) {
			// ������ �׷����� ��� ��Ī���� ó�� : ��Ī�Ǵ� ��ġ�� ���� ������ ���� ����
			this->ppAdjEdge[toVertexID][fromVertexID] = weight;
		}
	}

	return ret;
}

int ArrayGraph::checkVertexValid(int vertexID) {
	int ret = SUCCESS;

	if (vertexID >= this->maxVertexCount || this->pVertex[vertexID] == NOT_USED) {
		printf("����, ��� ���� [%d]\n", vertexID);
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
			// ���� ��尡 ��ȿ�� ������� ����
			ret = FAIL;
			return ret;
		}
		if (!checkVertexValid(toVertexID)) {
			// ���� ��尡 ��ȿ�� ������� ����
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
		// �����Ϸ��� ��忡 �μӵ� ���� ������ ���� ����
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