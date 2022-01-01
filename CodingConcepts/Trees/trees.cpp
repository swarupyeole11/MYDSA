#include <iostream>
#include<queue>
using namespace std;

class node
{

public:

 int data;
 node * Rchild; // these are self referential pointers which store address for the next node
 node *Lchild;

 node (int d)
 {
     data=d;
     Lchild=nullptr;
     Rchild=nullptr;
 }
     
};

node * buildTree()
{    

    int d;
    cout<<"val: "<<endl;
    cin>>d;

    if(d==-1)
    return NULL;

    node *t = new node(d);
    t->data=d;
    t->Lchild=buildTree();
    t->Rchild=buildTree();
    return t;

}

void preOrderTrav(node *p) //prorder is always rootnode then leftChild/Subtree and then Right Child/Subtree it can be seen here in recursion logic too
{
   if (p)
   {
       cout<<p->data<<" ";
       preOrderTrav(p->Lchild);
       preOrderTrav(p->Rchild);

   }  
   return;
}

void levelOrder(node *root)
{
    queue<node*> Q;  //<> inside the  two arrows contains the type of data ypu wan tto store in the queue
    node *t=NULL,*p=NULL;
    cout<<root->data<<" ";
    Q.push(root);
   

    while (Q.empty()!=true)
    {
        p= t = Q.front();
        Q.pop();// Note the pop function does not return anything be careful for that
        
      

        p=p->Lchild;
        if(p)
        {    
            cout<<p->data<<" ";
            Q.push(p);
        }


        t=t->Rchild;
        if(t)
        {
           cout<<t->data<<" ";
           Q.push(t);
        }

    }
    

}

int  main()
{
   node *root  = buildTree();
   //preOrderTrav(root);
   levelOrder(root);

}