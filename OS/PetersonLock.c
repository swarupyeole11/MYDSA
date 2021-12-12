
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>
#include <time.h>


int N;			
int* levels;   	
int* last;

int check(int id, int i){
	int k;
	for(k=0;k<N;++k)
		if(k!=id && levels[k]>=i)
			break;
	return k!=N;
}

void lock(int id){
	printf("Thread %d requested the lock\n", id);
	int i;
	for(i=0;i<N;++i){
		levels[id] = i;
		last[i] = id;
		while(last[i]==id && check(id, i));
	}
	printf("Thread %d obtained the lock\n", id);	
	
}

void unlock(int id){
	levels[id] = -1;
	printf("Thread %d released the lock\n", id);
}

void* on_thread_start(void* _arg){
	int id = (intptr_t)_arg;
	srand(time(NULL));


	usleep(rand() / 1000);
	
	lock(id);
	printf("Thread %d is inside the critical seciton\n", id);
	unlock(id);
	
	
	usleep(rand() / 1000);

	pthread_exit(NULL);  
    
}

int main(int argc, char const *argv[])
{
	int i;
	printf("No. of processes : ");
	scanf("%d", &N);   
	
	levels = calloc(N, sizeof(int));
	last = calloc(N-1, sizeof(int));


	pthread_t threads[N];

	for(i=0;i<N;++i){
		pthread_create(&threads[i], NULL, on_thread_start, (void*)(intptr_t)i);
		
	}
	

	for(i=0;i<N;++i){
		pthread_join(threads[i], NULL);
		
	}

	free(levels);
	free(last);

	return 0;
}
