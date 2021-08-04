// #include<bits/stdc++.h>
// using  namespace std;
// int main(){
   
//    string stringy;

//    getline(cin,stringy);
   
//    int H[26];//DO NOT EVER CROSS THE SIZE OF ARRAY IT WILL COST YOU

//    for(int i=0;i<26;i++)
//    {
//        H[i]=0;
//    }

  

//    for(int i=0;i<stringy.size();i++)
//    {   
//      H[stringy[i]-97]+=1;
//    }
   

//    for(int i=0;i<25;i++)
//    { 
//       char character;
//       if(H[i]>1)
//       {    
//            character=i+97;// for e.g index was 5 then ascii value was 5+97=102 which is f
//            cout<<character<<" "<<endl;
//            cout<<"No of times the character was repeated:"<<H[i]<<" "<<endl;
//       }
//    }
   
  
   

//   return 0;
// }
   
//THE ABOVE CODE WAS FOR CASE WHERE THE LETTERS ARE LOWER CASE BUT SAME LOGIC CAN BE APPLIED FOR UPPPER CASE TOO 
//BUT IF BOTH UPPER CASE AN DLOWER CASE ELEEMENTS ARE PRESENT THEN WE HAVE TO USE ARRAY TILL 122 ELEMENTS STARTING FROM 65 THIS WILL INCREASE THE ARRAY SIZE

// #include<bits/stdc++.h>
// using  namespace std;
// int main(){
   

//    string s;
//    getline(cin,s);
//    int H[122];

//    for(int i=0;i<122;i++)
//    {
//       H[i]=0;
//    }
   
//    for(int i=0;i<s.size();i++)
//    {
//         H[s[i]]+=1;
//         cout<<H[i];
//    }
   
   

//    for(int i=0;i<122;i++){
      
//       char character;
//       if(H[i]>1)
//       {
//          character = i ;
//          cout<<"The repeated character is:"<<character<<endl;
//          cout<<"Number of time sit was repeated was:"<<H[i]<<endl;
//       }
//    }
   
   



//   return 0;
// }
   

//THE ABOVE CODE WORKS FOR ANYTYP OF STRING UPPER CASE OR LOWER CASE DOES NOT MATTER



//--------------------------------------------------------------------------------------//
//                           APPROACH TWO                                              //


#include<bits/stdc++.h>
using  namespace std;
int main(){

   string s;
   getline(cin,s);

   long long int H=0,A=0;
   
   for(int i=0;i<s.size();i++)
   {   
         A=1;
         A=A<<s[i];

       if((H&A) > 0)
       {
          cout<<"Repeating character:"<<s[i]<<endl;
       }

       else
       {
          H = H|A;
          //cout<<H<<" ";
       }
   }
   

  return 0;
}
   
