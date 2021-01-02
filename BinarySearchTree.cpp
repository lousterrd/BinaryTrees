#include "BinarySearchTree.h"







//------------------------------------------------------------
// Protected Utility Methods Section:
// Recursive helper methods for the public methods.
//------------------------------------------------------------
// Places a given new node at its proper position in this binary
// search tree.
template <class ItemType>
auto BinarySearchTree<ItemType>::placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
          std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
   if (subTreePtr == nullptr)
      return newNodePtr;
   else if (subTreePtr->getItem() > newNodePtr->getItem())
   {
      auto tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newNodePtr);
      subTreePtr->setLeftChildPtr(tempPtr);
   }
   else
   {
      auto tempPtr = placeNode(subTreePtr->getRightChildPtr(), newNodePtr);
      subTreePtr->setRightChildPtr(tempPtr);
   }
   return subTreePtr;
}

// Removes a given node from a tree while maintaining a binary search tree.
//auto removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr);

// Removes the leftmost node in the left subtree of the node
// pointed to by nodePtr.
// Sets inorderSuccessor to the value in this node.
// Returns a pointer to the revised subtree.
//auto removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>>subTreePtr,
//                     ItemType& inorderSuccessor);

// Returns a pointer to the node containing the given value,
// or nullptr if not found.
//auto findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr,
//              const ItemType& target) const;




//------------------------------------------------------------
// Constructor and Destructor Section.
//------------------------------------------------------------
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(nullptr){}

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem)
: rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr))
{}


template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& treePtr)
{
   rootPtr = this->copyTree(treePtr.rootPtr);
}


template <class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
   this->destroyTree(rootPtr);
}

//------------------------------------------------------------
// Public Methods Section.
//------------------------------------------------------------
template <class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
   if (rootPtr == nullptr)
      return true;
   return false;
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
   return this->getHeightHelper(rootPtr);
}

template <class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const
{
   return this->getNumberOfNodesHelper(rootPtr);
}

template <class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const
{
   return rootPtr->getItem();
}

template <class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newData)
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
bool BinarySearchTree<ItemType>::add(const ItemType& newData)
{
   auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
   rootPtr = placeNode(rootPtr, newNodePtr);
   return true;
} // end add



//bool BinarySearchTree<ItemType>::remove(const ItemType& target);

template <class ItemType>
void BinarySearchTree<ItemType>::clear()
{
   this->destroyTree(rootPtr);
}

//ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const throw(NotFoundException);
//bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const;

//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------
template <class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
   this->preorder(visit, rootPtr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
   this->inorder(visit, rootPtr);
}

template <class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
   this->postorder(visit, rootPtr);
}

//------------------------------------------------------------
// Overloaded Operator Section.
//------------------------------------------------------------
/*template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree<ItemType>&
                           operator=(const BinarySearchTree<ItemType>& rightHandSide)
{
   rootPtr = copyTree(rightHandSide.rootPtr);
}
*/






