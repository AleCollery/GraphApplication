#include "Edge.h"



bool Edge::isValid()
{
	return (origin != NULL && destination != NULL);
}

Edge::Edge() 
{
	Edge(nullptr, nullptr, 1);
}

Edge::Edge(Vertex* _origin, Vertex* _destination)
{
	Edge( _origin, _destination, 1);
}

Edge::Edge(Vertex* _origin, Vertex* _destination, int _weight)
{
	origin = _origin;
	destination = _destination;
	weight = _weight;
}

