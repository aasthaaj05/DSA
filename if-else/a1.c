#include<stdio.h>
#include<limits.h>
int main (){
    int num,max;
    max=INT_MIN;
    while(scanf("%d",&num)!=EOF){
        if(num>max){
            max=num;
        }
    }
    printf("%d",max);
}s
