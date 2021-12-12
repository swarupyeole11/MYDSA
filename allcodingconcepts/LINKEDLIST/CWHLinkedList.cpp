#include<bits/stdc++.h>
using  namespace std;

struct Node
{
    int data;
    struct Node *next;
};

int main(){

 //MEMORY ALLOCATED IN HEAP
  struct Node *head = new Node;    /* |_|_| -> |_|_| ->|_|_|  */
  struct Node *second = new Node;  /*  head ->  second -> third */
  struct Node *third = new Node;

 //linking first and second node
  head->data = 7;
  head->next = second;

 //linking second and third node
  
  second->data =11;
  second->next = third;

 //terminationg the third

  third->data = 7;
  third->next = NULL;

  



  

  

  return 0;
}
   
