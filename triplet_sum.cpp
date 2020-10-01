using namespace std;
#include<bits/stdc++.h>
void printtriplet(int arr[], int k){
	// for(int i=0;i< n-2;i++){

	// 	for(int j=i+1;j< n-1;j++){

	// 		for(int k=j+1;k< n;k++){
	// 			if(arr[i]+arr[j]+arr[k] == k){
	// 				cout<< arr[i] <<" "<< arr[j] <<" "<<arr [k];
	// 			}
	// 		}
	// 	}
	// }
	int l,r;
	for(int i=0;i < n-2;i++){
		l=i+1;
		r=n-1;
		while(l<r){

			if(arr[i]+arr[l]+arr[r] == k){
				cout<< arr[i] <<" "<< arr[l++] <<" "<<arr [r--];
			}
			else if(arr[i]+arr[l]+arr[r] > k){
				r--;
			}
			else{
				l++;
			}
		}
	}

	// we can reduce one loop from finding different group by using this l
	// r technique.
}
int main(){
	int n, k;
	cin << n << k;
	int arr[n];
	for(int i=0; i< n;i++){
		cin >> arr[i];
	}

	printtriplet(arr,k);
}