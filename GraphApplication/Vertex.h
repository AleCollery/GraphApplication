#pragma once

#include <vector>
#include "Edge.h"

class Edge;

class Vertex
{
public:
	std::vector<Edge*> getEdgesFrom();
	std::vector<Edge*> getEdgesTo();
	void addEdge(Edge* _edge);
	int getId() const { return id; }
	void setId(int _id) { id = _id; };

	//Dijkstra
	bool getIsOrigin() const { return isOrigin; }
	void setAsOrigin() { totalWeight = 0; isOrigin = true; }
	int getTotalWeight() const { return totalWeight; };
	void setTotalWeight(int _w) { totalWeight = _w; }
	Vertex* previousVertex = nullptr;
	std::vector<Vertex*> getDestinationEdges();
	void printPathToOrigin();
	std::vector<Edge*> getBaseEdgesFrom();


protected:
	std::vector<Edge*> edges;
	int id = -999;

	//Dijkstra
	int totalWeight = INT32_MAX;
	bool isOrigin = false;
};

