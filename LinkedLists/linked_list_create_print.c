#include<stdio.h>
#include<conio.h>
typedef structNode{
    int data;
    struct Node* next;
}
Node;
Node* createNode(int data){
    Node* NEW=(Node*)malloc(size of(Node));
    if (NEW==NULL){
        printf("Failed memory allocation");
        return 1;
    }
    NEW->data=data;
    NEW->next=NULL;
    return NEW;
}
void insertStart(Node** head, int data){
    Node* NEW=createNode(data);
    NEW->next=*head;
    *head=NEW;
}
void printList(Node *head){
    Node* temp=head;
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}
int main(){
    Node* head=NULL;
    insertStart(&head,10);
    insertStart(&head,20);
    insertStart(&head,30);
    printList(head);
    return 0;
}
}