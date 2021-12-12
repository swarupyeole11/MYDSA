
#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	Node *Lchild, *Rchild;
};

Node* newNodes(int data);

int searching(int array[], int start, int end, int val);

Node* buildUtil(int in[], int postOrder[], int inOrderStart,
				int inOrderEnd, int* postOrderIndex)
{
	if (inOrderStart > inOrderEnd)
		return NULL;

	
	Node* node = newNodes(postOrder[*postOrderIndex]);
	(*postOrderIndex)--;

	if (inOrderStart == inOrderEnd)
		return node;

	int iIndex = searching(in, inOrderStart, inOrderEnd, node->data);

	node->Rchild = buildUtil(in, postOrder, iIndex + 1, inOrderEnd, postOrderIndex);
	node->Lchild = buildUtil(in, postOrder, inOrderStart, iIndex - 1, postOrderIndex);

	return node;
}

Node* makeTree(int in[], int postOrder[], int n)
{
	int postOrderIndex = n - 1;
	return buildUtil(in, postOrder, 0, n - 1, &postOrderIndex);
}

int searching(int array[], int start, int end, int val)
{
	int i;
	for (i = start; i <= end; i++) {
		if (array[i] == val)
			break;
	}
	return i;
}

Node* newNodes(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->Lchild = node->Rchild = NULL;
	return (node);
}

void preOrder(Node* node)
{
	if (node == NULL)
		return;

		switch (node->data)
		{
		case 1:
			cout<<'H'<<" ";
			break;
		
		case 2:
			cout<<'D'<<" ";
			break;
		case 3:
			cout<<'P'<<" ";
			break;
		case 4:
			cout<<'L'<<" ";
			break;
		case 5:
			cout<<'A'<<" ";
			break;
		case 6:
			cout<<'Z'<<" ";
			break;
		case 7:
			cout<<'C'<<" ";
			break;
		case 8:
			cout<<'E'<<" ";
			break;

		default:
			break;
		}
	//printf("%d ", node->data);
	preOrder(node->Lchild);
	preOrder(node->Rchild);
}



int main()
{
	int in[] = { 1,2,3,4,5,6,7,8};
	int postOrder[] = { 1,3,4,2,8,7,6,5 };
	int n = sizeof(in) / sizeof(in[0]);

	Node* root = makeTree(in, postOrder, n);
    
    cout<<"\nIf the tree was created we must be able to show preOrder of it "<<endl;
	cout << "\nPreOrder of the constructed tree : \n";
    preOrder(root);
    cout<<"\n Since Preorder Is visible hence the Tree Was Created using inOrder and postOrderOrder!";
	return 0;
}
