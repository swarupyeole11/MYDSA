#include<bits/stdc++.h>
using  namespace std;

struct node
{   
    struct node *Lchild=NULL;
    int data;
    struct node *Rchild=NULL;

}*root=NULL;

struct queues
{
    int front =0;
    int rear =0;
    int size;
    struct node  **Q;
};

void enqueue(struct queues *q,struct node *x)
{
   if((((q->rear+1)%q->size))==q->front) 
   {
       cout<<"queue is full";
   }

   else
   {
       q->rear=(q->rear+1)%q->size;
       q->Q[q->rear]=x;
   }
}

struct node *dequeue(struct queues *q)
{   
    struct node *x=-1;

    if(q->rear==q->front)
    {
        cout<<"empty Queue";
    }

    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }

    return x;
}

void display(struct queues *q)
{  
    int i = (q->front+1)%q->size;
    do
    {  
        cout<<q->Q[i]<<" ";
        i=(i+1)%q->size; // even bracket is very important;

    } while (i!=(q->rear+1)%q->size);
    
}

void createTree()
{  
   struct queue q; 
   int x; 
   cout<<"enter the root value:";
   cin>>x;
   root = new node;
   root->data=x;
   root->Lchild=root->Rchild=NULL;
   enqueue(&q,root);


}
int main()
{
   struct queues q;
   cout<<"enter the size of array";
   cin>>q.size;
   q.Q= new int[q.size];

  return 0;
}
   


