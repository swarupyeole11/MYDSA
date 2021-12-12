#include<bits/stdc++.h>
using namespace std;

int main() {
     
    int t,i;
    string str;
    stack<char> st;
    cout<<endl;
    cout<<" ..........Enter Number of Test Cases.......... :\n";
    cin>>t;
    cout<<endl;

    while(t--){
        
    
        cout<<" ..........Enter The Expression.......... :\n";
        cin>>str;
        for(i=0;i<str.size();i++){
            if(str[i]=='(')
                st.push(str[i]);
            else if(str[i]=='{')
                st.push(str[i]);
            else if(str[i]=='['){
                st.push(str[i]);
            }
            else if(str[i]==')'){
                if(!st.empty()){
                if(st.top()=='(')
                    st.pop();
                else 
                    break;
                }
                else
                    break;
            }
            else if(str[i]=='}'){
                if(!st.empty()){
                    if(st.top()=='{')
                    st.pop();
                else 
                    break;
                }
                else
                    break;
            }
            else if(str[i]==']'){
                if(!st.empty()){
                if(st.top()=='[')
                    st.pop();
                else 
                    break;
                }
                else
                    break;
            }
        }
        
        if(st.empty()&&i==str.size())
        {  
            cout<<"\nOutput: ";
            cout<<"YES"<<endl<<endl;
        }
        else
        {
            cout<<"\nOutput: ";
            cout<<"NO"<<endl<<endl;
        }

        while(!st.empty()){
            
            st.pop();
        }
    }

    cout<<endl;
    return 0;
}
