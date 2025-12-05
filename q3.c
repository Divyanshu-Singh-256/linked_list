//WAP to search a node at any position in the linked List 
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void insert(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}
int searchAtPosition(int position) {
    struct Node* temp = head;
    for (int i = 0; i < position; i++) {
        if (temp == NULL) {
            printf("Position out of bounds\n");
            return -1; // Indicate not found
        }
        temp = temp->next;
    }
    if (temp != NULL) {
        return temp->data;
    } else {
        printf("Position out of bounds\n");
        return -1; // Indicate not found
    }
}
void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    insert(10);
    insert(20);
    insert(30);
    display();
    int position = 1;
    int result = searchAtPosition(position);
    if (result != -1) {
        printf("Element at position %d is %d\n", position, result);
    }
    return 0;
}