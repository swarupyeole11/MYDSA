#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *Rchild;
    node *Lchild;

    node(int d)
    {
        data = d;
        Rchild = NULL;
        Lchild = NULL;
    }
};

void inorderTrav(node *t)
{
    if (t != NULL)
    {
        inorderTrav(t->Lchild);
        cout << t->data << " ";
        inorderTrav(t->Rchild);
    }
}

node *InsertBST(int key, node *t)
{
    if (t == NULL)
    {
        t = new node(key);
        return t;
    }

    node *pt = NULL;

    while (t)
    {
        pt = t;
        if (key > t->data)
            t = t->Rchild;
        else if (key < t->data)
            t = t->Lchild;
        else
            return NULL;
    }

    t = new node(key);

    if (key > pt->data)
        pt->Rchild = t;
    else
        pt->Lchild = t;

    return t;
}

int search(vector<int> &arr, int n, int key)
{
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            index = i;
    }

    return index;
}

int main()
{
    cout << endl;
    cout << "enter the number of values you want to enter : ";
    int n;
    cin >> n;
    vector<int> arr;
    cout << endl;
    cout << "Enter the Input Values : ";
    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        arr.push_back(val);
        if (i == 0)
            root = InsertBST(arr[i], root);
        else
            InsertBST(arr[i], root);
    }

    cout << "\nThe Inorder Traversal of created tree:\n ";
    inorderTrav(root);
    cout << endl;

    int partitionval;
    cout << " \nEnter the partition value : ";
    cin >> partitionval;
    cout << endl;

    int partitionIndex = search(arr, n, partitionval);

    node *t1 = NULL, *t2 = NULL; // try solving by passing through a function
    int i;
    for (i = 0; i < partitionIndex; i++)
    {
        if (i == 0)
            t1 = InsertBST(arr[i], t1);
        else
            InsertBST(arr[i], t1);
    }
  
    cout<<"The Inorder Display of part1 BST : \n";
    inorderTrav(t1);
    cout<<endl;

    for (; i < n; i++)
    {
        if(i==partitionIndex)
           t2=InsertBST(arr[i],t2);
        else
           InsertBST(arr[i],t2);
    }

    cout<<"The Inorder Display of part2 BST : \n";
    inorderTrav(t2);
    cout<<endl;

    return 0;
}