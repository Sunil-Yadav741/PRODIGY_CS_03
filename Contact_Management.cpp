#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

// Function to load contacts from a file
vector<Contact> loadContacts(const string& filename) {
    vector<Contact> contacts;
    ifstream file(filename);
    if (file.is_open()) {
        Contact contact;
        while (getline(file, contact.name) && getline(file, contact.phone) && getline(file, contact.email)) {
            contacts.push_back(contact);
        }
        file.close();
    }
    return contacts;
}

// Function to save contacts to a file
void saveContacts(const vector<Contact>& contacts, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& contact : contacts) {
            file << contact.name << endl;
            file << contact.phone << endl;
            file << contact.email << endl;
        }
        file.close();
    }
}

// Function to add a new contact
void addContact(vector<Contact>& contacts) {
    Contact newContact;
    cout << "Enter name: ";
    getline(cin, newContact.name);
    cout << "Enter phone number: ";
    getline(cin, newContact.phone);
    cout << "Enter email address: ";
    getline(cin, newContact.email);

    contacts.push_back(newContact);
    cout << "Contact added successfully." << endl;
}

// Function to view all contacts
void viewContacts(const vector<Contact>& contacts) {
    cout << "Contact List:" << endl;
    for (size_t i = 0; i < contacts.size(); ++i) {
        cout << "Contact " << i + 1 << ":" << endl;
        cout << "Name: " << contacts[i].name << endl;
        cout << "Phone: " << contacts[i].phone << endl;
        cout << "Email: " << contacts[i].email << endl;
        cout << "---------------------------" << endl;
    }
}

// Function to edit an existing contact
void editContact(vector<Contact>& contacts) {
    int index;
    viewContacts(contacts);
    cout << "Enter the contact number to edit: ";
    cin >> index;
    cin.ignore();

    if (index > 0 && index <= contacts.size()) {
        cout << "Editing contact " << index << endl;
        cout << "Enter new name (leave blank to keep current): ";
        string newName;
        getline(cin, newName);
        if (!newName.empty()) contacts[index - 1].name = newName;

        cout << "Enter new phone number (leave blank to keep current): ";
        string newPhone;
        getline(cin, newPhone);
        if (!newPhone.empty()) contacts[index - 1].phone = newPhone;

        cout << "Enter new email address (leave blank to keep current): ";
        string newEmail;
        getline(cin, newEmail);
        if (!newEmail.empty()) contacts[index - 1].email = newEmail;

        cout << "Contact updated successfully." << endl;
    } else {
        cout << "Invalid contact number." << endl;
    }
}

// Function to delete a contact
void deleteContact(vector<Contact>& contacts) {
    int index;
    viewContacts(contacts);
    cout << "Enter the contact number to delete: ";
    cin >> index;
    cin.ignore();

    if (index > 0 && index <= contacts.size()) {
        contacts.erase(contacts.begin() + index - 1);
        cout << "Contact deleted successfully." << endl;
    } else {
        cout << "Invalid contact number." << endl;
    }
}

// Main function
int main() {
    vector<Contact> contacts = loadContacts("contacts.txt");
    int choice;

    do {
        cout << "Contact Management System" << endl;
        cout << "1. Add a new contact" << endl;
        cout << "2. View contacts" << endl;
        cout << "3. Edit a contact" << endl;
        cout << "4. Delete a contact" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character after entering choice

        switch (choice) {
            case 1:
                addContact(contacts);
                saveContacts(contacts, "contacts.txt");
                break;
            case 2:
                viewContacts(contacts);
                break;
            case 3:
                editContact(contacts);
                saveContacts(contacts, "contacts.txt");
                break;
            case 4:
                deleteContact(contacts);
                saveContacts(contacts, "contacts.txt");
                break;
            case 5:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}