#include "Vertex.h"
#include <iostream>

void Vertex::addEdge(Edge* _edge)
{
	edges.push_back(_edge);
}

std::vector<Edge*> Vertex::getEdgesFrom()
{
	std::vector<Edge*> edgesFromThis;
	for (int i = 0; i < edges.size(); i++)
	{
		if (edges[i]->getOrigin() == this) 
		{
			edgesFromThis.push_back(edges[i]);
		}
	}
	return edgesFromThis;
}



std::vector<Edge*> Vertex::getEdgesTo()
{
	std::vector<Edge*> edgesFromThis;
	for (int i = 0; i < edges.size(); i++)
	{
		if (edges[i]->getDestination() == this)
		{
			edgesFromThis.push_back(edges[i]);
		}
	}
	return edgesFromThis;
}

std::vector<Vertex*> Vertex::getDestinationEdges()
{
	std::vector<Vertex*> dest;
	for (int i = 0; i < getEdgesFrom().size(); i++) {
		dest.push_back(getEdgesFrom()[i]->getDestination());
	}
	return dest;
}


//Dijkstra

void Vertex::printPathToOrigin() 
{
	Vertex* v = previousVertex;
	std::cout << "Vertex: " << getId() << " total distance: " << totalWeight << std::endl;
	std::cout << getId();
	while (!v->getIsOrigin())
	{
		std::cout << "<-" << v->getId();
		v = v->previousVertex;
	}
	std::cout << "<-" << v->getId() << std::endl;
}

std::vector<Edge*> Vertex::getBaseEdgesFrom() 
{
	std::vector<Edge*> edgesFromThis;
	for (int i = 0; i < edges.size(); i++)
	{
		if (edges[i]->getOrigin() == this && !edges[i]->isVirtualEdge())
		{
			edgesFromThis.push_back(edges[i]);
		}
	}
	return edgesFromThis;
}