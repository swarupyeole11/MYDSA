#include<bits/stdc++.h>
using  namespace std;

int fact(int n)
{
  if(n==0)
  {
    return  1;
  }

  return fact(n-1)*n;
}

int nCrp(int n , int r)
{
   if(r==0 || n==r)
   {
     return 1;
   }

   return  nCrp(n-1,r)+nCrp(n-1,r-1);
}

int main()
{
   int n,r;

    cout<<"enter n:";
    cin>>n;
    
    cout<<"enter r:";
    cin>>r;

    int nCr = fact(n)/(fact(n-r)*fact(r));

    cout<<nCr<<endl;

    int NCRP = nCrp(n,r);

    cout<<NCRP;


  return 0;
}
   
