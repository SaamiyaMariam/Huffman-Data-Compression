// DATA STRUCTURES PROJECT                               //
// Saamiya Mariam (20i-0612) & Bisma Haroon (20i-0716)   //
// Section D                                             //
// // // // // // // // // // // // // // // // // // // //

#include <iostream>
#include <fstream>
#include <string>
#include "Heap.cpp"

using namespace std;


Node* HuffmanScheme(Node* arr, Heap h1, Node freqArr[50])
{

    //		Huffman's Algorithm Implementation		//
    // (1) Build a Min-Heap of our unique characters
    // (2) Create a node and assign right and left childs to it by removing minimum nodes from the Min-Heap.
    //	   This will be done until all elements of the heap have been used and only one remains


    //Step 1: Insert Elements into heap and create Min Heap
    for (int i = 0; i < h1.heapCap; i++)
    {
        h1.Insertion(arr[i]);
        for (int j = 0; j <= i; j++)
        {
            cout << "current heap:\t";
            cout << h1.heap[j].data << "\t" << h1.heap[j].frequency << endl;
        }
    }
    cout << "--------------------------------------------------------\n";

    //Step 2: Building optimal huffman tree

    Node* leftN, * rightN, * printNode = new Node;
    int cnt = 0;

    while (h1.currSize != 1)    //our end goal is that only one element remains in our priority queue
    {
        leftN = h1.getMinimum();
        rightN = h1.getMinimum();


        freqArr[cnt].data = leftN->data;
        freqArr[cnt].frequency = leftN->frequency;
        cnt++;

        freqArr[cnt].data = rightN->data;
        freqArr[cnt].frequency = rightN->frequency;
        cnt++;


        Node* PriorityNode = new Node;
        //sumNode's frequency is the sum of the frequencies of its left and right node
        PriorityNode->frequency = leftN->frequency + rightN->frequency;
        PriorityNode->data = '#';

        PriorityNode->left = leftN;
        PriorityNode->right = rightN;

        //Insert the sumNode onto our priority queue.
        h1.Insertion(*PriorityNode);
        printNode = PriorityNode;

        cout << "LeftN:\t" << leftN->data << "\t" << leftN->frequency << endl;
        cout << "RightN:\t" << rightN->data << "\t" << rightN->frequency << endl;
        cout << "curr size = " << h1.currSize << endl;

        cout << "--------------------------------------------------------\n";
    }


    return printNode;

}



int main()
{
    //Accessing and reading from file
    ifstream readF("file.txt");
    string line;
    getline(readF, line);
    readF.close();

    cout << "FILE DATA:   " << line << endl;

    int size = line.length();
    int k = 0;
    Node* arr = new Node[size];


    for (int i = 0; i < size; i++)
    {
        bool unique = true;

        for (int j = 0; j < i; j++)   //check if this element already exists in our Node array
        {
            if (line[i] == arr[j].data) //if it does, we don't add it to arr, and we increment the frequency
            {
                unique = false;
                arr[j].frequency++;
            }
        }
        if (unique == true) //if it doesn't, we add it to arr
        {
            arr[k].data = line[i];
            k++;
        }
    }

    for (int i = 0; i < k; i++)
    {
        cout << arr[i].data << endl << "freq: \t" << arr[i].frequency << "\n-----------------\n";

    }

    ////////    Simple Tree Implementation  ////////
    cout << "Inserting\n";

    Tree treeObj;
    for (int i = 0; i < size; i++)
    {

        treeObj.Insert(arr[i]);

    }
    cout << "===============================================================\n";
    cout << "Displaying Tree" << endl;
    treeObj.InorderDisplay(treeObj.root);

    cout << "===============================================================\n";
    cout << "Displaying Paths\n";

    for (int i = 0; arr[i].data != '\0'; i++)
    {
        cout << "Path for " << arr[i].data << endl;
        treeObj.Path(treeObj.root, arr[i].frequency);
        cout << endl;

    }
    cout << "===============================================================\n";
    cout << "\nBUILDING THE HUFFMAN TREE:\n\n";

    Node freqArr[50];
    Heap h1(k);
    Node* HuffmanRoot = new Node;
    HuffmanRoot = HuffmanScheme(arr, h1, freqArr);

    cout << "===============================================================\n";

    cout << "Printing Huffman Tree:\n";
    string s, st;
    int len = 0;
    int* lenArr = new int[k];
    char* dataArr = new char[k];
    int* freArr = new int[k];
    treeObj.HuffmanPath(HuffmanRoot, s);
    cout << "===============================================================\n";


    /// AVERAGE BIT RATE AND COMPRESSION RATES

    /// Calculating lengths of paths and storing them in lenArr to use later in ABR formula
    treeObj.PathLength(HuffmanRoot, st, len, lenArr, dataArr, freArr);
    treeObj.x = -1;
    cout << "===============================================================\n";



    cout << "CALCULATING AVERAGE BIT RATE....\nLengths of Paths:\n";
    int LengthOfFile = 0;
    for (int i = 0; i < k; i++)
    {
        cout << dataArr[i] << ":  " << lenArr[i] << endl;
        LengthOfFile += freArr[i];
    }
    cout << "Total Length of File: " << LengthOfFile << endl;

    float ABRSum = 0;
    for (int i = 0; i < k; i++)
    {
        ABRSum += freArr[i] * lenArr[i];
    }
    float ABR = ABRSum / LengthOfFile;

    cout << "=> ABR :  " << ABR << endl;
    cout << "===============================================================\n";
    cout << "CALCULATING COMPRESSION RATIO\n";
    float CompRat = 8 / ABR;
    cout << "=> COMPRESSION RATIO :  " << CompRat << endl;


}


