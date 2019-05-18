#include "BSTInt.h"
#include "BST.hpp"
#include "BSTIterator.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

/**
 * A test driver for the BST int class and class template.
 * PA1 CSE 100 2017
 * Author: Christine Alvarado and YOU
 * TODO: Add more tests
 */
int main() 
{

    /* Create an STL vector of some ints */
    /*test*/
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    v.push_back(100);
    v.push_back(-33);


    vector<int> u;
    u.push_back(5);
    u.push_back(6);
    u.push_back(2);
    u.push_back(101);
    u.push_back(-32);


    vector<int> w;
    w.push_back(7);
    w.push_back(8);
    w.push_back(9);
    w.push_back(102);
    w.push_back(-34);


    vector<int> abcV;
    abcV.push_back(1);
    abcV.push_back(2);
    abcV.push_back(3);

    /* Create an instance of BST holding int */
    //Reusable
    BSTInt b;
    BSTInt AZB;
    BSTInt ZAB;

    //Not Reusable
    BSTInt emptySize;
    BSTInt emptyFind;
    BSTInt emptyHeight;
    BSTInt emptyEmpty;

///////////////////////////////////////////////////////////////////////////////
  /* Test Insert()*/

    cout << "Test adding new elements into BST" << endl;
    for(int item : v) 
    {
        bool pr = b.insert(item);
        if(pr == false)  
        {
            cout << "Incorrect bool return value when inserting " << item 
                 << endl;
            return -1;
        }
    }
    
    cout << "Test adding existed value into BST" << endl;
    for(int item : v) 
    {
        bool pr = b.insert(item);
        if(pr == true) 
        {
            cout << "Incorrect bool return value when inserting " << item 
                 << endl;
            return -1;
        }
    }
    
    cout << "Test adding new value into BST again" << endl;
    for(int item : u) 
    {
        bool pr = b.insert(item);
        if(pr == false) 
        {
            cout << "Incorrect bool return value when inserting " << item 
                 << endl;
            return -1;
        }
    }
    
    cout << "Test insert edge case" << endl;
    for(int i = 0; i < 100; i++ ) 
    {
        bool prA = AZB.insert(i);
        bool prB = ZAB.insert(i*(-1)); 
        
        if(prA == false || prB == false ) 
        {
            cout << "Incorrect bool return value when inserting Edge Case" 
                 << endl;
            return -1;
        }
    }

///////////////////////////////////////////////////////////////////////////////

    /* Test size. */
    
    cout << "Size is: " << b.size() << endl;
    if(b.size() != (v.size() * 2)) 
    {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test size with new BST*/

    cout << "Size is: " << emptySize.size() << endl;
    for(int i = 0; i < 100; i++)
    {
        if(emptySize.size() != (unsigned int) i)
        {
            cout << "... which is incorrect." << endl;
            return -1;
        }

        emptySize.insert(i);
    }
    
///////////////////////////////////////////////////////////////////////////////

    /* Test find return value. */
    
    // Test the items that are already in the tree
    cout << "Testing for Value that exist in BST:" << endl;
    for(int item : v) 
    {
        cout << "looking  for " << item << endl;
        if(b.find(item) == false) 
        {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }

    // Test for items that are not supposed to be in the tree
    cout << "Testing for Value that doesn't exist in BST:" << endl;
    for(int item : w) 
    {
        cout << "looking for " << item << endl;
        if(b.find(item) == true) 
        {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }

    // Test for looking item in an empty BST
    cout << "Testing for Find in Empty BST:" << endl;
    if(emptyFind.find(1) == true)
    {
        cout << "Incorrect return value when finding " << 1 << endl;
    }


///////////////////////////////////////////////////////////////////////////////

    /* Test height of BST*/

    cout << "Testing height for empty BST" << endl;
    
    if(emptyHeight.height() != -1)
    {
        cout << "Incorrect return value for empty BST" << endl;
        return -1;
    }
    
    cout << "Testing height for nonempty BST" << endl;
    
    emptyHeight.insert(0);
    
    if(emptyHeight.height() != 0)
    {
        cout << "Incorrect return value for one BST" << endl;
        return -1;
    }

    if(b.height() != 4)
    {
        cout << "Incorrect return value for nonempty BST" << endl;
        return -1;
    }

    if(AZB.height() != 99)
    {
        cout << "Incorrect return value for AZB BST" << endl;
        return -1;
    }
    
    if(ZAB.height() != 99)
    {
        cout << "Incorrect return value for ZAB BST" << endl;
        return -1;
    }

///////////////////////////////////////////////////////////////////////////////
    
    /* Test empty of BST*/
    
    cout << "Testing empty for empty BST" << endl;
    
    if(emptyEmpty.empty() == false)
    {
        cout << "Incorrect return value for empty BST" << endl;
        return -1;
    }
    
    cout << "Testing empty for nonempty BST" << endl;
    
    emptyEmpty.insert(0);
    
    if(emptyEmpty.empty() == true)
    {
        cout << "Incorrect return value for empty BST" << endl;
        return -1;
    }

    if(b.empty() == true)
    {
        cout << "Incorrect return value for empty BST" << endl;
        return -1;
    }

    if(AZB.empty() == true)
    {
        cout << "Incorrect return value for empty BST" << endl;
        return -1;
    }
    
    if(ZAB.empty() == true)
    {
        cout << "Incorrect return value for empty BST" << endl;
        return -1;
    }
 
    /* UNCOMMENT THE LINES BELOW TO TEST THE TEMPLATE-BASED ITERATOR */

///////////////////////////////////////////////////////////////////////////////
    
    // Test the template version of the BST  with ints 
    BST<int> btemp;
    BST<int> ABCBST;
    BST<int> EmptySizeTemp;
    BST<int> EmptyHeightTemp;
    BST<int> EmptyEmptyTemp;
///////////////////////////////////////////////////////////////////////////////
  /* Test Insert */
    
    for (int item : v) 
    {
        cout << "Inserting " << item << " into the int template-based BST...";
        
        auto p = btemp.insert(item);
        
        if (*(p.first) != item) 
        {
            cout << "Wrong iterator returned.  "
                 << "Expected " << item << " but got " << *(p.first) << endl;
            return -1;
        }
        
        if (p.second == false) 
        {
            cout << "Wrong boolean returned.  Expected true but got " 
                 << p.second << endl;
            return -1;
        }
        
        cout << "success!" << endl;
              
    }

    
    for (int item = 0; item < 50; item++) 
    {
        cout << "Inserting " << item << " into the int template-based BST...";
        
        auto p = ABCBST.insert(item);
        
        if (*(p.first) != item) 
        {
            cout << "Wrong iterator returned.  "
                 << "Expected " << item << " but got " << *(p.first) << endl;
            return -1;
        }
        
        if (p.second == false) 
        {
            cout << "Wrong boolean returned.  Expected true but got " 
                 << p.second << endl;
            return -1;
        }
        
        cout << "success!" << endl;
    }           

///////////////////////////////////////////////////////////////////////////////
  /* Test Find */

    // Now test finding the elements we just put in
    for (int item: v) 
    {
        cout << "Finding " << item << "...." << endl;
        
        BSTIterator<int> foundIt = btemp.find(item);
        
        if (*(foundIt) != item) 
        {
            cout << "incorrect value returned.  Expected iterator pointing to "
                 << item << " but found iterator pointing to " << *(foundIt) 
                 << endl;
            return -1;
        }
        
        cout << "success!" << endl;
    }

    // Finding elements that doesn't exist in BST
    for (int item = 55; item < 60; item++) 
    {
        cout << "Finding " << item << "...." << endl;
        
        BSTIterator<int> foundIt = ABCBST.find(item);
      
        if ((foundIt) != NULL) 
        {
            cout << "incorrect value returned. Expected pointing to NULL"
                 << endl;
            return -1;
        }
        
        cout << "success!" << endl;
    }

///////////////////////////////////////////////////////////////////////////////

    /* Test size. */
    
    cout << "Size is: " << btemp.size() << endl;
    if(btemp.size() != (v.size())) 
    {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test size with new BST*/

    cout << "Size is: " << EmptySizeTemp.size() << endl;
    for(int i = 0; i < 100; i++)
    {
        if(EmptySizeTemp.size() != (unsigned int) i)
        {
            cout << "... which is incorrect." << endl;
            return -1;
        }

        EmptySizeTemp.insert(i);
    }
    
///////////////////////////////////////////////////////////////////////////////

    /* Test height of BST*/

    cout << "Testing height for empty BST" << endl;
    
    if(EmptyHeightTemp.height() != -1)
    {
        cout << "Incorrect return value for empty BST" << endl;
        return -1;
    }
    
    cout << "Testing height for nonempty BST" << endl;
    
    EmptyHeightTemp.insert(0);
    
    if(EmptyHeightTemp.height() != 0)
    {
        cout << "Incorrect return value for one BST" << endl;
        return -1;
    }
    
    if(btemp.height() != 2)
    {
        cout << "Incorrect return value for nonempty BST" << endl;
        return -1;
    }

    if(ABCBST.height() != 49)
    {
        cout << "Incorrect return value for AZB BST" << endl;
        return -1;
    }
    

///////////////////////////////////////////////////////////////////////////////
    
    /* Test empty of BST*/
    
    cout << "Testing empty for empty BST" << endl;
    
    if(EmptyEmptyTemp.empty() == false)
    {
        cout << "Incorrect return value for empty BST" << endl;
        return -1;
    }
    
    cout << "Testing empty for nonempty BST" << endl;
    
    EmptyEmptyTemp.insert(0);
    
    if(EmptyEmptyTemp.empty() == true)
    {
        cout << "Incorrect return value for empty BST" << endl;
        return -1;
    }

    if(btemp.empty() == true)
    {
        cout << "Incorrect return value for empty BST" << endl;
        return -1;
    }

    if(ABCBST.empty() == true)
    {
        cout << "Incorrect return value for empty BST" << endl;
        return -1;
    }
    
///////////////////////////////////////////////////////////////////////////////

    // Test the iterator: The iterator should give an in-order traversal
  
    // Sort the vector, to compare with inorder iteration on the BST
    sort(v.begin(),v.end());

    cout << "traversal using iterator..." << endl;
    auto vit = v.begin();
    auto ven = v.end();

    // This is equivalent to BSTIterator<int> en = btemp.end();
    auto en = btemp.end();

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto it = btemp.begin();
 
    for(; vit != ven; ++vit) 
    {
        if(! (it != en) ) 
        {
            cout << *it << "," << *vit 
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        
        cout << *it << endl;
        
        if(*it != *vit) 
        {
            cout << *it << "," << *vit 
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }

        ++it;
    }

    cout << "success!" << endl;

    
///////////////////////////////////////////////////////////////////////////////
  
  /* == and != of iterator */
  BSTNode<int>* nodeA = new BSTNode<int>(1);
  BSTNode<int>* nodeB = new BSTNode<int>(1);

  BSTIterator<int> iterAone(nodeA);
  BSTIterator<int> iterAtwo(nodeA);
  BSTIterator<int> iterBone(nodeB);
  BSTIterator<int> iterBtwo(nodeB);

  bool pr;

  cout << "Testing == operation" << endl;
  
  pr = (iterAone == iterAtwo);
  if(pr == false)
  {
      cout << "== compare the iterator object instead of curr ptr" << endl;
      return -1;
  }

  pr = (iterAone == iterBone);
  if(pr == true)
  {
      cout << "== cannot distinguish the difference of curr" << endl;
      return -1;
  }

  cout << "Testing != operation" << endl;
  
  pr = (iterBone != iterBtwo);
  if(pr == true)
  {
      cout << "!= compare the iterator object instead of curr ptr" << endl;
      return -1;
  }

  pr = (iterBone != iterAone);
  if(pr == false)
  {
      cout << "!= cannot distinguish the difference of curr" << endl;
      return -1;
  }

  delete(nodeA);
  delete(nodeB);

///////////////////////////////////////////////////////////////////////////////
/* Testing ++ operators*/

  auto itA = ABCBST.begin();
  auto itB = ABCBST.begin();
  auto itC = ABCBST.begin();

  auto plusplustest = ++itA;
  auto testplusplus = itB++;


  cout << "Testing ++iter operation" << endl;
  
  pr = (itA == itC);
  if(pr == true)
  {
      cout << "++Wrong iter" << endl;
      return -1;
  }
  
  pr = (plusplustest == itC);
  if(pr == true)
  {
      cout << "Wrong ++iter" << endl;
      return -1;
  }


  cout << "Testing iter++ operation" << endl;
  
  pr = (itB == itC);
  if(pr == true)
  {
      cout << "Wrong iter++" << endl;
      return -1;
  }
  
  pr = (testplusplus == itC);
  if(pr != true)
  {
       cout << "Wrong iter++" << endl;
       return -1;
  }


///////////////////////////////////////////////////////////////////////////////
   
   
    cout << "All tests passed!" << endl;
    return 0;
}
