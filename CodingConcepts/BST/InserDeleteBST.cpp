#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *Rchild = NULL;
    struct node *Lchild = NULL;
} *root = NULL;

void Insert(int key)
{
    struct node *t = root;
    struct node *r = NULL;

    if (root == NULL)
    {
        root = new node;
        root->data = key;
    }

    else
    {
        while (t != NULL)
        {
            r = t;
            if (key > t->data)
                t = t->Rchild;
            else if (key < t->data)
                t = t->Lchild;
            else
                return;
        }

        t = new node;
        t->data = key;

        if (key > r->data)
            r->Rchild = t;
        else
            r->Lchild = t;
    }
}

void preOrderDisplay(struct node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        preOrderDisplay(p->Lchild);
        preOrderDisplay(p->Rchild);
    }
}

void inOrderDisplay(struct node *p)
{
    if (p != NULL)
    {

        inOrderDisplay(p->Lchild);
        cout << p->data << " ";
        inOrderDisplay(p->Rchild);
    }
}

void postOrderDisplay(struct node *p)
{
    if (p != NULL)
    {

        postOrderDisplay(p->Lchild);
        postOrderDisplay(p->Rchild);
        cout << p->data << " ";
    }
}

int Height(node *p)
{
int x,y;
if(p==NULL)return 0;
x=Height(p->Lchild);
y=Height(p->Rchild);
return x>y?x+1:y+1;
}

node *InorderPredecessor(node *p)
{
while(p && p->Rchild!=NULL)
p=p->Rchild;
return p;
}

node *InorderSuccessor(node *p)
{
    while (p&&p->Lchild!=NULL)
    p=p->Lchild;
    return p;
    
}

 node *Delete(node *p,int key)
{
node *q;
if(p==NULL)
return NULL;
if(p->Lchild==NULL && p->Rchild==NULL)
{
if(p==root)
root=NULL;
delete p;
return NULL;
}
if(key < p->data)
p->Lchild=Delete(p->Lchild,key);
else if(key > p->data)
p->Rchild=Delete(p->Rchild,key);
else
{
if(Height(p->Lchild)>Height(p->Rchild))
{
q=InorderPredecessor(p->Lchild);
p->data=q->data;
p->Lchild=Delete(p->Lchild,q->data);
}
else
{
q=InorderSuccessor(p->Rchild);
p->data=q->data;
p->Rchild=Delete(p->Rchild,q->data);
}

}
return p;

}


int main()
{
    Insert(8);
    Insert(3);
    Insert(10);
    Insert(1);
    Insert(6);
    Insert(14);
    Insert(4);
    Insert(7);
    
    cout<<"... Intial Display...."<<endl<<endl;
    cout << endl;
    cout << "The Preorder Display is : ";
    preOrderDisplay(root);
    cout << endl;
    cout << endl;
    cout << "The Inorder Display is : ";
    inOrderDisplay(root);
    cout << endl;
    cout << endl;
    cout << "The Postorder Display is : ";
    postOrderDisplay(root);
    cout << endl;
    cout << endl;

    Delete(root,14);
    
    cout<<"... After Deleting 14...."<<endl<<endl;
    cout << endl;
    cout << "The Preorder Display is : ";
    preOrderDisplay(root);
    cout << endl;
    cout << endl;
    cout << "The Inorder Display is : ";
    inOrderDisplay(root);
    cout << endl;
    cout << endl;
    cout << "The Postorder Display is : ";
    postOrderDisplay(root);
    cout << endl;
    cout << endl;
   
    Delete(root,3);
    cout<<"... After Deleting 3...."<<endl<<endl;
    cout << endl;
    cout << "The Preorder Display is : ";
    preOrderDisplay(root);
    cout << endl;
    cout << endl;
    cout << "The Inorder Display is : ";
    inOrderDisplay(root);
    cout << endl;
    cout << endl;
    cout << "The Postorder Display is : ";
    postOrderDisplay(root);
    cout << endl;
    cout << endl;

     Delete(root,8);
    cout<<"... After Deleting 8...."<<endl<<endl;
    cout << endl;
    cout << "The Preorder Display is : ";
    preOrderDisplay(root);
    cout << endl;
    cout << endl;
    cout << "The Inorder Display is : ";
    inOrderDisplay(root);
    cout << endl;
    cout << endl;
    cout << "The Postorder Display is : ";
    postOrderDisplay(root);
    cout << endl;
    cout << endl;
   

    return 0;
}