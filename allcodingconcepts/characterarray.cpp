#include<bits/stdc++.h>
using  namespace std;

void print(char s[])
{   
    cout<<strlen(s);
    int i=0;
    while(s[i]!='\0')
    {
        cout<<s[i];
        i++;
    }
}

int main(){
  
  int n;
  cin>>n;
  char arr[n+1];

  cin.ignore();

  cin.getline(arr,n+1);
  
  cout<<"value before passing:"<<arr;
  
  print(arr);

  
  

  return 0;
}
   
