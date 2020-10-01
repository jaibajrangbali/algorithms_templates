using namespace std;

#include<bits/stdc++.h>

int max(int a,int b){
	if(a>b)return a;
	else return b;
}
void printlongestsubsequence(int arr[],int n){
	unordered_set<int> S;
	int seqstart;
	for(int i=0;i<n;i++)S.insert(arr[i]);
	int ans=0;
	for(int i=0;i<n;i++){
		// check if arr[i]-1 is not present in the set, 
		// i.e. arr[i] is the starting of any sequence.

		if(S.find(arr[i]-1)==S.end()){
			int j=arr[i];
			while(S.find(j)!=S.end())j++;
			if(ans<j-arr[i]){
				ans=j-arr[i];
				seqstart=arr[i];
			}
		}
	}
	cout << ans << endl;
	for(int i=0;i<ans;i++)cout<< seqstart+i<<" ";
	cout << endl;
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)cin >> arr[i];

	printlongestsubsequence(arr,n);
}




unordered_set <int> S;

S.insert()

S.find(val)==S.end()

while(S.find(j)!=S.end())j++;

for(auto const&pair :hm ){
	coutn << pair.first << pair.second;
}