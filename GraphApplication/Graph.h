#pragma once

#include "Vertex.h"


class Edge;
class Vertex;

class Graph
{
public:
	// vertex 
	Vertex* addNewVertex();
	void addVertex(Vertex* _vertex);

	// edge
	void addEdge(Vertex* _origin, Vertex* _destination);
	void addEdge(Vertex* _origin, Vertex* _destination, int _weight);
	void addEdge(Edge* _edge);

	// attributes
	bool isWeighted() const { return weighted; }
	bool isOriented() const { return oriented; }
	void toggleWeight();
	void toggleOriented();

	// pointer
	Vertex* current();
	std::vector<Edge*> currentEdges();
	std::vector<Vertex*> currentDestinations();
	std::vector<int> currentDestinationIDs();
	void moveTo(int index);

	//io
	void printCurrentEdges();
	void printMoveToMenu();
	
	//Dijkstra
	void Dijkstra();
	int dFindLowerVertex(std::vector<Vertex*> q);
	int getWeightOfEdge(Edge* e);
	
protected:
	Vertex* pointer;
	bool weighted = false;
	bool oriented = true;
	std::vector<Vertex*> vertices;
	std::vector<Edge*> edges;
};

