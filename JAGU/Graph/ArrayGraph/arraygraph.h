#ifndef _GRAPHADJMATRIX_
#define _GRAPHADJMATRIX_

class ArrayGraph {
public:
	int maxVertexCount; // 최대 노드 개수
	int currentVertextCount; // 현재 사용되는 노드의 개수
	int graphType; // 그래프 종류 : 1-Undirected, 2-Directed
	int **ppAdjEdge; // 간선 저장을 위한 2차원 array
	int *pVertex; // 노드 저장을 위한 1차원 array

	void deleteArrayGraph();
	int isEmptyAG();
	int addVertexAG(int vertexID);
	int addEdgeAG(int fromVertexID, int toVertexID);
	int addEdgewithWeightAG(int fromVertexID, int toVertexID, int weight);
	int checkVertexValid(int vertexID);
	int removeVertexAG(int vertexID);
	int removeEdgeAG(int fromVertexID, int toVertexID);
	void displayArrayGraph();
};

ArrayGraph* createArrayGraph(int maxVertexCount);
ArrayGraph* createArrayDirectedGraph(int maxVertexCount);

#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define USED 1
#define NOT_USED 0

#define SUCCESS 1
#define FAIL 0

#define TRUE 1
#define FALSE 0

#define GRAPH_UNDIRECTED 1
#define GRAPH_DIRECTED 2

#endif