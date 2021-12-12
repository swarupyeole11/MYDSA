#include<bits/stdc++.h>
using  namespace std;

struct node
{
    int data;
    struct node *next;
}*first=NULL,*last=NULL;  // the first has been on purpose defined as global helps in acessing the linked list
                          // here last has been declare global as nedded in Last insert
void create(int arr[],int n)
{
    int i;
    struct node * t;
    first = new node;
    first->data=arr[0];
    first->next=NULL;
    last=first;

    for( i=1;i<n;i++)
    {
       t =new node;
       t->data=arr[i];
       t->next=NULL;
       last->next=t;
       last=t;
    }
    

}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/


struct node * Lsearch(struct node *p, int key )
{   

    struct node *q=NULL;   //the extra code is for improving linear search

   while (p!=NULL)
   {   

       if(p->data==key)
       {   
           q->next=p->next;
           p->next=first;
           first=p;
           return p;
       }
      
      q=p;
      p=p->next;
   
      
   }

   return NULL;
   
}


/*--------------------------------------------------------------------------------------------------------------------------------------------*/


void display(struct node *p)
{
   while (p!=NULL)
   {
       cout<<p->data<<" ";
       p=p->next;
   }
   
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

int count(struct node *p)
{   
    int l=0;
    while (p!=NULL)
    {
        l++;
        p=p->next;
    }
    return l;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

void insert(int x,struct node *p,int index)
{
    struct node *t = new node;
    t->data=x;

    if(index<0||index>count(p))
    {
        return;
    }

    if(index==0)
    {
        t->next=first;
        first=t;    

    }

    else
    {
        for(int i=0;i<index-1;i++)
        {
           p=p->next;
        }

        t->next=p->next;
        p->next=t;
        
    }
}  

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

 void LastInsert(int x)
 {
     struct node *t = new node;
     t->data=x;
     t->next=NULL;

     if(first==NULL)
     {   

         first=last=t;
     }

     else
     {
      last->next=t;
      last=t;
    
     }
 }

 /*--------------------------------------------------------------------------------------------------------------------------------------------*/
  
   void sortedInsert(struct node *p , int x)
   {
       struct node *q=NULL,*t;
       t = new node;
       t->data = x;

       if(first==NULL)
       {
          first=t;
          t->next=NULL;
       }

       else
       {

            while (p!=NULL && x>p->data )
          {  
            q=p;
            p=p->next;
          }

           if(p==first)
         {
            t->next=first;
            first=t;
         }
       
          else
         {
          q->next=t;
          t->next=p;
         }

       }
   }
 
 /*--------------------------------------------------------------------------------------------------------------------------------------------*/


 void reverse(struct node *p)  ///////*THree POinter APProach*/////////////
 {  
     struct node *q=NULL,*r=NULL;
     
     while (p!=NULL)
     {  
        
        r=q;
        q=p;
        p=p->next;
        q->next=r;
        
     }

     first = q;
     
 }
 /*--------------------------------------------------------------------------------------------------------------------------------------------*/

 struct node *q1=NULL,*r1=NULL;  // you can avoid this by declaring these pointer as static inside the function

 void Rreverse(struct node *p)
 {   
     
     if(p!=NULL)
     {
       r1=q1;
       q1=p;
       p=p->next;
       q1->next=r1;
       Rreverse(p);
     }

     first=q1;
 }

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

 int deleteNode(struct node *p, int index) // you require 2 ponters here one will be used for removing the unwanted node
 {
    struct node *q=p;

    int x =-1;
   
    if(index<0 && index>count(p))
    {
        return -1; 
    }
   
    if(index==1)
    {
        q=first;
        first=first->next;

        x=p->data;
        delete q;
        return x;
    }

    else
    {
        for(int i=0; i<index-1;i++)
        {
            q=p;
            p=p->next;
        }

        q->next=p->next;
        x=p->data;
        delete p;
        return x;
    }


 }

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

 void removeDuplicate( struct node *p)  // here q is ahead by 1 node of p
   // we delete the second pointer to avoid the changing of address in the (first (pointer))
 {
     struct node *q= p->next;
     
     while (p!=NULL && q!=NULL)
     {
        if(p->data!=q->data)
        {   
            
            p=q;
            q=q->next;
        }

        else
        {
           
            p->next=q->next;
            delete  q;
            q=p->next;
        }
     
     }
     

 }

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

 int isSorted( struct node *p) //ITIALIZE A VALUE WHICH IS 1 NODE BEHIND THE CURRENT p->data and then compare
 {
      int x = INT32_MIN;

      while (p!=NULL)
      {
          if(x>p->data)
          {
              return -1;
              
          }
         x=p->data; 
         p=p->next;

      }
      
      return 1;
 }

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

 int isLoop(struct node *p)  //SOLVED BY USING FAST AND SLOW POINTER APPROACH 
 {   

     struct node *q;
     q=p;
     
     do
     {
         p=p->next;
         q=q->next;
         q=q?q->next:q;
     }
     while (p!=NULL && q!=NULL && p!=q);
    

     if(p==q)
     {
         return 1;
     }
     
     else 
     {
         return -1;
     }
 }

 /*--------------------------------------------------------------------------------------------------------------------------------------------*/




int main()
{
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
      cin>>arr[i];
   }

   create(arr,n);

  /*CODE FOR LINEAR SEARCH*/

//    int key;
//    cout<<"enter the number you want to search: ";
//    cin>>key;
//    struct node *temp = Lsearch(first,key);
//    cout<<temp->data<<endl;
//    display(first);

/*--------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------*/

 
 /*CODE FOR INSERTING ELEMENTS  NOTE:YOU CAN CREATEWHOLE LL USING INSERT FUNCTION DONT'T USE CREATE FUNCTION IN THAT CASE*/
//    insert(4,first,0);
//    insert(5,first,1);
//    insert(6,first,2);
//    display(first);

/*--------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------*/


  /*LAST INSERT ACCESSS*/


//   LastInsert(4);
//   LastInsert(6);
//   display(first);

/*--------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------*/


  /* REVERSEING Linked list  NORMAL AND WITH RECURSION*/

//    Rreverse(first);
//    display(first);

/*--------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------*/


 /* checking is loop Linked list*/

//    struct node *t1,*t2;
//    t1 = first->next;
//    t2 = first->next->next->next->next;
//    t2->next= t1;
//    cout<<isLoop(first);

/*--------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------*/
  
  /* deleting the node*/
//    cout<<"The value in deleted node: "<<deleteNode(first,3)<<endl;
//    display(first);
 
/*--------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------*/
 
 /* removing duplicates*/

    // removeDuplicate(first);
    // display(first);

 /*--------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------*/

  /* inserting in sorted linked list*/
   
     sortedInsert(first,6);
     sortedInsert(first,1);
     display(first);

  return 0;
}
   
