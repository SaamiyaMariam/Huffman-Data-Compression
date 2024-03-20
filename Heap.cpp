// DATA STRUCTURES PROJECT                               //
// Saamiya Mariam (20i-0612) & Bisma Haroon (20i-0716)   //
// Section D                                             //
// // // // // // // // // // // // // // // // // // // //

#include <iostream>
#include "Tree.cpp"
using namespace std;

class Heap
{
public:

	int heapCap; //total capacity of heap
	int currSize; //current number of elements in heap
	Node* heap;
	int parentPos; //position of parent in heap
	int rightN; //right child position in heap
	int leftN; //left child position in heap


	//constructors
	Heap()
	{
		heapCap = 0;
		currSize = 0;
		heap = new Node[heapCap];
		parentPos = 0;
		rightN = 0;
		leftN = 0;
	}
	Heap(int capacity)
	{
		heapCap = capacity;
		heap = new Node[heapCap];
		currSize = 0;
		parentPos = 0;
		rightN = 0;
		leftN = 0;
	}

	int getParentPos(int childPos) //passes position of current index to get index of parent
	{
		int pos = (childPos - 1) / 2;
		return pos;
	}


	//		Helper Functions for Huffman's Algorithm		//


	////HEAP INSERTION
	void Insertion(Node node)
	{
		if (currSize == heapCap) //if the heap is full
		{
			cout << "The Heap Is Full!\n";
			return;
		}
		//if heap still has space, node will be inserted at the very end
		currSize = currSize + 1;
		heap[currSize - 1] = node;

		cout << heap[currSize - 1].data << "    " << heap[currSize - 1].frequency << " inserted!\n";

		//After insertion, we need to make sure the heap reorders itself acc to minheap requirements
		//i.e. all parents must be smaller than their children

		int trav = currSize - 1; //starts at the last element of the heap
		int par = getParentPos(trav);

		while ((heap[trav].frequency < heap[par].frequency) && trav >= 0) //trav=0, we have reached the root. can't go higher 
		{
			//if parent is greater than child, swap them
			Node temp = heap[par];
			heap[par] = heap[trav];
			heap[trav] = temp;

			trav = getParentPos(trav);
			par = getParentPos(trav); //reassigning parent pos after swap
		}

	}


	//to implement Huffman algorithm, we need to extract minimum nodes from the heap a.k.a the root node
	Node* getMinimum()
	{
		Node* minimum = new Node;
		/// 3 cases: 0 nodes, 1 node, or multiple nodes
		if (currSize == 0)//empty heap
		{
			return NULL;
		}
		else if (currSize == 1) //if only 1 element exists, there will be no need to maintain heap afterwards
		{
			currSize = currSize - 1;

			minimum->data = heap[currSize].data;
			minimum->frequency = heap[currSize].frequency;
			minimum->left = heap[currSize].left;
			minimum->right = heap[currSize].right;
			minimum->next = heap[currSize].next;
		}
		else //multiple nodes
		{

			//shallow copy
			minimum->data = heap[0].data;
			minimum->frequency = heap[0].frequency;
			minimum->left = heap[0].left;
			minimum->right = heap[0].right;
			minimum->next = heap[0].next;

			//root is stored in minimum, to be returned later
			//after removing the root, we need to replace it
			//since elements to heap are always added to the bottom, we use the last/bottom element of heap

			heap[0] = heap[currSize - 1];
			currSize = currSize - 1;

			//now we need to fix the order of the min heap
			Heapify(0);

		}
		return minimum;
	}


	//Inorder to maintain the order of the heap after removing the top element, we call Heapify
	//It works its way down from the root to ensure that each parent is smaller than its children


	void Heapify(int index)
	{
		int min, min_left, min_right;
		min = index;
		min_left = (2 * index) + 1;
		min_right = (2 * index) + 2;
		bool swapped = false;

		//checking if right child is smaller than min:
		if (heap[min_right].frequency < heap[min].frequency && min_right < currSize)
		{
			min = min_right;
			swapped = true;
		}


		//checking if left child is smaller than min:
		if (heap[min_left].frequency < heap[min].frequency && min_left < currSize)
		{
			min = min_left;
			swapped = true;
		}

		//checking if min is not root
		if (swapped == true)
		{
			int freq;
			char data;
			Node* left, * right, * next;

			freq = heap[index].frequency;
			data = heap[index].data;
			left = heap[index].left;
			right = heap[index].right;
			next = heap[index].next;

			heap[index].frequency = heap[min].frequency;
			heap[index].data = heap[min].data;
			heap[index].left = heap[min].left;
			heap[index].right = heap[min].right;
			heap[index].next = heap[min].next;


			heap[min].frequency = freq;
			heap[min].data = data;
			heap[min].left = left;
			heap[min].right = right;
			heap[min].next = next;

			Heapify(min);
		}
	}
};