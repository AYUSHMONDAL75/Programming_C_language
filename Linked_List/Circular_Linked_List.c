#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;
struct node *newnode;
int item;
void insertAtBeginning() {
    printf("Enter value to insert: ");
    scanf("%d", &item);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    if (head == NULL) {
        head = tail = newnode;
        newnode->next = head;
    } else {
        newnode->next = head;
        head = newnode;
        tail->next = head;
    }
    printf("%d inserted at beginning.\n", item);
}
void insertAtEnd() {
    printf("Enter value to insert: ");
    scanf("%d", &item);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    if (head == NULL) {
        head = tail = newnode;
        newnode->next = head;
    } else {
        tail->next = newnode;
        tail = newnode;
        tail->next = head;
    }
    printf("%d inserted at end.\n", item);
}
void insertAtPosition() {
    int pos, count = 1; //here use for only this function
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty. Use insert at beginning.\n");
        return;
    }
    printf("Enter position to insert: ");
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &item);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        tail->next = head;
        printf("%d inserted at position %d.\n", item, pos);
        return;
    }while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    if (temp == tail) {
        tail = newnode;
    }
    printf("%d inserted at position %d.\n", item, pos);
}
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    int deleted = head->data;
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        tail->next = head;
    }
    printf("%d deleted from beginning.\n", deleted);
}
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    int deleted = tail->data;
    if (head == tail) {
        head = tail = NULL;
    } else {
        struct node *temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        tail = temp;
        tail->next = head;
    }
    printf("%d deleted from end.\n", deleted);
}
void deleteFromPosition() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    int pos, count = 1; // This is also use for this funtion
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    if (pos == 1) {
        deleteFromBeginning();
        return;
    }
    struct node *temp = head;
    struct node *prev = NULL;
    while (count < pos && temp->next != head) {
        prev = temp;
        temp = temp->next;
        count++;
    }if (temp == head) {
        printf("Invalid position.\n");
        return;
    }
    prev->next = temp->next;
    if (temp == tail) {
        tail = prev;
    }
    printf("%d deleted from position %d.\n", temp->data, pos);
}
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;
    printf("Circular Linked List elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
int main() {
    int ch;
    printf("\n.....Circular Linked List Menu.....");
    printf("\n1. Insert at Beggining\n2. Insert at End\n3. Insert at Any Position");
    printf("\n4. Deleted from Beggining\n5. Deleted from End\n6. Deleted from Any Position");
    printf("\n7. Display\n8. Exit");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: insertAtBeginning(); break;
            case 2: insertAtEnd(); break;
            case 3: insertAtPosition(); break;
            case 4: deleteFromBeginning(); break;
            case 5: deleteFromEnd(); break;
            case 6: deleteFromPosition(); break;
            case 7: display(); break;
            case 8: printf("Goodbye!\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
