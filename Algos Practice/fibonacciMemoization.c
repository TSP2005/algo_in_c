#include <stdio.h>

int fibonacci (int n, int a[])
{
    if (a[n] != -1)
    {
        return a[n];
    }
    else
    {
        if (n == 0 || n == 1)
        {
            a[n] = n;
        }
        else
        {
            a[n] = a[n - 1] + a[n - 2];
        }
        return a[n];
    }
}

int main()
{
    int n;
    printf ("Enter the value of n to print the fibonacci series (starting with 0): ");
    scanf("%d", &n);
    int a[n + 1];
    for (int i = 0; i <= n; i++)
    {
        a[i] = -1;
    }  
    printf("The fibonacci series upto %d is: ", n);
    for (int i = 0; i <= n; i++)
    {
        int fib = fibonacci (i, a);
        printf("%d ", fib);
    }
}