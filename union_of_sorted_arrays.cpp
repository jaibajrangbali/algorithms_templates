using namespace std;
#include<bits/stdc++.h>


void printUnion(int arr1[], int arr2[], int n, int m){
	int i=0,j=0;

	while(i<n && j<m){
		if(arr1[i]<arr2[j]){
			cout << arr1[i++] << " ";
		}
		else if(arr1[i]>arr2[j]){
			cout << arr2[j++] << " ";
		}
		else{
			cout<< arr2[j++] << " ";
			i++;
		}
	}

	while(i<n){
			cout << arr1[i++] << " ";
	}
	while(j<m){
			cout << arr2[j++] << " ";
	}
}
int main(){
	int n, m;
	cin >> n >> m;
	int arr1[n];
	int arr2[m];
	for( int i=0; i < n;i ++){
		cin >> arr1[i];
	}
	for( int i=0; i < m;i ++){
		cin >> arr2[i];
	}

	printUnion(arr1,arr2,n,m);
}