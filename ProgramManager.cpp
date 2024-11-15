// ProgramManager.cpp
/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 11: Assignment
10 Nov 2024
This implementation file contains the functions for the
ProgramManager class. It requires iostream for user input/output
and ProgramManager.h for class definition.
-------------------------------------------------- */

#include "ProgramManager.h"
#include <iostream>
#include <limits>

// Validates user input within specified range
int ProgramManager::getValidInput(int min, int max) const {
    string input;
    int choice;

    while (true) {
        getline(cin, input);
        try {
            choice = stoi(input);
            if (choice >= min && choice <= max) {
                return choice;
            }
            cout << "Please enter a number between " << min << " and " << max << ": ";
        }
        catch (const exception&) {
            cout << "Please enter a valid number: ";
        }
    }
}

// Runs main program loop
void ProgramManager::run() {
    displayWelcome();
    bool running = true;

    while (running) {
        displayMenu();
        int choice = getValidInput(1, 3);

        switch (choice) {
        case 1:
            viewSpeciesGuide();
            break;
        case 2:
            viewAvailablePets();
            break;
        case 3:
            running = false;
            break;
        }
    }

    displayExit();
}

// Displays welcome message
void ProgramManager::displayWelcome() const {
    Utilities::displayBoxedContent(
        "Welcome to Magical Sea-Cat Sanctuary!",
        "Where oceanic felines find their forever homes!"
    );
}

// Displays main menu options
void ProgramManager::displayMenu() const {
    const string menuContent =
        "1. View Species Guide\n"
        "2. View Available Pets\n"
        "3. Exit";

    Utilities::displayFormattedSection("Main Menu:", menuContent);
    cout << "\nEnter your choice (1-3): ";
}

// Displays exit message
void ProgramManager::displayExit() const {
    Utilities::displayBoxedContent(
        "Thank you for visiting Magical Sea-Cat Sanctuary!",
        "Swim back soon!"
    );
}

// Displays species guide using preorder traversal
void ProgramManager::viewSpeciesGuide() const {
    cout << "\n" << speciesGuide.displayGuide();
}

// Displays available pets using inorder traversal
void ProgramManager::viewAvailablePets() const {
    cout << "\n" << petCatalog.displayCatalog();
}