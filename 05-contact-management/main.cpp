
#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

int main() {
    vector<Contact> contacts;
    int choice;

    do {
        cout << "\n===== CONTACT MANAGEMENT =====\n";
        cout << "1. Add Contact\n";
        cout << "2. View All Contacts\n";
        cout << "3. Search Contact by Name\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input!\n";
            return 0;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            Contact c;

            cout << "Enter name: ";
            getline(cin, c.name);

            cout << "Enter phone number: ";
            getline(cin, c.phone);

            cout << "Enter email: ";
            getline(cin, c.email);

            contacts.push_back(c);
            cout << "Contact added successfully!\n";
        }
        else if (choice == 2) {
            if (contacts.empty()) {
                cout << "No contacts available.\n";
            } else {
                for (int i = 0; i < contacts.size(); i++) {
                    cout << "\nContact " << i + 1 << "\n";
                    cout << "Name: " << contacts[i].name << "\n";
                    cout << "Phone: " << contacts[i].phone << "\n";
                    cout << "Email: " << contacts[i].email << "\n";
                }
            }
        }
        else if (choice == 3) {
            string searchName;
            bool found = false;

            cout << "Enter name to search: ";
            getline(cin, searchName);

            for (const Contact& c : contacts) {
                if (c.name == searchName) {
                    cout << "\nContact found!\n";
                    cout << "Name: " << c.name << "\n";
                    cout << "Phone: " << c.phone << "\n";
                    cout << "Email: " << c.email << "\n";
                    found = true;
                }
            }

            if (!found) {
                cout << "Contact not found.\n";
            }
        }
        else if (choice == 4) {
            cout << "Goodbye!\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
