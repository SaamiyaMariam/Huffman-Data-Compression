**Introduction**

This project was focused on data compression through Huﬀman’s Algorithm.
Our main goal was to deliver the same information in a smaller amount of
space. The method we decided to opt for to implement this scheme was
creating a Priority Queue through Minimum Heap, and creating new nodes
by removing the two minimum elements and assigning them to be the left
and right children of the new node. The new node was then inserted into
our Huﬀman tree.

**Classes Used**

A total of three classes were created to implement our program.

> 1\. Node.cpp
>
> We wanted to store data related to each unique character in the same
> place, therefore we created the node class to hold the data and its
> frequency. Other data members included pointers of Node type (left,
> right and next) which were used in the implementation of the trees.
>
> 2\. Tree.cpp
>
> This class was used to create simple trees as well as for Inorder
> Display and path calculation.
>
> 3\. Heap.cpp
>
> This was used to implement and maintain our minimum heap. Data members
> included heapCap (total capacity of the heap), currSize (current size
> of the heap), Node\* heap (a dynamic array, our heap), and variables
> used to store the positions of an index’s parent and left and right
> children.

ﬁle.txt stored our input line and functions in these classes were called
from the ‘**<u>Huﬀman</u>** **<u>Scheme()</u>**’ function in our main.

**File Reading and Storing**

Our ﬁrst step was to read the contents of ‘ﬁle.txt’ by including the
**\<fstream\>** library, and storing it in the string ‘line’. This
string was then read character by character and unique characters were stored in an array ‘arr’, whereas in case of a repeated
character occurring, the frequency was updated in ‘arr’.

**Simple Tree Implementation**

After storing characters in an array, we implemented a simple binary
search tree. We inserted characters in the tree on the basis of their
frequency using the function **<u>Insert</u>**. A new node was created
for each of the characters, the node was inserted towards the left if
its frequency was lower than that of the above nodes or was inserted
towards the right if its frequency was greater.

Then we used the function **<u>Path</u>** to print the path for each of
the characters. Arguments included a pointer to the root of the tree
(**root**) and the frequency of the character(**freq**). This function
traversed the tree until the character with the frequency(**freq**) was
found, printing ‘0’ if the character was to the left and ‘1’ if the
character was to the right.

**Huffman Tree Implementation**

Creation of Min Heap

> I. Insertion
>
> The priority queue is created by inserting elements one by one, and
> after the insertion of each element, the order is re-maintained to
> ensure that all parents are less than their children. The priority
> criteria used here was on the basis of frequency. In case of a full
> heap, no element is inserted, otherwise it is inserted at the very end
> of the heap. After insertion, the heap is traversed from the newly
> inserted element, and makes its way up, exchanging elements if any
> parent happens to be greater than its child.

Building the Optimal Huffman Tree

To build a Huﬀman Tree, the smallest two elements from our heap are
removed and a new node is created. Its frequency is the sum of the
frequencies of these two nodes, and these nodes respectively become its
left and right children. This process is repeated until only one element
remains in the heap. In order to remove these nodes and to maintain the
min-heap format of the heap, the following functions were used.

> 
>
> I. GetMinimum
>
> This function returned the minimum node from the heap. If the heap was
> empty, NULL was returned but if the heap contained multiple nodes or
> one node, the root (node at index 0) was returned. There was no need
> to maintain the heap if only one element existed, however in the case
> of multiple elements, **<u>Heapify</u>** was then called to ﬁx the
> order of the min heap.
>
> II\. Heapify
>
> In heapify, the element at the index passed as the argument was
> initially assumed to be the smallest element of the min heap. Then it
> was compared to its right and left children on the basis of frequency,
> if either of the children were smaller, they were swapped with the
> element. And this process continued until the indexes of the right and
> left children exceeded the current size of the heap.

Printing the Huffman Tree

> I. HuffmanPaths
>
> To print the path for each character in our Huﬀman Tree, we used a
> recursive function called <u>**HuﬀmanPath**.</u> Arguments included a
> pointer to the root of the tree (**rt**) and a string to store the
> path (**path**). This function traversed the tree until the root
> became NULL. During traversal, the function stored “0” in the string
> each time it moved towards the left node and “1” each time it moved
> towards the right node. The string (containing the path) was printed
> whenever the pointer (**rt**) pointed towards an external node.
>
> II\. PathLengths
>
> To calculate the path lengths for each character, we used a recursive
> function called **<u>PathLength.</u>** Arguments included a pointer to
> the root of the tree (**rt**), a string to store the path (**path**),
> a variable to calculate the length (**length**) and an array to store
> all of the lengths (**lenArr\[\]**). During the traversal of the tree,
> the variable **length** was incremented every time the function moved
> towards the left or right node. This **length** was then stored in the
> array (**lenArr\[\]**) whenever the pointer (**rt**) pointed towards
> an external node.
>
> 

**Average Bit Rates and Compression Ratio**

The very purpose of a Huﬀman Tree is to use less storage for frequently
occurring characters. In order to compute the amount of data
transferred, or the **Average** **Bit** **Rate** **(ABR)**, the lengths
of each path were stored in an array. Then the following formula was
used to calculate the ABR:

> **ABR** **=** **(Freq1LengthOfPath1** **+Freq2LengthOfPath2+** **...**
> **+** **FreqnLengthOfPathn)** **/** **N**

,where N is the total length of the ﬁle.

The **Compression** **Ratio** is the ratio between the ﬁle’s size before
Huﬀman Encoding and afterwards. Since normally, the ﬁle size per symbol
is 8 bits, we use the formula:

> **Compression** **Ratio** **=** **8** **/** **ABR**

This process was implemented in our main function.
