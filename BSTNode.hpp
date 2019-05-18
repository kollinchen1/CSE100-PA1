#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>

/** Starter code for PA1, CSE 100 2017
 * Authors: Christine Alvarado, based on code by Paul Kube 
 * ADD YOUR NAME AS AN AUTHOR HERE
 */

template<typename Data>
class BSTNode {

public:

  Data const data;   // the const Data in this node.
  BSTNode<Data>* left;
  BSTNode<Data>* right;
  BSTNode<Data>* parent;

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d);


  /** Return the successor of this BSTNode in a BST, or 0 if none.
   ** PRECONDITION: this BSTNode is a node in a BST.
   ** POSTCONDITION:  the BST is unchanged.
   ** RETURNS: the BSTNode that is the successor of this BSTNode,
   ** or 0 if there is none.
   */
  BSTNode<Data>* successor(); 

}; 


// Function definitions
// For a templated class it's easiest to just put them in the same file as the class declaration

template <typename Data>
BSTNode<Data>::BSTNode(const Data & d) : data(d), left(0), right(0), parent(0)
{
}
/* Return a pointer to the BSTNode that contains the item that is sequentially next 
 * in the tree */
template <typename Data>
BSTNode<Data>* BSTNode<Data>::successor()
{
  BSTNode<Data>* returnVal = NULL;
  
  BSTNode<Data>* parentPtr = NULL;

  //Case successor is its rightchild
  if( this->right != NULL )
  {
    returnVal = this->right;
    while(returnVal->left != NULL)
    {
      returnVal = returnVal->left;
    }
  }
  
  //Case sucessor is parent
  else if( this->parent != NULL )
  {
    parentPtr = this->parent;
    while(parentPtr->data < this->data)
    {
      if(parentPtr->parent != NULL)
        parentPtr = parentPtr->parent;
      else
        break;
    }

    if(this->data < parentPtr->data)
      returnVal = parentPtr;
  }
    //printf("hola\n");
    return returnVal;
}

/** Overload operator<< to print a BSTNode's fields to an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP
