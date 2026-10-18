#include<stdio.h>

// function calls itself
long long power(int base, int exp)
{
    if(exp == 0)
        return 1;
    else
        return base * power(base, exp - 1);
}

int main()
{
    int b, e;

    printf("Enter base: ");
    scanf("%d", &b);
    printf("Enter power: ");
    scanf("%d", &e);

    printf("%d raised to %d = %lld\n", b, e, power(b, e));

    return 0;
}
