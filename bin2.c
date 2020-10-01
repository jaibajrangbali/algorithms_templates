#include<stdio.h>
int binary2(int arr[],int a,int l){
        int min=1,max=l;
        int mid=(min+max)/2;
        while(min<=max){
                if(arr[mid]>a)max=mid-1;
                else if(arr[mid]<a)min=mid+1;
		if(arr[max]==a)return max;
                if(arr[mid]==a)return mid;
                if(min>=max && arr[min]<a)return min;
                else if(min>=max && arr[min]>=a)return min-1;
                mid=(min+max)/2;}}
int main(){
        int n,g;scanf("%d",&n);
        int arr[n+1];arr[0]=0;
        for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
        scanf("%d",&g);
        printf("%d\n",binary2(arr,g,n));
        return 0;}


