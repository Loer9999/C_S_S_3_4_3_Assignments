#include <iostream>
#include "bintree.h"

// ------------------------------ bintree.cpp ---------------------------------
// Programmer Name: Po-Lin Tu     Course Section Number: CSS 343 B
// Creation Date: 4/5/2022
// Date of Last Modification: 4/17/2022
//
// Purpose: This file is the header file of the BinTree class that defines my
// binary search tree. As for the data, my binary search tree can contain tree
// nodes whose data items are strings. As for the behaviors, my binary search
// tree overloads the equality and the inequality operators that compare two
// binary search trees. My binary search tree supports mutators that allow the
// client to add nodes to this binary search tree or empty this tree. My binary
// search tree also supports accessors that can traverse through the tree,
// retrieve a data item in the tree, or report the height of a data item.
// Finally, my binary search tree can be converted to a sorted array or be
// created from a sorted array.
// ----------------------------------------------------------------------------


// ---------------------------Default Constructor------------------------------
// Description: The default constructor creates an empty tree.
//
// Post: An empty tree, whose root node is a null pointer, exists.
BinTree::BinTree() : root(nullptr)
{

} // end of the default constructor

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
BinTree::BinTree(const BinTree& other) : root(nullptr)
{
    operator=(other);
} // end of the copy constructor

// ------------------------------Destructor------------------------------------
// Description: The destructor deletes this binary search tree, freeing the
// memory that is dynamically allocated to this tree.
//
// Post: This binary search tree does not exist, and the dynamically allocated
// memory is free.
BinTree::~BinTree()
{
    makeEmpty();
} // end of the destructor

// -------------------------------isEmpty--------------------------------------
// Description: The method isEmpty reports whether this binary search tree is
// empty.
//
// Post: This binary search tree does not change.
//
// Return: True if this binary search tree is empty (root node is a null
// pointer); false otherwise.
bool BinTree::isEmpty() const
{
    return root == nullptr;
} // end of the method isEmpty

// -------------------------------makeEmpty------------------------------------
// Description: The method makeEmpty empties this binary search tree, freeing
// the memory that is dynamically allocated to each node in this tree.
//
// Post: This binary search tree is empty (the root node is a null pointer).
// The dynamically allocated memory is free.
void BinTree::makeEmpty()
{
    // Recursively empty this binary search tree if this binary search tree is
    // not empty.
    if (!isEmpty())
    {
        emptyHelper(root);
    }
} // end of the method makeEmpty

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
BinTree& BinTree::operator=(const BinTree& rhs)
{
    // Do nothing if the assignment is a self-assignment.
    if (root != rhs.root)
    {
        // Empty this binary search tree.
        makeEmpty();

        // Copy the binary search tree on the right-hand side to this binary search
        // tree.
        copyHelper(rhs.root);
    }
    return *this;
} // end of the method operator =

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
bool BinTree::operator==(const BinTree& rhs) const
{
    return compareHelper(root, rhs.root);
} // end of the method operator ==

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
bool BinTree::operator!=(const BinTree& rhs) const
{
    return !compareHelper(root, rhs.root);
} // end of the method operator !=

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
bool BinTree::insert(NodeData* newData)
{
    // Search for a proper position to add a tree node if this binary search
    // tree is not empty.
    if (root != nullptr)
    {
        TreeNode* current = root;
        while (true)
        {
            // Go left if the string of the given node data object is less than
            // the string of the current node data object.
            if (*newData < *(current -> data))
            {
                if (current -> left != nullptr)
                {
                    current = current -> left;
                }
                else
                {   current -> left = new TreeNode(newData, nullptr, nullptr);
                    // Exit the loop and the method.
                    return true;
                }
            }
            // Go right if the string of the given node data object is greater
            // than the string of the current node data object.
            else if (*newData > *(current -> data))
            {
                if (current -> right != nullptr)
                {
                    current = current -> right;
                }
                else
                {
                    current -> right = new TreeNode(newData, nullptr, nullptr);
                    // Exit the loop and the method.
                    return true;
                }
            }
            // Exit the loop and the method without adding a tree node if the
            // string of the given node data object is the same as the string
            // of the current node data object.
            else
            {
                return false;
            }
        }
    }
    // Add a root node if this binary search tree is empty.
    else
    {
        root = new TreeNode(newData, nullptr, nullptr);
        return true;
    }
} // end of the method insert

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
std::ostream& operator<<(std::ostream& output, const BinTree& binTree)
{
    binTree.outputHelper(output, binTree.root);
    output << std::endl;
    return output;
} // end of the method operator <<

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
bool BinTree::retrieve(const NodeData& target, NodeData*& pointer) const
{
    return retrieveHelper(target, pointer, root);
} // end of the method retrieve

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
int BinTree::getHeight(const NodeData& target) const
{
    return heightHelper(target, root, 0);
} // end of the method getHeight

