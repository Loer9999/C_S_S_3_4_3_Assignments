#pragma once

#include <climits>
#include <fstream>
#include "nodedata.h"

// -------------------------------- graphm.h ----------------------------------
// Programmer Name: Po-Lin Tu     Course Section Number: CSS 343 B
// Creation Date: 4/25/2022
// Date of Last Modification: 5/7/2022
//
// Purpose: This file is the header file of my graph class that implements the
// Dijkstra's shortest path algorithm. My graph class can build a graph based
// on an input file that is of a specific format and modify the edges between
// the nodes in the graph. Most importantly, my graph class can find the
// shortest path from every node to every node in the graph and display the
// information about these shortest paths.
// ----------------------------------------------------------------------------

class GraphM
{
public:
    // ---------------------------Default Constructor------------------------------
    // Description: The default constructor creates an empty graph where the number
    // of nodes is zero. As for the adjacency matrix, it has infinity as each of
    // its elements. As for the table, all visited variables are false, all dist
    // variables are infinity, and all path variables are zero.
    //
    // Post: An empty graph, whose attributes are initialized, exists.
    GraphM();

    // ---------------------------------Destructor---------------------------------
    // Description: The destructor deletes this graph.
    //
    // Post: This graph does not exist.
    ~GraphM();

    // --------------------------------buildGraph----------------------------------
    // Description: The method buildGraph reads an input file and builds this graph
    // based on this input file.
    //
    // Pre: The first line of the input must be the number of the nodes. The
    // following lines must contain the text descriptions of these nodes, and one
    // line only contains the description of one node. After the text descriptions,
    // each line, which contains three integers, must represent an edge. The first
    // integer is the starting node of the edge, the second integer is the ending
    // node, and the third integer is the weight of the edge. The end of the input
    // must be signaled by a line whose integers are zero. Additionally, this graph
    // must be empty, and this graph can never have more than 100 nodes, which
    // means that the first line must be a number that is not greater than 100.
    //
    // Post: This method built this graph based on the input. Specifically, the
    // node data, the adjacency matrix, and the size of this graph are updated.
    //
    // Param: input, which is the ifstream object that is associated with the
    // input file.
    void buildGraph(std::ifstream& input);

    // --------------------------------insertEdge----------------------------------
    // Description: The method insertEdge inserts a (directed) edge that is of the
    // given weight between the given two nodes in this graph.
    //
    // Pre: The given weight must be a positive integer. The given two nodes must
    // exist in this graph.
    //
    // Post: The adjacency matrix is updated to include this edge. This method
    // does nothing if the parameters violate the preconditions.
    //
    // Param: start, the node that is the starting node of the edge.
    //
    // Param: end, the node that is the ending node of the edge.
    //
    // Param: weight, the weight of the edge.
    void insertEdge(int start, int end, int weight);

    // --------------------------------removeEdge----------------------------------
    // Description: The method removeEdge removes the (directed) edge between the
    // two given nodes.
    //
    // Pre: The two given nodes must exist in this graph.
    //
    // Post: The element of the adjacency matrix that represents the edge is set to
    // infinity. This method does nothing if one of the nodes does not exist.
    //
    // Param: start, which is the starting node of the edge to remove.
    //
    // Param: end, which is the ending node of the edge to remove.
    void removeEdge(int start, int end);

    // -----------------------------findShortestPath-------------------------------
    // Description: The method findShortestPath finds the shortest path from every
    // node to every node.
    //
    // Pre: This graph must not be empty. The edges in this graph are directed and
    // have positive weights.
    //
    // Post: The table is updated to store the shortest path from every node to
    // every node. If there is no possible path from one node to another node,
    // the distance between these two nodes remains to be infinity. If this graph
    // is empty, this method does nothing.
    void findShortestPath();

    // --------------------------------displayAll----------------------------------
    // Description: The method displayAll shows the shortest path from every node
    // to every node.
    //
    // Pre: This graph must not be empty. The method findShortestPath must have
    // been called.
    //
    // Post: This method displayed the shortest path from every node to every node
    // through the console. If this graph is empty, this method does nothing. If
    // the method findShortestPath has not been called, this method will show that
    // there is no possible path between any two nodes.
    void displayAll() const;

    // ----------------------------------display-----------------------------------
    // Description: The method display shows the detailed description of the
    // shortest path between the two given nodes.
    //
    // Pre: The two given nodes must exist in this graph. The method
    // findShortestPath must have been called.
    //
    // Post: This method displayed the detailed description of the shortest path
    // between the two given nodes through the console. If one of the nodes does
    // not exist in this graph, this method will indicate that there is no possible
    // path between them. If one of the nodes has an index that is less than 1 or
    // greater than the maximum number of nodes, this method does nothing.
    //
    // Param: start, the starting node of the shortest path to display.
    //
    // Param: end, the ending node of the shortest path to display.
    void display(int start, int end) const;

private:
    // The TableType struct stores whether a node has been visited, the shortest
    // distance to this node, and the path to this node.
    struct TableType
    {
        bool visited;
        int dist;
        int path;

        // Set visited to false, set dist to infinity, and set path to zero for
        // each instance of the TableType struct.
        TableType() : visited(false), dist(INT_MAX), path(0)
        {

        }
    };

    // The maximum number of nodes is expected to be 100.
    static const int MAXNODES = 100;

    // Index zero is not used in order to match the numbering of the nodes.
    // Data for graph nodes.
    NodeData data[MAXNODES + 1];

    // The adjacency matrix.
    int C[MAXNODES + 1][MAXNODES + 1];

    // The number of nodes in the graph.
    int size;

    // The table that stores whether the nodes have been visited, the shortest
    // distances to these nodes, and the paths to these nodes.
    TableType T[MAXNODES + 1][MAXNODES + 1];

    // -----------------------------findPathHelper---------------------------------
    // Description: The method findPathHelper deduces the shortest path from the
    // source to one other node in the graph.
    //
    // Pre: The edges in this graph are directed and have positive weights.
    //
    // Post: This method deduced the shortest path from the source to one node.
    // The table is updated for this shortest path.
    //
    // Param: source, which is the source of all the shortest paths.
    //
    // Param: previous, which is the ending node of the previous shortest path (
    // the path that was deduced just before this recursive call).
    void findPathHelper(int source, int previous);

    // -----------------------------showPathHelper---------------------------------
    // Description: The method showPathHelper shows the shortest path between the
    // two given nodes.
    //
    // Pre: The two given nodes must exist in this graph, and the table must store
    // the shortest path between the two given nodes.
    //
    // Post: This method displayed the shortest path between the two given nodes
    // through the console.
    //
    // Param: start, the starting node of the shortest path.
    //
    // Param: end, the ending node of the shortest path.
    void showPathHelper(int start, int end) const;

    // -------------------------showDescriptionHelper------------------------------
    // Description: The method showDescriptionHelper shows the description of the
    // shortest path between the two given nodes.
    //
    // Pre: The two given nodes must exist in this graph, and the table must store
    // the shortest path between the two given nodes.
    //
    // Post: This method displayed the description of the shortest path between the
    // two given nodes through the console.
    //
    // Param: start, the starting node of the shortest path.
    //
    // Param: end, the ending node of the shortest path.
    void showDescriptionHelper(int start, int end) const;
};