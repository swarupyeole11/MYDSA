#include <bits/stdc++.h>

///EDIT it 
using namespace std;

int arr1[100005];
int arr2[100005];
int arr3[100005];


int main ()
{   
    cout<<endl;
    cout<<"...Input...\n";
    int num1, num2, num3, h, add1=0, add2=0, add3=0, x1, x2, x3;
    cin >> num1 >> num2 >> num3;

    for(int i=0; i<num1; i++) {
        cin>>arr1[i];
        add1+=arr1[i];
    }
    x1 = 0;

    for(int i=0; i<num2; i++) {
        cin>>arr2[i];
        add2+=arr2[i];
    }
    x2 = 0;

    for(int i=0; i<num3; i++) {
        cin>>arr3[i];
        add3+=arr3[i];
    }
    x3 = 0;

    while(1) {
        if(x1 == num1 || x2 == num2 || x3 == num3) {
            h = 0;
            break;
        }

        if(add1 == add2 && add2 == add3) {
            h = add1;
            break;
        }

        
        if(add1 >= add2 && add1 >= add3) {
            add1 -= arr1[x1];
            x1++;
        }
        
        else if(add2 >= add1 && add2>=add3) {
           add2 -= arr2[x2];
           x2++;
        }

        else if(add3 >= add2 && add3 >= add1) {
            add3 -= arr3[x3];
            x3++;
        }
    }
    cout<<"\n....Output....\n\n";
    cout << h << endl;
    cout<<endl;
    return 0;
}