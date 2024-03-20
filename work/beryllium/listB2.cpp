#include <iostream>
#include <string>
using namespace std;


struct Node {
    int data;
    string name;
    Node* next;
};


class List {
private:
    Node* head;
    Node* tail;


public:
    // Add a new node to the end of the list
    void addNode(int data, string name) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->name = name;
        newNode->next = NULL;


    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Edit the name of a node
void editNode(int data, string newName) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == data) {
            temp->name = newName;
            break;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Data not found!" << endl;
    }
}

// Remove a node from the list
void removeNode(int data) {
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {
        if (temp->data == data) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }

            if (tail == temp) {
                tail = prev;
            }

            delete temp;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Data not found!" << endl;
    }
}

// Display the list