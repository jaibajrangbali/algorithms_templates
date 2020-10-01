#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{   int len, count = 1;
    char a[110];
    scanf("%s",a);
    len = strlen(a);
    for(int i=0;i<len-1;i++)
    {
        if(a[i]!=a[i+1])
        {
          count++;
        }
    }
    
    if(count%2 == 0)
    printf("IGNORE HIM!\n");
    else
    {
     printf("CHAT WITH HER!\n");
    }
    return 0;
}
