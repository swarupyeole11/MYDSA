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


//CONVERTING BINARY TREE TO BST

void arrayToBST(int* arr, struct node* root, int* index_ptr)
{
    
    if (root == NULL)
        return;
 
    arrayToBST(arr, root->lChild, index_ptr);
 
  
    root->data = arr[*index_ptr];
    (*index_ptr)++;
 
    arrayToBST(arr, root->RChild, index_ptr);
}

int countNodes(struct node* root)
{
    if (root == NULL)
        return 0;
    return countNodes(root->lChild) + countNodes(root->RChild) + 1;
}

void storeInorder(struct node* node, int inorder[], int* index_ptr)
{
 
    if (node == NULL)
        return;
 
    storeInorder(node->lChild, inorder, index_ptr);
 
    inorder[*index_ptr] = node->data;
    (*index_ptr)++; 
    storeInorder(node->RChild, inorder, index_ptr);
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

//Recursive function to push nodes of a given binary search tree into a
// vector in an inorder fashion
void pushTreeNodes(node* root, vector<node*> &nodes)
{
    // base case
    if (root == nullptr) {
        return;
    }
 
    pushTreeNodes(root->lChild, nodes);
    nodes.push_back(root);
    pushTreeNodes(root->RChild, nodes);
}
 
// Recursive function to construct a height-balanced BST from
// given nodes in sorted order
node* buildBalancedBST(vector<node*> &nodes, int start, int end)
{
    // base case
    if (start > end) {
        return nullptr;
    }
 
    // find the middle index
    int mid = (start + end) / 2;
 
    // The root node will be a node present at the mid-index
    node* root = nodes[mid];
 
    // recursively construct lChild and RChild subtree
    root->lChild = buildBalancedBST(nodes, start, mid - 1);
    root->RChild = buildBalancedBST(nodes, mid + 1, end);
 
    // return root node
    return root;
}
 
// Function to construct a height-balanced BST from an unbalanced BST
void constructBalancedBST(node*& root)
{
    // Push nodes of a given binary search tree into a vector in sorted order
    vector<node*> nodes;
    pushTreeNodes(root, nodes);
 
    // Construct a height-balanced BST from sorted BST nodes
    root = buildBalancedBST(nodes, 0, nodes.size() - 1);
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
    cout<<endl;
    cout<<"Tree Constructed From Inorder And Pre Order : \n";
    leveledLevelOrder(root);
    cout<<endl;

    return 0;
}