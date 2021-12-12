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
    struct node *t;
    t = new node;
    return t==NULL?1:0;
}

int stackTop()
{
    if(isEmpty()==true)
    {
        return -1;
    }

    else{
        return top->data;
    }
}

void push(int x)
{
    if(isFull()==true)
    {
        cout<<"stack overflow";
    }

    else{
        
        struct node *t = new node;
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
        return x;
    }

    else
    {
        struct node *t = top;
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

   return 1;
}



void EvaluatePostfix(string str)
{   
    int x1,x2,r;
    for(int i=0;i<str.size();i++)
    {
        if(isOperand(str[i])==true)
        {
            push(str[i]-'0');
        }
        
        else
        {
            x2=pop();
            x1=pop();

            switch(str[i])
            {
                case '+': r= x1 + x2;
               // cout<<r<<" "<<endl;
                push(r);
                break;
                case '-': r= x1 - x2;
                //cout<<r<<" "<<endl;
                push(r);
                break;
                case '/': r= x1 / x2;
               // cout<<r<<" "<<endl;
                push(r);
                 break;
                case '*': r= x1 * x2;
               // cout<<r<<" "<<endl;
                push(r);
                 break;

            }
        }
        

    }

        cout<<" "<<"\nOUTPUT:"<<pop()<<endl<<endl<<endl;
    
} 

int main()
{
    string s;
    cout<<endl<<endl;
    cout<<"Enter The String : ";
    getline(cin,s);
    EvaluatePostfix(s);

  return 0;
}
   
