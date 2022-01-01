#include <iostream>
#include <queue>
#include <list>

using namespace std;

queue<int> QueueReverse(queue<int> q) 
{ 
    int s = q.size(); 
    queue<int> ans; 

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < q.size() - 1; j++) { 
            int x = q.front(); 
            q.pop(); 
            q.push(x); 
        } 

        ans.push(q.front()); 
        q.pop(); 
    } 
    return ans; 
}

void queueDisplayFunx(queue<int> a) {
    while (!a.empty()) {
        cout << a.front() << " ";
        a.pop();
    }
}

int main(void) {
    auto it = {100,200,300,400,500,600,700,800,900,1000};
    queue<int> queue1(it);
    queue<int> queue2(queue1); 

    cout << "Values Present In intial Queue: " << endl;
    queueDisplayFunx(queue1);
    cout<<endl;
    cout<<endl;
    cout << "Values Present In Another Queue:" << endl;
    queueDisplayFunx(queue2);
    cout<<endl;
    cout<<endl;
    queue<int> queue3;
    queue3 = QueueReverse(queue1);

    cout << "Values Present In The Queue Where Values Were Pushed In Reverse : " << endl;
    queueDisplayFunx(queue3);
    cout<<endl;
    cout<<endl;
    

    if (queue1 != queue2) 
        cout << "The contents of second Queue and First Queue Are NOT Identical" << endl;
    else
        cout << "The contents of second Queue and First Queue identical." << endl;

    if (queue2 != queue3)   
         cout << "The contents of second Queue and Third Queue Are NOT Identical" << endl;
    else
        cout << "The contents of second Queue and Third Queue identical." << endl; 

    if (queue1 != queue3) 
      cout << "The contents of first Queue and Third Queue Are NOT Identical" << endl;
    else
        cout << "The contents of first Queue and Third Queue identical." << endl;

    cout << endl;

    cout << "Size of queue1 = " << queue1.size() << endl; 
    cout << "Size of queue2 = " << queue2.size() << endl;
    cout << "Size of queue3 = " << queue3.size() << endl;

    return 0;
}