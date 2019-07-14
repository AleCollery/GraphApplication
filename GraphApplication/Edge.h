#pragma once

#include "Vertex.h"

class Vertex;

class Edge
{
public:
	Edge();
	Edge(Vertex* _origin, Vertex* _destinatio);
	Edge(Vertex* _origin, Vertex* _destination, int weight);
	int getWeight() const { return weight; };
	Vertex* getOrigin() const { return origin; };
	Vertex* getDestination() const { return destination; };
	bool isValid();

	//Dijkstra
	bool isVirtualEdge() const { return virtualEdge; }
	void setAsVirtualEdge() { virtualEdge = true; }
protected:
	int weight;
	Vertex* origin;
	Vertex* destination;

	//Dijkstra
	bool virtualEdge = false;
};

