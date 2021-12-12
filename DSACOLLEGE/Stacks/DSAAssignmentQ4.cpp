#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool areAllFed(string s){
    stack<char> sc;
    bool flag = 0;
    for(int i=0;i<s.length();i++){
        if(sc.empty()&&s[i]=='0'){
            return false;
        }
        else if(s[i]=='*'){
            sc.push('*');
        }
        else if(s[i]=='0'&&flag){
            sc.pop();
            flag = false;
        }
        else
            flag = true;
    }
    return true;
}

int main(){
    int t;
    cout<<endl;
    cout<<" ..........Enter Number of Test Cases.......... :\n";
    cin>>t;
    cout<<endl;

    while(t--){
       
        cout<<" ..........Enter The Expression.......... :\n";
        string s;
        cin>>s;
        cout<<endl;
   
        cout<<" ..........OUTPUT.......... :\n";
        cout<<(areAllFed(s)?"YES":"NO")<<endl;
        cout<<endl;
    }
    return 0;
}
