#include <bits/stdc++.h>
using namespace std;


typedef struct tree_node
{
    char data;
    struct tree_node *Lchild, *Rchild;
} * node;


node newtree_node(char c)
{
    node n = new tree_node;
    n->data = c;
    n->Lchild = n->Rchild = nullptr;
    return n;
}

node Expression_Tree_Build(string &s)
{
    stack<node> stackNode;
    stack<char> characterStack;
    node t, t1, t2;

    int p[123] = {0};
    p['+'] = p['-'] = 1, p['/'] = p['*'] = 2, p['^'] = 3,
    p[')'] = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            characterStack.push(s[i]);
        }
        else if (isalpha(s[i]))
        {
            t = newtree_node(s[i]);
            stackNode.push(t);
        }
        else if (p[s[i]] > 0)
        {
            while (
                !characterStack.empty() && characterStack.top() != '(' && ((s[i] != '^' && p[characterStack.top()] >= p[s[i]]) || (s[i] == '^' && p[characterStack.top()] > p[s[i]])))
            {
                t = newtree_node(characterStack.top());
                characterStack.pop();
                t1 = stackNode.top();
                stackNode.pop();
                t2 = stackNode.top();
                stackNode.pop();
                t->Lchild = t2;
                t->Rchild = t1;
                stackNode.push(t);
            }
            characterStack.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!characterStack.empty() && characterStack.top() != '(')
            {
                t = newtree_node(characterStack.top());
                characterStack.pop();
                t1 = stackNode.top();
                stackNode.pop();
                t2 = stackNode.top();
                stackNode.pop();
                t->Lchild = t2;
                t->Rchild = t1;
                stackNode.push(t);
            }
            characterStack.pop();
        }
    }
    t = stackNode.top();
    return t;
}

void postorderTrav(node root)
{
    if (root)
    {
     postorderTrav(root->Lchild);
     postorderTrav(root->Rchild);
        cout << root->data;
    }
}
void preorderTrav(node root)
{
    if (root)
    {
        cout << root->data;
        preorderTrav(root->Lchild);
        preorderTrav(root->Rchild);
    }
}
int main()
{
    string s = "A*B+C/(D-E+F)-(G*H^I)+J";
    s = "(" + s;
    s += ")";
    node root = Expression_Tree_Build(s);
    cout<<endl;
    cout << "\n\n... Given Expression.... :\n";
    cout<<s;


    cout << "\n\n...Printing Postfix Expression By Postfix Traversal of Expression Tree :\n ";
    postorderTrav(root);
    cout << "\n\n...Printing Prefix Expression By Prefix Traversal of Expression Tree : \n";
    preorderTrav(root);
    cout << endl;
    return 0;
}