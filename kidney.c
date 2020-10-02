#include <stdio.h>
long long int in[1000000],temp[1000000];
int count=0;
void merge(int start,int end)
{
    if(start==end)
    {
        return;
    }
    int mid=((start+end)/2)+1;
    int max=end-start+1;
    int x=start,y=mid;
    for(int i=0;i<max;i++)
    {
        if(x<mid&&y<=end)
        {
            if(in[x]<=in[y])
            {
                temp[i]=in[x];
                x++;
            }
            else if(in[y]<in[x])
            {
                count+=mid-x;
                temp[i]=in[y];
                y++;
            }
        }
        else if(x==mid)
        {
            for(int j=i;j<max;j++)
            {
                count+=mid-x;
                temp[j]=in[y];
                y++;
            }
            break;
        }
        else if(y==end+1)
        {
            for(int j=i;j<max;j++)
            {
                temp[j]=in[x];
                x++;
            }
            break;
        }
    }
    int j=start;
    for(int i=0;i<max;i++)
    {
        in[j]=temp[i];
        j++;
    }
}

void mergesort(int start,int end)
{
    if(start==end)
        return;
    int mid=(start+end)/2;
    mergesort(start,mid);
    mergesort(mid+1,end);
    merge(start,end);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        count=0;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&in[i]);
        }
        mergesort(0,n-1);
        printf("%d\n",!(count%2));
    }
}

