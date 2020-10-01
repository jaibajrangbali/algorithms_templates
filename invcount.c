#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long int ll;
typedef long long unsigned lu;
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define prn printf("\n")
ll arr[500000],l[500000],r[500000];
ll min(ll a,ll b)
{
    if(a>b) return b;
    return a;
}
ll merge(ll start,ll mid,ll end)
{
    ll length = mid - start + 1,invcount = 0;
    for(ll i=start;i<=mid;i++)
    {
        l[i-start] = arr[i];
    }
    for(ll i=mid+1;i<=end;i++)
    {
        r[i-mid-1] = arr[i];
    }
    ll i=0,j=0,k=start;
    while((i<mid-start+1) && (j<end-mid))
    {
        if(l[i]<=r[j])
        {
            arr[k] = l[i];
            i++;
            k++;
        }
        else if(l[i]>r[j])
        {
            invcount += (length - i);
            arr[k] = r[j];
            j++;
            k++;
        }
    }
    while(i<mid - start + 1)
    {
        arr[k] = l[i];
        k++;
        i++;
    }
    while(j<end-mid)
    {
        arr[k]= r[j];
        j++;
        k++;
    }
/*    printf("merging:\n");
    for(int i=0;i<mid-start+1;i++) printf("%d ",l[i]);
    printf("\nand\n");
    for(int i=0;i<end-mid;i++) printf("%d ",r[i]);
    printf("\ninversion count is: %d\n",invcount);*/
    return invcount;
}

ll mergesort(ll start,ll end)
{
    ll mid = (start + end)/2;
    ll ans = 0;
    if(start<end)
    {
        ans+=mergesort(start,mid);
        ans+=mergesort(mid+1,end);
        ans+=merge(start,mid,end);
    }
    return ans;
}

int main()
{
      ll t;
      scl(t);
      while(t--)
      {
          ll n;
          scl(n);
          for(ll i=0;i<n;i++) 
              scl(arr[i]);
          ll ans = mergesort(0,n-1);
          printf("%lld\n",ans);    
      }
}
