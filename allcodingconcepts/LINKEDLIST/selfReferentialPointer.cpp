#include<bits/stdc++.h>
using  namespace std;

struct point
{
    int x;
    int y;
    struct point *srp1; //this is self referential pointer

}*p2,var1,var2;


int main()
{
    var1.x=10;
    var1.y=20;
    var2.x=30;
    var2.y=40;
   
    var1.srp1 = &var2; //this is storing of base address of structure with var2 as object
                    //in the self referential pointer(srp1) with var1 as object.
                    //NOTE: SINCE VAR2 IS NOT A POINTER AND WE HAVE TO STORE ADDRESS WE USE THE &SYMBOL
                    //HAD IT BEEN A POINTER THEN WE WOULD NOT HAVE USED & AS IT ALREADY STORES ADDRESS

    p2=&var2;

    cout<<endl;

    cout<<"output through srp1:"<<var1.srp1->x<<endl;  //Here you can see the access diffrence between srp1 & p2

    cout<<"output through p2:"<<p2->x;


   cout<<endl;
                    


  return 0;
}
   
