#pragma once

#include <iostream>
#include "treenode.h"

// -------------------------------- bintree.h -------------------------------------
// Programmer Name: Po-Lin Tu     Course Section Number: CSS 343 B
// Creation Date: 4/5/2022
// Date of Last Modification: 4/17/2022
//
// Purpose: This file is the header file of the BinTree class that defines my
// binary search tree. As for the data, my binary search tree can contain tree
// nodes whose data items are strings. As for the behaviors, my binary search tree
// overloads the equality and the inequality operators that compare two binary
// search trees. My binary search tree supports mutators that allow the client to
// add nodes to this binary search tree or empty this tree. My binary search tree
// also supports accessors that can traverse through the tree, retrieve a data item
// in the tree, or report the height of a data item. Finally, my binary search tree
// can be converted to a sorted array or be created from a sorted array.
// --------------------------------------------------------------------------------

class BinTree
{
public:
    // ---------------------------Default Constructor------------------------------
    // Description: The default constructor creates an empty tree.
    //
    // Post: An empty tree, whose root node is a null pointer, exists.
    BinTree();

    // ------------------------------Copy Constructor------------------------------
    // Description: The copy constructor copies the given binary search tree and
    // creates a new binary search tree that is the same as the given one.
    //
    // Pre: The given tree must be a binary search tree.
    //
    // Post: A new binary search tree that is the same as the given binary search
    // tree exists.
    //
    // Parameter: other, which is the binary search tree to copy.
    BinTree(const BinTree& other);

    // ------------------------------Destructor------------------------------------
    // Description: The destructor deletes this binary search tree, freeing the
    // memory that is dynamically allocated to this tree.
    //
    // Post: This binary search tree does not exist, and the dynamically allocated
    // memory is free.
    ~BinTree();

    // -------------------------------isEmpty--------------------------------------
    // Description: The method isEmpty reports whether this binary search tree is
    // empty.
    //
    // Post: This binary search tree does not change.
    //
    // Return: True if this binary search tree is empty (root node is a null
    // pointer); false otherwise.
    bool isEmpty() const;

    // -------------------------------makeEmpty------------------------------------
    // Description: The method makeEmpty empties this binary search tree, freeing
    // the memory that is dynamically allocated to each node in this tree.
    //
    // Post: This binary search tree is empty (the root node is a null pointer).
    // The dynamically allocated memory is free.
    void makeEmpty();

    // ------------------------------operator = -----------------------------------
    // Description: The method operator= overloads the operator =, assigning the
    // binary search tree on the right-hand side of the operator = to this binary
    // search tree, which is on the left-hand side.
    //
    // Pre: The tree on the right-hand side must be a binary search tree.
    //
    // Post: This binary search tree is the same as the one on the right-hand
    // side.
    //
    // Parameter: rhs, the binary search tree to assign to this one.
    //
    // Return: A reference to this binary search tree.
    BinTree& operator=(const BinTree& rhs);

    // ------------------------------operator == ----------------------------------
    // Description: The operator == reports whether this binary search tree, which
    // is on the left-hand side of the operator ==, and the binary search tree on
    // the right-hand side have the same data items and the same structure.
    //
    // Post: Both binary search trees do not change.
    //
    // Parameter: rhs, which is the binary search tree on the right-hand side.
    //
    // Return: True if the two binary search trees are the same; false otherwise.
    bool operator==(const BinTree& rhs) const;

    // ------------------------------operator != ----------------------------------
    // Description: The operator != reports whether this binary search tree, which
    // is on the left-hand side of the operator !=, and the binary search tree on
    // the right-hand side do not have the same data items and the same structure.
    //
    // Post: Both binary search trees do not change.
    //
    // Parameter: rhs, which is the binary search tree on the right-hand side.
    //
    // Return: True if the two binary search trees are not the same; false
    // otherwise.
    bool operator!=(const BinTree& rhs) const;

    // ---------------------------------insert-------------------------------------
    // Description: The method insert adds a tree node with the given node data
    // object, which contains a string, to this binary search tree.
    //
    // Pre: This binary search tree must be valid based on the strings that the
    // node data objects in this tree contain. The given node data object must be
    // dynamically allocated.
    //
    // Post: A tree node with the given node data object is added to this binary
    // search tree, and this binary search tree is still valid. If the same node
    // data object have already been inserted into this binary search tree, this
    // method does nothing.
    //
    // Parameter: newData, a node data object to insert into this binary search
    // tree.
    //
    // Return: True if this method added a tree node with the given node data
    // object to this binary search tree; false if this method did nothing.
    bool insert(NodeData* newData);

    // ------------------------------operator << ----------------------------------
    // Description: The method operator << overloads the operator<<, displaying
    // the given binary search tree, which is on the right-hand side of the
    // operator <<, through the given ostream object, which is on the left-hand
    // side, by using inorder traversal.
    //
    // Post: This method displays the given binary search tree with inorder
    // traversal. The binary search tree does not change.
    //
    // Parameter: output, which is the ostream object through which the binary
    // search tree should be displayed.
    //
    // Parameter: binTree, which is the binary search tree to display.
    //
    // Return: A reference to the ostream object.
    friend std::ostream& operator<<(std::ostream& output, const BinTree& binTree);

