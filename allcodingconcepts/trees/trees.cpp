#include<bits/stdc++.h>
using  namespace std;

struct node
{
    int data;
    struct node *Lchild;
    struct node *Rchild;
} *root=NULL;


struct Queue
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

int isFull()
{
    struct node *t = new node;
    return t->next=NULL?1:0;
}

int isEmpty()
{
    return front==NULL?1:0;
}

void enqueue(int x)
{
   if(isFull()==true)
   {
       cout<<"queue overflow";
   }

   else
   {   
       struct node *t = new node;

       if(isEmpty()==true)
       {
           front=rear=t;
           t->data=x;
       }

       else
       {
           t->data=x;
           t->next=NULL;
           rear->next=t;
           rear=t;
       }


   }
}                

void createTree(int arr[],int n)
{
  root = new node;
  root->data=arr[0];
  root->Lchild=NULL;  //remeber . is for acessing member through simple element of structure -> acessing element of structure through pointer
  root->Rchild=NULL;

}

                    

int main()
{  

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
       cin>>arr[i];
    }

    createTree(arr,n);
  
  return 0;
}
   
