#include<stdio.h>

int main()
{
    int n, rev = 0, digit;

    printf("Enter a number: ");
    scanf("%d", &n);

    while(n != 0)
    {
        digit = n % 10;
        rev = rev * 10 + digit;
        n = n / 10;
    }

    printf("Reverse = %d\n", rev);

    return 0;
}
