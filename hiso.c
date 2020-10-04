#include <stdio.h>
long long int his[2][100005],stack[100005][2],c[100005][5],head=-1;
void push(long long int a,long long int i)
{
    stack[++head][0]=a;
    stack[head][1]=i;
}
void pop()
{
    if(head>=0)
    {
        head--;
    }
}
int main()
{
    while(1)
    {
        for(int i=0;i<100005;i++)
        {
            his[0][i]=0;
            his[1][i]=0;
            stack[i][0]=0;
            stack[i][1]=0;
            c[i][0]=0;
            c[i][1]=0;
            c[i][2]=0;
            c[i][3]=0;
            c[i][4]=0;
        }
        long long int n;
        scanf("%lld",&n);
        if(n==0)
        {
            break;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&his[0][i]);
        }
        if(n==1)
        {
            printf("%lld\n",his[0][1]);
        }
        else
        {
            long long int count=1;
            push(his[0][1],1);
            c[1][0]=his[0][1];
            c[1][1]=1;
            int i=2;
            for( i=0;i<=n;i++)
            {
                if(head==-1)
                { 
                    push(his[0][i],++count);
                    c[count][0]=his[0][i];
                    c[count][1]=i;
                }
                else if(head>=0&&his[0][i]>stack[head][0])
                {
                    push(his[0][i],++count);
                    c[count][0]=his[0][i];
                    c[count][1]=i;
                }
                else if(head>=0&&his[0][i]<stack[head][0])
                {
                    while(head>=0&&his[0][i]<stack[head][0])
                    {
                        c[stack[head][1]][2]=i;
                        pop();
                    }
                    if(head>=0&&his[0][i]==stack[head][0])
                    {
                        his[1][i]=1;
                    }
                    else
                    {
                        push(his[0][i],++count);
                        c[count][0]=his[0][i];
                        c[count][1]=i;
                    }
                }
                else 
                {
                    his[1][i]=1;
                }
            }
            while(head>=0)
            {
                c[stack[head][1]][2]=i;
                pop();
            }
            /*    for(int i=0;i<=count;i++)
                  {
                  printf("%lld %lld %lld\n",c[i][0],c[i][1],c[i][2]);
                  }
                  for(int i=1;i<=n;i++)
                  {
                  printf("%lld ",his[1][i]);
                  }
                  printf("\n");
                  */    long long int ct=count;
            for(int i=n;i>=0;i--)
            {
                if(head==-1 && his[1][i]==0)
                { 
                    push(his[0][i],count);
                    c[count--][3]=i;
                }
                else if(head>=0&&his[0][i]>stack[head][0] && his[1][i]==0)
                {
                    push(his[0][i],count);
                    c[count--][3]=i;
                }
                else if(head>=0&&his[0][i]<stack[head][0])
                {
                    while(head>=0&&his[0][i]<stack[head][0])
                    {
                        c[stack[head][1]][4]=i;
                        pop();
                    }
                    if(head>=0&&his[0][i]==stack[head][0])
                    {
                        his[1][i]=1;
                    }
                    else if(his[1][i]==0)
                    {
                        push(his[0][i],count);
                        c[count--][3]=i;
                    }
                }
                else 
                {
                    his[1][i]=1;
                }
            }
            while(head>=0)
            {
                c[stack[head][1]][4]=0;
                pop();
            }
                for(int i=0;i<=ct;i++)
                  {
                  printf("%lld %lld %lld %lld %lld\n",c[i][0],c[i][1],c[i][2],c[i][3],c[i][4]);
                  }
                  for(int i=1;i<=n;i++)
                  {
                  printf("%lld ",his[1][i]);
                  }
                  printf("\n");
                    long long int max=-1;
            for(int i=1;i<=ct;i++)
            {
                long long int area=c[i][0]*(c[i][2]-c[i][1]+c[i][3]-c[i][4]-1);
                if(area>max)
                {
                    max=area;
                }
            }
            printf("%lld\n",max);
        }
    }
}





















