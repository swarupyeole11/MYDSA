#include<bits/stdc++.h>
using  namespace std;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void Delete(int List[],int pos,int *currentIndex)
{  
    int val=*currentIndex;
    int index = pos-1;
   if((*currentIndex)==-1)
   {
       cout<<"Cannont delete since the list is empty ";
   }

   else if(index<0||index>(*currentIndex))
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

    --(*currentIndex);

          cout<<"Product DELETED ! Please Enter New Product To Be Inserted & If no Product To be Inserted Press -1: "<<endl;
          int x;
          cin>>x;
          if(x!=-1)
          {
          *currentIndex=*currentIndex+1;
          List[*currentIndex]=x;
          }

   }
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void displayList(int List[],int Top)
{
    for(int i=0;i<=Top;i++)
    {
       cout<<List[i]<<" ";
    }
    cout<<endl;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int  SearchDeleteExpiredProduct(int List[],int *Top,int key)
{  
   int val =-1;
   for(int i=0;i<=(*Top);i++)
   {
      if(List[i]==key)
      {   
          val = i;
          cout<<"The Expired Product Was Found At Pos: "<<i+1<<endl;
          cout<<endl;
          Delete(List,i+1,Top);
          return val;
      }
   }
    
    cout<<"THE EXPIRED PRODUCT IS NOT PRESENT IN THE lIST!";
    
    return val;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void OnlyDelete(int List[],int pos,int *currentIndex)
{  
    int val=*currentIndex;
    int index = pos-1;
   if((*currentIndex)==-1)
   {
       cout<<"Cannot delete since the list is empty ";
   }

   else if(index<0||index>(*currentIndex))
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

    --(*currentIndex);

   }
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int  OnlySearchDeleteExpiredProduct(int List[],int *Top,int key)
{   
    int val =-1;
   for(int i=0;i<=(*Top);i++)
   {
      if(List[i]==key)
      {   
          val=i;
          OnlyDelete(List,i+1,Top);
          return val;
      }
   }
    return val;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void ReplacetheExpiredProduct(int List[],int ExpiredProduct,int newProduct,int *Top)
{
    int Index = OnlySearchDeleteExpiredProduct( List,Top,ExpiredProduct);

     if(Index<0||Index>9)
   {
     cout<<"Index Not Valid!"<<endl;
     return;
   }

   int j;

   for(j=(*Top);j>=Index;j--)
   {
       List[j+1]=List[j];
   }
    
    List[j+1]=newProduct;
    ++(*Top);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int main()
{
  int ProductList[10];
  int front=-1;
  int date = 2021;

 // INSERTING THE PRODUCTS IN THE LIST
  for(int i=0;i<10;i++)
  { 
     front++;
     ProductList[i]=date;
     date++;
  }

   cout<<endl;
   cout<<"<---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->"<<endl;
   cout<<endl;
   cout<<"The intial Values in the List: "<<endl;
   displayList(ProductList,front);
   cout<<endl;
   cout<<"<---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->"<<endl;
   
   cout<<endl;
   Delete(ProductList,6,&front);
   cout<<endl;
   cout<<"List Value After Deleting Exipired Product From Given Position"<<endl;
   cout<<"NOTE:IF NEW PRODUCT IS ENTERED WHILE DELETING THEN THE LIST WILL ALSO DISPLAY THAT PRODUCT INFORMATION:"<<endl;
   cout<<endl;
   displayList(ProductList,front);
   cout<<endl;

   cout<<"<---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->"<<endl;
    
     cout<<endl;
    SearchDeleteExpiredProduct( ProductList,&front,2030);
     cout<<endl;
     cout<<"The Values In The List After Deleting The Expired Product"<<endl;
     cout<<"NOTE:IF NEW PRODUCT IS ENTERED WHILE DELETING THEN THE LIST WILL ALSO DISPLAY THAT PRODUCT INFORMATION :"<<endl;
     cout<<endl;
     displayList(ProductList,front);
     cout<<endl;

   cout<<"<---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->"<<endl;

   cout<<endl;
   cout<<"The Values In The List After Replacing Products:"<<endl;
   cout<<endl;
   ReplacetheExpiredProduct(ProductList,2021,2031,&front);
   displayList(ProductList,front);
   cout<<endl;

  return 0;
}
   
