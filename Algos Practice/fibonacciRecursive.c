#include <stdio.h>

int fibonacci (int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return fibonacci (n - 1) + fibonacci (n - 2);
    }
}

int main()
{
    int n;
    printf ("Enter the value of n to print the fibonacci series (starting with 0): ");
    scanf("%d", &n);
    printf("The fibonacci series upto %d is: ", n);
    for (int i = 0; i <= n; i++)
    {
        int fib = fibonacci (i);
        printf("%d ", fib);
    }
}