#include<stdio.h>
int main()
{
    long long int a[100000],n,counter,temp,i;
    a[0]=1;
    counter=0;
    printf("Enter the number to Find Factorial: ");
    scanf("%lld",&n);
    for(; n>=2; n--)
    {
        temp=0;
        for(i=0; i<=counter; i++)
        {
            temp=(a[i]*n)+temp;
            a[i]=temp%10;
            temp=temp/10;
        }
        while(temp>0)
        {
            a[++counter]=temp%10;
            temp=temp/10;
        }
    }
    for(i=counter; i>=0; i--)
        printf("%lld",a[i]);
    return 0;
}
~                                         