    // --------------------------------retrieve------------------------------------
    // Description: The retrieve method finds the given node data object in this
    // binary search tree and set the given pointer to the address of the given
    // object in this tree.
    //
    // Post: The given pointer will point to the given node data object in this
    // binary search tree if the given object is in this tree. The given pointer
    // will point to garbage if the given object is not in this tree.
    //
    // Parameter: target, which is the object to retrieve.
    //
    // Parameter: pointer, which will point to the given object if it is in this
    // tree.
    //
    // Return: True if this method found the given object, false otherwise.
    bool retrieve(const NodeData& target, NodeData*& pointer) const;

    // -------------------------------getHeight------------------------------------
    // Description: The method getHeight reports the height of the tree node that
    // contains the given node data object.
    //
    // Pre: The given node data object should be in this binary search tree.
    //
    // Post: This binary search tree does not change.
    //
    // Parameter: target, which is the node data object whose height should be
    // reported.
    //
    // Return: The height of the given node data object; zero if the given object
    // does not exist in this binary search tree.
    int getHeight(const NodeData& target) const;

    // ----------------------------displaySideways---------------------------------
    // Description: The method displaySideways displays this binary search tree as
    // though you are viewing it from the side.
    //
    // Post: This binary search tree does not change.
    void displaySideways() const;

    // -----------------------------bstreeToArray----------------------------------
    // Description: The method bstreeToArray adds the node data objects in this
    // binary search tree to the given array based on inorder traversal.
    //
    // Pre: The given array should be a statically allocated array which has 100
    // null pointers. The number of tree nodes in this binary search tree cannot be
    // greater than 100.
    //
    // Post: The given array contains the node data objects in this binary search
    // tree, and the node data objects are sorted in an increasing order based on
    // the strings they contain. This binary search tree is empty.
    //
    // Parameter: dataArray, which is the array where the node data objects should
    // be contained.
    void bstreeToArray(NodeData* dataArray[]);

    // -----------------------------arrayToBSTree----------------------------------
    // Description: The method arrayToBSTree creates a balanced binary search tree
    // from a sorted array that contains node data objects.
    //
    // Pre: The given array should be of size 100 and be sorted in an increasing
    // order based on the strings that the node data objects contain. This binary
    // search tree should be empty. Finally, there should not be null pointers
    // between the node data objects in the given array.
    //
    // Post: The node data objects in the given array are replaced with null
    // pointers. This binary search tree is a balanced tree which contains the node
    // data objects that the given array contained. If the given array is not
    // sorted or this binary search tree is not empty when this method is invoked,
    // this method does nothing. If there are null pointers between the node data
    // objects in the given array, this method considers the node data objects
    // before the first null pointer.
    //
    // Parameter: dataArray, which is the array that contains node data objects.
    void arrayToBSTree(NodeData* dataArray[]);

private:
    TreeNode* root;

    // -------------------------------emptyHelper----------------------------------
    // Description: The method emptyHelper deletes the binary tree whose root node
    // is the given tree node, freeing the memory that is dynamically allocated to
    // the binary tree.
    //
    // Pre: The given tree node must be a node of this binary search tree (where
    // this method is initially invoked) or a null pointer.
    //
    // Post: The binary tree whose root node is the given tree node is empty. The
    // dynamically allocated memory is free.
    //
    // Parameter: rootEmpty, which is the root node of the binary tree to delete
    // within this recursive call.
    void emptyHelper(TreeNode*& rootEmpty);

    // -------------------------------copyHelper---------------------------------
    // Description: The method copyHelper copies another binary search tree to
    // this binary search tree by using preorder traversal to add the nodes in
    // another binary search tree, whose root node is the given tree node, to
    // this binary search tree.
    //
    // Pre: The given tree node must be a node of the binary search tree to copy.
    // Before this method is initially invoked, this binary search tree (where
    // this method is initially invoked) must be empty.
    //
    // Post: The nodes in the binary search tree whose root node is the given tree
    // node is added to this binary search tree based on preorder traversal.
    //
    // Parameter: rootCopy, which is the root node of the binary search tree to
    // copy within this recursive call.
    void copyHelper(TreeNode* rootCopy);

    // ------------------------------compareHelper---------------------------------
    // Description: The method compareHelper checks whether the two binary trees,
    // whose root nodes are the given nodes, have the same data items and the same
    // structure.
    //
    // Pre: One given node must be a node of this binary search tree (where this
    // method is initially invoked); the other given node must be a node of a
    // different binary tree.
    //
    // Post: Both binary trees do not change.
    //
    // Parameter: rootThis, which is a node of this binary search tree and is the
    // root node of a binary tree to check within this recursive call.
    //
    // Parameter: rootOther, which is a node of a different binary tree and is
    // the root node of another binary tree to check within this recursive call.
    //
    // Return: True if the two binary trees are the same; false otherwise.
    bool compareHelper(TreeNode* rootThis, TreeNode* rootOther) const;

