#include<bits/stdc++.h>
using  namespace std;

void Delete(int List[],int pos,int *IndexPointer)
{  
    int val=*IndexPointer;
    int index = pos-1;
   if((*IndexPointer)==-1)
   {
       cout<<"Cannont delete since the list is empty ";
   }

   else if(index<0||index>(*IndexPointer))
   {
       cout<<"enter a valid index";
   }

   else
   {
      int i;
    for(i=index;i<val;i++)
    {
       List[i]=List[i+1];
    }

    --(*IndexPointer);

     cout<<"ELEMENT DELETED ! Please Enter New Product To Be Inserted Else Press -1: ";
     cout<<endl;
          int x;
          cin>>x;
          if(x!=-1)
          {
          *IndexPointer=*IndexPointer+1;
          List[*IndexPointer]=x;
          }

   }
}

void displayList(int List[],int pointer)
{
    for(int i=0;i<=pointer;i++)
    {
       cout<<List[i]<<" ";
    }
    cout<<endl;
}

int  DelExpired(int List[],int *pointer,int key)
{  
   int val =-1;
   for(int i=0;i<=(*pointer);i++)
   {
      if(List[i]==key)
      {   
          val = i;
          Delete(List,i+1,pointer);
          return val;
      }
   }
    
    return val;
}

void Odel(int List[],int pos,int *IndexPointer)
{  
    int val=*IndexPointer;
    int index = pos-1;

    if(index<0||index>(*IndexPointer))
   {
       cout<<"Enter valid index";
   }

   else
   {
      int i;
    for(i=index;i<val;i++)
    {
       List[i]=List[i+1];
    }

    --(*IndexPointer);

   }
}


int  ODelExp(int List[],int *pointer,int key)
{   
    int val =-1;
   for(int i=0;i<=(*pointer);i++)
   {
      if(List[i]==key)
      {   
          val=i;
          Odel(List,i+1,pointer);
          return val;
      }
   }
    return val;
}

void Replace(int List[],int ExpiredElement,int newElement,int *pointer)
{
    int Index = ODelExp( List,pointer,ExpiredElement);

     if(Index<0||Index>9)
   {
     cout<<"Index Not Valid!"<<endl;
     return;
   }

   int j;

   for(j=(*pointer);j>=Index;j--)
   {
       List[j+1]=List[j];
   }
    
    List[j+1]=newElement;
    ++(*pointer);
}


int main()
{
  int arr[10];
  int top=-1;
  int date = 2021;

 // INSERTING THE PRODUCTS IN THE LIST
  for(int i=0;i<10;i++)
  { 
     top++;
     arr[i]=date;
     date++;
  }
   displayList(arr,top);
   Delete(arr,6,&top);
   displayList(arr,top);
   DelExpired( arr,&top,2030);
   displayList(arr,top);
   Replace(arr,2021,2031,&top);
   displayList(arr,top);
   

  return 0;
}
   
