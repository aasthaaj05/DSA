#include <stdio.h>
#include<math.h>

 int main()
 {
     int i,n,a,sum,sum1,sum2;
     sum1=0;
     sum2=0;
     a=1;
     scanf("%d",&n);
     for(i=1;i<=n;i++)
         {
             if(i==1){
                 printf("1");
                 sum1=sum1+1;
             }else{
                 if(i%2==0){
                     printf("-%d",a);
                     sum2=sum2+a;
                 }else{
                     printf("+%d",a);
                     sum1=sum1+a;
            }
             }
             a=a+2;
         }
         sum=sum1-sum2;
         printf("\n%d",sum);
 }
 
 
 
