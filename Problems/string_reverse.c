#include<stdio.h>
#include<string.h>

int main()
{
    char str[100], rev[100];
    int i, len;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    for(i = 0; i < len; i++)
    {
        rev[i] = str[len - 1 - i];
    }
    rev[len] = '\0';

    printf("Reversed string: %s\n", rev);

    return 0;
}
