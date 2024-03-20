#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the linked list
void insert_at_beginning(struct node **head_ref, int data) {
    struct node *new_node = create_node(data);

    // If the list is empty, new_node will become the head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // Otherwise, make the new node point to the old head and update the head reference
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to traverse the linked list and print the elements
void traverse(struct node *head) {
    struct node *current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Driver code
int main() {
    struct node *head = NULL;  // Initialize the head of the linked list as NULL

    // Create and insert nodes into the linked list
    insert_at_beginning(&head, 10);
    insert_at_beginning(&head, 20);
    insert_at_beginning(&head, 30);
    insert_at_beginning(&head, 40);

    printf("Traversing the linked list: \n");
    traverse(head);

    return 0;
}