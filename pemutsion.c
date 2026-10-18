#include <stdio.h>
#include <string.h>
#define max 100
char str[max];
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
void permutation(int left, int right) {
    if (left == right) {
        printf("[%s] ", str);
        return;
    }
    for (int i = left; i <= right; i++) {
        swap(&str[left], &str[i]);
        permutation(left + 1, right);
        swap(&str[left], &str[i]);
    }
}
int main() {
    printf("Enter a string: ");
    scanf("%99s", str);
    int n = strlen(str);
    permutation(0, n - 1);
    return 0;
}