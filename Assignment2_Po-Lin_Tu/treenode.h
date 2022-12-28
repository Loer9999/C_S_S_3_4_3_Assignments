#pragma once

#include "nodedata.h"

// ---------------------------------- treenode.h ----------------------------------
// Programmer Name: Po-Lin Tu     Course Section Number: CSS 343 B
// Creation Date: 4/5/2022
// Date of Last Modification: 4/17/2022
//
// Purpose: This file is the header file of the TreeNode class that defines the
// tree nodes in my binary search tree. A tree node have pointers that point to the
// node data and its left and right children.
// --------------------------------------------------------------------------------


class TreeNode
{
private:
    NodeData* data;
    TreeNode* left;
    TreeNode* right;

    friend class BinTree;

public:
    // ---------------------------Default Constructor------------------------------
    // Description: The default constructor creates an empty tree node.
    //
    // Post: An empty tree node, whose pointers are all null pointers, exists.
    TreeNode();

    // ------------------------Parametrized Constructor----------------------------
    // Description: The parametrized constructor creates a new tree node whose
    // pointers are set to the parameters.
    //
    // Post: A new tree node, whose pointers are set to the parameters, exists.
    //
    // Parameter: dataPtr, a pointer to the node data.
    //
    // Parameter: leftPtr, a pointer to the tree node that should be the left child.
    //
    // Parameter: rightPtr, a pointer to the tree node that should be the right
    // child.
    TreeNode(NodeData* dataPtr, TreeNode* leftPtr, TreeNode* rightPtr);

    // ------------------------------Destructor------------------------------------
    // Description: The destructor deletes this tree node, freeing the memory that
    // was dynamically allocated to this tree node.
    //
    // Post: This tree node does not exist, and the dynamically allocated memory
    // is free.
    ~TreeNode();
};