#include<bits/stdc++.h>
using namespace std;


int main()
{   
    string str;
	long long  t;
	long long checkVal = 0;
	long long i;
	long long flag;
	long long correctLastPosn;
    
    cout<<endl;
    cout<<" ..........Enter Number of Test Cases.......... :\n";
	cin>>t;

	while( t-- )
	{
		checkVal = 0 ;
		flag = 0 ;
		correctLastPosn = 0;
        cout<<" ..........Enter The Expression.......... :\n";
		cin>>str;

		for( i = 0 ; str[i] != '\0' ; i++ )
		{

			if( str[i] == '<' )
				checkVal++;
			else if( str[i] == '>' )
				checkVal--;

			if( checkVal < 0 )
			{
				flag = 2;
				break;
			}
			else if( checkVal == 0 )
			{
				correctLastPosn = i;
				flag = 1;
			}

		}

		if( flag == 1 )
		{   
             cout<<"Output: ";
			cout<<correctLastPosn+1<<endl;
		}

		else if( flag == 2 )
		{
			if( correctLastPosn == 0 )
            {   
                cout<<"Output: ";
				cout<<"0\n";
            }
			else
            {  
                cout<<"Output: ";
				cout<<correctLastPosn+1<<endl;
            }
		}

		else if( checkVal > 0 )
		{
			cout<<"0\n";
		}

	}

    cout<<endl;

	return 0;
}