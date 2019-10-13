#include<stdio.h>
#include<math.h>

void fact(int n)
{
        long long int ar[1201]={0};
        int i,x=1,j,temp=0;
        ar[1149]=1;
        ar[1150]=5;
        while(x<=n)
            {
                temp=0;
                for(i=1149;i>0;i--)
                {
                    ar[i]*=x;
                    ar[i]+=temp;
                    temp=ar[i]/1000000000000000;
                    ar[i]=ar[i]%1000000000000000;
                }
                x++;
            }       
        for(i=1;i<=1149;i++)
        {
            if(ar[i]!=0)
            {
                if(ar[i-1]==0)
                    printf("%lld",ar[i]);
                else
                {
                        long long int n1=ar[i];
                        int count=0;
                        while(n1)
                        {
                            n1/=10;
                            count++;
                        }
                        for(j=1;j<=15-count;j++)
                                printf("0");
                        printf("%lld",ar[i]);                  
                }
                if(ar[i+1]==0)
                {
                    break;
                }
                
            }

        }
        for(j=i+1;j<=1149;j++)
        {
            printf("000000000000000");
        }
        printf("\n");
    
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        fact(n);
    }
    return 0;
}
