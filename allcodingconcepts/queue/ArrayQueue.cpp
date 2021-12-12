//IMPLEMNTATON USING CIRCULAR QUEUE BEST OPTION

#include<bits/stdc++.h>
using  namespace std;

struct Queues
{
    int size;
    int *q;
    int front=0,rear=0;
}Q;

void enqueue(int x,struct Queues *Qu)
{
    if((Qu->rear+1)%(Qu->size)==(Qu->front))
    {
        cout<<"QueueOverflow";
    }

    else
    {   
        Qu->rear=(Qu->rear+1)%(Qu->size);
        Qu->q[Qu->rear] = x;
    }
}

void display(struct Queues *qu)
{
    int i = qu->front+1;

    do
    {
        cout<<qu->q[i]<<" ";
        i=(i+1)%qu->size;
    } while (i!=(qu->rear+1)%qu->size);
    
    
}

int dequeue(struct Queues *qu)
{
    int x=-1;

    if(qu->front==qu->rear)
    {
        cout<<"Queue  is empty"<<endl;
        return x;
    }

    else
    {
        qu->front=(qu->front+1)%qu->size;
        x = qu->q[qu->front];
        return x;
    }
}

int main()
{  
    cout<<"enter the size of array: ";
    cin>>Q.size;

    Q.q= new int[Q.size];
    
    enqueue(4,&Q);
    enqueue(5,&Q);
    display(&Q);
    dequeue(&Q);
    cout<<endl;
    display(&Q);

  return 0;
}
   
