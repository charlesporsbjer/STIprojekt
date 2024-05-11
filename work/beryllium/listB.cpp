#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define the List class
class List {
private:
    vector<string> items;

public:
    // Add an item to the list
    void addItem(string item) {
        items.push_back(item);
    }

    // Remove the last item from the list
    void removeItem() {
        if (!items.empty()) {
            items.pop_back();
        }
    }

    // Edit the item at the given index
    void editItem(int index, string new_item) {
        if (index >= 0 && index < (int)items.size()) {
            items[index] = new_item;
        } else {
            cout << "Index out of range!" << endl;
        }
    }

    // Display all the items in the list
    void displayItems() {
        for (const string& item : items) {
            cout << item << endl;
        }
    }

    // Size of the list
    int size() {
        return items.size();
    }
};

int main() {
    List myList;
    string item;
    // Adding items
    cout << "Add items to the list:\n";
    do {
        
        cout << "Enter item or 'exit' to stop adding: ";
        getline(cin, item);

        if (item != "exit") {
            myList.addItem(item);
        }
    } while (item != "exit");

    // Display the list
    cout << "\nList after adding items:\n";
    myList.displayItems();
    cout << "Size of the list: " << myList.size() << endl;

    // Editing and removing items
    cout << "\nOptions:\n";
    cout << "1. Add item\n";
    cout << "2. Edit item\n";
    cout << "3. Remove item\n";
    cout << "4. Display items\n";
    cout << "5. Exit\n";
    int choice;

    do {
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter item to add: ";
                string new_item;
                getline(cin, new_item);
                myList.addItem(new_item);
                break;
            case 2:
                cout << "Enter the index of the item you want to edit: ";
                int index;
                cin >> index;
                cout << "Enter the new item: ";
                string edit_item;
                getline(cin, edit_item);
                myList.editItem(index, edit_item);
                break;
            case 3:
                myList.removeItem();
                break;
            case 4:
                cout << "\nList after editing/removing items:\n";
                myList.displayItems();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}