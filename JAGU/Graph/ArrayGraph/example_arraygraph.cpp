#include <iostream>
#include "arraygraph.h"
using namespace std;

int main() {
	int i = 0;
	ArrayGraph *pG1 = NULL;
	ArrayGraph *pG2 = NULL;
	ArrayGraph *pG4 = NULL;

	// 그래프 생성
	pG1 = createArrayGraph(6);
	pG2 = createArrayDirectedGraph(6);
	pG4 = createArrayDirectedGraph(6);

	if (pG1 != NULL && pG2 != NULL && pG4 != NULL) {
		// 그래프 초기화 : 노드 추가
		for (i = 0; i < 6; i++) {
			pG1->addVertexAG(i);
			pG2->addVertexAG(i);
			pG4->addVertexAG(i);
		}
		// 그래프 초기화 : 간선 추가
		pG1->addEdgeAG(0, 1);
		pG1->addEdgeAG(0, 2);
		pG1->addEdgeAG(1, 2);
		pG1->addEdgeAG(2, 3);
		pG1->addEdgeAG(3, 4);
		pG1->addEdgeAG(3, 5);
		pG1->addEdgeAG(4, 5);
		pG1->addEdgeAG(0, 1);
		pG1->addEdgeAG(1, 2);
		pG1->addEdgeAG(2, 0);

		pG2->addEdgeAG(2, 1);
		pG2->addEdgeAG(2, 3);
		pG2->addEdgeAG(3, 2);
		pG2->addEdgeAG(3, 4);
		pG2->addEdgeAG(4, 5);
		pG2->addEdgeAG(5, 3);

		pG4->addEdgewithWeightAG(0, 1, 4);
		pG4->addEdgewithWeightAG(1, 2, 1);
		pG4->addEdgewithWeightAG(2, 0, 2);
		pG4->addEdgewithWeightAG(2, 1, 3);
		pG4->addEdgewithWeightAG(2, 3, 2);
		pG4->addEdgewithWeightAG(3, 2, 1);
		pG4->addEdgewithWeightAG(3, 4, 1);
		pG4->addEdgewithWeightAG(4, 5, 1);
		pG4->addEdgewithWeightAG(5, 3, 2);

		printf("G1: Undirected\n");
		pG1->displayArrayGraph();
		printf("\nG2: Directed\n");
		pG2->displayArrayGraph();
		printf("\nG3: Directed Weighted\n");
		pG4->displayArrayGraph();

		// 그래프 삭제
		pG1->deleteArrayGraph();
		pG2->deleteArrayGraph();
		pG4->deleteArrayGraph();
	}

	return 0;
}