#include <climits>
#include <string>
#include <ostream>
#include "graphm.h"

// ------------------------------- graphm.cpp ---------------------------------
// Programmer Name: Po-Lin Tu     Course Section Number: CSS 343 B
// Creation Date: 4/25/2022
// Date of Last Modification: 5/7/2022
//
// Purpose: This file is the implementation file of my graph class that
// implements the Dijkstra's shortest path algorithm. My graph class can build
// a graph based on an input file that is of a specific format and modify the
// edges between the nodes in the graph. Most importantly, my graph class can
// find the shortest path from every node to every node in the graph and
// display the  information about these shortest paths.
// ----------------------------------------------------------------------------

// ---------------------------Default Constructor------------------------------
// Description: The default constructor creates an empty graph where the number
// of nodes is zero. As for the adjacency matrix, it has infinity as each of
// its elements. As for the table, all visited variables are false, all dist
// variables are infinity, and all path variables are zero.
//
// Post: An empty graph, whose attributes are initialized, exists.
GraphM::GraphM() : size(0)
{
    // Initialize the adjacency matrix.
    for (int i = 0; i <= MAXNODES; i++)
    {
        for (int j = 0; j <= MAXNODES; j++)
        {
            C[i][j] = INT_MAX;
        }
    }
} // end of the default constructor

// ---------------------------------Destructor---------------------------------
// Description: The destructor deletes this graph.
//
// Post: This graph does not exist.
GraphM::~GraphM()
{

} // end of the destructor

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
// This method does nothing if this graph is not empty.
//
// Param: input, which is the ifstream object that is associated with the
// input file.
void GraphM::buildGraph(std::ifstream& input)
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
                data[i].setData(input);
            }

            // Read the lines that represent the edges.
            int first;
            int second;
            int third;
            input >> first;
            input >> second;
            input >> third;
            while (first != 0)
            {
                insertEdge(first, second, third);
                input >> first;
                input >> second;
                input >> third;
            }
        }
    }
} // end of the method buildGraph

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
void GraphM::insertEdge(int start, int end, int weight)
{
    // Insert the edge if the preconditions are not violated.
    if (start > 0 && start <= size && end > 0 && end <= size && weight > 0)
    {
        C[start][end] = weight;
    }
} // end of the method insertEdge

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
void GraphM::removeEdge(int start, int end)
{
    // Remove the edge if the two given nodes exist.
    if (start > 0 && start <= size && end > 0 && end <= size)
    {
        C[start][end] = INT_MAX;
    }
} // end of the method removeEdge

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
void GraphM::findShortestPath()
{
    // Reset the table.
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            T[i][j].visited = false;
            T[i][j].dist = INT_MAX;
            T[i][j].path = 0;
        }
    }

    // For every node in this graph, find the shortest paths from it to the
    // other nodes in this graph.
    for (int source = 1; source <= size; source++)
    {
        T[source][source].dist = 0;
        findPathHelper(source, source);
    }
} // end of the method findShortestPath

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
// there is no possible between any two nodes.
void GraphM::displayAll() const
{
    // Only show the shortest paths if this graph is not empty.
    if (size > 0)
    {
        // Display the column headers.
        std::cout << "Description\t\tFrom node\tTo node\t\tDijkstra's\tPath" << std::endl;

        // Display the shortest paths from each of the sources.
        for (int i = 1; i <= size; i++)
        {
            std::cout << data[i] << std::endl;

            for (int j = 1; j <= size; j++)
            {
                if (i != j)
                {
                    std::cout << "\t\t\t" << i << "\t\t" << j << "\t\t";

                    // Display the shortest path to the node if there is one.
                    // Display "---" if there is no possible path from the
                    // source to this node.
                    if (T[i][j].dist < INT_MAX)
                    {
                        std::cout << T[i][j].dist << "\t\t";
                        showPathHelper(i, j);
                    }
                    else
                    {
                        std::cout << "---";
                    }
                    std::cout << std::endl;
                }
            }
        }
        std::cout << std::endl;
    }
} // end of the method displayAll

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
void GraphM::display(int start, int end) const
{
    if (start > 0 && start <= MAXNODES && end > 0 && end <= MAXNODES)
    {
        std::cout << start << "\t" << end << "\t";

        // Display detailed description of the shortest path between the two given
        // nodes if there is one.
        if (T[start][end].dist < INT_MAX)
        {
            std::cout  << T[start][end].dist << "\t";
            showPathHelper(start, end);
            std::cout << std::endl;
            showDescriptionHelper(start, end);
            std::cout << std::endl;
        }
        // Display "---" if there is no possible path between the two given nodes.
        else
        {
            std::cout << "---" << std::endl << std::endl;
        }
    }
} // end of the method display

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
void GraphM::findPathHelper(int source, int previous)
{
    // Mark the ending node of the previous shortest path as visited. This
    // recursive call considers the edges of this node.
    T[source][previous].visited = true;

    // Check all the edges from the ending node of the previous shortest path.
    for (int i = 1; i <= size; i++)
    {
        // Update the possible shortest paths from the source to the other
        // unvisited nodes based on the edges from the ending node of the
        // previous shortest path.
        if (!T[source][i].visited && C[previous][i] < INT_MAX)
        {
            int temp = T[source][previous].dist + C[previous][i];
            if (temp < T[source][i].dist)
            {
                T[source][i].dist = temp;
                T[source][i].path = previous;
            }

        }
    }

    // Find the next shortest path. Notice that T[source][0].dist is infinity.
    int shortest = 0;
    for (int i = 1; i <=size; i++)
    {
        if (!T[source][i].visited && T[source][i].dist < T[source][shortest].dist)
        {
            shortest = i;
        }
    }

    // Continue to find the shortest paths using the shortest path deduced in
    // this recursive call. If the distance of the shortest path is infinity,
    // this means that this recursive call has reached the base case. The
    // shortest paths between the source and all the nodes that connect to
    // the source have been deduced.
    if (T[source][shortest].dist < INT_MAX)
    {
        findPathHelper(source, shortest);
    }
} // end of the method findPathHelper

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
void GraphM::showPathHelper(int start, int end) const
{
    // The shortest path to the same node is the node itself.
    if (start == end)
    {
        std::cout << start << " ";
    }
    else
    {
        // Show the shortest path to the nearest neighbor of the ending node.
        showPathHelper(start, T[start][end].path);
        std::cout << end << " ";
    }
} // end of the method showPathHelper

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
void GraphM::showDescriptionHelper(int start, int end) const
{
    // The shortest path to the same node is the node itself.
    if (start == end)
    {
        std::cout << data[start] << std::endl;
    }
    else
    {
        // Show the description of the shortest path to the nearest neighbor of
        // the ending node.
        showDescriptionHelper(start, T[start][end].path);
        std::cout << data[end] << std::endl;
    }
} // end of the method showDescriptionHelper