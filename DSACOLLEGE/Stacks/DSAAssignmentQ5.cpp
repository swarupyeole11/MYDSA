#include<bits/stdc++.h>
using namespace std;


#define MAX 100005

typedef struct elements
{
    int x1;
    int x2;
}elements;



int  main()
{
    int n;
    cout<<endl;
    cout<<" ..........Enter Number of Plants.......... :\n";
    cin>>n;
    vector<int>a(n);
    cout<<endl;
    
    cout<<" ..........Enter Pesticide Values.......... :\n";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        a[i]=-a[i];
    }
    cout<<endl;
    stack<elements>s;
    int maxi=0;

    for(int  i=0;i<n;i++)
    {
        if(s.empty())
        {
            s.push({a[i],0});
        }
        else
        {
            elements tempVar=s.top();

            if(a[i]<tempVar.x1)
            {
                int sc=1;
                maxi=max(maxi,sc);
                s.push({a[i],sc});
            }
            else
            {

                elements v=s.top();
                int pr=v.x2;
                while(!s.empty()&&v.x1<=a[i])
                {
                    s.pop();
                    if(s.empty())
                        break;
                    pr=max(pr,v.x2);
                    v=s.top();
                }

                if(s.empty())
                {
                    s.push({a[i],0});
                }

                else
                {
                    s.push({a[i],pr+1});
                    maxi=max(maxi,pr+1);
                }


            }
        }
    }
    cout<<"....OUTPUT.....\n";
    cout<<" ..........Number Of Days After Which Plant Do Not Die.......... :\n";
    cout<<maxi<<endl;
    cout<<endl;
}