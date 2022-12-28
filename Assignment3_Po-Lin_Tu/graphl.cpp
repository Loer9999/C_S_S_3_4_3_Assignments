#include <ostream>
#include "graphl.h"

// ------------------------------- graphl.cpp ---------------------------------
// Programmer Name: Po-Lin Tu     Course Section Number: CSS 343 B
// Creation Date: 5/1/2022
// Date of Last Modification: 5/7/2022
//
// Purpose: This file is the implementation file of my graph class that
// implements the depth-first search. My graph class can build a graph based on
// an input file that is of a specific format and display the information about
// the nodes and the edges in the graph. Most importantly, my graph class can
// perform the depth-first search.
// ----------------------------------------------------------------------------

// ---------------------------Default Constructor------------------------------
// Description: The default constructor creates an empty graph where the number
// of nodes is zero.
//
// Post: An empty graph exists.
GraphL::GraphL() : size(0)
{

} // end of the default constructor

// -------------------------------Destructor-----------------------------------
// Description: The destructor deletes this graph, freeing the memory that was
// dynamically allocated to the instances of the EdgeNode struct and the
// instances of the NodeData class.
//
// Post: This graph does not exist. The memory that was dynamically allocated
// to this graph is free.
GraphL::~GraphL()
{
    // Delete the edge list and the node data of each of the nodes in this
    // graph.
    for (int i = 1; i <= size; i++)
    {
        while (N[i].edgeHead != nullptr)
        {
            EdgeNode* temp = N[i].edgeHead;
            N[i].edgeHead = N[i].edgeHead -> nextEdge;
            delete temp;
            temp = nullptr;
        }

        if (N[i].data != nullptr)
        {
            delete N[i].data;
            N[i].data = nullptr;
        }
    }
} // end of the destructor

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
void GraphL::buildGraph(std::ifstream& input)
{
    // Only read the input if this graph is empty.
    if (size == 0)
    {
        // Read the first line of the input as an integer. If this evaluates to
        // false, the end of the input file is reached, and this method stops
        // reading the input file.
        int temp = 0;
        if (input >> temp)
        {
            size = temp;

            // Advance to the second line of the input.
            std::string next;
            std::getline(input, next);

            // Read the text description of each node.
            for (int i = 1; i <= size; i++)
            {
                N[i].data = new NodeData();
                N[i].data -> setData(input);
            }

            // Read the lines that represent the edges.
            int first;
            int second;
            input >> first;
            input >> second;
            while (first != 0)
            {
                EdgeNode* temp = N[first].edgeHead;
                N[first].edgeHead = new EdgeNode();
                N[first].edgeHead -> adjGraphNode = second;
                N[first].edgeHead -> nextEdge = temp;

                input >> first;
                input >> second;
            }
        }
    }
} // end of the method buildGraph

// -------------------------------displayGraph---------------------------------
// Description: The method displayGraph shows the description and the edges of
// each of the nodes in this graph.
//
// Pre: This graph must not be empty.
//
// Post: This method showed the description and the edges of each of the nodes
// through the console. If this graph is emtpy, this method does nothing.
void GraphL::displayGraph() const
{
    std::cout << "Graph:" << std::endl;

    // Display the description and the edges for each of the nodes.
    for (int i = 1; i <= size; i++)
    {
        std::cout << "Node " << i << "\t\t" << *(N[i].data) << std::endl;

        EdgeNode* current = N[i].edgeHead;
        while (current != nullptr)
        {
            std::cout << "  edge " << i << " " << (current -> adjGraphNode)
                      << std::endl;
            current = current -> nextEdge;
        }
    }

    std::cout << std::endl;
} // end of the method displayGraph

// ----------------------------depthFirstSearch--------------------------------
// Description: The method depthFirstSearch displays each node in this graph
// by performing a depth-first search.
//
// Pre: This graph must not be empty. All the nodes in this graph must be
// marked unvisited.
//
// Post: This method displayed each node in this graph through the console in
// depth-first order. If this graph is empty, this method does nothing.
void GraphL::depthFirstSearch()
{
    // Only perform depth-first search if this graph is not empty.
    if (size > 0)
    {
        std::cout << "Depth-first ordering: ";

        // Check each node in this graph.
        for (int i = 1; i <= size; i++)
        {
            // Perform depth-first search on each unvisited node.
            if (!N[i].visited)
            {
                depthFirstSearchHelper(i);
            }
        }

        std::cout << std::endl << std::endl;

        // After the depth-first search, reset all nodes by setting them to
        // unvisited.
        for (int i = 1; i <= size; i++)
        {
            N[i].visited = false;
        }
    }
} // end of the method depthFirstSearch

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
void GraphL::depthFirstSearchHelper(int node)
{
    // Print this node and mark this node as visited.
    std::cout << node << " ";
    N[node].visited = true;

    // Check each edge of this node.
    EdgeNode* current = N[node].edgeHead;
    while (current != nullptr)
    {
        // Perform depth-first search on the adjacent node if this adjacent node
        // is unvisited.
        if (!N[current -> adjGraphNode].visited)
        {
            depthFirstSearchHelper(current -> adjGraphNode);
        }

        current = current -> nextEdge;
    }
} // end of the method depthFirstSearchHelper