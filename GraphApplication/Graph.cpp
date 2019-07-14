#include "Graph.h"
#include <iostream>

void Graph::toggleWeight()
{
	weighted = !weighted;
}

void Graph::toggleOriented()
{
	oriented = !oriented;
}

// pointer
Vertex* Graph::current()
{
	if (vertices.size() == 0) 
	{
		return nullptr;
	}
	if (pointer == nullptr) 
	{
		pointer = vertices[0];
	};
	return pointer;
}

std::vector<Edge*> Graph::currentEdges()
{
	return current()->getEdgesFrom();
}

std::vector<Vertex*> Graph::currentDestinations() 
{
	std::vector<Vertex*> dest;
	for (int i = 0; i < currentEdges().size(); i++) {
		dest.push_back(currentEdges()[i]->getDestination());
	}
	return dest;
}

std::vector<int> Graph::currentDestinationIDs()
{
	std::vector<int> destID;
	for (int i = 0; i < currentEdges().size(); i++) {
		destID.push_back(currentEdges()[i]->getDestination()->getId());
	}
	return destID;
}

void Graph::moveTo(int index)
{
	for (int i = 0 ; i < currentEdges().size(); i++)
	{
		if (currentEdges()[i]->getDestination()->getId() == index)
		{
			pointer = currentEdges()[i]->getDestination();
			return;
		}
	}
}

// vertex
Vertex* Graph::addNewVertex()
{
	Vertex* v = new Vertex();
	addVertex(v);
	return v;
}

void Graph::addVertex(Vertex* _vertex)
{
	if (_vertex->getId() == -999) 
	{
		_vertex->setId((int)vertices.size());
	}
	vertices.push_back(_vertex);
}

// edge
void Graph::addEdge(Vertex* _origin, Vertex* _destination, int _weight)
{
	
	Edge* e = new Edge(_origin, _destination, _weight);
	_origin->addEdge(e);
	_destination->addEdge(e);
	if (!oriented) {
		Edge* secondEdge = new Edge(_destination, _origin, _weight);
		secondEdge->setAsVirtualEdge();
		_origin->addEdge(secondEdge);
		_destination->addEdge(secondEdge);
		addEdge(secondEdge);
	}
	addEdge(e);
}

void Graph::addEdge(Vertex* _origin, Vertex* _destination) 
{
	addEdge(_origin, _destination, 1);
}

void Graph::addEdge(Edge* _edge) 
{
	edges.push_back(_edge);
}

//print
void Graph::printCurrentEdges()
{
	std::vector<Edge*> _currentEdges = currentEdges();
	std::cout << "Current edges: \n";
	for (int i = 0; i < _currentEdges.size(); i++)
	{
		std::cout << "  " << _currentEdges[i]->getOrigin()->getId();
		if (weighted) { 
			for (int w = 0; w < _currentEdges[i]->getWeight(); w++) {
				std::cout << "-";} 
			std::cout << ">"; 
		}
		else { std::cout << "->"; }
		std::cout << _currentEdges[i]->getDestination()->getId() << std::endl;
	}
}

void Graph::printMoveToMenu()
{
	int index;
	std::cout << "Graph\n" << "number of edges: " << edges.size() << " number of vertices: " << vertices.size() << std::endl;
	std::cout << "Current Vertex: " << current()->getId() << std::endl;
	printCurrentEdges();
	std::cout << "Select edge to move to: ";
	std::cin >> index;
	moveTo(index);
}


// Dijkstra

int Graph::dFindLowerVertex(std::vector<Vertex*> q)
{
	int min = q[0]->getTotalWeight();
	int index = 0;
	for (int i = 0; i < q.size(); i++)
	{
		if (q[i]->getTotalWeight() < min) {
			min = q[i]->getTotalWeight();
			index = i;
		}
	}
	return index;
}

void Graph::Dijkstra() 
{
	std::vector<Vertex*> Q = vertices;
	std::vector<Edge*> adj;
	Vertex* u;
	int index;
	int alt;
	int edgeWeight;
	while (Q.size() > 0)
	{
		index = dFindLowerVertex(Q);
		u = Q[index];
		Q.erase(Q.begin() + index);
		if (u->getTotalWeight() == INT32_MAX) 
		{
			break;
		}

		if(isOriented())
		{
			adj = u->getBaseEdgesFrom();
		}
		else{ adj = u->getEdgesFrom(); }
		
		for (int i = 0; i < adj.size(); i++)
		{
			edgeWeight = getWeightOfEdge(adj[i]);
			alt = u->getTotalWeight() + edgeWeight;
			if (alt < adj[i]->getDestination()->getTotalWeight())
			{
				adj[i]->getDestination()->setTotalWeight(alt);
				adj[i]->getDestination()->previousVertex = u;
			}
		}
	}
}

int Graph::getWeightOfEdge(Edge* e)
{
	if (!isWeighted()) return 1;
	return e->getWeight();
}



