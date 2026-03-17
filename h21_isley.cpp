#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to display inventory
void displayInventory(const vector<string>& inventory) {
    cout << "\n--- Inventory ---\n";
    for (int i = 0; i < inventory.size(); i++) {
        cout << inventory[i] << endl;
    }
}

// Function to search for an item
void searchItem(const vector<string>& inventory) {
    string search;
    cout << "\nEnter item to search: ";
    cin.ignore(); // clear input buffer
    getline(cin, search);

    bool found = false;

    for (int i = 0; i < inventory.size(); i++) {
        if (inventory[i] == search) {
            cout << "Item: " << search << " found in index " << i << "." << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Item: " << search << " not found." << endl;
    }
}

int main() {
    // Feature 2: Initialize inventory
    vector<string> inventory = {"sword", "gold key", "apple", "shield", "health potion", "mysterious flask", "pouch of herbs"};

    int choice;

    do {
        // Feature 1: Menu
        cout << "\n=== Adventure Inventory Menu ===\n";
        cout << "1. View Inventory\n";
        cout << "2. Search for Item\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayInventory(inventory);
                break;

            case 2:
                searchItem(inventory);
                break;

            case 3:
                cout << "Ending adventure\n";
                break;

            default:
                cout << "Alas, that was invalid. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}