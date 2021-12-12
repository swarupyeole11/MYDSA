#include<bits/stdc++.h>
using  namespace std;


struct Node
{
 struct Node *prev;
 int data;
 struct Node *next;
}*first=NULL;

void create(int arr[],int n)
{
 struct Node *t,*last;
 int i;
 
 first=new Node;
 first->data=arr[0];
 first->prev=first->next=NULL;
 last=first;
 
 for(i=1;i<n;i++)
 {
 t=new Node;
 t->data=arr[i];
 t->next=last->next;
 t->prev=last;
 last->next=t;
 last=t;
 }
}


void Display(struct Node *p)
{
 while(p)
 {
 cout<<p->data<<" ";
 p=p->next;
 }
 printf("\n");
}


int count(struct Node *p)
{
 int len=0;
 
 while(p)
 {
 len++;
 p=p->next;
 }
 return len;
}


void Insert(struct Node *p,int index,int x)
{
 struct Node *t;
 int i;
 
 if(index < 0 || index > count(p))
 return;

 if(index==0)
 {
 t=new Node;
 t->data=x;
 t->prev=NULL;
 t->next=first;
 first->prev=t;
 first=t;
 }

 else
 {
 for(i=0;i<index-1;i++)
 p=p->next;
 t=new Node;
 t->data=x;
 
 t->prev=p;
 t->next=p->next;
 if(p->next)p->next->prev=t;
 p->next=t;
 
 }
}


int Delete(struct Node *p,int index)
{
 //struct Node *q;
 int x=-1,i;
 
 if(index < 1 || index > count(p))
 return -1;
 
 if(index==1)
 {
    first=first->next;
    if(first)
    {
     first->prev=NULL;
    }    
 
    x=p->data;
    delete p;
 }

 else
 {
 for(i=0;i<index-1;i++)
 {
    p=p->next;
 }
 
 p->prev->next=p->next;

 if(p->next)
 {
   p->next->prev=p->prev;
 }

   x=p->data;

 delete p;
 }

 return x;
 
}

int searchIndex(Node *p, int x)
{  
    int count = 0;
   while (p!=NULL)
   {  
       count++;
       if(p->data==x)
       {
           return count;
       }
       p=p->next;
   }
   
   return count;
}

int main()
{

///////////////////////////////////////////_________I__________/////////////////////////////////////////
 
 int arr[9]={10,20,30,40,50,60,70,80,90};
 cout<<endl<<"                                    The Orginal Doubly Linked List:                     "<<endl;
 cout<<endl;
 create(arr,9);
 Display(first);
 

 ///////////////////////////////////////////_________II__________/////////////////////////////////////////
 
 int index = searchIndex(first,30);
 Delete(first,index);
 Insert(first,6,30); //The value is inseted after index 6 that is at 7th position

 cout<<endl;
 cout<<endl<<"                            DLL After Deleting 30 & Adding 30 At 7th position:                                "<<endl;
 cout<<endl;
 Display(first);


///////////////////////////////////////////_________III__________/////////////////////////////////////////
 
 Insert(first,1,80);
 Delete(first,count(first));

 cout<<endl;
 cout<<endl<<"                          DLL After Adding 80 At 2nd Position & Deleting Last Element:                                "<<endl;
 cout<<endl;
 Display(first);
 cout<<endl;

 return 0;
}