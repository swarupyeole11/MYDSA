#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        string arr[n][n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = ".";
                // cout<<arr[i][j]<<" ";
            }
            // cout<<endl;
        }

        if (n % 2 == 0)
        {
            if (k > n / 2)
            {
                cout << -1 << endl;
            }

            else
            {  
                //   cout<<endl;
                int a = 0, b = 0;
                while (k--)
                {
                    arr[a][b] = "R";
                    a = a + 2;
                    b = b + 2;
                }
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        cout << arr[i][j];
                    }
                    cout << endl;
                }
            }
        }

        else
        {
            if (k > ((n / 2) + 1))
            {
                cout << -1 << endl;
            }

            else
            {   
                //   cout<<endl;
                int a = 0, b = 0;
                while (k--)
                {
                    arr[a][b] = "R";
                    a = a + 2;
                    b = b + 2;
                }
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        cout << arr[i][j];
                    }
                    cout << endl;
                }

            }
        }
    }

    return 0;
}

