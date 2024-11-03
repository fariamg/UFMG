#include <stdio.h>;
#include <stdlib.h>;

void media(double vet[], int n, int *i);

int main()
{

    int i;
    int n;
    scanf("%d", &n);

    double vet[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &vet[i]);
    }

    media(vet, n, &i);

    printf("%d\n", i);

    return 0;
}

void media(double vet[], int n, int *i)
{
    double sum = 0;
    for (int j = 0; j < n; j++)
    {
        sum += vet[j];
    }

    double average = sum / n;

    double minDifference = fabs(vet[0] - average);
    *i = 0;

    for (int j = 0; j < n; j++)
    {
        double diference = fabs(vet[j] - average);
        if (diference < minDifference)
        {
            minDifference = diference;
            *i = j;
        }
    }
}