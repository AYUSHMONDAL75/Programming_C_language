#include<stdio.h>

int main()
{
    int x = 10;
    int *p;

    p = &x;

    printf("Value of x = %d\n", x);
    printf("Address of x = %p\n", &x);
    printf("p stores address = %p\n", p);
    printf("Value at p = %d\n", *p);

    // changing value using pointer
    *p = 50;
    printf("New value of x = %d\n", x);

    return 0;
}
