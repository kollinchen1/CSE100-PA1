#include "BSTInt.h"

/* Function definitions for a int-based BST class */


/** Default destructor.
    Delete every node in this BST.
*/
BSTInt::~BSTInt() {
  deleteAll(root);
}

/** Given a reference to a Data item, insert a copy of it in this BST.
 *  Return  true if the item was added to this BST
 *  as a result of this call to insert,
 *  false if an item equal to this one was already in this BST.
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=)  For the reasoning
 *  behind this, see the assignment writeup.
 */

bool BSTInt::insert(int item)
{
  if (!root) {
    root = new BSTNodeInt(item);
    ++isize;
    return true;
  }

  BSTNodeInt* curr = root;

  //if(!(item < curr->data) && !(curr->data < item))
    //return false;

  //printf("pre: curr is: %d, item is: %d\n", curr->data, item);
  
  while (((item < curr->data) && (curr->left)) || 
         ((curr->data < item) && (curr->right))) 
  {
    //printf("whi: curr is: %d, item is: %d\n", curr->data, item);
   
    if (item < curr->data) 
    {
      curr = curr->left;
    }
    else if (curr->data < item) 
    {
      curr = curr->right;
    }
    else 
    {
      return false;
    }
  }

  if(!(item < curr->data) && !(curr->data < item))
    return false;
  //printf("rea: curr is: %d, item is: %d\n", curr->data, item);
  // Ready to insert
  
  BSTNodeInt* newNode = new BSTNodeInt(item);
  if (item < curr->data) 
  {
    /*
    if(curr->left != NULL)
    {
      delete(newNode);
      return false;
    }
    */
    curr->left = newNode;
    newNode->parent = curr;
  }
  else 
  {
    /*
    if(curr->right != NULL)
    {
     // delete(newNode);
     // return false;
    }
    */

    curr->right = newNode;
    newNode->parent = curr;
  }

  ++isize;
  return true;

}


/** Find a Data item in the BST.
 *  Return true if the item is in the BST or false otherwise
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=).  For the reasoning
 *  behind this, see the assignment writeup.
 */
bool BSTInt::find(int item) const
{
  BSTNodeInt* curr = root;
  while (curr) {
    if (curr->data < item) {
      curr = curr->right;
    }
    else if (item < curr->data) {
      curr = curr->left;
    }
    else {
      return true;
    }
  }
  return false;
}

  
/** Return the number of items currently in the BST.
 */
unsigned int BSTInt::size() const 
{
  return isize;
}

  
/** Return the height of the BST.
    Height of tree with just root node is 0
 */
int BSTInt::height() const
{
  int returnVal = -999;
  
  if(root == NULL)
    returnVal =  -1;
  else
    returnVal = heightHelper(root, 0);
  
  return returnVal;
}

int BSTInt::heightHelper(BSTNodeInt* n, int h) const
{
  if( n == NULL)
    return h-1;
  
  int leftHeight = heightHelper(n->left, h+1);
  int rightHeight = heightHelper(n->right, h+1);

  if(leftHeight < rightHeight)
    return rightHeight;
  else
    return leftHeight;
 
  
}


/** Return true if the BST is empty, else false. 
 */
bool BSTInt::empty() const 
{
  if(isize < 1)
    return true;
  else
    return false;
}




/** do a postorder traversal, deleting nodes
 * This is a helper for the destructor
 * This method is static because it acts on BSTNodeInts
 *   and not on the BSTInt object directly.
 */
void BSTInt::deleteAll(BSTNodeInt* n)
{
  if( n == NULL )
    return;

  deleteAll(n->left);
  deleteAll(n->right);
  //printf("%d", n->data);
  delete(n);
}
