#include<bits/stdc++.h>
using  namespace std;

void fun2(int n)
{   
    if(n>0)
    {
    fun2(n-1);
    cout<<n;
    }
}

int fun(int n)
{
    if(n>0)
    {
        
        return fun(n-1)+n;
    }

    return 0;


}


int fun1(int n1)
{
   static int x=0;

   if(n1>0)
   { 
     x++;
    return fun1(n1-1)+x;
   }

   return 0;

}

int main()
{
   
//   cout<<fun(5); //PRINTS SUM OF FIRST 5 NUMBERS 
  
//   cout<<fun(5);
   

//   cout<<fun1(5);

//   cout<<fun1(5);//SEE DIFFENE WHEN IT IS CALLED SECOND TIME
   
   fun2(5);

  return 0;
}
   
