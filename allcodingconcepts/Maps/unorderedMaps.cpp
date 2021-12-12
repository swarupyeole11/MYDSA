#include<bits/stdc++.h>
using  namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////
   
   //A) In UNORDERED_Maps The values are NOT stored in sorted order of keys they are stored Randomly AND EACH KEY STORES UNIQUE ELEMENT
   //B)INSERTION OF UNORDERED_MAP TAKES O(1)
   //C)Even if you do not insert value to a map it gives a default value if a key is declared e.g m[6] would give 0 value for map<int,int> m;
   //D) for acessing each element the time complexity in a map is O(1) THUS for printMap function it takes T.C O(N) since for loop is used
   //E) Find operation also take the time complexity of O(1)
   //F)The IMPLEMNETATION OF MAPS TAKES PLACE THROUGH HASH TABLES
   //G) WHEN YOU USE & YOU PASS THE ADDRESS STILL YOU CAN REAT THEMLIKE NORMAL VATIABLES
//////////////////////////////////////////////////////////////////////////////////////////////////////////



int main(){

   unordered_map<int,int> m;

   // Inserting in unordered_map
   
   for (int i = 0; i < 4; i++)
   {  
       cout<<"enter thr key value pair:"<<endl;
       int a,b;
       cin>>a>>b;
       m.insert(pair<int,int>(a,b));
   }
   
    
   m.insert(pair<int, int>(5, 50));
   m.insert(pair<int, int>(6, 50));
   m.insert(pair<int, int>(7, 10));
  
  cout<<endl;

   for(auto &it: m)
   {
      cout<<it.first<<" "<<it.second<<" "<<endl;
   }
   
   //
   cout<<"another method"<<endl;

   // printing map m
    unordered_map<int, int>::iterator itr;
   //cout << "\nThe map m is : \n";
   //   cout << "\tKEY\tELEMENT\n";
    for (itr = m.begin(); itr != m.end(); ++itr) {
        cout<< itr->first<<" ";
        cout<< itr->second << '\n';
    }
  //   cout << endl;
  return 0;
}