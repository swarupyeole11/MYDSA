#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *Rchild=NULL;
    struct node *Lchild=NULL;
}*root=NULL;

void Insert(int key)
{
    struct node * t =root;
    struct node *r=NULL;
   
    if(root==NULL)
    {
        root= new node;
        root->data=key;
    }
   
    else
    {  
        while(t!=NULL)
        {
        r=t;
        if(key>t->data)
        t=t->Rchild;
        else if (key<t->data)
        t=t->Lchild;
        else
        return;
        }
       
        t = new node;
        t->data=key;
       
        if(key>r->data)
            r->Rchild=t;
        else
            r->Lchild=t;
    }
}

void preOrderDisplay(struct node *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<" ";
        preOrderDisplay(p->Lchild);
        preOrderDisplay(p->Rchild);
    }
}

void inOrderDisplay(struct node *p)
{
    if(p!=NULL)
    {
       
        inOrderDisplay(p->Lchild);
        cout<<p->data<<" ";
        inOrderDisplay(p->Rchild);
    }
}

void postOrderDisplay(struct node *p)
{
    if(p!=NULL)
    {
       
        postOrderDisplay(p->Lchild);
        postOrderDisplay(p->Rchild);
        cout<<p->data<<" ";
    }
}

// int countLeaves(node *t)
// {
  
//     if(t== nullptr) //I was missing this
//         return 0;

//     else if(t->Rchild==NULL&&t->Lchild==NULL)
//        return 1;

//     int x=0,y=0;
//     x += countLeaves(t->Lchild);
//     y += countLeaves(t->Rchild);

//     return x+y;
// }

int main()
{
    Insert(8);
    Insert(3);
    Insert(10);
    Insert(1);
    Insert(6);
    Insert(14);
    Insert(4);
    Insert(7);
   
    preOrderDisplay(root);
    cout<<endl;
    inOrderDisplay(root);
    cout<<endl;
    postOrderDisplay(root);
    cout<<endl;
    // int val = countLeaves(root);
    // cout<<"the number of leaf nodes : "<<val;
   
    return 0;
}