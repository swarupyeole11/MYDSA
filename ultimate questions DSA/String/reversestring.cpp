// #include<bits/stdc++.h>
// using  namespace std;
// class Solution {
// public:
//     void reverseString(vector<char>& s) {
        
//         int n=s.size();
        
//         for(int i=0;i<n/2;i++)
//         {
//             swap(s[i],s[n-1-i]);
            
//         }

//     }
// };

// int main(){
   
//    vector<char> s1;

//    int size;
//    char element;

//    cout<<"ENTER THESIZE OF STRING:";

//    cin>>size;

//    for(int i=0;i<size;i++)
//    {
//       cin>>element;
//       //cout<<element;
//       s1.push_back(element);
      
//    }

   
//   Solution pappu;

//   pappu.reverseString(s1);
  
 
//     for(int i=0;i<size;i++)
//    {
//       cout<<s1[i];
//    }
   
  

//   return 0;
// }
   


/*ONE MORE WAY */

#include<bits/stdc++.h>
using  namespace std;

void rev(string &s)
{
       int n=s.size();
        
        for(int i=0;i<n/2;i++)
        {
            swap(s[i],s[n-1-i]);
            
        }
}

int main(){
   
   string s;
   cout<<"ENTER THE String:";
   getline(cin,s);
   rev(s);
   cout<<s;

  return 0;
}
   
