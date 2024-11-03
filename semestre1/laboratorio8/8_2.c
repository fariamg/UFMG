#include <stdio.h>;

void primos(int m, int *p1, int *p2);

int isPrime(int num);

int main()
{

    int m, p1, p2;
    scanf("%d", m);

    primos(m, &p1, &p2);

    printf("%d\n%d\n", p1, p2);

    return 0;
}

void primos(int m, int *p1, int *p2)
{
    for (int i = m + 1;; i++)
    {
        if (isPrime(i))
        {
            *p1 = i;
            break;
        }
    }
    for (int i = m + 1;; i++)
    {
        if (isPrime(i))
        {
            *p2 = i;
            break;
        }
    }
}

int isPrime(int num)
{
    if (num <= 1)
        return 0;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}