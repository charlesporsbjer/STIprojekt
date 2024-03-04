#include <stdio.h> 
#include <string.h>

#define MAX_TASKS 10
#define MAX_NAME_LENGTH 256

char tasks[MAX_TASKS][MAX_NAME_LENGTH];
int taskCount = 0;

void addTask(char* task) {
    if (taskCount < MAX_TASKS) {
        strcpy(tasks[taskCount++], task);
    } else {
        printf("Task list is full.\n");
    }
}

void removeTask(char* task) {
    for (int i = 0; i < taskCount; i++) {
        if (strcmp(tasks[i], task) == 0) {
            for (int j = i; j < taskCount - 1; j++) {
                strcpy(tasks[j], tasks[j + 1]);
            }
            taskCount--;
            return;
        }
    }
    printf("Task not found.\n");
}

void viewTasks() {
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s\n", i + 1, tasks[i]);
    }
}

int main() {
    addTask("Buy groceries");
    addTask("Do laundry");
    addTask("Finish project");

    while (1) {
        printf("\n1. Add task\n2. Remove task\n3. View tasks\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        switch (choice) {
            case 1:
                char task[MAX_NAME_LENGTH] = "";
                printf("Enter a task: ");
                fgets(task, MAX_NAME_LENGTH, stdin);
                // Remove the newline character from the input string
                task[strcspn(task, "\n")] = 0;
                addTask(task);
                break;
            case 2:
                printf("Enter a task to remove: ");
                fgets(task, MAX_NAME_LENGTH, stdin);
                // Remove the newline character from the input string
                task[strcspn(task, "\n")] = 0;
                removeTask(task);
                break;
            case 3:
                viewTasks();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
