#include<bits/stdc++.h>
using  namespace std;

struct node
{
    int coeff;
    int expo;
    struct node *next;
}*head1=NULL,*head2=NULL,*head3=NULL;

node* InsertLast(int coeffe, int expoe , node* head)
{
    struct node *last;
    struct node *t=new node;
    t->coeff=coeffe;
    t->expo=expoe;
    t->next=NULL;
    
    if(head==NULL)
    {
        last=head=t;
    }

    else
    {
        last->next=t;
        last=t;
    }

  return head;
}

void Display(node *t)
{
    
    while (t!=NULL)
    {
        cout<<" "<<"coff:"<<" "<<t->coeff<<" "<<"expo:"<<" "<<t->expo<<" "<<endl;
        t=t->next;
    }
    
}

int main()
{
   int n;
   cout<<"enter the number of elements: ";
   cin>>n;
   int a,b;
   
   cout<<"enter the coffiecients and exponent values:"<<endl;
   
   for (int i = 0; i < n; i++)
   {   
       cin>>a>>b;
       if(i==0)
       {
            head1 = InsertLast(a,b,head1);
       }
       else
       { InsertLast(a,b,head1);}
   }
   
 
 
   
//   for( int i=1;i<3;i++)   ///CHECK WHY NOT WORKING
//   {  
//      cout<<"enter the coffeicient : ";
//      cin>>coff;
//      cout<<endl;
//      cout<<"enter the exponent : ";
//      cin>>expo;
//      cout<<endl;
//      InsertLast(coff,expo,head1);
     
//   }

  

  Display(head1);
  

  return 0;
}
   
