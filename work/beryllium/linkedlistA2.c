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
    if (!newNode) {
        perror("malloc error");
        exit(1);
    }
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

// Function to search for a node with specific data in the linked list
Node* searchNode(Node* head, int data) {
    Node* current = head;
    while (current) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete a node with a specific value. Now uses the search function.
void deleteNode(Node** head, int data) {
    Node* nodeToDelete = searchNode(*head, data);
    if (!nodeToDelete) {
        printf("Node with value %d not found in the list.\n", data);
        return;
    }

    Node* prev = NULL;
    Node* current = *head;
    if (current == nodeToDelete) {
        *head = current->next;
    } else {
        while (current->next && current->next != nodeToDelete) {
            prev = current;
            current = current->next;
        }
        if (current) {
            prev->next = current->next;
        }
    }
    free(nodeToDelete);
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

    int dataToDelete;
    printf("Enter the data to delete: ");
    scanf("%d", &dataToDelete);

    // Delete node using the search function
    deleteNode(&head, dataToDelete);

    // Display the linked list after deletion
    printf("Linked List after deletion: ");
    displayList(head);

    printf("Freeing memory:\n");
    freeList(head);

    return 0;
}