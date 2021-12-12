#include<bits/stdc++.h>
using  namespace std;

struct queues
{
    struct node *data;
    struct queues *next;
}*front=NULL,*rear=NULL;

void enqueue(struct node *x)
{
    struct queues *t = new queues;

    if(t==NULL){
        cout<<"stack is full";
    }

    else
    {
        if (front==NULL)
        {
           t->data=x;
           t->next=NULL;
           front=rear=t;
        }

        else
        {
            t->data=x;
            t->next=NULL;
            rear->next=t;
            rear=t;//forgot to write this
        }
    }   
    
}

struct node *dequeue()
{ 
   struct node *x = NULL;

   if(front==NULL)
   {
       cout<<"Q is Empty";
   }
   
   else
   {
       struct queues *t = front;
       front= front->next;
       x=t->data;
       delete t;
   }
    return x;
}

struct node
{   
    struct node *lchild;
    int data;
    struct node *rchild;
}*root=NULL;


void createTree()
{  
    root = new node;
    cout<<"enter the root value:";
    int x;
    cin>>x;
    root->data=x;
    root->lchild=NULL;
    root->rchild=NULL;
    enqueue(root);

    while(front!=NULL)  // jab tak p null na hojaye aur front null na hojaye chalte raho
    {   
        struct node *p = dequeue();  // ERROR ! USED DEQUEE AT LAT INSTAD OF HERE DO NOT ISE DEQUE AT LAST IN ANY TRE PROGRAM IT  CREATES PROBLEMS IN EVERYTHING
        cout<<"enter the lchild of"<<p->data<<": ";
        cin>>x;

        if(x!=-1){
        struct node *t=new node;
        // ERROR! wrote cin>>x here instead of outside
        t->lchild=NULL;
        t->data=x;
        t->rchild=NULL;
        p->lchild=t;
        enqueue(t);
        }

        cout<<"enter the rchild of"<<p->data<<": ";
        cin>>x;
        if(x!=-1){
        struct node *t=new node;
        t->lchild=NULL;
        t->data=x;
        t->rchild=NULL;
        p->rchild=t;
        enqueue(t);
        }

    }
}

void preOrder(struct node *t)
{   
    if(t)  // FORGOT TO WRITE THE IF CONDITION
    {
    cout<<t->data<<" ";
    preOrder(t->lchild);
    preOrder(t->rchild);
    }
}

int main()
{
   createTree();
   preOrder(root);

  return 0;
}
   