    // -------------------------------outputHelper---------------------------------
    // Description: The method outputHelper outputs the binary tree whose root
    // node is the given tree node through the given ostream object by using
    // inorder traversal.
    //
    // Pre: The given tree node must be a node of this binary search tree (where
    // this method is initially invoked).
    //
    // Post: This method displays the binary tree whose root node is the given tree
    // node with inorder traversal. The binary tree does not change.
    //
    // Parameter: output, which is the ostream object through which the binary
    // tree should be outputted.
    //
    // Parameter: rootOutput, which is the root node of the binary tree to output
    // within this recursive call.
    void outputHelper(std::ostream& output, TreeNode* rootOutput) const;

    // ------------------------------retrieveHelper--------------------------------
    // Description: The method retrieveHelper finds the given node data object in
    // the binary search tree whose root node is the given node and set the given
    // pointer to the address of the given object in the tree.
    //
    // Pre: The given node must be a node of this binary search tree.
    //
    // Post: The given pointer will point to the given node data object in the
    // binary search tree if the given object is in the tree. The given pointer
    // will point to garbage if the given object is not in the tree.
    //
    // Parameter: target, which is the object to retrieve.
    //
    // Parameter: pointer, which will point to the given object if it is in the
    // tree.
    //
    // Parameter: rootRetrieve, which is the root node of the binary search tree
    // that this recursive call considers.
    //
    // Return: True if this method found the given object, false otherwise.
    bool retrieveHelper(const NodeData& target, NodeData*& pointer, TreeNode* rootRetrieve) const;

    // -------------------------------heightHelper---------------------------------
    // Description: The method heightHelper searches for the tree node that
    // contains the given node data object within the binary tree whose root node
    // is the given node and reports the height of the node that contains the
    // object.
    //
    // Pre: The given node data object should be in this binary search tree (where
    // this method is initially invoked). The given tree node should be a node of
    // this binary search tree.
    //
    // Post: The binary tree whose root node is the given tree node does not
    // change.
    //
    // Parameter: target, which is the node data object whose height should be
    // reported.
    //
    // Parameter: rootGetHeight, which is the root node of the binary tree that
    // this recursive call considers.
    //
    // Parameter: height, which is the cumulative height of the given node data
    // object. If this is greater than zero, the tree node that contains the
    // object is an ascendant of the binary tree whose root node is the given
    // tree node.
    //
    // Return: The height of the given node data object; zero if the object does
    // not exist in the binary tree whose root node is the given node.
    int heightHelper(const NodeData& target, TreeNode* rootGetHeight, int height) const;

    // -----------------------------sidewaysHelper---------------------------------
    // Description: The method sidewaysHelper displays the binary tree whose root
    // node is the given tree node as if you are viewing it from the side.
    //
    // Pre: The given tree node should be a node of this binary search tree (where
    // this method is initially invoked).
    //
    // Post: The binary tree whose root node is the given tree node does not change.
    //
    // Parameter: rootSideways, which is the root node of the binary tree that this
    // recursive call considers.
    //
    // Parameter: level, which is an integer that determines the indentation.
    void sidewaysHelper(TreeNode* rootSideways, int level) const;

    // ------------------------------toArrayHelper---------------------------------
    // Description: The method toArrayHelper adds the node data objects in the
    // binary search tree whose root node is the given tree node to the given
    // array based on inorder traversal.
    //
    // Pre: The given array should be a statically allocated array whose size is
    // 100. The number of tree nodes in the binary search tree whose root node is
    // the given node cannot be more than the remaining spaces in the array.
    // Finally, the given tree node should be a node of this binary search tree
    // (where this method is initially invoked).
    //
    // Post: The given array contains the node data objects in the binary search
    // tree whose root node is the given node, and the node data objects are
    // sorted in an increasing order based on the strings they contain. The binary
    // search tree is empty.
    //
    // Parameter: dataArray, which is the array where the node data objects should
    // be contained.
    //
    // Parameter: index, which is the position at which this method starts to add
    // the node data objects to the array.
    //
    // Parameter: rootToArray, which is the root node of the binary search tree
    // that this recursive call consider.
    void toArrayHelper(NodeData* dataArray[], int& index, TreeNode*& rootToArray);

    // ------------------------------toTreeHelper----------------------------------
    // Description: The method toTreeHelper creates a balanced binary search tree
    // from a sorted array that contains node data objects.
    //
    // Pre: The given array should be sorted in an increasing order based on the
    // strings that the node data objects contain. There should not be null
    // pointers between the node data objects in the given array.
    //
    // Post: The node data objects in the given array are replaced with null
    // pointers. The given pointer points to the root of a balanced binary search
    // tree that contains the node data objects in the given array.
    //
    // Parameter: dataArray, which is the array that contains node data objects.
    //
    // Parameter: low, which is the lowest subscript of the array that this
    // recursive call considers.
    //
    // Parameter: high, which is the highest subscript of the array that this
    // recursive call considers.
    //
    // Parameter: rootToTree, which is the pointer that should point to the root
    // node of the created binary search tree.
    void toTreeHelper(NodeData* dataArray[], int low, int high, TreeNode*& rootToTree);
};