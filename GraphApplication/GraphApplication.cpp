#include <iostream>
#include "Graph.h"


int main()
{
	std::cout << "Creating a new graph\n";
	Graph* g = new Graph();
	g->toggleWeight();
	g->toggleOriented();
	Vertex* v0 = g->addNewVertex();
	Vertex* v1 = g->addNewVertex();
	Vertex* v2 = g->addNewVertex();
	Vertex* v3 = g->addNewVertex();
	Vertex* v4 = g->addNewVertex();
	Vertex* v5 = g->addNewVertex();
	Vertex* v6 = g->addNewVertex();

	g->addEdge(v0, v1, 2);
	g->addEdge(v0, v4, 8);
	
	g->addEdge(v1, v2, 6);
	g->addEdge(v1, v3, 2);

	g->addEdge(v2, v6, 5);

	g->addEdge(v3, v4, 2);
	g->addEdge(v3, v5, 9);

	g->addEdge(v4, v5, 3);

	g->addEdge(v5, v6, 1);


	v0->setAsOrigin();
	g->initializeDijstra();
	g->Dijkstra();

	
	//v2->printPathToOrigin();
	v6->printPathToOrigin();
	/*while (true) {
		system("cls");
		g->printMoveToMenu();
	}*/
}