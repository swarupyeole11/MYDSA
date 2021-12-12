#include<bits/stdc++.h>
using  namespace std;

struct node
{
    int data;
    struct node *next;
}*top=NULL;


void display(struct node *p)
{
    while (p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    
}

int isEmpty()
{
    return top==NULL?1:0;
}

int isFull()
{
    struct node *t = new node;
    if(t==NULL)
    {
        return 1;
    }

    return 0;
}

void push(struct node *p , int x)
{  
   if(isFull()==true)
   {
       cout<<"stackoverflow";
   } 
   else
   {
   p = new node;
   p->data=x;
   p->next=top;
   top=p;
   }
}

 int pop(struct node *p)
 {   
     int x=-1;
     if(isEmpty()==true)
     {
         return x;
     }

     else
     {
         top=top->next;
         x=p->data;
         delete p;
         return x;

     }
 }

 void stackTop(struct node *p)
 {
     if(isEmpty()==true)
     {
         cout<<"stack underflow";
     }
     else
     {
         cout<<p->data<<endl;
     }
 }


 

int main(){

    //  push(top,3);
    //  cout<<top->data;
    //  push(top,4);
    //  cout<<endl<<top->data<<endl;
    //  pop(top);
    //  display(top);
    //  push(top,5);
    //  stackTop(top);


  return 0;
}
   
