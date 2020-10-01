#include<stdio.h>
void merge(int arr[],int l, int m,int r,int arr2[]){
        int a[m-l+10],b[r-m+10],c[m-l+10],d[r-m+10];
        int n1=m-l+1, n2=r-m;
        for(int i=0;i<n1;i++){a[i]=arr[l+i];
		c[i]=arr2[l+i];}
        for(int i=0;i<n2;i++){b[i]=arr[m+i+1];
		d[i]=arr2[m+i+1];}
        int x=0,y=0,i=l;
        while(x<n1 && y<n2){
                if(a[x]>b[y]){arr[i]=b[y];
			arr2[i]=d[y];
                        y++;i++;}
                else if(a[x]<b[y]){arr[i]=a[x];
			arr2[i]=c[x];
                        x++;i++;}
		else{
			if(c[x]==d[y]){
				arr[i]=a[x];
				arr2[i]=c[x];
				i++;
				x++;y++;}
			else if(c[x]>d[y]){
				arr[i]=b[y];
				arr2[i]=d[y];
				i++;y++;
				}
			else {
                                arr[i]=a[x];
                                arr2[i]=c[x];
                                i++;x++;
                                }}}
        while(x<n1){
		if(a[x]==a[x-1] && c[x]==c[x-1]){x++;}
		else{	
                arr[i]=a[x];
		arr2[i]=c[x];
                x++;i++;}}
        while(y<n2){
		if(b[y]==b[y-1] && d[y]==d[y-1]){y++;}
		else{
                arr[i]=b[y];
		arr2[i]=d[y];
                y++;i++;}}}

void merges(int arr[],int l,int r,int arr2[]){
        if(l<r){
        int m=l+(r-l)/2;
        merges(arr,l,m,arr2);
        merges(arr,m+1,r,arr2);
        merge(arr,l,m,r,arr2);}}

long long int nc3(int n,int mod){
	long long int ans=((n*(n-1)*(n-2))/6)%mod;
	return ans;}

int main(){
	int n,mod;scanf("%d%d",&n,&mod);
	int a[n],b[n],tb[n],ta[n],ysame[n],xsame[n];
	for(int i=0;i<n;i++){
		scanf("%d%d",&a[i],&b[i]);
		ta[i]=a[i];tb[i]=b[i];}
	merges(a,0,n-1,tb);
	merges(b,0,n-1,ta);
	int w=0,z=0;
	for(int i=0;i<n;i++){
		int c=0;
		while(a[i]==a[i+1]){
			c++;i++;}
		if(c>1){xsame[w]=c;
		w++;}}
	for(int i=0;i<n;i++){
                int c=0;
                while(b[i]==b[i+1]){
                        c++;i++;}
                if(c>1){ysame[z]=c;
                z++;}}
	for(int i=0;i<n;i++){
		printf("%d %d ",a[i],tb[i]);}
	long long int ans=nc3(n,mod);
	for(int i=0;i<w;i++)ans-=nc3(xsame[i],mod);
	for(int i=0;i<z;i++)ans-=nc3(ysame[i],mod);

	while(ans<0)ans+=mod;

	printf("%lld\n",ans);
	return 0;
}

