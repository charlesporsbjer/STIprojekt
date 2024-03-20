#include <iostream> 

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        std::cerr << "new error" << std::endl;
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
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
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
        std::cout << "Node with value " << data << " not found in the list." << std::endl;
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
    delete nodeToDelete;
}

// Function to free the memory allocated for the linked list
void freeList(Node* head) {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
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
    std::cout << "Linked List: ";
    displayList(head);

    int dataToDelete;
    std::cout << "Enter the data to delete: ";
    std::cin >> dataToDelete;

    // Delete node using the search function
    deleteNode(&head, dataToDelete);

    // Display the linked list after deletion
    std::cout << "Linked List after deletion: ";
    displayList(head);

    std::cout << "Freeing memory:\n";
    freeList(head);

    return 0;
}