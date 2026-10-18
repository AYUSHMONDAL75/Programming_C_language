#include<stdio.h>
#include<string.h>

int main()
{
    char s1[50], s2[50], s3[100];

    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);

    // copy
    strcpy(s3, s1);
    printf("After copy, s3 = %s\n", s3);

    // concatenate
    strcat(s3, s2);
    printf("After concatenation, s3 = %s\n", s3);

    // compare
    if(strcmp(s1, s2) == 0)
        printf("Both strings are same\n");
    else
        printf("Strings are not same\n");

    return 0;
}
