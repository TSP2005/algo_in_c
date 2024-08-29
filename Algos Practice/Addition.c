#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 501
#define M 502

int length (char n[])
{
    return strlen(n);
}

void add (char num1[], char num2[], char sum[])
{
    int n1 = length(num1);
    int n2 = length(num2);
    int n = (n1 > n2) ? n1 : n2;
    int carry = 0;
    for (int i = 0; i < n; i++)
    {
        int digit1 = (i < n1) ? (num1[n1 - 1 - i] - '0') : 0;
        int digit2 = (i < n2) ? (num2[n2 - 1 - i] - '0') : 0;
        int sum_digit = digit1 + digit2 + carry;
        carry = sum_digit / 10;
        sum[i] = (sum_digit % 10) + '0';
    }
    if (carry > 0)
    {
        sum[n] = carry + '0';
        n++;
    }
    sum[n] = '\0';
    char temp;
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        temp = sum[i];
        sum[i] = sum[j];
        sum[j] = temp;
    }
}

int main ()
{
    char num1[N];
    char num2[N];
    char sum[M];
    printf("Enter the numbers to be added\n");
    scanf("%s %s", num1, num2);
    printf("The given numbers are\n%s\n%s\n", num1, num2);
    add (num1, num2, sum);
    printf("The sum is %s", sum);
    return 0;
}