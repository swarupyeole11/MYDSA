#include <iostream>
#include <queue>

using namespace std;

class node
{
private:
    /* data */
public:
    int data;
    node *lChild;
    node *RChild;

    node(int d)
    {
        data = d;
        lChild = NULL;
        RChild = NULL;
    }
};

node *LevelOrderTree()
{
    int rootData;
    cout << "Enter The Root Data : ";
    cin >> rootData;
    queue<node *> Q;

    if (rootData == -1)
        return NULL;

    node *root = new node(rootData), *p;
    Q.push(root);

    while (!Q.empty())
    {
        // Dequeuing the queue
        node *t = Q.front();
        Q.pop();

        int lChilddata, Rchilddata;
        cout << "enter the lChild of " << t->data << ": ";
        cin >> lChilddata;
        if (lChilddata != -1)
        {
            p = new node(lChilddata);
            t->lChild = p;
            Q.push(p);
        }

        cout << "enter the Rchild of " << t->data << ": ";
        cin >> Rchilddata;
        if (Rchilddata != -1)
        {
            p = new node(Rchilddata);
            t->RChild = p;
            Q.push(p);
        }
    }
    return root;
}

void InorederTrav(node *t)
{
    if (t)
    {
        InorederTrav(t->lChild);
        cout << t->data << " ";
        InorederTrav(t->RChild);
    }
}

int search(int inorder[], int start, int end,int key)
{
    int index;
    for (int i = start; i <=end; i++)
    {
        if (inorder[i] == key)
            index = i;
    }
    return index;
}

node *InPreBuild(int inorder[], int preorder[], int start, int end)
{
    // if (start > end)
    //     return NULL;

    // static int precount = 0;
    // node *t = NULL;
    // if (precount != n)
    // {
    //     int key = preorder[precount++];
    //     t = new node(key);
    //     if (start == end)
    //         return t;

    //     int partitonIndex = search(inorder, n, key);

    //     t->lChild = InPreBuild(inorder, preorder, 0, partitonIndex - 1, n);
    //     t->RChild = InPreBuild(inorder, preorder, partitonIndex + 1, n - 1, n);
    // }

    // return t;

     static int preIndex = 0;
 
    if (start > end)
        return NULL;
 
    /* Pick current node from Preorder
    traversal using preIndex
    and increment preIndex */
    node* tNode = new node(preorder[preIndex++]);
 
    /* If this node has no children then return */
    if (start == end)
        return tNode;
 
    /* Else find the index of this node in Inorder traversal */
    int inIndex = search(inorder, start, end, tNode->data);
 
    /* Using index in Inorder traversal, construct left and
    right subtress */
    tNode->lChild = InPreBuild(inorder, preorder, start, inIndex - 1);
    tNode->RChild = InPreBuild(inorder, preorder, inIndex + 1, end);
 
    return tNode;
}

void leveledLevelOrder(node *t)
{
    queue<node *> Q;
    Q.push(t);
    Q.push(NULL);

    while (!Q.empty())
    {
        // poping the value from queue
        t = Q.front();
        Q.pop();

        // if the value not null
        if (t)
        {
            cout << t->data << " ";
            if (t->lChild)
                Q.push(t->lChild);
            if (t->RChild)
                Q.push(t->RChild);
        }

        // if popped value is null
        else
        {
            cout << endl;
            if (!Q.empty()) // important condition or at the last step of queue if condition missed leads to infi loop
                Q.push(NULL);
        }
    }
}

int main()
{
    // node *root = LevelOrderTree();
    // InorederTrav(root);

    int n;
    cout << "enter the number of elements in the the tree : ";
    cin >> n;

    int inorder[n];
    int preorder[n];

    cout << "Enter the inorder elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }

    cout << "enter the preorder elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }

    node *root = InPreBuild(inorder, preorder, 0, n - 1);
    InorederTrav(root);

    return 0;
}