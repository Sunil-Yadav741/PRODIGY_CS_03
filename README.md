# Task 3: Contact Management Program
## Overview
- The Contact Management Program is a simple console-based application developed in C++. It allows users to manage their contacts by providing options to add new contacts, view the existing contact list, edit contact information, and delete contacts. The contacts can be stored either in memory or saved to a file for persistent storage, ensuring that they are available even after the program is closed and reopened.

## Features
- Add New Contact: Users can add a new contact by entering the name, phone number, and email address.
- View Contacts: The program displays a list of all contacts with their details.
- Edit Contact: Users can select a contact to modify its information.
- Delete Contact: Allows users to remove a contact from the list.
- Persistent Storage: Contacts are saved to a file (contacts.txt), ensuring that the data is retained between sessions.
## How It Works
- Loading Contacts: When the program starts, it loads the contacts from contacts.txt into memory if the file exists.
- Managing Contacts: Users can interact with the program through a menu-driven interface to add, view, edit, or delete contacts.
- Saving Contacts: After any modification (add, edit, delete), the contacts are saved back to the file, ensuring data persistence.
- Exiting the Program: The program runs in a loop until the user chooses to exit.
## Requirements
- C++
