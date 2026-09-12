#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string FILE_NAME = "users.txt";

// Check if username already exists in the file
bool isUsernameTaken(const string &username) {
    ifstream file(FILE_NAME);
    string storedUser, storedPass;

    while (file >> storedUser >> storedPass) {
        if (storedUser == username) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

// Register a new user
void registerUser() {
    string username, password;

    cout << "Enter new username: ";
    cin >> username;

    if (isUsernameTaken(username)) {
        cout << "Error: Username already exists. Try a different one.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream file(FILE_NAME, ios::app); // append mode
    file << username << " " << password << "\n";
    file.close();

    cout << "Registration successful!\n";
}

// Login existing user
void loginUser() {
    string username, password;
    string storedUser, storedPass;
    bool found = false;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file(FILE_NAME);
    while (file >> storedUser >> storedPass) {
        if (storedUser == username && storedPass == password) {
            found = true;
            break;
        }
    }
    file.close();

    if (found)
        cout << "Login successful! Welcome, " << username << ".\n";
    else
        cout << "Error: Invalid username or password.\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- Login & Registration System ---\n";
        cout << "1. Register\n2. Login\n3. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 3);

    return 0;
}
