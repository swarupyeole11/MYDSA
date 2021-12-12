#include<bits/stdc++.h>
using  namespace std;



    struct node 
    {
        int data;
        struct node *next;
    }*front=NULL,*rear=NULL;


    void enqueue(int x)
    {
       int i;
       struct node *t =new node ;
       
       if(t==NULL)
       {
           cout<<"QueueisFull";
       }
       else
       {
           if(front==NULL)  //checking special conditon when Linked List is empty this is not required stack because there we use only one pointer thus we do not need to position the rear pointer we add from the right dise in stack and remove from that side only |_|<-|_| -<|_|
           {
               front=rear=new node;
               front->data=x;
               front->next=NULL;
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

    int dequeue()
    {

    }

    void display(struct node *p)
    {
        while (p!=NULL)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        
    }
    
    int deenqueue()
    {   
        int x=-1;
        if(front==NULL)
        {
            cout<<"Queue is Empty";
            return x;
        }

        else
        {
            struct node *p = front;
            front=front->next;
            x=p->data;
            delete p;
            return x;
        }
    }


int main()
{  
    enqueue(4);
    enqueue(5);
    enqueue(6);
    display(front);
    deenqueue();
    deenqueue();
    cout<<endl;
    display(front);

  return 0;
}
   
