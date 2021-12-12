#include<bits/stdc++.h>
using  namespace std;   

struct Node
{
 int coeff;
 int exp;
 struct Node *next;
}*poly1=NULL,*poly2=NULL,*poly3=NULL;

Node* create(Node *poly)
{
 struct Node *t,*last;
 int num,i;
 
 cout<<"Enter number of terms: ";
 cin>>num;
 cout<<"Enter each term with coeff and exp\n";
 
 for(i=0;i<num;i++)
 {
 t=new Node;
 cin>>t->coeff>>t->exp;
 t->next=NULL;
 if(poly==NULL)
 {
 poly=last=t;
 }
 else
 {
 last->next=t;
 last=t;
 }
 }

 return poly;
}

void Display(struct Node *p)
{
 while(p)
 {
 cout<<p->coeff<<'x'<<p->exp<<" ";
 p=p->next;
  if(p)
  {
      cout<<"+"<<" ";
  }
 }
 printf("\n");
}

Node* InsertLast(int coeffe, int expoe , Node* head)
{
    struct Node *last;
    struct Node *t=new Node;
    t->coeff=coeffe;
    t->exp=expoe;
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

void sum(Node *pol1 , Node*pol2)
{  
    int pc,pe;

    while (pol1 && pol2)
    {
        if(pol1->exp==pol2->exp)
        {
             pc = pol1->coeff+pol2->coeff;
             pe=  pol1->exp;
             pol1 = pol1->next;
             pol2=pol2->next;
        }

        else if (pol1->exp>pol2->exp)
        {
            pe=pol1->exp;
            pc=pol1->coeff;
            pol1=pol1->next;
        }

        else
        {
            pe=pol2->exp;
            pc=pol2->coeff;
            pol2=pol2->next;
        }

        //cout<<" pe "<<pe << " pc "<<pc<<endl;
        if(poly3==NULL)
        {
            poly3 = InsertLast(pc,pe,poly3);
        }

        else
        {
            InsertLast(pc,pe,poly3);
        }
    }
    
    if(pol2!=NULL)
    {
       while (pol2!=NULL)
       {
            pe=pol2->exp;
            pc=pol2->coeff;
            pol2=pol2->next;
            InsertLast(pc,pe,poly3);
       }
       
    }

    if(pol1!=NULL)
    {
       while (pol1!=NULL)
       {
            pe=pol1->exp;
            pc=pol1->coeff;
            pol1=pol1->next;
            InsertLast(pc,pe,poly3);
       }
       
    }
}

int main()
{
 cout<<"Input the first polynomial:"<<endl;
 poly1=create(poly1);

 cout<<endl;

 cout<<"Input the second polynomial:"<<endl;
 poly2=create(poly2);
 sum(poly1,poly2);
 
 cout<<endl;

 cout<<"The final Polynomial is : ";
 Display(poly3);
 cout<<endl;
 return 0;
}