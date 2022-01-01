#include <iostream>
#include <queue>

using namespace std;

class node
{
private:
  
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
     static int preIndex = 0;
 
    if (start > end)
        return NULL;
 
    node* tNode = new node(preorder[preIndex++]);
 
    
    if (start == end)
        return tNode;
 
   
    int inIndex = search(inorder, start, end, tNode->data);
 
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
        
        t = Q.front();
        Q.pop();

        
        if (t)
        {
            cout << t->data << " ";
            if (t->lChild)
                Q.push(t->lChild);
            if (t->RChild)
                Q.push(t->RChild);
        }

        
        else
        {
            cout << endl;
            if (!Q.empty()) 
                Q.push(NULL);
        }
    }
}

int main()
{
    

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
    leveledLevelOrder(root);
    return 0;
}