 #include<bits/stdc++.h>
using  namespace std;

 
int isListEmpty(int top)
{  
 
   if(top==-1)
   {
       cout<<"the list is empty"<<endl;;
       return 1;
   }
    return 0;
} 

int  isListFull(int top,int n)
{
    if(top==n-1)
    {
        cout<<"the list is Full"<<endl;
        return 1;
    }

    return 0;
}

void insertAtEnd(int List[],int key,int *IndexPointer,int n)
{   
    int val = *IndexPointer;
   if(isListFull(val,n)==true)
   {
      cout<<"Cannot Insert Element : "<<key<<endl;
   }

   else
   {   
        int i = ++(*IndexPointer);
        List[i] = key;
   }

}

void InsertAtFront(int List[],int key,int *IndexPointer,int n)
{
    int val = *IndexPointer;
   if(isListFull(val,n)==true)
   {
      cout<<"Cannot Insert Element : "<<key<<endl;
      return;
   }

    int j;
   for(j=val;j>=0;j--)
   {
       List[j+1]=List[j];
   }
    
    List[j+1]=key;
    ++(*IndexPointer);

}


void InsertAtIndex(int List[],int key,int *IndexPointer,int n,int Index)
{
    int val = *IndexPointer;
   if(isListFull(val,n)==true)
   {
      cout<<"Cannot Insert Element : "<<key<<endl;
      return;
   }

   else if(Index<0||Index>n-1)
   {
     cout<<"Index Not Valid!"<<endl;
     return;
   }

   int j;

   for(j=val;j>=Index;j--)
   {
       List[j+1]=List[j];
   }
    
    List[j+1]=key;
    ++(*IndexPointer);

}

void DeleteAtEnd(int *IndexPointer)
{   
    int val = *IndexPointer;
    if(isListEmpty(val)==true)
    {
       cout<<"Cannot Delete The List is empty";
       return;
    }
    --(*IndexPointer);
}

void DeleteAtFront(int List[],int *IndexPointer)
{
    int val = *IndexPointer;
    if(isListEmpty(val)==true)
    {
       cout<<"Cannot Delete!"<<endl;
       return;
    }

     int i;
    for( i=0;i<val;i++)
    {
       List[i]=List[i+1];
    }

    --(*IndexPointer);
    
}

void DeleteAtIndex(int List[],int *IndexPointer,int index)
{
    int val = *IndexPointer;
    if(isListEmpty(val)==true)
    {
       cout<<"Cannot Delete! "<<endl;
       return;
    }

    else if(index<0||index>val)
    {
        cout<<"Incorrect Index"<<endl;
    }
    
    int i;
    for(i=index;i<val;i++)
    {
       List[i]=List[i+1];
    }

    --(*IndexPointer);
    
}

void displayList(int List[],int Top)
{
    for(int i=0;i<=Top;i++)
    {
       cout<<"List Value at index "<< i <<" = "<<List[i]<<" ";
    }
    cout<<endl;
}

int  SearchElement(int List[],int Top,int key)
{  
   int val =-1;
   for(int i=0;i<=Top;i++)
   {
      if(List[i]==key)
      {   
          val = i;
      }
   }
    
    return val;
}


int main(){
   
  cout<<"enter the size of the array:"; 
  int n;
  cin>>n;
  int List[n];
  int Top=-1;

  //isListEmpty(Top);
  insertAtEnd(List,1,&Top,n);
  displayList(List,Top);
  insertAtEnd(List,2,&Top,n);
  displayList(List,Top);
  insertAtEnd(List,3,&Top,n);
  insertAtEnd(List,4,&Top,n);
  
  cout<<SearchElement(List,Top,3)<<endl;

  DeleteAtIndex(List,&Top,1);
  displayList(List,Top);
  DeleteAtIndex(List,&Top,1);
  displayList(List,Top);
  DeleteAtIndex(List,&Top,1);
  displayList(List,Top);
  DeleteAtIndex(List,&Top,0);
  DeleteAtIndex(List,&Top,0);
  displayList(List,Top);
  

  return 0;
}
   
