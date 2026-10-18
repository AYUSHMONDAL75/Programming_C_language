#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
struct node *tail=NULL;
struct node *newnode;
int item,loc,ch;
void iab(){
    printf("Enter item: ");
    scanf("%d",&item);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->next=head;
    newnode->prev=NULL;
    if(head==NULL){
        head=tail=newnode;
    }else{
        head->prev=newnode;
        head=newnode;
    }
    printf("%d inserted at beginning",item);
}
void iae(){
    printf("Enter item: ");
    scanf("%d",&item);
    newnode=(struct node*)malloc(sizeof(struct node*));
    newnode->data=item;
    newnode->next=NULL;
    if(tail!=NULL){
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;
    }else{
        newnode->prev=NULL;
        head=tail=newnode;
    }
    printf("%d inserted at end",item);
}
void iap(){
    printf("Enter position: ");
    scanf("%d",&loc);
    printf("Enter item: ");
    scanf("%d",&item);
    if(loc<=1 || head==NULL){
        iab();
        return;
    }
    struct node *temp=head;
    for (int i=1;i<loc-1 && temp->next!=NULL;i++){
        temp=temp->next;
    }if(temp->next=NULL){
        iae();
        return;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next->prev=newnode;
    temp->next=newnode;
    printf("%d inserted into %d position",item,loc);
}
void dfb(){
    if(head==NULL){
        printf("empty");
        return;
    }if(head==tail){
        head=tail=NULL;
    }else{
        head=head->next;
        head->prev=NULL;
    }
    printf("%d deleted from beginning",head->data);
}
void dfe(){
    if(tail==NULL){
        printf("empty");
        return;
    }if(head==tail){
        head=tail=NULL;
    }else{
        tail->next=NULL;
        tail=tail->prev;
    }
    printf("%d deleted from end",tail->data);
}
void dfap(){
    if(head==NULL){
        printf("Empty");
        return;
    }
    printf("Enter position to deleted: ");
    scanf("%d",&loc);
    if(loc<=1){
        dfb();
        return;
    }
    struct node *temp=head;
    for(int i=1;i<loc-1 && temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("out of range");
        return;
    }
    if(temp==tail){
        dfe();
        return;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    printf("%d deleted from position %d",temp->data,loc);
    }
void display(){
    if(head==NULL){
        printf("Empty");
    }else{
        newnode=head;
        printf("All elements are: ");
    }while(newnode!=NULL){
        printf("%d ",newnode->data);
        newnode=newnode->next;
    }
}
int main(){
    printf("\n.....Double Linked List Menu.....");
    printf("\n1. Insert at Beggining\n2. Insert at End\n3. Insert at Any Position");
    printf("\n4. Deleted from Beggining\n5. Deleted from End\n6. Deleted from Any Position");
    printf("\n7. Display\n8. Exit");
    while(1){
        printf("\nPlease enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: iab(); break;
            case 2: iae(); break;
            case 3: iap(); break;
            case 4: dfb(); break;
            case 5: dfe(); break;
            case 6: dfap(); break;
            case 7: display(); break;
            case 8: return 0;
            default: printf("INVALID CHOICE!!!");
        }
    }
    return 0;
}
