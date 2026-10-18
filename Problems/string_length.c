#include<stdio.h>

int main()
{
    char str[100];
    int i = 0;

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    // count till newline or end
    while(str[i] != '\0' && str[i] != '\n')
    {
        i++;
    }

    printf("Length of string = %d\n", i);

    return 0;
}
