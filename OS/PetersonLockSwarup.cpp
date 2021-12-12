#include<bits/stdc++.h>
using namespace std;

#define True 1
#define False 0

int flag[2];  
int turn;

void entry_Section_code (int process);
void Critical_Section(int process);
void exit_Section_code (int process);

void entry_Section_code (int process){  
    int other;
	cout<<"..Process"<<" "<<process<<" Ready to Enter Critical Section .."<<endl;
    other = 1-process;  
    flag[process] = True;  
    turn = other;
	if(flag [other] == True && turn==other){
        cout<<"..Process"<<" "<<process<<" !Busy Waiting since the process "<<other<<" is in Critical Section!"<<endl;
	}   
	if(flag [other] != True || turn!=other){
		Critical_Section(process);
	}
  
}  


void Critical_Section(int process){
	
    cout<<"..Process"<<" "<<process<<" Present In The Critical Section .."<<endl;
}  


void exit_Section_code (int process){  
	 
    cout<<"..Process"<<" "<<process<<" Execution Done In Critical Section Process Completed .."<<endl;
	flag [process] = False; 
}


int main(){
	flag[0]=flag[1]=False;
     
	cout<<endl;
    cout<<"..Displaying That The Program satisfies PROGRESS ..."<<endl<<endl;
	entry_Section_code(0);
	exit_Section_code(0);
	entry_Section_code(0);
	exit_Section_code(0);
    cout<<"\n";

	cout<<"..Displaying That The Program satisfies MUTUAL EXCLUSION  ..."<<endl<<endl;
	entry_Section_code(0);
	entry_Section_code(1);
	exit_Section_code(0);
	entry_Section_code(1);
	exit_Section_code(1);
	cout<<endl;
}
