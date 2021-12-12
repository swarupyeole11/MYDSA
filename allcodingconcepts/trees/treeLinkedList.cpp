#include<bits/stdc++.h>
using  namespace std;

struct queues  //do not use queue as it is a key word
{
    struct node *data;
    struct queues *next;

}*front=NULL,*rear=NULL;

int isEmptyQ()
{
    return front==NULL?1:0;
}

void enqueue( struct node *x)
{   
    struct queues *t = new queues;

    if(t==NULL)
    {
        cout<<"queue is full";
    }
    
    else
    {
          if(front==NULL)
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
              rear=t;


          }
    }
}

struct node* dequeue()
{  
     struct node* x=NULL; // since it is pointer it cannot store normal values it stores addresses and that is the reaon why we take (x as pointer instead of int)  in this case because when we dequeue we want to get pointer in form of p which pointts to parent node for this we return x which is a pointer and stores adress we cannot achieve this by having x as int x
     struct queues *t;

    if(front==NULL)
    {
        cout<<"queue is empty";
        
    }

    else
    {
       
       x=front->data;
       t=front;   // ---BY MISTAKE WROTE t= new queues---
       front=front->next;
       delete t;
        
    }

    return x;
}

struct node
{
    struct node *lchild;
    int data;//this data and the data variable in struct queues is diffrent
    struct node *rchild;
}*root = NULL;

void createTree()
{   
    int x;                                                    
    cout<<"enter the value of root node:";
    cin>>x;
    root = new node;                  //r|_ _ _|
    root->lchild=NULL;
    root->data=x;                                              
    root->rchild=NULL;                //r|- - -| - THIS SYMBOL IDICATES VALUE HA BEEN ISETRED AT THIS PLACE -> |0 x 0|
    enqueue(root);                   // |--|  value stored in the queue


    while (front!=NULL)  // while  is not empty
    {
        struct node * p = dequeue();
 
        cout<<"enter the left child: ";
        cin>>x;
        if(x!=-1){
        struct node *t = new node;    //|_ _ _|
         t->lchild=NULL;
         t->data=x;                                              
         t->rchild=NULL;    //|- - -| - THIS SYMBOL IDICATES VALUE HAs BEEN INSETRED AT THIS PLACE -> | 0 x 0 |
         p->lchild=t;       // r|- - -| -> | t x 0 |
         enqueue(t);        // |--| >> | t 0 |
        }


        cout<<"enter the right child: ";
        cin>>x;
        struct node *t = new node;    //|_ _ _| 
        if(x!=-1){
         t->lchild=NULL;
         t->data=x;                                              
         t->rchild=NULL;    //|- - -| - THIS SYMBOL IDICATES VALUE HAs BEEN INSETRED AT THIS PLACE -> | 0 x 0 |
         p->rchild=t;   //--------- //BY MISTAKE WROTE rchild//---------   // r|- - -| -> | t x t |  // the t on the right side is diffren fro that on left side
         enqueue(t);        // |--|->|--| >> |t adressofNextNode|->|t 0| 
        }
    }
    
}

 struct stacks
 {
     struct node *data;
     struct stacks *next;
 }*top=NULL;

 void push(struct node*x)
 {
     struct stacks *t = new stacks;
     if(t==NULL)
     {
         cout<<"stack is Full";
     }

     else
     {
         t->data = x;
         t->next=top;
         top=t;
     }
 }

 struct node *pop()
 {  
     struct node *x=NULL; //fogot to write x=NULL

     if(top==NULL)
     {
         cout<<"stack is Empty"<<endl;
     }

     else
     {  
         struct stacks *p = top;
         x=top->data;
         top=top->next;
         delete p;
     }
     
     return x;
 }

 int isEmptyStack()
 {
     return top==NULL?1:0;
 }


 void preorder(struct node *p)
 {
    if(p)
    {
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
 }

 void inorder(struct node *p)
 {
     if(p)
     {
         inorder(p->lchild);
         cout<<p->data<<" ";
         inorder(p->rchild);
     }
 }

 void postorder(struct node *p)
 {
     if(p)
     {
         postorder(p->lchild);
         postorder(p->rchild);
         cout<<p->data<<" ";
     }
 }

 void Ipreorder(struct node *p)
 {
     while(p||!isEmptyStack())
     {
        // flag=1;
         if(p)
         {  
             push(p);
             cout<<p->data<<" "; 
             p=p->lchild; 
         }

         else if(p==NULL)
         {
            p = pop();
            p=p->rchild;
         }

     }
     
 }

  void Iinorder(struct node *p)
 {
     
 }

  void Ipostorder(struct node *p)
 {
     
 }

int main()
{
    createTree();
    preorder(root);
    Ipreorder(root);

  return 0;
}
   
