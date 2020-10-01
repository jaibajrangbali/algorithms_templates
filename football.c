#include<stdio.h>
#include<string.h>
int main()
{
  char a[110] = {'\0'};
  int count=1,len,i;
  scanf("%s",a);
  len = strlen(a);
  for(i=1;i<len;++i)
  {
  	if(a[i]==a[i-1])
  		{
  			count += 1;
  			if(count==7)
        {
  			  printf("YES\n");
          return 0;
        }
      }
       else
       {
          count = 1;
       }
       
  	
}
  printf("NO\n");
   return 0;  
}
