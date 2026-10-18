#include<stdio.h>

int main()
{
    float a, b;
    char op;

    printf("Enter first number: ");
    scanf("%f", &a);
    printf("Enter operator (+ - * /): ");
    scanf(" %c", &op);
    printf("Enter second number: ");
    scanf("%f", &b);

    switch(op)
    {
        case '+':
            printf("%.2f + %.2f = %.2f\n", a, b, a + b);
            break;
        case '-':
            printf("%.2f - %.2f = %.2f\n", a, b, a - b);
            break;
        case '*':
            printf("%.2f * %.2f = %.2f\n", a, b, a * b);
            break;
        case '/':
            if(b == 0)
                printf("Cannot divide by zero\n");
            else
                printf("%.2f / %.2f = %.2f\n", a, b, a / b);
            break;
        default:
            printf("Wrong operator\n");
    }

    return 0;
}
