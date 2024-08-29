#include <stdio.h>

void profitsForEachDay (int c, int a[], int p[], int r)
{
    for (int i = 0; i < c; i++)
    {
        p[i] = a[i + 1] - a[i] - r;
    }
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int maxProfit(int c, int p[])
{
    int MSA = p[0];
    int MSF = p[0];
    for (int i = 1; i < c; i++)
    {
        MSF = max(p[i], MSF + p[i]);
        MSA = max(MSA, MSF);
    }
    return MSA;
}

int main()
{
    int n, r;
    printf("Event duration (days): ");
    scanf("%d", &n);
    printf("Rent per day: ");
    scanf("%d", &r);
    int a[n];
    printf("Prices for each day respectively: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The given prices of day 1 through %d are: ", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("The rent per day is: %d\n", r);
    int c = n - 1;
    int p[c];
    profitsForEachDay(c, a, p, r);
    int maxIncome = maxProfit(c, p);
    printf("%d is the max Income possible.", maxIncome);
}