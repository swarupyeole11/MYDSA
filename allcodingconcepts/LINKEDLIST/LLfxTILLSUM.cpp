#include<bits/stdc++.h>
using  namespace std;

struct node
{
    int data;
    struct node *next;
}*first=NULL;

void create(int arr[],int n)
{
    int i;
    struct node *t,*last;
    first=new node;
    first->data=arr[0];
    first->next=NULL;
    last=first;

    for( i=1;i<n;i++)
    {
      t = new node;
      t->data=arr[i];
      t->next=NULL;
      last->next=t;
      last=t;
    }
    
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/


void display(struct node *p)
{
   while (p!=NULL)
   {
     cout<<"data value:"<<" "<<p->data<<" ";
     p = p->next;
   }
   
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/


void Rdisplay(struct node *p)
{  

   if(p!=NULL)
   {
       cout<<p->data;
       p=p->next;
       Rdisplay(p);
   }

}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

int countnode(struct node *p)
{
   int count =0;
   while(p!=0)
   {
      count++;
      p=p->next;
   }
   return count;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/


int Rcountm(struct node *p)
{
    static int count=0;
    if(p==NULL)
    {
       return 0;
    }

    count++;
    Rcountm(p->next);
    return count;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/


int Rcount(struct node *p)
{
    if(p!=NULL)
    {
        return 1+Rcount(p->next);
    }

    return 0;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/



int sum(struct node *p)
{
   int sum=0;
   while(p!=0)
   {
       sum+=p->data;
       p=p->next;
   }
   return sum;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/



int Rsum(struct node *p)
{
    if(p!=NULL)
    {
        return p->data+Rsum(p->next);
    }

    return 0;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

int Rmax(struct node *p)
{
    static int Max = INT32_MIN;

    if(p!=NULL)
    {      
          // cout<<p->data<<" ";
           //cout<<"The Max values:"<<Max<<" ";

        if(p->data>Max)
        {
            
                Max = p->data;
                // cout<<"The Max values:"<<Max<<endl;
        }
         Rmax(p->next);
    }
   
    return Max;

}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/


int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
       cin>>arr[i];
    }

    create(arr,n);
    // Rdisplay(first);
    // cout<<endl;
    //cout<<Rcount(first)<<endl;
    // cout<<Rsum(first)<<endl;
    //cout<<Rmax(first);

  return 0;
}
/*--------------------------------------------------------------------------------------------------------------------------------------------*/
   
