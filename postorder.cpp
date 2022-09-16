#include <bits/stdc++.h>
using namespace std;

template <typename T>
class binaryTree
{
public:
    T data;
    binaryTree<T> *left;
    binaryTree<T> *right;

    binaryTree(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~binaryTree()
    {
        delete left;
        delete right;
    }
};
binaryTree<int> *levelwiseinput()
{
    cout << "enter root data" << endl;
    int rootdata;
    cin >> rootdata;
    if (rootdata == -1)
    {
        return 0;
    }
    else
    {
        queue<binaryTree<int> *> pendingnode;
        binaryTree<int> *root = new binaryTree<int>(rootdata);
        pendingnode.push(root);
        while (pendingnode.size() != 0)
        {
            binaryTree<int> *current = pendingnode.front();
            pendingnode.pop();

            cout << "enter the left child data" << current->data << endl;
            int leftchilddata;
            cin >> leftchilddata;
            if (leftchilddata != -1)
            {
                binaryTree<int> *leftchild = new binaryTree<int>(leftchilddata);
                current->left = leftchild;
                pendingnode.push(leftchild);
            }

            // enter the element of right child

            cout << "enter the right child data" << current->data << endl;
            int rightchilddata;
            cin >> rightchilddata;
            if (rightchilddata != -1)
            {
                binaryTree<int> *rightchild = new binaryTree<int>(rightchilddata);
                current->right = rightchild;
                pendingnode.push(rightchild);
            }
        }
        return root;
    }
    
}

void printLevelWise(binaryTree<int> *root)
{
    if (root == 0)
    {
        return ;
    }
    else
    {
        queue<binaryTree<int> *> pending;
        pending.push(root);
        while (pending.size() != 0)
        {
            binaryTree<int> *front = pending.front();
            pending.pop();
            cout << front->data << ":";
            if (front->left)
            {
                pending.push(front->left);
                cout << "L:" << front->left->data;
            }
            else
            {
                cout << "L:-1";
            }
            cout << ",";
            if (front->right)
            {
                pending.push(front->right);
                cout << "R:" << front->right->data << endl;
            }
            else
            {
                cout << "R:-1" << endl;
            }
        }
    }
}

void preorder(binaryTree<int> *root)
{
    if (root == NULL)
    {
        return ;
    }
    else
    {
        cout << root->data << endl;
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    binaryTree<int> *root = levelwiseinput();
    printLevelWise(root);
    cout << "the preorder of the tree is " << endl;
    preorder(root);
}