#include <iostream>
#include "linkedgraph.h"
using namespace std;

int main() {
	int i = 0;
	LinkedGraph *pG1 = NULL;
	LinkedGraph *pG2 = NULL;
	LinkedGraph *pG4 = NULL;

	// 그래프 생성
	pG1 = createLinkedGraph(6);
	pG2 = createLinkedDirectedGraph(6);
	pG4 = createLinkedDirectedGraph(6);

	if (pG1 != NULL && pG2 != NULL && pG4 != NULL) {
		// 그래프 초기화 : 노드 추가
		for (i = 0; i < 6; i++) {
			pG1->addVertexLG(i);
			pG2->addVertexLG(i);
			pG4->addVertexLG(i);
		}
		// 그래프 초기화 : 간선 추가
		pG1->addEdgeLG(0, 1);
		pG1->addEdgeLG(0, 2);
		pG1->addEdgeLG(1, 2);
		pG1->addEdgeLG(2, 3);
		pG1->addEdgeLG(3, 4);
		pG1->addEdgeLG(3, 5);
		pG1->addEdgeLG(4, 5);
		pG1->addEdgeLG(0, 1);
		pG1->addEdgeLG(1, 2);
		pG1->addEdgeLG(2, 0);

		pG2->addEdgeLG(2, 1);
		pG2->addEdgeLG(2, 3);
		pG2->addEdgeLG(3, 2);
		pG2->addEdgeLG(3, 4);
		pG2->addEdgeLG(4, 5);
		pG2->addEdgeLG(5, 3);

		pG4->addEdgewithWeightLG(0, 1, 4);
		pG4->addEdgewithWeightLG(1, 2, 1);
		pG4->addEdgewithWeightLG(2, 0, 2);
		pG4->addEdgewithWeightLG(2, 1, 3);
		pG4->addEdgewithWeightLG(2, 3, 2);
		pG4->addEdgewithWeightLG(3, 2, 1);
		pG4->addEdgewithWeightLG(3, 4, 1);
		pG4->addEdgewithWeightLG(4, 5, 1);
		pG4->addEdgewithWeightLG(5, 3, 2);

		printf("G1: Undirected\n");
		pG1->displayLinkedGraph();
		printf("\nG2: Directed\n");
		pG2->displayLinkedGraph();
		printf("\nG3: Directed Weighted\n");
		pG4->displayLinkedGraph();

		// 그래프 삭제
		pG1->deleteLinkedGraph();
		pG2->deleteLinkedGraph();
		pG4->deleteLinkedGraph();
	}

	return 0;
}