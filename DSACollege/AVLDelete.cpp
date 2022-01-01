#include <iostream>
 #include <queue> 
 using namespace std;
 
 class node
 {
    public:
    
    int data;
    node * lChild;
    node * RChild;
    
    node(int d)
    {
        data = d;
        lChild = NULL;
        RChild = NULL;
    }
 };
 
 node *InsertBST(int key , node *t)
 {
     if(t==NULL)
     {
      t = new node(key);
      return t;
     }
     
     node *pt=NULL; 
      
      while(t)
      {   
          pt=t;
          if(key>t->data)
           t=t->RChild;
          else if(key<t->data)
           t=t->lChild;
          else
           return NULL;
      }
      
      t=new node(key);
      
      if(key>pt->data)
        pt->RChild = t;
      else
        pt->lChild = t;
        
    return t;         
        
 }
 
 void Inorder(node *t)
 {   
     if(t)
     {
     Inorder(t->lChild);
     cout<<t->data<<" ";
     Inorder(t->RChild);
     }
 }
 
 int height(node *t)
 {
     if(t==NULL) //write wholw t==NULL if ypu just write t it is somehow not working
      return 0;
      
     int x = height(t->lChild);
     int y = height(t->RChild);
     
     if(x>y)
       return x+1;
       
     else
       return y+1;
 }
 
 node* InSucc(node *t)
 {
     while(t!=NULL && t->lChild!=NULL)
     {
         t=t->RChild;
     }
     
     return t;
 }
 
 node* InPre(node *t)
 {
     while(t!=NULL && t->RChild!=NULL)
     {
         t=t->RChild;
     }
     
     return t;
 }
 
 node *deletes(int key , node *t)
 {
     
     if(t==NULL)
       return NULL;
       
     
     if(t->lChild==NULL && t->RChild==NULL)
     {
          delete t;
          return NULL;
     }
     
     
      if(t->data>key)
        t=deletes(key,t->lChild);
          
      else if(t->data<key)
        t=deletes(key,t->RChild);
        
        
      else
      {  
          if(height(t->RChild)>height(t->lChild))
          {
            node *nt = InSucc(t->RChild);
            t->data = nt->data;
            t->RChild=deletes(nt->data,t->RChild);
          }
          
          else
          {
              node *nt = InPre(t->lChild);
              t->data= nt->data;
              t->lChild= deletes(nt->data,t->lChild);
          }
      }
      
        return t;
 }


 //for AVL TREE


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

void pushTreeNodes(node* root, vector<node*> &nodes)
{
  
    if (root == nullptr) {
        return;
    }
 
    pushTreeNodes(root->lChild, nodes);
    nodes.push_back(root);
    pushTreeNodes(root->RChild, nodes);
}
 

node* buildBalancedBST(vector<node*> &nodes, int start, int end)
{
    if (start > end) {
        return nullptr;
    }
 
    int mid = (start + end) / 2;
 
 
    node* root = nodes[mid];
 
    root->lChild = buildBalancedBST(nodes, start, mid - 1);
    root->RChild = buildBalancedBST(nodes, mid + 1, end);
 
    return root;
}
 
void constructBalancedBST(node*& root)
{
 
    vector<node*> nodes;
    pushTreeNodes(root, nodes);
 
    root = buildBalancedBST(nodes, 0, nodes.size() - 1);
}

 
 int main()
 {
     node *root = NULL;
     root = InsertBST(100,root);
     InsertBST(34,root);
     InsertBST(108,root);
     InsertBST(20,root);
     InsertBST(25,root);
     InsertBST(38,root);
     InsertBST(68,root);
     InsertBST(45,root);
     InsertBST(106,root);
     InsertBST(120,root);
     InsertBST(128,root);
     cout<<"Tree Before Deleting the element : \n";
     leveledLevelOrder(root);
     cout<<endl;
     cout<<"Tree After Deleting the element : \n";
     deletes(108,root);
     leveledLevelOrder(root);
     cout<<endl;
   
     
     
     return 0;
 }