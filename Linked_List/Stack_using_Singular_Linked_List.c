#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
    struct node* prev;
};
struct node* top = NULL;
struct node* ptr;
int item;
void push() {
    printf("Enter item to insert: ");
    scanf("%d", &item);
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = item;
    ptr->next = top;
    ptr->prev = NULL;
    if (top != NULL)
        top->prev = ptr;
    top = ptr;
    printf("%d inserted into the stack\n", item);
}
void pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("%d deleted from the stack\n", top->data);
    ptr = top;
    top = top->next;
    if (top != NULL)
        top->prev = NULL;
}
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    ptr = top;
    printf("Stack elements are: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int main() {
    int choice;
    printf("\n.....Stack Operation Menu.....");
    printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: printf("Exiting program.\n"); return 0;
            default: printf("Invalid choice!!\n");
        }
    }
}
