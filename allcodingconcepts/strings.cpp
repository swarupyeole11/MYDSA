#include<bits/stdc++.h>
using  namespace std;

void ToggleString(string &s1)//YOU CAN PASS BY REFERENCE ,BY VALUE .BUT NOT BY address *arr wala method
{

    // sort(s.begin(),s.end()); //JUST TO SHOW THAT STRING FUNCTIONS WORK HERE
    // cout<<s<<endl;
for(int i=0;s1[i]!='\0';i++)
  {
      if(s1[i]>='a'&& s1[i]<='z')
      {
          s1[i]=s1[i]-32;
      }

      else if(s1[i]>=65 && s1[i]<=90)
      {
          s1[i]+=32;
      }
  }

}

 string ToggleByReturning(string s)//call by value YOU DO NOT CHANGE THE ACTUAL STRING HERE BUT JUST GIVE THE REQUIRED OUTPUT
 {
   for(int i=0;s[i]!='\0';i++)
  {
      if(s[i]>='a'&& s[i]<='z')
      {
          s[i]=s[i]-32;
      }

      else if(s[i]>=65 && s[i]<=90)
      {
          s[i]+=32;
      }
  }
    return s;
 }

int main(){
   
   string s;
   cout<<"enter the string:";
   getline(cin,s);
   
   ToggleString(s);

   string arr=ToggleByReturning(s);
 
   //cout<<arr;



  return 0;
}
   
