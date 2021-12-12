
#include<bits/stdc++.h>
using namespace std;
 
stack<char> st;

string str;

void insert_bottom(char x)
{
 
    if(st.size() == 0)
    st.push(x);
 
    else
    {
             
        char a = st.top();
        st.pop();
        insert_bottom(x);
        st.push(a);
    }
}
 
void reverse_stack()
{
    if(st.size()>0)
    {
       
        char x = st.top();
        st.pop();
        reverse_stack();
        insert_bottom(x);
    }
}
 
int main()
{
     

    st.push('1');
    st.push('2');
    st.push('3');
    st.push('4');
    st.push('5');
    st.push('6');
    
    cout<<endl;
    cout<<"......Original Stack......"<<endl;
     
    cout<<"1"<<" "<<"2"<<" "<<"3"<<" "<<"4"<<" "<<"5"<<" "<<"6"<<endl;
    cout<<endl;

    reverse_stack();
    
    cout<<"......Reversed Stack........" <<endl;
    
    while(!st.empty())
    {
        char p=st.top();
        st.pop();
        str+=p;
    }
     
    cout<<str[5]<<" "<<str[4]<<" "<<str[3]<<" "<<str[2]<<" "<<str[1]<<" "<<str[0]<<endl<<endl;

    return 0;
}
 
