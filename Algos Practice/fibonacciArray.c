#include <stdio.h>

void fibonacci (int a[], int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i == 0 || i ==1)
        {
            a[i] = i;
        }
        else
        {
            a[i] = a[i - 1] + a[i - 2];
        }
    }
}

int main()
{
    int n;
    printf ("Enter n: ");
    scanf("%d", &n);
    int a[n + 1];
    fibonacci(a, n);
    printf("The series is: ");
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}