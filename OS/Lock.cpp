# define N 2   
# define TRUE 1  
# define FALSE 0   
int interested[N] = FALSE;  
int turn;   
voidEntry_Section (int process)   
{  
    int other;   
    other = 1-process;  
    interested[process] = TRUE;  
    turn = process;   
    while (interested [other] ==TRUE && Turn==process); 



}  

void Critical_Section(int process)
{
	printf("The process %d is in critical section \n",process);
}  

voidExit_Section (int process)  
{  
    interested [process] = FALSE;  
}  

int main()
{
   
}