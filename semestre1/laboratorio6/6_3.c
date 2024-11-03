#include <stdio.h>
#include <stdlib.h>

int prime(unsigned long int number);
unsigned long int sumPrimes(int n);

int main()
{
    int n;
    while(scanf("%d", &n) != EOF) {
        printf("%lu\n", sumPrimes(n));
    }
    return 0;
}

int prime(unsigned long int number)
{
    if (number < (unsigned int) 2) return -1; 
    for (unsigned long int i = 2; (unsigned int) i * i <= number; i++) 
    {
        if (number % i == 0)
        {
            return 0; 
        }
    }
    return 1; 
}

unsigned long int sumPrimes(int n)
{
    unsigned long int sum = 0;
    unsigned long int count = 0;
    unsigned long int i = 2;
    
    while (count < n)
    {
        if (prime(i))
        {
            sum += i;
            count++;
        }
        i++;
    }
    return sum;
}