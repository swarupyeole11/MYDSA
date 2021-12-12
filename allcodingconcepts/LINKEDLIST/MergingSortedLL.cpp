#include<bits/stdc++.h>
using  namespace std;

struct node
{
    int data;
    struct node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create1(int arr[],int n)
{
    int i;
    struct node *t,*last;
    first=new node;
    first->data=arr[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
       t=new node;
       t->data=arr[i];
       t->next=NULL;
       last->next=t;
       last=t;
    }
}


void create2(int arr[],int n)
{
    int i;
    struct node *t,*last;
    second=new node;
    second->data=arr[0];
    second->next=NULL;
    last=second;

    for(i=1;i<n;i++)
    {
       t=new node;
       t->data=arr[i];
       t->next=NULL;
       last->next=t;
       last=t;
    }
}
   
  // |_| |_| |_|
  // |_| |_| |_|

void sortedMerge(struct node *p , struct node *q)
{
   
}

void display( struct node *p)
{
   while (p!=NULL)
   {
      cout<<p->data<<" ";
      p=p->next;
   }
   
}


int main(){
   
   int n1;
   cin>>n1;
   int arr1[n1];
   for(int i=0;i<n1;i++){
      cin>>arr1[i];
   }

   create1(arr1,n1);

  
  int n2;
  cin>>n2;
  int arr2[n2];
  for(int i=0;i<n2;i++){
     cin>>arr2[i];
  }

   create2(arr2,n2);


  sortedMerge(first,second);

  display(third);


  return 0;
}
   
