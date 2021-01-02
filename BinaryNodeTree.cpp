#include "BinaryNodeTree.h"



// PROTECTED UTILITY METHODS SECTION: RECURSIVE HELPER METHODS FOR THE PUBLIC METHODS


template<class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
   if (subTreePtr == nullptr)
      return 0;
   else
      return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()),
                     getHeightHelper(subTreePtr->getRightChildPtr()));
} // end getHeightHelper


template <class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
   int numNodes = 0;
   if (subTreePtr != nullptr)
   {
      getNumberOfNodesHelper(subTreePtr->getLeftChildPtr());
      numNodes++;
      getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
   }
   return numNodes;

} // end getNumberOfNodesHelper



template<class ItemType>
auto BinaryNodeTree<ItemType>::balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                           std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
   if (subTreePtr == nullptr)
      return newNodePtr;
   else
   {
      auto leftPtr = subTreePtr->getLeftChildPtr();
      auto rightPtr = subTreePtr->getRightChildPtr();
      if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
      {
         rightPtr = balancedAdd(rightPtr, newNodePtr);
         subTreePtr->setRightChildPtr(rightPtr);
      }
      else
      {
         leftPtr = balancedAdd(leftPtr, newNodePtr);
         subTreePtr->setLeftChildPtr(leftPtr);
      }
         return subTreePtr;
   } // end else
} // end balancedAdd

/*
template <class ItemType>
auto BinaryNodeTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                         const ItemType target, bool& isSuccessful)
{
   if (subTreePtr == nullptr)
      return subTreePtr;
   else if (target < subTreePtr->getItem())
   {
      auto leftPtr = subTreePtr->getLeftChildPtr();
      subTreePtr->setLeftChildPtr(removeValue(leftPtr, target));
   }
   else if (target > subTreePtr->getItem())
   {
      auto rightPtr = subTreePtr->getRightChildPtr();
      subTreePtr->setRightChildPtr(removeValue(rightPtr, target));
   }
   else
   {
      auto leftPtr = subTreePtr->getLeftChildPtr();
      auto rightPtr = subTreePtr->getRightChildPtr();

      if (leftPtr == nullptr && rightPtr == nullptr)
      {
         delete subTreePtr;
         subTreePtr = nullptr;
      }
      else if (rightPtr == nullptr)
      {
         auto temp = subTreePtr;
         subTreePtr = leftPtr;
         delete temp;
      }
      else if (leftPtr == nullptr)
      {
         auto temp = subTreePtr;
         subTreePtr = rightPtr;
         delete temp;
      }
      else
      {
         auto temp = max(leftPtr, rightPtr)
      }
   }
} // end removeValue
*/

/*
template <class ItemType>
auto BinaryNodeTree<ItemType>::moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{

} // end moveValuesUpTree
*/

/*
template<class ItemType>
auto BinaryNodeTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr,
                      const ItemType& target, bool& isSuccessful) const
{

} // end findNode
*/




template<class ItemType>
auto BinaryNodeTree<ItemType>::copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const
{
   std::shared_ptr<BinaryNode<ItemType>> newTreePtr;
   // Copy tree nodes during a preorder traversal
   if (oldTreeRootPtr != nullptr)
   {
      // Copy node
      newTreePtr = std::make_shared<BinaryNode<ItemType>>(oldTreeRootPtr->getItem(), nullptr, nullptr);
      newTreePtr->setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));
      newTreePtr->setRightChildPtr(copyTree(oldTreeRootPtr->getRightChildPtr()));
   } // end if
     // Else tree is empty (newTreePtr is nullptr)
   return newTreePtr;
} // end copyTree

template<class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
   if (subTreePtr != nullptr)
   {
      destroyTree(subTreePtr->getLeftChildPtr());
      destroyTree(subTreePtr->getRightChildPtr());
      subTreePtr.reset(); // Decrement reference count to node
   } // end if
} // end destroyTree





template <class ItemType>
void BinaryNodeTree<ItemType>::preorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
   if (treePtr != nullptr)
   {
      ItemType theItem = treePtr->getItem();
      visit(theItem);
      preorder(visit, treePtr->getLeftChildPtr());
      preorder(visit, treePtr->getRightChildPtr());
   } // end if
} // end preorder



template<class ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit(ItemType&),
                                       std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
   if (treePtr != nullptr)
   {
      inorder(visit, treePtr->getLeftChildPtr());
      ItemType theItem = treePtr->getItem();
      visit(theItem);
      inorder(visit, treePtr->getRightChildPtr());
   } // end if
} // end inorder


template<class ItemType>
void BinaryNodeTree<ItemType>::postorder(void visit(ItemType&),
                                         std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
   if (treePtr != nullptr)
   {
      postorder(visit, treePtr->getLeftChildPtr());
      postorder(visit, treePtr->getRightChildPtr());
      ItemType theItem = treePtr->getItem();
      visit(theItem);
   }
} // end postorder




//CONSTRUCTOR AND DESTRUCTOR SECTION
template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr(nullptr)
{
} // end default constructor


template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem)
: rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr))
{
} // end constructor



template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem,
                                         const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
                                         const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr)
: rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem,
                                                 copyTree(leftTreePtr->rootPtr),
                                                 copyTree(rightTreePtr->rootPtr)))
{
} // end constructor



template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const std::shared_ptr<BinaryNodeTree<ItemType>>& treePtr)
{
   rootPtr = copyTree(treePtr.rootPtr);
} // end copy constructor


template<class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree()
{
   destroyTree(rootPtr);
} // end destructor


// PUBLIC BINARY_TREE_INTERFACE METHODS SECTION
template<class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const
{
   if (rootPtr == nullptr)
      return true;
   return false;
}

template<class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const
{
   return getHeightHelper(rootPtr);
}

template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const
{
   return getNumberOfNodesHelper(rootPtr);
}

template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const
{
   return rootPtr->getItem();
}

template<class ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType& newData)
{
   if (rootPtr != nullptr)
   {
      rootPtr->setItem(newData);
   }
   else
   {
      add(newData);
   }
}




template<class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData)
{
   auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
   rootPtr = balancedAdd(rootPtr, newNodePtr);
   return true;
} // end add


/*template<class ItemType>
bool BinaryNodeTree<ItemType>::remove(const ItemType& data) // Removes specified item from the tree
{
   findNode(rootPtr, target,
   removeValue(rootPtr, data);
}
*/
template<class ItemType>
void BinaryNodeTree<ItemType>::clear()
{
   destroyTree(rootPtr);
}

/*template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const ItemType& anEntry) const
{

}*/
/*
template<class ItemType>
bool BinaryNodeTree<ItemType>::contains(const ItemType& anEntry) const
{

}
*/

// PUBLIC TRAVERSAL SECTION
template<class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
   preorder(visit, rootPtr);
}

template<class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
   inorder(visit, rootPtr);
}

template<class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
   postorder(visit, rootPtr);
}


// OVERLOADED OPERATOR SECTION
template<class ItemType>
BinaryNodeTree<ItemType>& BinaryNodeTree<ItemType>::operator= (const BinaryNodeTree<ItemType>& rightHandSide)
{
   rootPtr = copyTree(rightHandSide.rootPtr);
}

