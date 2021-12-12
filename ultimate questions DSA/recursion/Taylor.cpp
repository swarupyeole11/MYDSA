                       // METHOD 1 USING HORNER SERIES WITH LOOP //
//------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//concept here is do for e(x,4) HERE 4 CAN BE N WE HAVE TAKEN 4 FOR EXAMPLE
// 1+x[1+x/2(1+x/3(1+x/4))]

//------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// #include<bits/stdc++.h>
// using  namespace std;

// int main(){
   
//  cout<<"Enter the power to which you want to raise e:";//ex: e^2 => 2
//  int x;
//  cin>>x;
 
//  cout<<"Enter the precision you want:";
//  int n;
//  cin>>n;

//  double pro=1;

//   for(int i=n;i>0;i--)
//   {
//      pro = pro*((double)x/(double)i) + 1;
//   }
  
//   cout<<pro;

//   return 0;
// }
   


//------------------------------------------------------------------------------------------------------------------------------------------------------------------//
                          //HORNER WITH RECURSION//


#include<bits/stdc++.h>
using  namespace std;

double e(int x,int n)
{

}

int main()
{
    cout<<"Enter the power to which you want to raise e:";//ex: e^2 => 2
 int x;
 cin>>x;
 
 cout<<"Enter the precision you want:";
 int n;
 cin>>n;
  return 0;
}
   
