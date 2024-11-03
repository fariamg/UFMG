#include <stdio.h>
#include <stdlib.h>

int prime(unsigned long int n);

int main()
{
    unsigned long int n;

    while(scanf("%lu", &n) != EOF) {
        printf("%d \n", prime(n));
    }
    return 0;
}

int prime(unsigned long int n)
{
    if (n < 2) return -1; 

    for (int i = 2; i * i <= n; i++) 
    {
        if (n % i == 0)
        {
            return 0; 
        }
    }
    return 1; 
}
