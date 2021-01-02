/*

 Louis Doherty
 Project 3: Binary Search Tree





 */




#include <iostream>
#include <stdlib.h> // Allows usage of the rand() function to generate numbers

using namespace std;

#include "BinarySearchTree.cpp"
#include "BinaryNodeTree.cpp"
#include "BinaryNode.cpp"




const int SIZE = 100; // First file contains 1,000 integers
const int MAX_RANGE = 200; // Randomly generated integers won't exceed 200


const int* genNums(int maxNum)
{
   int* arr = new int[maxNum];
   for (int i = 0; i < maxNum; i++)
   {
      arr[i]=(rand() % MAX_RANGE + 1); // Adding 1 to include 200
   }
   return arr;
}



template <class ItemType>
void print(ItemType& i)
{
   cout << i << endl;
}



int main()
{
   BinarySearchTree<int> b1;
   const int* nums = genNums(SIZE);


   for (int i = 0; i < SIZE; ++i)
   {
      b1.add(nums[i]);
      //cout << i << ": " << nums[i] << endl;
   }


   cout << endl << "Printing the tree via Inorder Traversal: " << endl;
   cout << "---------------------------------------------" << endl;
   b1.inorderTraverse(print);
   cout << endl << "=============================================" << endl << endl;


   cout << "Printing the tree via Preorder Traversal: " << endl;
   cout << "---------------------------------------------" << endl;
   b1.preorderTraverse(print);
   cout << endl << "=============================================" << endl << endl;


   cout << "Printing the tree via Postorder Traversal: " << endl;
   cout << "---------------------------------------------" << endl;
   b1.postorderTraverse(print);
   cout << endl << "=============================================" << endl << endl;

   cout << "Tree Height: ";
   cout << b1.getHeight() << endl;













   return 0;
}
