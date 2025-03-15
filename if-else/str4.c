/*
 Write a function to find gcd() of 2 numbers. 
 Write a function to find lcm() of 2 numbers
*/

#include <stdio.h>
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int num1, num2, result1, result2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    result1= lcm(num1, num2);
    result2=gcd(num1, num2);    
    printf("LCM %d\n", result1);
    printf("GCD %d\n", result2);
    return 0;
}

