#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
};

typedef node node;

int Calculate(node *h1, node *h2)
{
    int ans = 0;
    while (h1 != NULL)
    {
        ans += h1->data * h2->data;
        h1 = h1->next;
        h2 = h2->next;
    }
    return ans;
}

void pushValue(node **head_ref, int new_data)
{
    node *new_node = new node[(sizeof(node))];
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    node *h1 = NULL, *h2 = NULL, *ans = NULL;
    int n;
    cout << "\nEnter The Number Of Nodes You want In Your Linked List :\n ";
    cin >> n;
    int arr1[n], arr2[n];

    cout << "Enter integers for the first Linked List : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter integers for the second Linked List : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }

    int s1 = n, s2 = n;
    int i;

    for (i = s1 - 1; i >= 0; i--)
    {
        pushValue(&h1, arr1[i]);
    }
    for (i = s2 - 1; i >= 0; i--)
    {
        pushValue(&h2, arr2[i]);
    }

    cout << "\n\nFinal Answer..\n";
    cout << Calculate(h1, h2);
    cout << endl;

    return 0;
}

