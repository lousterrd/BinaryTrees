#include "BinaryNode.h"


// CONSTRUCTORS
template <class ItemType>
BinaryNode<ItemType>::BinaryNode()
{
   leftChildPtr = nullptr;
   rightChildPtr = nullptr;
}

template <class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem)
{
   setItem(anItem);
   leftChildPtr = nullptr;
   rightChildPtr = nullptr;

}

template <class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem,
                                 std::shared_ptr<BinaryNode<ItemType>> leftPtr,
                                 std::shared_ptr<BinaryNode<ItemType>> rightPtr)
{
   setItem(anItem);
   setLeftChild(leftChildPtr);
   setRightChild(rightChildPtr);
}


// HELPER METHODS
template <class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem)
{
   if (anItem)
      item = anItem;
}

template <class ItemType>
ItemType BinaryNode<ItemType>::getItem() const
{
   return item;
}

template <class ItemType>
bool BinaryNode<ItemType>::isLeaf() const
{
   if (leftChildPtr != nullptr || rightChildPtr != nullptr)
      return false;
   return true;
}

template <class ItemType>
auto BinaryNode<ItemType>::getLeftChildPtr() const
{
   return leftChildPtr;
}

template <class ItemType>
auto BinaryNode<ItemType>::getRightChildPtr() const
{
   return rightChildPtr;
}

template <class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr)
{
   if (leftPtr)
      leftChildPtr = leftPtr;
   else
      leftChildPtr = nullptr;
}


template <class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr)
{
   if (rightPtr)
      rightChildPtr = rightPtr;
   else
      rightChildPtr = nullptr;
}







