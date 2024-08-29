#include <stdio.h>
#include <string.h>

#define N 501
#define M 1002

int main()
{
    char num1[N];
    char num2[N];
    printf("Enter the 2 numbers: ");
    scanf("%s %s", num1, num2);
    printf("The given numbers are\n%s\n%s\n", num1, num2);
    char result[M];
    multiply (num1, num2, result);
    printf("The product is\n%s", result);
}