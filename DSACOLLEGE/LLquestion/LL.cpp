#include <iostream>
using namespace std;
struct node   //CREATING NODE
{
    int RollNo;
    string Name;
    string Branch;
    int Marks;
    struct node *next;
}*CSEFirst=NULL,*ECEFirst=NULL,*EEEFirst=NULL,*MECHFirst=NULL,*MIXFirst=NULL,*CSELast=NULL,*CircularCSEFirst=NULL,*CircularECEFirst=NULL;

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void CSEcreate(int RollNoarr[], string Namearr[],string Brancharr[], int Marksarr[] ,int n)  // CREATING LINKED LIST FOR CSE DATA
{
    int i;
    struct node *last;
    struct node *t;
    CSEFirst = new node;
    CSEFirst->RollNo = RollNoarr[0];
    CSEFirst->Name = Namearr[0];
    CSEFirst->Branch = Brancharr[0];
    CSEFirst->Marks = Marksarr[0];
    CSEFirst->next=NULL;
    CSELast=CSEFirst;
    
    for(i=1;i<n;i++)
    {
        t = new node;
        t->RollNo = RollNoarr[i];
        t->Name = Namearr[i];
        t->Branch = Brancharr[i];
        t->Marks = Marksarr[i];
        t->next=NULL;
        CSELast->next=t;
        CSELast=t;
    }
    
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void ECEcreate(int RollNoarr[], string Namearr[],string Brancharr[], int Marksarr[] ,int n)  // CREATING LINKED LIST FOR ECE DATA
{
    int i;
    struct node *last;
    struct node *t;
    ECEFirst = new node;
    ECEFirst->RollNo = RollNoarr[0];
    ECEFirst->Name = Namearr[0];
    ECEFirst->Branch = Brancharr[0];
    ECEFirst->Marks = Marksarr[0];
    ECEFirst->next=NULL;
    last=ECEFirst;
    
    for(i=1;i<n;i++)
    {
        t = new node;
        t->RollNo = RollNoarr[i];
        t->Name = Namearr[i];
        t->Branch = Brancharr[i];
        t->Marks = Marksarr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void EEEcreate(int RollNoarr[], string Namearr[],string Brancharr[], int Marksarr[] ,int n) // CREATING LINKED LIST FOR EEE DATA
{
    int i;
    struct node *last;
    struct node *t;
    EEEFirst = new node;
    EEEFirst->RollNo = RollNoarr[0];
    EEEFirst->Name = Namearr[0];
    EEEFirst->Branch = Brancharr[0];
    EEEFirst->Marks = Marksarr[0];
    EEEFirst->next=NULL;
    last=EEEFirst;
    
    for(i=1;i<n;i++)
    {
        t = new node;
        t->RollNo = RollNoarr[i];
        t->Name = Namearr[i];
        t->Branch = Brancharr[i];
        t->Marks = Marksarr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void MECHcreate(int RollNoarr[], string Namearr[],string Brancharr[], int Marksarr[] ,int n) // CREATING LINKED LIST FOR MECH DATA
{
    int i;
    struct node *last;
    struct node *t;
    MECHFirst = new node;
    MECHFirst->RollNo = RollNoarr[0];
    MECHFirst->Name = Namearr[0];
    MECHFirst->Branch = Brancharr[0];
    MECHFirst->Marks = Marksarr[0];
    MECHFirst->next=NULL;
    last=MECHFirst;
    
    for(i=1;i<n;i++)
    {
        t = new node;
        t->RollNo = RollNoarr[i];
        t->Name = Namearr[i];
        t->Branch = Brancharr[i];
        t->Marks = Marksarr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    
}

// //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void MIXcreate(int RollNoarr[], string Namearr[],string Brancharr[], int Marksarr[] ,int n)  // CREATING LINKED LIST FOR MIX DATA
{
    int i;
    struct node *last;
    struct node *t;
    MIXFirst = new node;
    MIXFirst->RollNo = RollNoarr[0];
    MIXFirst->Name = Namearr[0];
    MIXFirst->Branch = Brancharr[0];
    MIXFirst->Marks = Marksarr[0];
    MIXFirst->next=NULL;
    last=MIXFirst;
    
    for(i=1;i<n;i++)
    {
        t = new node;
        t->RollNo = RollNoarr[i];
        t->Name = Namearr[i];
        t->Branch = Brancharr[i];
        t->Marks = Marksarr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void display(struct node *p)  // FUNCTION TO DISPLAY LINKED LIST
{
     int i=1;
    while(p!=NULL)
    {
        cout<<"Student"<<" "<<i<<" "<<"Roll No : "<<p->RollNo<<" "<<"Name : "<<p->Name<<" "<<" "<<"Branch : "<<p->Branch<<" "<<" "<<"Marks : "<<p->Marks<<endl;
        i++;
        p=p->next;
    }
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int count(struct node *p)   // PROGRAM TO COUNT THE NUMBER OF NODES IN LINKED LIST
{
   int count =0;
   while(p!=0)
   {
      count++;
      p=p->next;
   }
   return count;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

struct node *FindTopper(struct node *p)
{
    int XMax = INT16_MIN;
    struct node *t = NULL;
    while(p!=NULL)
    {
        if(p->Marks>XMax)
        {
            XMax=p->Marks;
            t=p;
        }

         p=p->next;
    }
  return t;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void ECEinsert(struct node *p,int index,int RollNos, string Names,string Branchs,int Markss)  //FUNCTION TO INSERT ELEMENT IN THE GIVEN ECE LINKED LIST 
{
    struct node *t = new node;
     t->RollNo=RollNos;
     t->Branch=Branchs;
     t->Marks=Markss;
     t->Name=Names;

    if(index<0||index>count(p))
    {
        return;
    }

    if(index==0)
    {
        t->next=ECEFirst;
        ECEFirst=t;    

    }

    else
    {
        for(int i=0;i<index-1;i++)
        {
           p=p->next;
        }

        t->next=p->next;
        p->next=t;
        
    }
}  

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void CSELastInsert(int RollNos, string Names,string Branchs, int Markss)  //FUNCTION TO INSERT THE ELEMENT IN CSE LINKED LIST AT THE LAST
 { 
     struct node *t = new node;
     t->RollNo=RollNos;
     t->Branch=Branchs;
     t->Marks=Markss;
     t->Name=Names;
     t->next=NULL;

     if(CSEFirst==NULL)
     {   

         CSEFirst=CSELast=t;
     }

     else
     {
      CSELast->next=t;
      CSELast=t;
    
     }
 }

 //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

 void CircularCSEcreate(int RollNoarr[], string Namearr[],string Brancharr[], int Marksarr[] ,int n)  //FUNCTION TO CREATE CIRCULAR LINKED LIST FOR CSE DATA
{
    int i;
    struct node *last;
    struct node *t;
    CircularCSEFirst = new node;
    CircularCSEFirst->RollNo = RollNoarr[0];
    CircularCSEFirst->Name = Namearr[0];
    CircularCSEFirst->Branch = Brancharr[0];
    CircularCSEFirst->Marks = Marksarr[0];
    CircularCSEFirst->next=NULL;
    last=CircularCSEFirst;
    
    for(i=1;i<n;i++)
    {
        t = new node;
        t->RollNo = RollNoarr[i];
        t->Name = Namearr[i];
        t->Branch = Brancharr[i];
        t->Marks = Marksarr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }

    last->next=CircularCSEFirst;
    
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void CircularCSEdisplay(struct node *p)  //FUNCTION TO DISPLAY CIRCULAR  LINKED LIST FOR CSE DATA
{
     int i=1;

    do
    {
      cout<<"Student"<<" "<<i<<" "<<"Roll No : "<<p->RollNo<<" "<<"Name : "<<p->Name<<" "<<" "<<"Branch : "<<p->Branch<<" "<<" "<<"Marks : "<<p->Marks<<endl;
        i++;
        p=p->next;
    }
    while(p!=CircularCSEFirst);
    
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

  void CircularECEcreate(int RollNoarr[], string Namearr[],string Brancharr[], int Marksarr[] ,int n)  //FUNCTION TO CREATE CIRCULAR LINKED LIST FOR ECE DATA
{
     int i;
    struct node *last;
    struct node *t;
    CircularECEFirst = new node;
    CircularECEFirst->RollNo = RollNoarr[0];
    CircularECEFirst->Name = Namearr[0];
    CircularECEFirst->Branch = Brancharr[0];
    CircularECEFirst->Marks = Marksarr[0];
    CircularECEFirst->next=NULL;
    last=CircularECEFirst;
    
    for(i=1;i<n;i++)
    {
        t = new node;
        t->RollNo = RollNoarr[i];
        t->Name = Namearr[i];
        t->Branch = Brancharr[i];
        t->Marks = Marksarr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }

    last->next=CircularECEFirst;
    
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void CircularECEdisplay(struct node *p)  //FUNCTION TO DISPLAY CIRCULAR  LINKED LIST FOR ECE DATA
{
     int i=1;

    do
    {
      cout<<"Student"<<" "<<i<<" "<<"Roll No : "<<p->RollNo<<" "<<"Name : "<<p->Name<<" "<<" "<<"Branch : "<<p->Branch<<" "<<" "<<"Marks : "<<p->Marks<<endl;
        i++;
        p=p->next;
    }
    while(p!=CircularECEFirst);
    
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int main()
{  
                                                                          ////////////   I   ////////////
  //1A---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

    int CSERoll[5] = {1001,1002,1003,1004,1005};
    string CSEname[5] = {"AAA","BBB","CCC","DDD","EEE"};
    string Stubranch1[5] = {"CSE","CSE","CSE","CSE","CSE"};
    int CSEMarks[5]= {94,91,75,89,69};

    cout<<endl;

    cout<<"                        "<<" CSE List Display :"<<"                      "<<endl;
    cout<<endl;
    CSEcreate(CSERoll,CSEname,Stubranch1,CSEMarks,5);
    display(CSEFirst);

 //1B---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//  

    cout<<endl;
    int ECERoll[5] = {2001,2002,2003,2004,2005};
    string ECEname[5] = {"FFF","GGG","HHH","III","JJJ"};
    string Stubranch2[5] = {"ECE","ECE","ECE","ECE","ECE"};
    int ECEMarks[5]= {72,89,75,76,58};
    

    
    cout<<"                        "<<" ECE List Display :"<<"                      "<<endl;
    cout<<endl;
    ECEcreate(ECERoll,ECEname,Stubranch2,ECEMarks,5);
    display(ECEFirst);

//1C---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

  
    cout<<endl;
    int EEERoll[5] = {3001,3002,3003,3004,3005};
    string EEEname[5] = {"KKK","LLL","MMM","NNN","OOO"};
    string Stubranch3[5] = {"EEE","EEE","EEE","EEE","EEE"};
    int EEEMarks[5]= {91,89,75,76,58};
    

    
    cout<<"                        "<<" EEE List Display :"<<"                      "<<endl;
    cout<<endl;
    EEEcreate(EEERoll,EEEname,Stubranch3,EEEMarks,5);
    display(EEEFirst);

//1D---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

  cout<<endl;
    int MECHRoll[5] = {4001,4002,4003,4004,4005};
    string MECHname[5] = {"QQQ","RRR","SSS","TTT","UUU"};
    string Stubranch4[5] = {"MECH","MECH","MECH","MECH","MECH"};
    int MECHMarks[5]= {92,89,95,66,78};
    

    
    cout<<"                        "<<" MECH List Display :"<<"                      "<<endl;
    cout<<endl;
    MECHcreate(MECHRoll,MECHname,Stubranch4,MECHMarks,5);
    display(MECHFirst);

//1E---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

    cout<<endl;
    int MIXRoll[5] = {4003,3001,4001,3002,4001};
    string MIXname[5] = {"SSS","KKK","QQQ","LLL","QQQ"};
    string Stubranch5[5] = {"MECH","EEE","MECH","EEE","MECH"};
    int MIXMarks[5]= {95,91,92,89,92};
    

    
    cout<<"                        "<<" MIX List Display :"<<"                      "<<endl;
    cout<<endl;
    MIXcreate(MIXRoll,MIXname,Stubranch5,MIXMarks,5);
    display(MIXFirst);    

                                               ////////////   II  ////////////
//2---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

                                          // ADDING MECH TOPPER TO END OF CSE LIST

   cout<<endl;
   struct node *t = FindTopper(MECHFirst);
   CSELastInsert(t->RollNo,t->Name,t->Branch,t->Marks);// CSELastInsert(4003,"SSS","MECH",95);


   

                                             ////////////   III  ////////////
//3---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//  
                                          // ADDING EEE TOPPER TO THE BEGINNING OF ECE LIST

   cout<<endl;
   struct node *s = FindTopper(EEEFirst);
   ECEinsert(ECEFirst,0,s->RollNo,s->Name,s->Branch,s->Marks);
//   ECEinsert(ECEFirst,0,3001,"KKK","EEE",91);


                                          ////////////   IV  ////////////
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//  
                                         // DISPLAYING UPDATED LINKED LISTS

                                                    cout<<endl;

             cout<<"                        "<<" NEW CSE List Display :"<<"                      "<<endl;
  
  display(CSEFirst); 

                                                    cout<<endl;

             cout<<"                        "<<" NEW ECE List Display :"<<"                      "<<endl;

  display(ECEFirst);    



                                              ////////////   V  ////////////
//5A---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//   
                                            //CREATING AND DISPLAYING CSE CIRCULAR LIST
     cout<<endl;

             cout<<"                        "<<" CSE CIRCULAR List Display :"<<"                      "<<endl;

    CircularCSEcreate(CSERoll,CSEname,Stubranch1,CSEMarks,5);
    CircularCSEdisplay(CircularCSEFirst);

//5B---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//   
                                          // CREATING AND DISPLAYING ECE CIRCULAR LIST
   
     cout<<endl;

             cout<<"                        "<<" ECE CIRCULAR List Display :"<<"                      "<<endl;

    CircularECEcreate(ECERoll,ECEname,Stubranch2,ECEMarks,5);
    CircularECEdisplay(CircularECEFirst);    
    

   
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//    



    return 0;
}
