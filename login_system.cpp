#include <iostream>
#include <fstream>
using namespace std;

// Check if username already exists
bool userExists(string username) {
    ifstream file("users.txt");
    string user, pass;

    while (file >> user >> pass) {
        if (user == username) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// Register function
void registerUser() {
    string username, password;

    cout << "\n--- Registration ---\n";
    cout << "Enter username: ";
    cin >> username;

    // Validation
    if (username.length() < 3) {
        cout << "❌ Username must be at least 3 characters\n";
        return;
    }

    if (userExists(username)) {
        cout << "❌ Username already exists!\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    if (password.length() < 3) {
        cout << "❌ Password must be at least 3 characters\n";
        return;
    }

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "✅ Registration successful!\n";
}

// Login function
void loginUser() {
    string username, password;
    string user, pass;
    bool found = false;

    cout << "\n--- Login ---\n";
    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");

    while (file >> user >> pass) {
        if (user == username && pass == password) {
            found = true;
            break;
        }
    }

    file.close();

    if (found) {
        cout << "✅ Login successful! Welcome " << username << endl;
    } else {
        cout << "❌ Invalid username or password!\n";
    }
}

// Main function
int main() {
    int choice;

    do {
        cout << "\n===== LOGIN SYSTEM =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "❌ Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}
