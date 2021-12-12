#include<bits/stdc++.h>
using  namespace std;


struct node
{
    char data;
    struct node *next;
}*top=NULL;


void push(struct node *p , char x)
{  
    
    struct node *t = new node;
    if(t==NULL)
    {
        cout<<"stackOverflow"<<endl;
    }
    else
    {
     t->data=x;   
     t->next=top;
     top=t;
    }

}

int pop(struct node *p)
{  
   char x=-1; 
   if(top==NULL)
   {
       cout<<"stack Underflow"<<endl;
   }
   else
   {   
       top=top->next;
       delete p;
   }

   return x;
}


int parenthesisCheck(string str , struct node *p)
 {
    for(int i=0;i<=str.size();i++)
    {
        if (str[i]=='(')
        {
            push(top,'(');
        }

       else if(str[i]==')')
        {   
            if(top==NULL)
            {
                return 0;
            }
            pop(top);
        }
    }

    if(top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
 }

int main()
{  
    string s;
    getline(cin,s);

    // for(int i=0;i<s.size();i++)
    // {
    //     cout<<s[i];
    // }
    
    cout<<parenthesisCheck(s,top);
    
  return 0;
}
   
