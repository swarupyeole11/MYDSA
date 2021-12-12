#include<bits/stdc++.h>
using  namespace std;
int counter =0;
struct node
{
    char data;  // here we use character data type since we have to store thr character elements
    struct node * next;      //|_| 
}*top=NULL;

int isEmpty()
{
   return top==NULL?1:0;
}

int isFull()
{
    struct node *t = new node;

    return t==NULL?1:0;
}

char stackTop() // it is not advisable to use this function in questions which involve char return it may lead to problems
{
    struct node *t = top;

    if(isEmpty()==true)
    {
        return '#';
    }

    else
    {
        return t->data;
    }
}

void push(char x)
{   
    if(isFull()==true)
    {
        cout<<"stack overflow";
    }

    else
    {
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

int INpre(char x , int *coun)
{
    if(x=='+'||x=='-')
    {
       return 1;
    }

    else if(x=='*'||x=='/')
    {
        return 3;
    }

    else if(x=='^')
    {
        return 6;
    }

    else if(x=='(')
    {   
        *coun=+*coun+1;
       // cout<<"counter value:"<<*coun;
        return 7;
    }

    else if(x==')')
    {
        return 0;
    }

    return -1;

}

int OUTpre(char x)
{
    if(x=='+'||x=='-')
    {
       return 2;
    }

    else if(x=='*'||x=='/')
    {
        return 4;
    }

    else if(x=='^')
    {
        return 5;
    }

    else if (x=='(')
    {
        return 0;
    }
    
    return -1;
}

int isoperand( char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^'||x=='('||x==')')
    {
        return 0;
    }

    return 1;
}

char* convertInfixTOPostfix(string str)
{   
    char *ptr = new char[str.size()];
    int i=0,j=0;
    while(str[i]!='\0')
    {
       if(isoperand(str[i])==true)
       {    
           //cout<<"operand:"<<str[i]<<endl;
            ptr[j++]=str[i++]; //note first i value is used then incremented in increment operator
       }

       else
       {
           if(INpre(str[i],&counter)>OUTpre(stackTop()))
           {  
               //cout<<"operator:"<<str[i]<<endl;
               push(str[i++]);
           }

          else if(INpre(str[i],&counter)==OUTpre(stackTop()))
           {  
               //cout<<"equality"<<endl;
               pop();
               i++; //FORGOT THIS STEP
           }

           else
           {
               ptr[j++]=pop();
           }
       }
      

    }

     while(top!=NULL)
     {
           ptr[j++]=pop();
     }

     ptr[j]='\0'; // YOU FORGOT TIHS REMEMEMBER IT

    return ptr;
}


int main(){
  
 
  string s;

  cout<<"\n\nEnter The String : ";
  getline(cin,s);
  int n= s.size();
  for(int i=0;i<n/2;i++)
  {  
      if(s[i]=='(')
      {
            s[i]='(';
            s[n-1-i]=')';
      }

      else if(s[i]==')')
      {
            s[i]=')';
            s[n-1-i]='(';
      }

      else
      {
          swap(s[i],s[n-1-i]);
      }
    
  }

    cout<<s;

  
  
  string p=convertInfixTOPostfix(s);
  
  int val = s.size()-(2*counter); // since number of total brackets= 2*no.of closing ones
  
  cout<<endl;

  int m = p.size();
  for (int i = 0; i < m/2; i++)
  {   
      swap(p[i],p[m-i-1]);
  }

  cout<<endl<<"OUTPUT: "<<endl;
  cout<<p<<endl<<endl;
  
  
  
  return 0;
}
   
