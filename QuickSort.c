#include<stdio.h>
#include<stdlib.h>
void quicksort(long long int a[100001],long long int first,long long int last){
	long long int i, j, part, temp;
	if(first<last)
	{
		part=first;
		i=first;
		j=last;
		while(i<j)
		{
			while((a[i]<=a[part])&&(i<last))
			{
				i++;
			}
			while(a[j]>a[part])
			{
				j--;
			}
			if(i<j)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		temp=a[part];
		a[part]=a[j];
		a[j]=temp;
		quicksort(a,first,j-1);
		quicksort(a,j+1,last);
	}
}
int main()
{
	long long int T,i=0;
	printf("How many times do you want to run the program?\n");
	scanf("%lld",&T);
	for(i=0;i<T;i++)
	{
		long long int arr[100001]={0},N,j=0,k=0,l=0;
		printf("Please enter the length of the array\n");
		scanf("%lld",&N);
		printf("Now input the array\n");
		for(j=0;j<N;j++)
		{
			scanf("%lld",&arr[j]);
		}
		quicksort(arr,0,N-1);
		printf("Printed array is :\n");
		for(j=0;j<N;j++)
		{
			printf("%lld ",arr[j]);
		}
		printf("\n");
	}
	return 0;
}

