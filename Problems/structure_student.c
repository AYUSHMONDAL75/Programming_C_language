#include<stdio.h>

struct student
{
    int roll;
    char name[30];
    float marks;
};

int main()
{
    struct student s[20];
    int n, i;

    printf("How many students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d\n", i + 1);
        printf("Roll no: ");
        scanf("%d", &s[i].roll);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }

    printf("\nStudent details\n");
    for(i = 0; i < n; i++)
    {
        printf("%d  %s  %.2f\n", s[i].roll, s[i].name, s[i].marks);
    }

    return 0;
}
