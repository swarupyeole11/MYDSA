#include <bits/stdc++.h>
using namespace std;

class node
{
    public:

    int data;
    node *rChild;
    node *lChild;

    node(int d)
    {
        data=d;
        rChild=NULL;
        lChild=NULL;
    }
};


node * levelOrderBuild()
{
    queue<node *> Q;
    int rootval;
    cin>>rootval;
    node *t,*root;
    root = new node(rootval);
    Q.push(root);
    node *p;

    while (!Q.empty())
    {   
        t=root;
        t=Q.front();
        Q.pop();
        
        int lchildData,rchildData;
       
       cout<<"Enter Value of Lchild of "<<t->data<<" : ";
        cin>>lchildData;
        if(lchildData!=-1)
        {
           p = new node(lchildData);
           t->lChild=p;
           Q.push(p);
        }

       cout<<"Enter Value of Rchild of "<<t->data<<" : ";
        cin>>rchildData;
        if(rchildData!=-1)
        {
             p = new node(rchildData);
             t->rChild=p;
             Q.push(p);
        }
    }
    
    return root;
}


int main()
{
    
    node * root = levelOrderBuild();


    return 0;
}

