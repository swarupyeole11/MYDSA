#include <bits/stdc++.h>
using namespace std;

void displayStack(stack<int> St, int Tn, int Sn)
{
    for (int i = 0; i < Tn + Sn; i++)
    {
        cout << St.top() << " ";
        St.pop();
    }
}
int main()
{
    deque<int> D;
    stack<int> S;
    stack<int> T;

    int Sn;
    cout << "\nenter the number of elements in stack S : ";
    cin >> Sn;

    for (int i = 0; i < Sn; i++)
    {
        int val;
        cin >> val;
        S.push(val);
    }

    int Tn;
    cout << "\nenter the number of elements in stack T : ";
    cin >> Tn;

    for (int i = 0; i < Tn; i++)
    {
        int val;
        cin >> val;
        T.push(val);
    }

    for (int i = 0; i < Tn; i++)
    {
        D.push_back(T.top());
        T.pop();
    }

    for (int i = 0; i < Sn; i++)
    {
        T.push(S.top());
        S.pop();
    }

    // FOR Pushing values
    for (int i = 0; i < Tn; i++)
    {
        S.push(D.front());
        D.pop_front();
    }

    for (int i = 0; i < Sn; i++)
    {
        D.push_back(T.top());
        T.pop();
    }

    for (int i = 0; i < Sn; i++)
    {
        S.push(D.back());
        D.pop_back();
    }
    

    // FOr Displaying the New Stack
    
    cout<<"\nFinal Values In Stack S : \n";
    displayStack(S,Tn,Sn);
    cout<<endl;

    //  D.push_back(4);
    //  D.push_back(5);
    //  D.push_back(6);

    // cout<<" kwldx";
    // cout << D.back();
    // D.pop_back();
    // cout << D.back();
    // D.pop_back();
    // // cout << D.front();
    // // D.pop_front();
    // // cout << D.front();
    // // D.pop_front();

    return 0;
}