#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <wait.h>
#include <limits.h>
#include <fcntl.h>
#include <pthread.h>
#include <inttypes.h>
#include <math.h>

#define _POSIX_C_SOURCE 199309L //required for clock

int* shareMem (size_t size)
{
    key_t mem_key = IPC_PRIVATE;
    int shm_id = shmget(mem_key, size, IPC_CREAT | 0666);
    return (int*)shmat(shm_id, NULL, 0);
}

void insertionsort(int *arr, int start, int end) 
{
	for(int i = start + 1; i < end; i++) {
		int c = i;
		while(c > start && arr[c] < arr[c-1])
		{
			arr[c] = arr[c-1] ^ arr[c] ^ (arr[c-1] = arr[c]);
			c--;
		}
	}
}

int partition(int *arr, int start, int end) 
{
	int i = start + 1;
	int j = end - 1;
	while(1) {
		while(arr[i] <= arr[start] && i < end) {
			i++;
		}
		while(arr[j] > arr[start] && j > start) {
			j--;
		}
		if(i >= j) {
			break;
		}
		arr[j] = arr[i] ^ arr[j] ^ (arr[i] = arr[j]);
	}
	arr[start] = arr[start] ^ arr[j] ^ (arr[j] = arr[start]);
	return j;
}

void quicksort(int *arr, int start, int end, int multiproc)
{
	int size = end - start;
	if(size <= 5) {
		insertionsort(arr, start, end);
		return;
	}
	int p1 = start + rand() % size;
	int p2 = start + rand() % size;
	int p3 = start + rand() % size;
	
	if(arr[p1] > arr[p2]) {
		arr[p1] = arr[p1] ^ arr[p2] ^ (arr[p2] = arr[p1]);
	}
	if(arr[p2] > arr[p3]) {
		arr[p2] = arr[p2] ^ arr[p3] ^ (arr[p3] = arr[p2]);
	}
	if(arr[p1] > arr[p2]) {
		arr[p1] = arr[p1] ^ arr[p2] ^ (arr[p2] = arr[p1]);
	}
	arr[start] = arr[start] ^ arr[p2] ^ (arr[p2] = arr[start]);

	int d = partition(arr, start, end);
	
	if(multiproc == 1) {
		pid_t pid1 = fork();
		if(pid1 == 0) {
			quicksort(arr, start, d, 1);
			_exit(0);
		}
		pid_t pid2 = fork();
		if(pid2 == 0) {
			quicksort(arr, d+1, end, 1);
			_exit(0);
		}
		int status;
		waitpid(pid1, &status, 0);
		waitpid(pid2, &status, 0);
		return;
	}
	quicksort(arr, start, d, 0);
	quicksort(arr, d+1, end, 0);
}

struct arg
{
	int start;
	int end;
	int *arr;
};

void *thread_quicksort(void *ar)
{
	struct arg *args = (struct arg *)ar;
	int start = args->start;
	int end = args->end;
	int *arr = args->arr;
	int size = end - start;
	if(size <= 5) {
		insertionsort(arr, start, end);
		return NULL;
	}
	int p1 = start + rand() % size;
	int p2 = start + rand() % size;
	int p3 = start + rand() % size;
	
	if(arr[p1] > arr[p2]) {
		arr[p1] = arr[p1] ^ arr[p2] ^ (arr[p2] = arr[p1]);
	}
	if(arr[p2] > arr[p3]) {
		arr[p2] = arr[p2] ^ arr[p3] ^ (arr[p3] = arr[p2]);
	}
	if(arr[p1] > arr[p2]) {
		arr[p1] = arr[p1] ^ arr[p2] ^ (arr[p2] = arr[p1]);
	}
	arr[start] = arr[start] ^ arr[p2] ^ (arr[p2] = arr[start]);

	int d = partition(arr, start, end);
	
	struct arg a1;
    a1.start = start;
    a1.end = d;
    a1.arr = arr;
    pthread_t tid1;
    pthread_create(&tid1, NULL, thread_quicksort, &a1);
    
    struct arg a2;
    a2.start = d + 	1;
    a2.end = end;
    a2.arr = arr;
    pthread_t tid2;
    pthread_create(&tid2, NULL, thread_quicksort, &a2);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    return NULL;	
}

void runSorts(int n)
{
    struct timespec ts;
    
    //getting shared memory
    int *arr = shareMem(sizeof(int)*(n+1));
    for(int i = 0 ; i < n; i++) {
    	scanf("%d", &arr[i]);
    }
    int brr[n+1];
    int crr[n+1];
    for(int i = 0; i < n; i++) {
    	brr[i] = arr[i];
    }
    for(int i = 0; i < n; i++) {
    	crr[i] = arr[i];
    }

    printf("Running concurrent quicksort for n = %d\n", n);
    clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
    long double st = ts.tv_nsec/(1e9)+ts.tv_sec;

    //multiprocess mergesort
    quicksort(arr, 0, n, 1);
    
    clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
    long double en = ts.tv_nsec/(1e9)+ts.tv_sec;
    printf("time = %Lf\n", en - st);
    long double t1 = en-st;

    

    printf("Running normal quicksort for n = %d\n", n);
    clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
    st = ts.tv_nsec/(1e9)+ts.tv_sec;

    // normal mergesort
    quicksort(brr, 0, n, 0);    
    
    clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
    en = ts.tv_nsec/(1e9)+ts.tv_sec;
    printf("time = %Lf\n", en - st);
    long double t3 = en - st;
    
    pthread_t tid;
    struct arg a;
    a.start = 0;
    a.end = n;
    a.arr = crr;
    printf("Running threaded quicksort for n = %d\n", n);
    clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
    st = ts.tv_nsec/(1e9)+ts.tv_sec;

    //multithreaded mergesort
    pthread_create(&tid, NULL, thread_quicksort, &a);
    pthread_join(tid, NULL);    
    
    clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
    en = ts.tv_nsec/(1e9)+ts.tv_sec;
    printf("time = %Lf\n", en - st);
    long double t2 = en-st;
    printf("output for concurrent mergesort:");
    for(int i = 0; i < n; i++) {
    	printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("output for normal mergesort:");
    for(int i = 0; i < n; i++) {
    	printf("%d ", brr[i]);
    }
    printf("\n");
    
    printf("output for threaded mergesort:");
	for(int i = 0; i < n; i++) {
    	printf("%d ", crr[i]);
    }
    printf("\n");
    shmdt(arr);
    return;
}

int main(){

    long long int n;
    scanf("%lld", &n);
    runSorts(n);
    return 0;
}
