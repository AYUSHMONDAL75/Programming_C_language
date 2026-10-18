#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *arr;
    int n, i, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int*)malloc(n * sizeof(int));

    if(arr == NULL)
    {
        printf("Memory not allocated\n");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
    }

    printf("Sum = %d\n", sum);

    free(arr);

    return 0;
}
