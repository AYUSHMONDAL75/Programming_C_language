#include<stdio.h>

int main()
{
    int i, n;
    long long fact = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    if(n < 0)
    {
        printf("Factorial of negative number not possible\n");
        return 0;
    }

    for(i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    printf("Factorial of %d is %lld\n", n, fact);

    return 0;
}
