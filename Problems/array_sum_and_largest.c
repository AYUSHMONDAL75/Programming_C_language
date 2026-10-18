#include<stdio.h>

int main()
{
    int arr[50], n, i;
    int sum = 0, max, min;

    printf("How many elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    max = arr[0];
    min = arr[0];

    for(i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        if(arr[i] > max)
            max = arr[i];
        if(arr[i] < min)
            min = arr[i];
    }

    printf("Sum = %d\n", sum);
    printf("Largest = %d\n", max);
    printf("Smallest = %d\n", min);

    return 0;
}
