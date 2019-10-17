#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    long long int l,r,l1,r1;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lld %lld", &l,&r);
        double d=0.00;
        l1=l;
        r1=r;
        int i=99,j=99,c1[100]={0},c2[100]={0},x,y,m,flag=1;
        if(l==r)
            d=r;
        else 
            {   
                d=0.00; 
                while(l1)
                {
                    c1[j]=l1%2;
                    l1/=2;
                    j--;
                }
                while(r1)
                {
                    c2[i]=r1%2;
                    r1/=2;
                    i--;                    
                }
                i++;
                j++;
                m=i;
                for(x=i;x<100;x++)
                {
                    if(c2[x]==1 && c1[x]==0)
                    {
                        y=x;
                        break;
                    }
                }
                for(x=y;x<100;x++)
                {
                    if(c2[x]==0)
                        flag=0;
                }
                for(x=y;x<100;x++)
                {
                    c2[x]=1;
                }
                if(flag==1)
                    c2[y]=1;
                if(flag==0)
                    c2[y]=0;
                /*for(x=i;x<100;x++)
                    printf("%d",c2[x]);
                printf("\n");*/
                for(x=m;x<100;x++)
                {
                    if(c2[x]==1)
                        d+=pow(2,99-x);
                }
            }
            printf("%lld\n",(long long int)d);
    }
}