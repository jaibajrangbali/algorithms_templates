#include <stdio.h>
long long int inp[2000009][2],temp[2000009][2],input[2000009][2],x[1000009],y[1000009],out[2000009][2];
void sortx(int uppar,int neche)
{
    for(int r=1;r<=neche-uppar+1;r++)
    {
        inp[r][0]=input[uppar+r-1][0];
        inp[r][1]=input[uppar+r-1][1];
    }
    int n=neche-uppar+1;
    int l=2;
    int up=1,down=l,mid=(l/2)+1;
    while(l/2<=n)
    {
        int up=1,down=l,mid=(l/2)+1;
        while(down<=n)
        {
            int i=1;
            mid=up+(l/2);
            int a=up,b=mid;
            while(i<=l)
            {
                if(a<mid && b<=down)
                {
                    if(inp[b][0]>inp[a][0])
                    {
                        temp[i][0]=inp[a][0];
                        temp[i][1]=inp[a][1];
                        a++;
                    }
                    else
                    {
                        temp[i][0]=inp[b][0];
                        temp[i][1]=inp[b][1];
                        b++;
                    }
                }
                else if(a==mid && b<=down)
                {
                        temp[i][0]=inp[b][0];
                        temp[i][1]=inp[b][1];
                    b++;
                }
                else if(b>down && a<mid)
                {
                        temp[i][0]=inp[a][0];
                        temp[i][1]=inp[a][1];
                    a++;
                }
                i++;
/*                for(int l=1;l<=n;l++)
                {
                    printf("temp%d\n",temp[l]);
                }
                printf("-------------\n");*/
            }
            int c=up;
            for(int j=1;j<=l;j++)
            {
                inp[c][0]=temp[j][0];
                inp[c][1]=temp[j][1];
                c++;
            }
            up=down+1;
            down+=l;
            /*for(int l=1;l<=n;l++)
            {
                printf("%d\n",inp[l]);
            }
            printf("-------------\n");*/
        }
        if(n<down && down<=2*n)
        {
            int i=1;
            mid=up+(l/2);
            int a=up,b=mid;
            while(i<=l)
            {
                if(a<mid && b<=n)
                {
                    if(inp[b][0]>inp[a][0])
                    {
                        temp[i][0]=inp[a][0];
                        temp[i][1]=inp[a][1];
                        a++;
                    }
                    else
                    {
                        temp[i][0]=inp[b][0];
                        temp[i][1]=inp[b][1];
                        b++;
                    }
                }
                else if(a==mid && b<=n)
                {
                        temp[i][0]=inp[b][0];
                        temp[i][1]=inp[b][1];
                    b++;
                }
                else if(b>n && a<mid)
                {
                        temp[i][0]=inp[a][0];
                        temp[i][1]=inp[a][1];
                    a++;
                }
                i++;
                /*for(int l=1;l<=n;l++)
                {
                    printf("temp%d\n",temp[l]);
                }
                printf("-------------\n");*/
            }
            int c=up;
            for(int j=1;j<=l;j++)
            {
                inp[c][0]=temp[j][0];
                inp[c][1]=temp[j][1];
                c++;
            }
            up=down+1;
            down+=l;
            /*for(int l=1;l<=n;l++)
            {
                printf("%d\n",inp[l]);
            }
            printf("-------------\n");*/
        }           

       /* for(int l=1;l<=n;l++)
        {
            printf("%d\n",inp[l]);
        }
        printf("-------------\n");*/
        l=2*l;
    }
    for(int r=1;r<=neche-uppar+1;r++)
    {
        input[uppar+r-1][0]=inp[r][0];
        input[uppar+r-1][1]=inp[r][1];
    }
}

int main()
{
    long long int len,t,k;
    scanf("%lld %lld %lld",&len,&k,&t);
    for(long long int i=1;i<=len;i++)
    {
        scanf("%lld",&input[i][0]);
    }
    long long int sum=0,maxi=len;;
    for(long long int i=len;len-k<i;i--)
    {
        sum+=input[i][0];
    }
    //printf("sum=%d\n",sum);
    long long int maxSum=sum;
    for(long long int i=len-1;k<=i;i--)
    {
        sum=sum-input[i+1][0]+input[i-k+1][0];
    //printf("sum=%d\n",sum);
        if(maxSum<sum)
        {
            maxSum=sum;
            maxi=i;
        }
    }

    //printf("maxSum=%d i=%d\n",maxSum,maxi);
    sortx(maxi-k+1,maxi);
    long long int ans=0;
    for(long long int i=maxi;maxi-t<i;i--)
    {
        ans+=input[i][0];
    }
    printf("%lld\n",ans);
    return 0;
}




