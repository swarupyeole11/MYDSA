#include<bits/stdc++.h>
using  namespace std;

struct node 
{
    char data;
    struct node *next;
}*top=NULL;

int isEmpty()
{
    return top==NULL?1:0;
}

int isFull()
{
    struct node *t;
    t = new node;

    return t==NULL?1:0;

}

int stackTop(struct node *p)
{
   return isEmpty()==true?0:p->data;
}


void push(char x)
{
   
  if(isFull()==true)
  {
      cout<<"stack Overflow";
  }

  else
  {
   struct node *t=new node;   
   t->data=x;   
   t->next=top;
   top=t;
  } 

}


int pop()
{   
    int x=-1;
    struct node *t = top;

    if(isEmpty()==true)
    {
        return x;
    }

    else
    {
       top=top->next;
       x=t->data;
       delete t;
       return x;
    }
}

int isOperand(char x)
{
    if(x=='+'||x=='-'||x=='/'||x=='*')
    {
       return 0;
    }

    else
       return 1;
}

int pre(char x) // to check presedence 
{
     if(x=='+'||x=='-')
    {
       return 1;
    }

    else if(x=='/'||x=='*')
    {
       return 2;
    }

    return 0;
}

void infixToPostfix(stirng str)
{
    
}


int main()
{
    
    string s;
    getline(cin,s);
    infixToPostfix(s);
    

  return 0;
}
   