// ----------------------------displaySideways---------------------------------
// Description: The method displaySideways displays this binary search tree as
// though you are viewing it from the side.
//
// Post: This binary search tree does not change.
void BinTree::displaySideways() const
{
    sidewaysHelper(root, 0);
} // end of the method displaySideways

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
void BinTree::bstreeToArray(NodeData* dataArray[])
{
    int index = 0;
    toArrayHelper(dataArray, index, root);
} // end of the method bstreeToArray

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
void BinTree::arrayToBSTree(NodeData* dataArray[])
{
    // Use the array to build this binary search tree if this binary search
    // tree is empty.
    if (isEmpty())
    {
        // Check whether the given array is sorted.
        bool sorted = true;
        int index = 0;
        NodeData* previous = dataArray[index];
        index++;
        while (sorted && index < 100 && dataArray[index] != nullptr)
        {
            sorted = (*previous < *dataArray[index]);
            previous = dataArray[index];
            index++;
        }

        // Use the sorted array to build this binary search tree.
        if (sorted)
        {
            toTreeHelper(dataArray, 0, --index, root);
        }
    }
} // end of the method arrayToBSTree

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
void BinTree::emptyHelper(TreeNode*& rootEmpty)
{
    // Empty the binary tree whose root node is the given node if the given
    // node is not a null pointer.
    if (rootEmpty != nullptr)
    {
        // Delete the left and right subtrees of the given node and set the
        // left and right pointers of the given node to null pointers.
        emptyHelper(rootEmpty -> left);
        emptyHelper(rootEmpty -> right);

        // Delete the given node and set it to null pointer.
        delete rootEmpty;
        rootEmpty = nullptr;
    }
} // end of the method emptyHelper

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
void BinTree::copyHelper(TreeNode* rootCopy)
{
    // Copy the binary search tree whose root node is the given node if the
    // given node is not a null pointer.
    if (rootCopy != nullptr)
    {
        NodeData* newData = new NodeData(*(rootCopy -> data));
        insert(newData);

        // Copy the left and right subtrees of the given node.
        copyHelper(rootCopy -> left);
        copyHelper(rootCopy -> right);
    }
} // end of the method copyHelper

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
bool BinTree::compareHelper(TreeNode* rootThis, TreeNode* rootOther) const
{
    // Return true if both given nodes are null pointers.
    if (rootThis == nullptr && rootOther == nullptr)
    {
        return true;
    }
    // Return false if only one given node is a null pointer.
    else if (rootThis == nullptr || rootOther == nullptr)
    {
        return false;
    }
    // Return false if the two given nodes have different data items.
    else if (*(rootThis -> data) != *(rootOther -> data))
    {
        return false;
    }
    // Check the subtrees of the two given nodes.
    else
    {
        return compareHelper(rootThis -> left, rootOther -> left) &&
               compareHelper(rootThis -> right, rootOther -> right);
    }
} // end of the method compareHelper

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
void BinTree::outputHelper(std::ostream& output, TreeNode* rootOutput) const
{
    // Output the binary tree whose root node is the given tree node if the
    // given tree node is not a null pointer.
    if (rootOutput != nullptr)
    {
        outputHelper(output, rootOutput -> left);
        output << *(rootOutput -> data) << " ";
        outputHelper(output, rootOutput -> right);
    }
} // end of the method outputHelper

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
bool BinTree::retrieveHelper
(const NodeData& target, NodeData*& pointer, TreeNode* rootRetrieve) const
{
    // The given node data object is not in the tree if the root node is a null
    // pointer.
    if (rootRetrieve == nullptr)
    {
        return false;
    }
    // Go left if the string of the given node data object is less than the
    // string of the object of the root node.
    else if (target < *(rootRetrieve -> data))
    {
        return retrieveHelper(target, pointer, rootRetrieve -> left);
    }
    // Go right if the string of the given node data object is greater than the
    // string of the object of the root node.
    else if (target > *(rootRetrieve -> data))
    {
        return retrieveHelper(target, pointer, rootRetrieve -> right);
    }
    // Update the pointer if the given node data object and the object of the
    // root node have the same string.
    else
    {
        pointer = rootRetrieve -> data;
        return true;
    }
} // end of the method retrieveHelper

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
int BinTree::heightHelper
(const NodeData& target, TreeNode* rootGetHeight, int height) const
{
    // Return the cumulative height if the root node is a null pointer.
    if (rootGetHeight == nullptr)
    {
        return height;
    }
    else
    {
        // Add one to the cumulative height if the tree node that contains the
        // given node data object is an ascendant or the given tree node contains
        // the given node data.
        if (height > 0 || target == *(rootGetHeight -> data))
        {
            height++;
        }

        // Return the longer path to a leaf node.
        int left = heightHelper(target, rootGetHeight -> left, height);
        int right = heightHelper(target, rootGetHeight -> right, height);
        return left > right ? left : right;
    }
} // end of the method heightHelper

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
void BinTree::sidewaysHelper(TreeNode* rootSideways, int level) const
{
    // Display the tree if the given node is not a null pointer.
    if (rootSideways != nullptr)
    {
        level++;
        sidewaysHelper(rootSideways -> right, level);

        // Indent for readability, 4 spaces per depth level.
        for (int i = level; i >= 0; i--) {
            cout << "    ";
        }

        cout << *(rootSideways -> data) << endl;
        sidewaysHelper(rootSideways -> left, level);
    }
} // end of the method sidewaysHelper

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
void BinTree::toArrayHelper(NodeData* dataArray[], int& index, TreeNode*& rootToArray)
{
    // Add the node data objects in the tree to the given array if the given root
    // node is not a null pointer.
    if (rootToArray != nullptr)
    {
        // Add the node data objects in the left subtree to the given array and
        // empty the left subtree.
        toArrayHelper(dataArray, index, rootToArray -> left);

        // Add the node data object of the given node to the given array.
        dataArray[index] = rootToArray -> data;
        rootToArray -> data = nullptr;

        // Add the node data objects in the right subtree to the given array and
        // empty the right subtree.
        toArrayHelper(dataArray, ++index, rootToArray -> right);

        // Delete the given node.
        delete rootToArray;
        rootToArray = nullptr;
    }
} // end of the method toArrayHelper

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
void BinTree::toTreeHelper
(NodeData* dataArray[], int low, int high, TreeNode*& rootToTree)
{
    // Create a binary search tree if the size of the given array is at least one.
    if (low <= high)
    {
        // The root node of the binary search tree contains the node data object
        // in the middle of the array.
        int middle = (low + high) / 2;
        rootToTree = new TreeNode(dataArray[middle], nullptr, nullptr);
        dataArray[middle] = nullptr;

        // Create the left and right subtrees of the root node.
        toTreeHelper(dataArray, low, middle - 1, rootToTree -> left);
        toTreeHelper(dataArray, middle + 1, high, rootToTree -> right);
    }
} // end of the method toTreeHelper