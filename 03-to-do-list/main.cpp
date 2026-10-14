
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> tasks;
    int choice;
    string task;

    do {
        cout << "\n===== TO-DO LIST =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter your task: ";
                getline(cin, task);
                tasks.push_back(task);
                cout << "Task added successfully!\n";
                break;

            case 2:
                if (tasks.empty()) {
                    cout << "No tasks added yet.\n";
                } else {
                    cout << "\nYour Tasks:\n";
                    for (int i = 0; i < tasks.size(); i++) {
                        cout << i + 1 << ". " << tasks[i] << "\n";
                    }
                }
                break;

            case 3:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
