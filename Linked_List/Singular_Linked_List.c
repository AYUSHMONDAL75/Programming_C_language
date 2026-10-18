#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head = NULL,*ptr,*temp,*prev;
int item,loc,pos,ch;
void insertBeginning() {
    ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Overflow! Memory not available.\n");
    }else{
        printf("Enter value to insert: ");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = head;
        head = ptr;
    }
    printf("%d inserted at the beginning.\n", item);
}
void insertEnd() {
    ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Overflow! Memory not available.\n");
        return;
    }
    printf("Enter value to insert: ");
    scanf("%d", &item);
    ptr->data = item;
    ptr->next = NULL;
    if (head == NULL) {
        head = ptr;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
    }
    printf("%d inserted at the end.\n", item);
}
void insertAnyPos() {
    ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Overflow! Memory not available.\n");
        return;
    }
    printf("Enter value to insert: ");
    scanf("%d", &item);
    printf("Enter position after which to insert: ");
    scanf("%d", &loc);
    temp = head;
    for (int i = 1; i < loc; i++) {
        if (temp == NULL) {
            printf("Position not found.\n");
        }
        temp = temp->next;
    }
    ptr->data = item;
    ptr->next = temp->next;
    temp->next = ptr;
    printf("%d inserted after position %d.\n", item, loc);
}
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
    }
    temp = head;
    head = head->next;
    printf("%d deleted from beginning.\n", temp->data);
    free(temp);
}
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
    }
    temp = head;
    if (head->next == NULL) {
        printf("%d deleted from end.\n", head->data);
        head = NULL;
        free(temp);
    }
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    printf("%d deleted from end.\n", temp->data);
    prev->next = NULL;
    free(temp);
}
void deleteAnyPos() {
    if (head == NULL) {
        printf("List is empty.\n");
    }
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    temp = head;
    if (pos == 1) {
        head = head->next;
        printf("%d deleted from position %d.\n", temp->data, pos);
        free(temp);
    }for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }if (temp == NULL) {
        printf("Position not found.\n");
    }
    prev->next = temp->next;
    printf("%d deleted from position %d.\n", temp->data, pos);
    free(temp);
}
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
    }
    temp = head;
    printf("Linked List elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    while (1) {
        printf("\n..... Linked List Menu .....\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Any Position\n");
        printf("4. Delete from Beginning\n5. Delete from End\n6. Delete from Any Position\n");
        printf("7. Display All Elements\n8. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: insertBeginning(); break;
            case 2: insertEnd(); break;
            case 3: insertAnyPos(); break;
            case 4: deleteBeginning(); break;
            case 5: deleteEnd(); break;
            case 6: deleteAnyPos(); break;
            case 7: display(); break;
            case 8: return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
