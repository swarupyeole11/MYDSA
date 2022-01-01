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

node *buildTree()
{
    cout<<"val: ";
    int d;
    cin>>d;

    if(d==-1)
    {
        return NULL;
    }

    node *t = new node(d);
    t->data=d;
    t->lChild=buildTree();
    t->rChild=buildTree();
    return t;
}

void preOrder(node *t)
{
    if(t)
    {
        cout<<t->data<<" ";
        preOrder(t->lChild);
        preOrder(t->rChild);
    }

    return;
}

void levelOrder(node *t)
{
    queue<node*> Q;
    Q.push(t);
    
    while (!Q.empty())  // literal  meaning of statent while queue not empty
    {  
        //dequeing the value
        t=Q.front();
        Q.pop();

        //displaying the value
        cout<<t->data<<" ";

        //storing the children address
         if (t->lChild) //to check if there is a child at left postion if it is null then no child at left position
         {
             Q.push(t->lChild);
         }

         if(t->rChild)
         {
             Q.push(t->rChild);
         }
         
    }
    
}

void leveledLevelOrder(node *t)
{
     queue<node*> Q;
     Q.push(t);
     Q.push(NULL);

     while (!Q.empty())
     {
        //poping the value from queue
         t=Q.front();
         Q.pop();

        //if the value not null
        if(t)
        {
            cout<<t->data<<" ";
            if(t->lChild)
            Q.push(t->lChild);
            if(t->rChild)
            Q.push(t->rChild);
        } 
        
        //if popped value is null
        else
        {
           cout<<endl;
           if(!Q.empty())//important condition or at the last step of queue if condition missed leads to infi loop
           Q.push(NULL);
        }
     }
     
}

vector<vector<int>> vectorleveledLevelOrder(node *t) //doubt
{   
     vector<vector<int>> ans;

     if(t==NULL)
     return ans;

     queue<node*> Q;
     Q.push(t);
     Q.push(NULL);

     vector<int> ansrow;
     while (!Q.empty())
     {   


        //poping the value from queue
         t=Q.front();
         Q.pop();

        //if the value not null
        if(t)
        {     
            ansrow.push_back(t->data);
            
            if(t->lChild)
            Q.push(t->lChild);
            if(t->rChild)
            Q.push(t->rChild);
        } 
        
        //if popped value is null
        else
        {
            
           ans.push_back(ansrow);
           ansrow.clear();
           if(!Q.empty())//important condition or at the last step of queue if condition missed leads to infi loop
           Q.push(NULL);
        }
     }

     reverse(ans.begin(),ans.end());
     
     return ans;
}


node * levelOrderBuild()
{
    queue<node *> Q;
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
        
        int lchildData,rchildData;
       
       cout<<"Enter Value of Lchild of "<<t->data<<" : ";
        cin>>lchildData;
        if(lchildData!=-1)
        {
           p = new node(lchildData);
           t->lChild=p;
           Q.push(p);
        }

       cout<<"Enter Value of Rchild of "<<t->data<<" : ";
        cin>>rchildData;
        if(rchildData!=-1)
        {
             p = new node(rchildData);
             t->rChild=p;
             Q.push(p);
        }
    }
    
    return root;
}

int countLeaves(node *t)
{   
    
     int x=0,y=0;

    if(t==NULL)
      return 0;

    else if(t->lChild==NULL && t->rChild==NULL)
      return 1;
    
    x=countLeaves(t->lChild);
    y=countLeaves(t->rChild);
    return x+y;
}


int height(node *t)
{  
    int x=0,y=0;

    if(t==NULL)
     return 0;

    // else if(t->lChild==NULL&&t->rChild==NULL) 
    //  return 0;

    x=height(t->lChild);
    y=height(t->rChild);
  
    return max(x,y)+1;
}

node *search(node *t,int key)
{
    if(t==NULL)
     return NULL;

    else if(t->data==key) 
     return t;

    node *tx=NULL,*ty=NULL,*ptx=NULL,*pty=NULL;
    node *pt=NULL,*ppt=NULL;
    ppt=pt;
    pt=t;
    tx=search(t->lChild,key);
    ty=search(t->rChild,key);

    if(tx)
     return tx;

    if(ty)
      return ty; 

    return NULL;  
}

// parent of the given node
int findParent(node* node,
                int val, int parent)
{
    if (node == NULL)
        return 0;
 
    // If current node is the required node
    if (node->data == val) {
 
        // Print its parent
        return parent;
    }
    else {
 
        // Recursive calls for the children
        // of the current node
        // Current node is now the new parent
        findParent(node->lChild, val, node->data);
        findParent(node->rChild, val, node->data);
    }
}

 




int main()
{   
    node *root = levelOrderBuild();
    cout<<endl;
    leveledLevelOrder(root);
    // cout<<"parent :"<<findParent(root,10,-1);
    // int parent = findParent(root,10,-1);
    // cout<<"gradparent :"<<findParent(root,parent,-1);
    //countLeaves(root);
    //cout<<"\n Number of leaves:"<<countLeaves(root);
   // cout<<" Height Of Trees : "<<height(root);
   
     

    return 0;
}