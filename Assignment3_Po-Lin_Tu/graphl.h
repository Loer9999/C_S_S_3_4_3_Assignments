#pragma once

#include <fstream>
#include "nodedata.h"

// -------------------------------- graphl.h ----------------------------------
// Programmer Name: Po-Lin Tu     Course Section Number: CSS 343 B
// Creation Date: 5/1/2022
// Date of Last Modification: 5/7/2022
//
// Purpose: This file is the header file of my graph class that implements the
// depth-first search. My graph class can build a graph based on an input file
// that is of a specific format and display the information about the nodes
// and the edges in the graph. Most importantly, my graph class can perform the
// depth-first search.
// ----------------------------------------------------------------------------

class GraphL
{
public:
    // ---------------------------Default Constructor------------------------------
    // Description: The default constructor creates an empty graph where the number
    // of nodes is zero.
    //
    // Post: An empty graph exists.
    GraphL();

    // -------------------------------Destructor-----------------------------------
    // Description: The destructor deletes this graph, freeing the memory that was
    // dynamically allocated to the instances of the EdgeNode struct and the
    // instances of the NodeData class.
    //
    // Post: This graph does not exist. The memory that was dynamically allocated
    // to this graph is free.
    ~GraphL();

    // --------------------------------buildGraph----------------------------------
    // Description: The method buildGraph reads an input file and builds this graph
    // based on this input file.
    //
    // Pre: The first line of the input must be the number of the nodes. The
    // following lines must contain the text descriptions of these nodes, and one
    // line only contains the description of one node. After the text descriptions,
    // each line, which contains two integers, must represent an edge. The first
    // integer is the starting node of the edge, and the second integer is the
    // ending node. The end of the input must be signaled by a line whose integers
    // are zero. Additionally, this graph must be empty, and this graph can never
    // have more than 100 nodes, which means that the first line must be a number
    // that is not greater than 100.
    //
    // Post: This method built this graph based on the input. Specifically, the
    // size of this graph and the adjacency list are updated.
    //
    // Param: input, which is the ifstream object that is associated with the
    // input file.
    void buildGraph(std::ifstream& input);

    // -------------------------------displayGraph---------------------------------
    // Description: The method displayGraph shows the description and the edges of
    // each of the nodes in this graph.
    //
    // Pre: This graph must not be empty.
    //
    // Post: This method showed the description and the edges of each of the nodes
    // through the console. If this graph is emtpy, this method does nothing.
    void displayGraph() const;

    // ----------------------------depthFirstSearch--------------------------------
    // Description: The method depthFirstSearch displays each node in this graph
    // by performing a depth-first search.
    //
    // Pre: This graph must not be empty. All the nodes in this graph must be
    // marked unvisited.
    //
    // Post: This method displayed each node in this graph through the console in
    // depth-first order. If this graph is empty, this method does nothing.
    void depthFirstSearch();

private:
    // The EdgeNode struct represents an edge of a node in this graph.
    struct EdgeNode
    {
        // The index of an adjacent graph node.
        int adjGraphNode;

        // The pointer to the next edge of this graph node.
        EdgeNode* nextEdge;

        EdgeNode() : adjGraphNode(0), nextEdge(nullptr)
        {

        }
    };

    // The GraphNode struct represents a node in this graph.
    struct GraphNode
    {
        // The pointer to the head of the list of edges of this graph node.
        EdgeNode* edgeHead;

        // The description of this graph node.
        NodeData* data;

        bool visited;

        GraphNode() : edgeHead(nullptr), data(nullptr), visited(false)
        {

        }
    };

    // The maximum number of nodes is expected to be 100.
    static const int MAXNODES = 100;

    // The number of nodes in the graph.
    int size;

    // An array of graph nodes that contains the nodes (and the lists of their
    // edges) in this graph. This acts as the adjacency list. Index zero is not
    // used in order to match the numbering of the nodes in this graph.
    GraphNode N[MAXNODES + 1];

    // -------------------------depthFirstSearchHelper-----------------------------
    // Description: The method depthFirstSearchHelper performs depth-first search
    // on the given node and prints each node it visits.
    //
    // Pre: The given node must exist in this graph and must be unvisited.
    //
    // Post: This method printed each of the nodes that could be visited by
    // performing depth-first search on the given node. This method also marked
    // these nodes as visited.
    //
    // Param: node, which is the index of the node to perform depth-first search on.
    void depthFirstSearchHelper(int node);
};