#include<stdio.h>
#include<string.h>

int main()
{
    int i,t;
    char c[100005],s[100005];
    scanf("%d",&t);
    while(t--)
    {
        int flag=1;
        int count[100]={0},c2[100]={0};
        scanf("%s %s",c,s);
        if(strlen(c)!=strlen(s))
            printf("No\n");
        else
        {
            for(i=0;i<strlen(c);i++)
            {
                count[(int)c[i]-48]++;
                c2[(int)s[i]-48]++;
            }
            for(i=0;i<100;i++)
            {
                if(count[i]!=c2[i])
                    flag=0;
            }
            if(flag==1)
                printf("Yes\n");
            else 
                printf("No\n");
        }
        

    }
}
