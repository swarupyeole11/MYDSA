#include<bits/stdc++.h>
using  namespace std;

struct Queues
{
    struct node * data;
    struct Queues *next;
}*front=NULL,*rear=NULL;

void enqueue(struct node *x)
{
    struct Queues *t = new Queues;
    if(t==NULL)
    {
        cout<<"queues is Full";
    }

    else
    {
        if(front==NULL)
        {
            t->data=x;
            t->next=NULL;
            rear=front=t;
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

 struct node * dequeue() // bymistake wrote int istead of struct node*
 {
     struct node *x=NULL;
    if(front==NULL)
    {
        cout<<"Queue is empty";
        return x;
    }

    else
    {   
        struct Queues *t = front;
        x=front->data;
        front=front->next;
        delete t;
        return x;

    }
 }

 int isEmptyQueue()
 {
     return front==NULL?1:0;
 }

 struct node
 {
     int data;
     struct node *lchild;
     struct node *rchild;
 }*root=NULL;
 
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

 struct Sstacks
 {
     long long data;
     struct Sstacks *next;

 }*S_top=NULL;

 void Spush(long long x)
 {
     struct Sstacks *t = new Sstacks;
     if(t==NULL)
     {
         cout<<"stack is Full";
     }

     else
     {
         t->data = x;
         t->next=S_top;
         S_top=t;
     }
 }

  long long Spop()
 {  
     long long x=0; //fogot to write x=NULL

     if(S_top==NULL)
     {
         cout<<"stack is Empty"<<endl;
     }

     else
     {  
         struct Sstacks *p = S_top;
         x=S_top->data;
         S_top=S_top->next;
         delete p;
     }
     
     return x;
 }

 int isEmptyStack()
 {
     return top==NULL?1:0;
 }

 void createTree()
 {
     root = new node;
     cout<<"Enter the value of the root node:";
     int x;
     cin>>x;
     root->lchild=NULL;
     root->data=x;
     root->rchild=NULL;
     enqueue(root);

     while(!isEmptyQueue())
     {  
        struct node *p = dequeue();
        cout<<"Enter the value of the left child:";
        cin>>x;
        if(x!=-1){
        struct node *t = new node;
        t->lchild=NULL;
        t->data=x;
        t->rchild=NULL;
        p->lchild=t;
        enqueue(t);
        }


        struct node *t = new node;
        cout<<"Enter the value of the right child:";
        cin>>x;
        if(x!=-1){
        t->lchild=NULL;
        t->data=x;
        t->rchild=NULL;
        p->rchild=t;
        enqueue(t);
        }
     }
     
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
     while(p||!isEmptyStack())
     {
         if(p)
         {  
             push(p); 
             p=p->lchild; 
         }

         else if(p==NULL)
         {
            p = pop();
            cout<<p->data<<" ";
            p=p->rchild;
         }

     }
 }

 
 void LevelOrder(struct node *p)
 {  
     cout<<p->data<<" ";
     enqueue(root);

     while (!isEmptyQueue())  //forgot to put () in isEmptyQueue() function
    {
            p= dequeue();
            if(p->lchild){
            cout<<p->lchild->data<<" ";
            enqueue(p->lchild);
            }

            if(p->rchild){
            cout<<p->rchild->data<<" ";
            enqueue(p->rchild);
            }
     }
      
 }

int main()
{

    createTree();
    LevelOrder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    Ipreorder(root);
    cout<<endl;
    Iinorder(root);
    cout<<endl;

  return 0;
}
   
