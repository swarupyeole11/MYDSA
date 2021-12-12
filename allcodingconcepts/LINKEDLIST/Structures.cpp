// #include<bits/stdc++.h>
// using  namespace std;

// struct point 
// {
//     int x;
//     int y;
// }*first,var1,var2;



// int main(){



//    var1.x=10;
//    var1.y=20;
//    var2.x=68;
//    var2.y=98;
//    first = &var2;

//    cout<<first->x;
//    cout<<first->y;

//   return 0;
// }
   

#include <iostream>
using namespace std;
 
class Node{
public:
    int data;
    Node* next;
};
 
int main() {
 
    int A[] = {3, 5, 7, 10, 15};
 
    Node* head = new Node;
 
    Node* temp;
    Node* last;
 
    head->data = A[0];
    head->next = nullptr;
    last = head;
 
    // Create a Linked List
    for (int i=1; i<sizeof(A)/sizeof(A[0]); i++){
 
        // Create a temporary Node
        temp = new Node;
 
        // Populate temporary Node
        temp->data = A[i];
        temp->next = nullptr;
 
        // last's next is pointing to temp
        last->next = temp;
        last = temp;
    }
 
    // Display Linked List
    Node* p = head;
 
    while (p != nullptr){
        cout << p->data << " -> " << flush;
        p = p->next;
    }
 
    return 0;
}