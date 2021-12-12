#include<bits/stdc++.h>
using  namespace std;

struct point
{
   int x;
   int y;
};

struct point *fun(int a,int b)
{
    struct point *ptr = new point;
    ptr->x=a;
    ptr->y=b;

    return ptr;

}

void print(struct point *ptr)
{
    cout<<ptr->x<<" "<<ptr->y;
}


int main(){


    struct  point *p1 , *p2;

    p1 = fun(2,3);
    
    print(p1);


  return 0;
}
   
