// DATA STRUCTURES PROJECT                               //
// Saamiya Mariam (20i-0612) & Bisma Haroon (20i-0716)   //
// Section D                                             //
// // // // // // // // // // // // // // // // // // // //

#include <iostream>
#include "Node.cpp"
using namespace std;

class Tree
{
public:
    Node* root;
    int x = -1;
    //constructors
    Tree()
    {
        root = NULL;
    }
    Tree(Node* rt)
    {
        root = rt;
    }



    ///INSERT
    void Insert(Node temp)
    {
        Node* newNode = new Node;
        newNode->data = temp.data;
        newNode->frequency = temp.frequency;


        if (root == NULL) //empty tree
        {
            root = newNode;
        }
        else
        {
            Node* ptr = root; //ptr used to traverse
            while (ptr != NULL)
            {
                if ((newNode->frequency < ptr->frequency) && (ptr->left == NULL)) //newNode is less than ptr and left child doesn't exist
                {
                    ptr->left = newNode;
                    cout << "Node Inserted\n";
                    break;

                }
                else if (newNode->frequency < ptr->frequency) //newNode is less than ptr and left child exists
                {
                    ptr = ptr->left;
                }
                else if ((newNode->frequency > ptr->frequency) && (ptr->right == NULL)) //newNode is greater than ptr and right child doesn't exist
                {
                    ptr->right = newNode;
                    cout << "Node Inserted\n";
                    break;
                }
                else //newNode is greater than ptr and right child exists
                {
                    ptr = ptr->right;
                }
            }
        }

    }

    void InorderDisplay(Node* root)
    {
        if (root != NULL)
        {
            InorderDisplay(root->left);
            cout << root->data << " " << root->frequency << "\n";
            InorderDisplay(root->right);
        }
    }

    void Path(Node* root, int freq)
    {
        if (root == NULL)
        {
            return;
        }

        else if (root->frequency > freq)
        {
            cout << "0";
            Path(root->left, freq);
        }
        else if (root->frequency < freq)
        {
            cout << "1";
            Path(root->right, freq);
        }

        else if (root->frequency = freq)
        {
            return;
        }
    }

    void HuffmanPath(Node* rt, string path)
    {
        if (rt == NULL)
        {
            return;
        }

        //if node is an external node
        if (rt->data != '#')
        {
            //print string 
            cout << rt->data << " : ";
            cout << path << endl;
        }

        string path2 = path + "0";
        HuffmanPath(rt->left, path2); //recursive call to check left path
        path2 = path + "1";
        HuffmanPath(rt->right, path2); //recursive call to check right path

    }

    void PathLength(Node* rt, string path, int len, int lenArr[], char dataArr[], int freArr[])
    {

        if (rt == NULL)
        {
            return;
        }


        //if node is an external node
        if (rt->data != '#')
        {
            //print string 
            cout << rt->data << " : ";
            cout << path << endl;
            cout << "Path Length: " << len << endl;
            lenArr[++x] = len;
            dataArr[x] = rt->data;
            freArr[x] = rt->frequency;
            return;
        }

        len = len + 1;
        string path2 = path + "0";
        PathLength(rt->left, path2, len, lenArr, dataArr, freArr); //recursive call to check left path
        path2 = path + "1";
        PathLength(rt->right, path2, len, lenArr, dataArr, freArr); //recursive call to check right path

    }
};
