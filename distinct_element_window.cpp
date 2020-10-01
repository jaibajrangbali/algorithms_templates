using namespace std;
#include<bits/stdc++.h>
#include<map>


void printDistEle(int arr[], int k, int n){
	map<int,int> hm;
	int dist=0;
	int i=0;
	for(;i< k;i++){
		if(hm[arr[i]]==0) dist++;
		hm[arr[i]]++;
	}

	cout << dist << endl;
	for( ; i< n;i++){
		hm[arr[i-k]]--;
		if(hm[arr[i-k]]==0)dist--;

		if(hm[arr[i]]==0)dist++;
		


		cout << dist << endl;
	}
}
int main(){
	int n,k;
	cin >> n >> k;
	int arr[n];
	for(int i=0;i<n;i++)cin >> arr[i];

	printDistEle(arr,k,n);
}