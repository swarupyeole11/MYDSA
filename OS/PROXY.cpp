#include<bits/stdc++.h>
using namespace std;

struct Queues
{
  int *Q;
  int front;
  int rear;
  int size;
};

void
create (struct Queues *q, int size)
{
  q->size = size;
  q->front = q->rear = 0;
  q->Q = new int[q->size];
}

void
Enqueues (struct Queues *q, int x)
{
  if ((q->rear + 1) % q->size == q->front)
    {
      cout << "the queue iis full";
    }

  else
    {
      q->rear = (q->rear + 1) % q->size;
      q->Q[q->rear] = x;
    }
}

int
Dequeues (struct Queues *q)
{
  int x = -1;

  if (q->front == q->rear)
    {
      cout << "the queue is empty";
    }

  else
    {
      q->front = (q->front + 1) % q->size;
      x = q->Q[q->front];
    }

  return x;
}

void
Display (struct Queues *q, int Pnum)
{
  int i = (q->front + 1) % q->size;
  do
    {
      cout << q->Q[i] << " ";
      i = (i + 1) % q->size;
    }
  while (i != (q->rear + 1) % q->size);

}

int
main ()
{

  ///-----------------------------------------------------------------------------------------------------------------------------------------//   
  struct Queues q;
  int maxProcess;
  cout << "Enter the maximum Processes that can be Entered : " ;
  cin>>maxProcess;
  cout<<endl;
  create (&q, 20);

  ///-----------------------------------------------------------------------------------------------------------------------------------------//

  cout << "Enter the number of processes  you want to enter :";
  int Pnum;			//number of processes to be entered
  cin >> Pnum;
  cout<<endl;
  cout<<endl;

  ///-----------------------------------------------------------------------------------------------------------------------------------------//

  cout << "enter the process id of each Process: " << endl;
  for (int i = 1; i <= Pnum; i++)
    {
      int Pid;
      cin >> Pid;
      Enqueues (&q, Pid);
    }
  cout<<endl;
///-----------------------------------------------------------------------------------------------------------------------------------------//

  float overheadTime;
  cout<<"enter the over head time for the processes : ";
  cin>>overheadTime;
  cout<<endl;

///-----------------------------------------------------------------------------------------------------------------------------------------//

  int At[Pnum+1], Bt[Pnum+1];

  cout << "enter the arrival Time of each Process: " << endl;
  for (int i = 1; i <= Pnum; i++)
    {
      int num;
      cin >> num;
      At[i] = num;
    }
  cout<<endl;

///-----------------------------------------------------------------------------------------------------------------------------------------//    

  cout << "enter the CPU Time of each Process: " << endl;
  for (int i = 1; i <= Pnum; i++)
    {
      int num;
      cin >> num;
      Bt[i] = num;
    }
  cout<<endl;
  
///-----------------------------------------------------------------------------------------------------------------------------------------//


  ////////////////////////
  /////////////////////////////////////////////
  ///// // shuffling the processes according to their order in which tey are supposed to arrive/////////////////////
  ////////////////////////////////////////////
  //////////////////////

  for (int i = 1; i <= Pnum; i++)
    {
      for (int j = 1; j <= Pnum - 1; j++)
	{
	  if (At[j] > At[j + 1])
	    {
	      swap (At[j], At[j + 1]);
	      swap (Bt[j], Bt[j + 1]);
	      swap (q.Q[j], q.Q[j + 1]);
	    }
	}

    }

///-----------------------------------------------------------------------------------------------------------------------------------------//    

//
//////
///////////////////
///////////////////////////////////////////////////////
  //REMEMBER SINCE WE HAVE USED CIRCULAR QUEUE tHUS WE HAVE TO START INDEXING FROM 1 FOR PROCESS ID
//////////////////////////////////////////////////////
/////////////////
/////
//     
///-----------------------------------------------------------------------------------------------------------------------------------------//  

  int Ct[Pnum+1];			// The completion time of each process
  Ct[0] = 0;		// WRITNG COMPLETION TiME OF FIRST

  ///-----------------------------------------------------------------------------------------------------------------------------------------//

  // CALCULATING THE COMPLETION TIME//

  for (int i = 1; i <= Pnum; i++)
    {
        if(At[i]>Ct[i-1+overheadTime])
        {
            Ct[i]=At[i]+Bt[i];
        }
        
        else
        {
         Ct[i] = Bt[i] + Ct[i - 1] + overheadTime;
        }
    }

  // for(int i=1;i<=Pnum;i++)
  // {
  //    cout<<"ct"<<Ct[i]<<" ";
  // }


///-----------------------------------------------------------------------------------------------------------------------------------------//

  int Tat[Pnum+1];		// total Turnaround time TAT = CT-AT
  float TatSum = 0;
  for (int i = 1; i <= Pnum; i++)
    {
      Tat[i] = Ct[i] - At[i];
      TatSum = TatSum + Tat[i];
    }

  
  float AvgTat = ((TatSum)/ Pnum);
  cout<<endl;
  cout << " The Avg Turnaround Time is : " << AvgTat << endl;
  cout<<endl;
///-----------------------------------------------------------------------------------------------------------------------------------------//


  int Wt[Pnum+1];			// Wt = Tat - Bt
  float WtSum = 0;		// REMEMBER DECLARE IT FLOAT NOT INT

  for (int i = 1; i <= Pnum; i++)
    {
      Wt[i] = Tat[i] - Bt[i];
      WtSum = WtSum + Wt[i];
      //cout<<Wt[i]<<" ";

    }

  float AvgWt = ((WtSum)/ Pnum);
  cout<<endl;
  cout << " The Avg Waiting Time is : " << AvgWt << endl;
  cout<<endl;
///-----------------------------------------------------------------------------------------------------------------------------------------// 

  int Rt[Pnum];			// SINCE THERE IS NO PREMPTION THUS Rt = Wt
  float RtSum = 0;		// REMEMBER DECLARE IT FLOAT NOT INT

  for (int i = 1; i <= Pnum; i++)
    {
      Rt[i] = Wt[i];
      RtSum = RtSum + Rt[i];
      //cout<<Wt[i]<<" ";

    }

  float AvgRt = ((RtSum)/ Pnum);
  cout<<endl;
  cout << " The Avg Response Time is : " << AvgRt << endl;
  cout<<endl;
///-----------------------------------------------------------------------------------------------------------------------------------------//   

 

   cout<<"Pid "<<"A_T "<<"B_T "<<"C_T "<<"T_A_T "<<"W_T "<<endl;
    
    for(int i=1;i<=Pnum;i++){
        cout<<q.Q[i]<<"    "<<At[i]<<"   "<<Bt[i]<<"    "<<Ct[i]<<"    "<<Tat[i]<<"   "<<Wt[i]<<endl;
    }

///-----------------------------------------------------------------------------------------------------------------------------------------//

  return 0;
}