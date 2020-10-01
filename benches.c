#include<stdio.h>
void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;}

void bubbleSort(int *arr, int n){
   int i, j;
   for (i = 0; i < n-1; i++){
       for (j = 0; j < n-i-1; j++){
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);}}}
int main(){
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	int l=m;
	int list[n],listmax[n],a;
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		list[i]=a;}
	bubbleSort(list,n);
	for (int i = 0; i < n; i++){
		listmax[i] = list[i];}
	while(m--){
		for(int j=1;j<n;j++){
			if(list[0]>list[j]){swap(&list[0],&list[j]);break;}
			}
			
		list[0]++;}
	while(l--){
		listmax[n-1]++;}
	printf("%d %d\n",list[0],listmax[n-1]);
	return 0;
}
