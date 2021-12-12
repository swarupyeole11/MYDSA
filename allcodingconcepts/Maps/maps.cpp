#include<bits/stdc++.h>
using  namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////
   
   //A) In Maps The values are stored in sorted order of keys
   //B)INSERTION OF MAP TAKES O(logN)
   //C)Even if you do not insert value to a map it gives a default value if a key is declared e.g m[6] would give 0 value for map<int,int> m;
   //D) for acessing each element the time complexity in a map is O(logN) THUS for printMap function it takes T.C O(NlogN) since for loop is used
   //E) Find operation also take the time complexity of O(logN)
   //F) If key is a string then it sorts in lexicographical order for that it takes O(logN)*s.size() for string comparsion
   //G) Insertinon in maps takes through self Balancinfg treses thus there is the diffrence
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void printMap(map<int,string>&m)
{
    for(auto &pr:m)
    {
        cout<<pr.first<<" "<<pr.second<<endl;
    }
}


int main(){

//inserting values in a map
 map<int,string> m;
 m[1]="abc";   //here index is the key and the value is the value
 m[5]="cdc";
 m[6]="nn";
 m.insert({4,"agf"});

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//printing values in a map

 map<int,string> :: iterator it;

 for( it=m.begin();it!=m.end();it++){
    cout<<(*it).first<<" "<<(*it).second<<" ";
 }

 cout<<endl;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Shortcut for printing values in a map auto

//////////////////////////////////////////
///////
 //THIS IS THE USE OF RANGE OOP ALONG WITH AUTO IN ORDERED MAPS
//////
///////////////////////////////////////// 
 for(auto &pr : m)
 {
     cout<< pr.first<<" "<<pr.second<<" ";
 }
  cout<<endl;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Function for displaying the map

 printMap(m);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//using find() function in a map
 
  return 0;
}
   
