// #include<iostream>
// #include<queue>

// using namespace std;

// struct node 
// {
//     int data;
//     node *Lchild=NULL;
//     node *Rchild=NULL;
// }*root=NULL;

// node * BuildTree()
// {
//     queue<node *> Q;
//     int rootdata;
//     cout<<"enter the value of root : ";
//     cout<<endl;
//     cin>>rootdata;
//     node *root,*t,*p;
//     root = new node;
//     root->data=rootdata;
//     root->Lchild=NULL;
//     root->Rchild=NULL;
//     Q.push(root);


//     while (!Q.empty())
//     {   
//         t=root;
//         t =  Q.front();
//         Q.pop();
        
//         cout<<"Enter Value of Lchild of "<<t->data<<" : ";
//         int Lchilddata;
//         cin>>Lchilddata;
//         cout<<endl;
//         if(Lchilddata!=-1)
//         {
//            p = new node;
//            p->data=Lchilddata;
//            p->Lchild=NULL;
//            p->Rchild=NULL;
//            t->Lchild=p;
//            Q.push(p);
//         }
        
//         cout<<"Enter the value for Rchild of "<<t->data<<" : ";
//         int Rchilddata;
//         cin>>Rchilddata;
//         cout<<endl;
//         if(Rchilddata!=-1)
//         {
//            p = new node;
//            p->data=Rchilddata;
//            p->Lchild=NULL;
//            p->Rchild=NULL;
//            t->Rchild=p;
//            Q.push(p);
//         }

//     }
    
//  return root;
// }

// void preOrderDisplay(struct node *p)
// {
//     if(p!=NULL)
//     {
//         cout<<p->data<<" ";
//         preOrderDisplay(p->Lchild);
//         preOrderDisplay(p->Rchild);
//     }
// }

// void levelOrderDisplay(node *root)
// {
//     queue<node *>Q;
//     Q.push(root);
//     Q.push(NULL);
//     node *t;

//     while (!Q.empty())
//     {
//         t= Q.front();
//         Q.pop();

//         if(t)
//         {
//             cout<<t->data<<" ";
//             if(t->Lchild)
//                 Q.push(t->Lchild);
//             if(t->Rchild) 
//                 Q.push(t->Rchild);   
//         }

//         else
//         {
//             cout<<endl;
//             if(!Q.empty())
//                Q.push(NULL);
//         }
//     }
    
// }


// int countLeaves(node *t)
// {
  
//     if(t== nullptr) //I was missing this
//         return 0;

//     else if(t->Rchild==NULL&&t->Lchild==NULL)
//        return 1;

//     int x=0,y=0;
//     x += countLeaves(t->Lchild);
//     y += countLeaves(t->Rchild);

//     return x+y;
// }


// int main()
// {
   
//    node *root = BuildTree();
//    int val = countLeaves(root);
//    //preOrderDisplay(root);
//    cout<<"\n Level Wise Tree Display :\n";
//    levelOrderDisplay(root);
//    cout<<endl<<endl;
//    cout<<"\n ... The Number of leaf nodes are:..\n";
//    cout<<val;
//    cout<<endl;
//    cout<<endl;
   
// }


#include<iostream>
#include<queue>

using namespace std;

class node
{
private:
    /* data */
public:
    
    int data;
    node *Lchild;
    node *RChild;

    node(int d)
    {
        data = d;
        Lchild = NULL;
        RChild = NULL;
    }
    
};

node* LevelOrderTree()
{
     int rootData;
     cout<<"Enter The Root Data : ";
     cin>>rootData;
     queue<node *> Q;

      if(rootData==-1)
       return NULL;

     node *root = new node(rootData),*p;
     Q.push(root);

     while (!Q.empty())
     { 
        //Dequeuing the queue
        node *t = Q.front();
        Q.pop();

        int Lchilddata,Rchilddata;
        cout<<"enter the Lchild of "<<t->data<<": ";
        cin>>Lchilddata;
        if(Lchilddata!=-1)
        {
        p = new node (Lchilddata);
        t->Lchild=p;
        Q.push(p);
        }
        
      
        cout<<"enter the Rchild of "<<t->data<<": ";
        cin>>Rchilddata;
        if(Rchilddata!=-1)
        {
        p= new node (Rchilddata);
        t->RChild=p;
        Q.push(p);
        }

     }
     return root;
}

void InorederTrav(node *t)
{
    if(t)
    {
        InorederTrav(t->Lchild);
        cout<<t->data<<" ";
        InorederTrav(t->RChild);
    }
}

int  main()
{   
    node *root = LevelOrderTree();
    InorederTrav(root);

    return 0;
}