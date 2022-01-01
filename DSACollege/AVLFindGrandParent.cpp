#include <bits/stdc++.h>
using namespace std;

class node
{
    public:

    int data;
    node *rChild;
    node *lChild;

    node(int d)
    {
        data=d;
        rChild=NULL;
        lChild=NULL;
    }
};


node * levelOrderBuild()
{
    queue<node *> Q;
    cout<<"Enter The Value Of Root : ";
    int rootval;
    cin>>rootval;
    node *t,*root;
    root = new node(rootval);
    Q.push(root);
    node *p;

    while (!Q.empty())
    {   
        t=root;
        t=Q.front();
        Q.pop();
        
        int lchildData,rChildData;
       
       cout<<"Enter Value of Lchild of "<<t->data<<" : ";
        cin>>lchildData;
        if(lchildData!=-1)
        {
           p = new node(lchildData);
           t->lChild=p;
           Q.push(p);
        }

       cout<<"Enter Value of rChild of "<<t->data<<" : ";
        cin>>rChildData;
        if(rChildData!=-1)
        {
             p = new node(rChildData);
             t->rChild=p;
             Q.push(p);
        }
    }
    
    return root;
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
            if (t->rChild)
                Q.push(t->rChild);
        }

        
        else
        {
            cout << endl;
            if (!Q.empty()) 
                Q.push(NULL);
        }
    }
}


//CONVERTING BINARY TREE TO BST

void arrayToBST(int* arr, struct node* root, int* index_ptr)
{
    
    if (root == NULL)
        return;
 
    arrayToBST(arr, root->lChild, index_ptr);
 
  
    root->data = arr[*index_ptr];
    (*index_ptr)++;
 
    arrayToBST(arr, root->rChild, index_ptr);
}

int countNodes(struct node* root)
{
    if (root == NULL)
        return 0;
    return countNodes(root->lChild) + countNodes(root->rChild) + 1;
}

void storeInorder(struct node* node, int inorder[], int* index_ptr)
{
 
    if (node == NULL)
        return;
 
    storeInorder(node->lChild, inorder, index_ptr);
 
    inorder[*index_ptr] = node->data;
    (*index_ptr)++; 
    storeInorder(node->rChild, inorder, index_ptr);
}

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}


void binaryTreeToBST(struct node* root)
{
    
    if (root == NULL)
        return;
 
    int n = countNodes(root);
 
    int* arr = new int[n];
    int i = 0;
    storeInorder(root, arr, &i);
 
    qsort(arr, n, sizeof(arr[0]), compare);
 
    i = 0;
    arrayToBST(arr, root, &i);
 
    delete[] arr;
}


//converting bst to balanced BST


void pushTreeNodes(node* root, vector<node*> &nodes)
{
  
    if (root == nullptr) {
        return;
    }
 
    pushTreeNodes(root->lChild, nodes);
    nodes.push_back(root);
    pushTreeNodes(root->rChild, nodes);
}
 

node* buildBalancedBST(vector<node*> &nodes, int start, int end)
{
    
    if (start > end) {
        return nullptr;
    }
 
    
    int mid = (start + end) / 2;
 
    node* root = nodes[mid];
 
    
    root->lChild = buildBalancedBST(nodes, start, mid - 1);
    root->rChild = buildBalancedBST(nodes, mid + 1, end);
 
    return root;
}
 

void constructBalancedBST(node*& root)
{
    
    vector<node*> nodes;
    pushTreeNodes(root, nodes);
 
    root = buildBalancedBST(nodes, 0, nodes.size() - 1);
}

int findParent( node* t, int val, int parent)
{   

    static int retParent=0;

    if (t == NULL)
        return 0;
 
 
    if (t->data == val) {
        retParent=parent;
    }
    else {
      
        findParent(t->lChild, val, t->data);
        findParent(t->rChild, val, t->data);
    }

    return retParent;
}


int main()
{ 
    node * root = levelOrderBuild();
    cout<<"Level Order Of the formed Tree : \n";
    leveledLevelOrder(root);
    cout<<endl;
    
    int parent = findParent(root,10,-1);
    cout<<"The parent of 10 is: "<<findParent(root,10,-1)<<endl;
    int grandparent = findParent(root,parent,-1);
    cout<<"The Grandparent of 10 is: "<<findParent(root,parent,-1)<<endl;

    return 0;
}