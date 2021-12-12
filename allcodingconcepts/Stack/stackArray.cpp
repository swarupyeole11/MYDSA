#include<bits/stdc++.h>
using  namespace std;
typedef long long int ll;

struct Stack
{
    int size;
    int top;
    int *ptr;// this is a pointer pointing to array in heap to acess it elsewhere we use (st.ptr)
}st;


void createStack() // this creates an array Stack with size from user and pointer at first pointing at index -1
{
  cout<<"enter the size of array:";         //          |_|                                    
  cin>>st.size;                             //          |_|
  st.top = -1;                              //          |_|
  st.ptr = new int[st.size];                //          |_|
}                                           //          |_|

int isFull(struct Stack *st)
{
   if(st->top==st->size-1)
   {
       return 1;
   }

   return 0;
}

int isEmpty(struct Stack *st)
{
    return ( st->top==-1) ? 1:0;
}

void push(struct Stack *st , int x)
{
    if(isFull(st)==true)
    {
        cout<<"stack overflow";
    }

    else
    {
       st->top++;
       st->ptr[st->top]=x;
    }
}

int pop(struct Stack *st)
{   
    int x=-1;

   if(isEmpty(st)==true)
   {
       cout<<"stack underflow"<<endl;

   }

   else
   {
      x=st->ptr[st->top];
      st->top--;
   }

   return x;
}


int peek(struct Stack st, int pos) // Top-pos+1 = array index
{
    if(isEmpty(&st)==true || st.top-pos+1<0 )
    {
        return -1;
    }



    else
    {
        return st.ptr[st.top-pos+1];
    }
}

int stackTop(struct Stack *st)
{
    return isEmpty(st)==true?-1:st->ptr[st->top];
}


int main()
{
  
   createStack();
   push(&st , 3);  // KEEP in mind  where to use & and where not to if you want to pass address of normalvariable to pointer you use & if you want to pass address stored in one pointer to another pointer no need to use & as that pointer already stores the address 
   
   for(int i=0;i<=st.top;i++)
   {
      cout<<st.ptr[i]<<" ";
   }

   cout<<pop(&st)<<endl;
   
   push(&st , 3);
   push(&st , 3);
   push(&st , 4);

   cout<<stackTop(&st);
   


  return 0;
}
   
