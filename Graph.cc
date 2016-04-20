#include "Graph.h"

GraphL::GraphL(istream & source)
{
    // Read number of vertices and number of edges
    int numberOfEdges;
    source >> _numberOfVertices >> numberOfEdges;
    // Read in names of vertices.  Add a Vertex object for each to the
    // _vertex array, and also temporarily store its name in a map to
    // facilitate reading in the edge descriptions by vertex name
    _vertex = new Vertex[_numberOfVertices];
    map < string, int > nameMap;
    for (int i = 0; i < _numberOfVertices; i ++)
    {
        string name;
        source >> name;
        _vertex[i]._name = name;
        nameMap[name] = i;
    }
    // Read in edges.  Add an edge node for each to the adjacency
    // list for its vertices
    for (int i = 0; i < numberOfEdges; i ++)
    {
        string tail, head;
        source >> tail >> head;
        int tailIndex = nameMap[tail];
        int headIndex = nameMap[head];
        // **** FOR A NETWORK, ADD THE FOLLOWING LINES, AND ADD weight AS A ****
        // **** PARAMETER TO THE Edge CONSTRUCTOR IN THE SUBSEQUENT LINE(S) ****
        // double weight;
        // source >> weight;
        _vertex [ tailIndex ]._edges.push_back(Edge(headIndex));
        // ** THE FOLLOWING LINE WOULD BE OMITTED FOR A DIGRAPH **
        _vertex [ headIndex ]._edges.push_back(Edge(tailIndex));
    }
}
