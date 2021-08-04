#include <bits/stdc++.h>
using namespace std;

void display(vector<int> &v)
{
   for(int i=0;i<v.size();i++)
   {
      cout<<v[i]<<" ";
   }
   
}


int main()
{

    vector<int> v1;

    //    cout<<v1.capacity(); // for finding the length of vector

    //    v1.push_back(10); // for adding an element in vector
    //    v1.push_back(20);
    //    v1.push_back(30);

    int element,size;

    cout<<"enter the size of vector array:";
    cin>>size;

    cout<<"enter array:";

    for (int i = 0; i < size; i++)
    {
        
        cin >> element;

        v1.push_back(element);

    }// used for taking input from user 

   

    vector<int> :: iterator iter/*iter is name of iterator it can be anything*/ = v1.begin(); //iter is a type of pointer and we wnat to start it from the beginning thus the v1.begin()
    // v1.insert(iter,566); //elemnt at 0th index adding element at o th index
    v1.insert(iter+2,455);//element at second index 

    

    display(v1);



    return 0;
}
