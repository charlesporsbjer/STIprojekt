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
    void displayList() {
        Node* temp = head;

        cout << "Linked List: " << endl;
        while (temp != NULL) {
            cout << temp->data << " " << temp->name << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    List myList;

    int choice, data, newData, editData;
    string newName;

    do {
        cout << "1. Add Node" << endl;
        cout << "2. Edit Node" << endl;
        cout << "3. Remove Node" << endl;
        cout << "4. Display List" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data and name for the new node: ";
            cin >> data >> newName;
            myList.addNode(data, newName);
            break;
        case 2:
            cout << "Enter data to edit: ";
            cin >> editData;
            cout << "Enter new name: ";
            cin >> newName;
            myList.editNode(editData, newName);
            break;
        case 3:
            cout << "Enter data to remove: ";
            cin >> data;
            myList.removeNode(data);
            break;
        case 4:
            myList.displayList();
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 5);

    cout << "Bye!" << endl;
    return 0;
}