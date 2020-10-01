#include<stdio.h>
int main()
{   
   int i,j,k,l,m;
   int str1[20],str2[20],str3[20],str4[20],str5[20];
    for(i=0;i<5;i++)
           scanf("%d",&str1[i]);
    for(j=0;j<5;j++)
           scanf("%d",&str2[j]);
   for(k=0;k<5;k++)
           scanf("%d",&str3[k]);
    for(l=0;l<5;l++)
           scanf("%d",&str4[l]);
    for(m=0;m<5;m++)
           scanf("%d",&str5[m]);

     if(str1[0]==1 || str1[4]==1 || str5[0]==1 || str5[4]==1)
                  printf("4\n");
   if(str1[1]==1 || str1[3]==1 || str5[1]==1 || str5[3]==1 || str2[0]==1 || str2[4]==1 || str4[0]==1 || str4[4]==1)
                  printf("3\n");
    if(str1[2]==1 || str5[2]==1 || str2[1]==1 || str2[3]==1 || str4[1]==1 || str4[3]==1 || str3[0]==1 || str3[4]==1)
                  printf("2\n");
    if(str2[2]==1 || str3[1]==1 || str3[3]==1 || str4[2]==1)
                 printf("1\n");
     if(str3[2]==1)
                  printf("0\n");

return 0;
  }

