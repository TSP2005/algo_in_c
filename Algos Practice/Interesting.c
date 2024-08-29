#include <stdio.h>

int interesting (int a1[], int a2[], int n1, int n2)
{
    int b[n1+ n2];
    int count = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < n1 && j < n2)
    {
        if (a1[i] > a2[j])
        {
            b[k] = a2[j];
            j++;
            count += n1 - i;
        }
        else 
        {
            b[k] = a1[i];
            i++;
        }
        k++;
    }
    return count;
}

int main ()
{
    int n1, n2;
    printf("Enter the size of the arrays: ");
    scanf("%d %d", &n1, &n2);
    int a1[n1], a2[n2];
    printf("Enter the elements of the array 1 (distinct and sorted): ");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &a1[i]);
    }
    printf("Enter the elements of the array 2 (distinct and sorted): ");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &a2[i]);
    }
    printf("the given array 1 is: ");
    for (int i = 0; i < n1; i++)
    {
        printf("%d ", a1[i]);
    }
    printf("\n");
    printf("the given array 2 is: ");
    for (int i = 0; i < n2; i++)
    {
        printf("%d ", a2[i]);
    }
    printf("\n");
    int count = interesting (a1, a2, n1, n2);
    printf("The number of such pairs are %d.\n", count);
}