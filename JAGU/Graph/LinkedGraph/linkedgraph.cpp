#include <iostream>
#include <string.h>
#include "linkedgraph.h"

LinkedGraph* createLinkedGraph(int maxVertexCount) {
	int i = 0, j = 0;
	LinkedGraph *pReturn = NULL;

	if (maxVertexCount > 0) {
		pReturn = new LinkedGraph();
		if (pReturn == NULL) {
			printf("����, �޸��Ҵ�(1), in createLinkedGraph()\n");
			return NULL;
		}
		pReturn->graphType = GRAPH_UNDIRECTED;
		pReturn->maxVertexCount = maxVertexCount;
		pReturn->currentEdgeCount = 0;
		pReturn->currentVertexCount = 0;
	}
	else {
		printf("����, �ִ� ��� ������ 0���� Ŀ���մϴ�\n");
		return NULL;
	}

	pReturn->pVertex = new int[maxVertexCount];
	if (pReturn->pVertex == NULL) {
		printf("����, �޸� �Ҵ�(2), in createArrayGraph()\n");
		return NULL;
	}
	memset(pReturn->pVertex, NOT_USED, sizeof(int)*maxVertexCount);

	pReturn->ppAdjEdge = new LinkedList*[maxVertexCount];
	if (pReturn->ppAdjEdge == NULL) {
		printf("����, �޸� �Ҵ�(3), in createLinkedGraph()\n");
		return NULL;
	}
	for (i = 0; i < maxVertexCount; i++) {
		pReturn->ppAdjEdge[i] = createLinkedList();
		if (pReturn->ppAdjEdge[i] == NULL) {
			printf("����, �޸��Ҵ�(4), in createLinkedGraph()\n");
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
				// �߰��Ϸ��� ��尡 �̹� �����ϴ� ������� ���θ� ����
				this->pVertex[vertexID] = USED;
				this->currentVertexCount++;
			}
			else {
				printf("����, ��� ID(1) [%d], in addVertexLG()\n", vertexID);
				ret = FAIL;
			}
		}
		else {
			printf("����, �ִ� ��� ID (%d) ���� ū ���� (%d) �Դϴ�, in addVertexLG()\n", vertexID, this->maxVertexCount);
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

		// ������ �׷����� ��Ī�� ó��
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