#include<bits/stdc++.h>
using  namespace std;

struct node
{
    int data;
    struct node *next;
}*head=NULL;

/*-----------------------------------CIRCULAR LL CREATION ------------------------------------------------------------------------------------*/
/*------------------------creating ccircular LL is same as the singly LL only at end we do last->next=head-------------------------------------------*/

void create(int arr[],int n)
{
    int i;
    struct node *t,*last;
    head = new node;
    head->data=arr[0];
    head->next=NULL;
    last=head;

    for(i=1;i<n;i++)
    {
        t = new node;
        t->data = arr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }

    last->next=head;
}

/* -------------------------------------Displaying the circular linked list-------------------------------*/

void display(struct node *p)
{
    do
    {
        cout<<p->data;
        p=p->next;

    } while (p!=head);
    
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------INSERTING ELEMENTS IN LL---------------------------------------------------------------------------------------------*/
  
  void insert(struct node *p , int index)
  {

  }

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int main()
{
  
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
     cin>>arr[i];
  }

  create(arr,n);
  display(head);
  insert();

  return 0;
}
   
