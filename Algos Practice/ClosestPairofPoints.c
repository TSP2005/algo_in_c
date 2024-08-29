#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <math.h>

typedef struct point 
{
    float x;
    float y;
}point;

void mergex (int n, point Px[], int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = start;
    point b[n];
    while (i <= mid && j <= end)
    {
        if (Px[i].x > Px[j].x)
        {
            b[k] = Px[j];
            j++;
        }
        else
        {
            b[k] = Px[i];
            i++;
        }
        k++;
    }
    while (i <= mid)
    {
        b[k] = Px[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        b[k] = Px[j];
        j++;
        k++;
    }
    for (int p = start; p <= end; p++)
    {
        Px[p] = b[p];
    }
}

void mergeSortx (int n, point Px[], int start, int end)
{
    if (start < end)
    {
        int mid = start + ((end - start) / 2);
        mergeSortx (n, Px, start, mid);
        mergeSortx (n, Px, mid + 1, end);
        mergex (n, Px, start, mid, end);
    }
}

void mergey (int n, point Py[], int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = start;
    point b[n];
    while (i <= mid && j <= end)
    {
        if (Py[i].y > Py[j].y)
        {
            b[k] = Py[j];
            j++;
        }
        else
        {
            b[k] = Py[i];
            i++;
        }
        k++;
    }
    while (i <= mid)
    {
        b[k] = Py[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        b[k] = Py[j];
        j++;
        k++;
    }
    for (int p = start; p <= end; p++)
    {
        Py[p] = b[p];
    }
}

void mergeSorty (int n, point Py[], int start, int end)
{
    if (start < end)
    {
        int mid = start + ((end - start) / 2);
        mergeSorty (n, Py, start, mid);
        mergeSorty (n, Py, mid + 1, end);
        mergey (n, Py, start, mid, end);
    }
}

float distance (point p1, point p2)
{
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

void closestAmong (point p1, point p2, point p3, point pair[], float * leastDistance)
{
    if (distance (p1, p2) < distance (p2, p3))
        {
            if (distance (p1, p3) < distance (p1, p2))
            {
                float d = distance (p1, p3);
                if (d < * leastDistance)
                {
                    * leastDistance = d;
                    pair [0] = p1;
                    pair [1] = p3;
                }
            }
            else
            {
                float d = distance (p1, p2);
                if (d < * leastDistance)
                {
                    * leastDistance = d;
                    pair [0] = p1;
                    pair [1] = p2;
                }
            }
        }
        else
        {
            if (distance (p1, p3) < distance (p3, p2))
            {
                float d = distance (p1, p3);
                if (d < * leastDistance)
                {
                    * leastDistance = d;
                    pair [0] = p1;
                    pair [1] = p3;
                }
            }
            else
            {
                float d = distance (p2, p3);
                if (d < * leastDistance)
                {
                    * leastDistance = d;
                    pair [0] = p2;
                    pair [1] = p3;
                }
            }
        }
}

void crossingPair (point Px[], point Py[], int start, int mid, int end, point pair[], float * leastDistance)
{
    int n = end - start + 1;
    for (int i = 0; i < n; i++)
    {
        if ((Py[i].x > Px[mid].x - * leastDistance) && (Py[i].x < Px[mid].x + * leastDistance))
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((Py[j].x > Px[mid].x - * leastDistance) && (Py[j].x < Px[mid].x + * leastDistance) && (Py[j].y < Py[i].y + * leastDistance))
                {
                    float d = distance (Py[i], Py[j]);
                    if (d < * leastDistance)
                    {
                        * leastDistance = d;
                        pair[0] = Py[i];
                        pair[1] = Py[j];
                    }
                }
            }
        }
    }
}

void findingClosestPair (point Px[], point Py[], int start, int end, point pair[], float * leastDistance)
{
    int n = end - start + 1;
    if (n < 2)
    {
        printf("Atleast 2 points are required.\n");
        exit(0);
    }
    else if (n == 2)
    {
        float d = distance (Px[start], Px[end]);
        if (d < * leastDistance)
        {
            * leastDistance = d;
            pair [0] = Px[start];
            pair [1] = Px[end];
        }
    }
    else if (n == 3)
    {
        closestAmong (Px[start], Px[start + 1], Px[end], pair, leastDistance);
    }
    else
    {
        int mid = start + ((end - start) / 2);
        findingClosestPair (Px, Py, start, mid, pair, leastDistance);
        findingClosestPair (Px, Py, mid + 1, end, pair, leastDistance);
        crossingPair (Px, Py, start, mid, end, pair, leastDistance);
    }
}

int main ()
{
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);
    point P[n];
    printf("Enter the coordinates (x, y) of the %d points.\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Point %d\n", i + 1);
        printf("x coordinate: ");
        scanf("%f", &(P[i].x));
        printf("y coordinate: ");
        scanf("%f", &(P[i].y));
    }
    printf ("The given points are\n");
    for (int i = 0; i < n; i++)
    {
        printf ("(%.2f, %.2f)\n", P[i].x, P[i].y);
    }
    point Px[n], Py[n];
    for (int i = 0; i < n; i++)
    {
        Px[i] = P[i];
        Py[i] = P[i];
    }
    mergeSortx (n, Px, 0, n - 1);
    mergeSorty (n, Py, 0, n - 1);
    point pair[2];
    float leastDistance = FLT_MAX;
    findingClosestPair (Px, Py, 0, n - 1, pair, &leastDistance);
    printf("The closest pair is (%.2f, %.2f), (%.2f, %.2f)\n", pair[0].x, pair[0].y, pair[1].x, pair[1].y);
    printf("The distance between them is %f units.\n", leastDistance);
    return 0;
}