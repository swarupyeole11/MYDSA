#include <bits/stdc++.h>
using namespace std;

void display(vector<int> &v)
{
   for(int i=0;i<v.size();i++)
   {
      cout<<v[i]<<" ";
   }
   
}

void Rangedisplay(vector<int> &v)
{   
    cout<<endl<<"using range display in an vector"<<" ";
    //Here val acts as a variable this is somewhat like the fr loop in python
    //Note we use &val becz if we only use val it willonly make the copies of the values of the vector array and will not change the real values
    for (int &val : v)
    {
        cout<<val<<" ";
    }
    
}

void iterdisplay(vector<int> &v)
{   
    // we do not use it=it+1 istead of it++ becz it=it+1 will mkve pointer to next loction permenantly and it may give error in case of sets and maps when we reach end
    vector<int> ::iterator it ;
    for(it=v.begin();it!=v.end();it++)
    {
       cout<<(*it)<<" ";
    }
    
}

void autoiterdisplay(vector<int> &v)
{    
    cout<<endl<<"This is auto iterative display function :  ";
    // we do not use it=it+1 istead of it++ becz it=it+1 will mkve pointer to next loction permenantly and it may give error in case of sets and maps when we reach end
    for(auto it=v.begin();it!=v.end();it++)
    {
       cout<<(*it)<<" ";
    }

    // auto AUTOMATICALLY ASSUMES THE DATATYPE OF THE VARIABLE 
    
}

int main()
{

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

   


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     // Using display 
       display(v1);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
  // CONCEPT OF ITERATORS IN C++

  // Vectors can be visualized just like arrays so iterators work like pointers
  // IF ITERATOR NAME IS it then it.begin() points at first element while it.end() points at null just after completing the vector array
  // Ex 2-3-4-5-6 it.begin() points at 2 and it.end() points at point just after 6
  
    cout<<endl;
    vector<int> :: iterator iter/*iter is name of iterator it can be anything*/ = v1.begin(); //iter is a type of pointer and we wnat to start it from the beginning thus the v1.begin()
    // v1.insert(iter,566); //elemnt at 0th index adding element at o th index
    v1.insert(iter+2,455);//element at second index 
    cout<<"down is iterative display: "<<endl;
    iterdisplay(v1);
    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
  
   //using Auto in case of iterators

   // auto AUTOMATICALLY CATCHES THE DATA TYPE OF VARIABLE 

   auto it = v1.begin();
   v1.insert(it,123);
   autoiterdisplay(v1);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   //USING RANGE LOOPS IN C++

     Rangedisplay(v1);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   //VECTOR PAIRS IN AN VECTOR

   vector<pair<int,int>> v_p ={{1,2},{9,8}} ;
   vector<pair<int,int>> :: iterator it_p = v_p.begin();
   cout<<endl;
   cout<<"displaying vector pairs:"<<endl;

   for ( it_p=v_p.begin(); it_p!=v_p.end() ; it_p++)
   {
       cout<<(*it_p).first<<" "<<it_p->second<<" "; //any syntax can be used *(). OR ->
   }
   
    return 0;
}
