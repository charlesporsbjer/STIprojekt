#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* current = *head;
    if (!current) {
        *head = newNode;
    } else {
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to display the linked list
void displayList(Node* head) {
    Node* current = head;
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to delete a node with a specific value
void deleteNode(Node** head, int data) {
    Node* current = *head;
    Node* prev = NULL;
    if (!current) {
        return;
    }
    if (current->data == data) {
        *head = current->next;
        free(current);
        return;
    }
    while (current && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current) {
        prev->next = current->next;
        free(current);
    }
}

// Function to free the memory allocated for the linked list
void freeList(Node* head) {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;

    // Insert nodes at the beginning and end
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 15);
    insertAtEnd(&head, 20);

    // Display the linked list
    printf("Linked List: ");
    displayList(head);

    // Delete node with value 10
    printf("Deleting node with value 10:\n");
    deleteNode(&head, 10);
    displayList(head);

    // Free memory allocated for the linked list
    printf("Freeing memory:\n");
    freeList(head);

    return 0;
}