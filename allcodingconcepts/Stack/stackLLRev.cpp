#include<bits/stdc++.h>
using  namespace std;

struct node
{
    int data;
    struct node *next;
}*top=NULL;

int isEmpty()
{
    return top==NULL?1:0;
}

int isFull()
{
    struct node *t= new node;
    return t==NULL?1:0;
}

void push(int x)
{
    if(isFull()==true)
    {
        cout<<"stack ovverflow";
    }

   
   else
   { 
        struct node *t =new node;
        
           t =new node;
           t->data=x;
           t->next=top;
           top=t;
       
   }
}

int pop()
{    
    int x=-1;

     if(isEmpty()==true)
    {
        cout<<"stack underflow";
        return -1;
    }

    else
    {
        struct node *p = top;
         x=p->data;
         top=p->next;
         delete p;
         return x;

    }
}

int main(){


  return 0;
}
   
