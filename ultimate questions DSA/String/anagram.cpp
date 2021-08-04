#include<bits/stdc++.h>
using  namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
         
//         bool check;
        
//          if(s.size()!=t.size())
//          {
//              return false;
//          }
        
//         else
//         {
//          check=true;
//         sort(s.begin(),s.end());
//         sort(t.begin(),t.end());//since in elese condition hterefore s.size()=t.size()
            
//             for(int i=0;i<s.size();i++)
//             {
//                 if(s[i]!=t[i])
//                 {
//                     check=false;
//                 }
//             }
//         }
//         return check;
        
        
 ///UPPER ONE WAS A NLOGN SOLUTION//////////////////////////////////////////////////////
        
 //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//       
   
      bool check=true;  
       
      int H[256]={0};
        
        
      if(s.size()!=t.size())
      {
          return false;
      }
        
        
      else
      {
          for(int i=0;i<s.size();i++)
          {
              H[s[i]]+=1;
          }
          
          for(int i=0;i<t.size();i++)
          {
              H[t[i]]-=1;
          }
          
          for(int i=0;i<256;i++)
          {
              if(H[i]!=0)
              {
                  check=false;
              }
          }
      }
        
      return check;  
    }
};
int main(){
  
  string s,t;
  
  cout<<"Enter first string:";
  getline(cin,s);

  cout<<"Enter second string:";
  getline(cin,t);

  Solution pappu;

  bool checker = pappu.isAnagram(s,t);

  if(checker==0)
  {
      cout<<"false";
  }
  else
  {
      cout<<"true";
  }


  return 0;
}
   
