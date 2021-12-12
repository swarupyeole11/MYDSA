#include<bits/stdc++.h>
using  namespace std;

void stPush(int x ,queue<int> &gq)
{  
   gq.push(x);
}

void stPop(queue<int> &gq)  // pass by reference 
{   
    if(gq.empty()==true)
    {
    cout<<"!! ....Cannot POP values The Stack Is Empty....!! \n";
    return ;
    }

    int n=gq.size(); // this is important because the valu of gq.size() changes
    for(int i=0;i<n-1;i++)
    {  
       int x = gq.front();
       gq.pop();
       gq.push(x);
    }

     gq.pop();
    
}


void stDisplay(queue<int> q) // pass by value
{   
    if(q.empty()==true)
    {
       cout<<"---------EMPTY STACK ----------\n\n\n";
       return;
    }

    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    
}

int main()
{

    queue<int> gquiz;
    
    cout<<"... The Intial  Stack.....\n\n";
    stDisplay(gquiz);

    stPush(1,gquiz);
    stPush(2,gquiz);
    stPush(3,gquiz);
    stPush(4,gquiz);
    stPush(5,gquiz);
    stPush(6,gquiz);

    cout<<"...After Pushing 6 values...\n\n" ;
    stDisplay(gquiz);
    cout<<endl;
    cout<<endl;
    cout<<endl;

    stPop(gquiz);
    stPop(gquiz);
    stPop(gquiz);
    stPop(gquiz);
    stPop(gquiz);

    cout<<"....After Popping the 5 values....\n\n";
    stDisplay(gquiz);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    
    cout<<"...When Tried To Pop From Empty Stack!....\n\n";
    stPop(gquiz);
    stPop(gquiz);
    cout<<endl;

  return 0;
}
   
