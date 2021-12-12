// { Driver Code Starts
// C++ program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}


//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
      struct Node *p = head;
      int nc=0; // nc=nodeCount
      
      //for counting the number of nodes
      while(p!=NULL)
      {
          nc++;
          p=p->next;
      }
      
      // for checking if index exceds the nuber of nodes or the index is invalid entry
      if(nc<n || n<=0)
      {
          return -1;
      }
      
      //for finding Nth node from the end
      struct Node *q= head;
      
      for(int i=1;i<nc-n+1;i++)
      {
          q=q->next;
      }
      
      return q->data;
}
