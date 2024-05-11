#include <iostream> 
#include <vector>
#include <string>

using namespace std;

class ToDoList {
private:
    vector<string> tasks;

public:
    void addTask(const string& task) {
        tasks.push_back(task);
    }

    void viewTasks() {
        for (int i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }

    void deleteTask(int taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
        } else {
            cout << "Invalid task number." << endl;
        }
    }
};

int main() {
    ToDoList todo;
    int choice;

    while (true) {
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string task;
                cout << "Enter task: ";
                cin.ignore();
                getline(cin, task);
                todo.addTask(task);
                break;
            }
            case 2: {
                todo.viewTasks();
                break;
            }
            case 3: {
                int taskNumber;
                cout << "Enter task number to delete: ";
                cin >> taskNumber;
                todo.deleteTask(taskNumber);
                break;
            }
            case 4: {
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
            }
        }

        cout << endl;
    }

    return 0;
}