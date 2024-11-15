// Utilities.cpp
/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 11: Assignment
10 Nov 2024
This implementation file contains the functions for the
Utilities class. It requires Utilities.h for class definition.
-------------------------------------------------- */

#include "Utilities.h"

// Creates border string with specified length and character
string Utilities::createBorder(int length, char borderChar) {
    return string(length, borderChar);
}

// Displays content in section with title and borders
void Utilities::displayFormattedSection(const string& title,
    const string& content) {
    cout << createBorder() << "\n";
    cout << title << "\n";
    cout << createBorder(80, '-') << "\n";
    cout << content << "\n";
    cout << createBorder() << "\n";
}

// Displays content in box
void Utilities::displayBoxedContent(const string& title,
    const string& content) {
    cout << createBorder() << "\n";
    cout << title << "\n";
    cout << createBorder(80, '-') << "\n";
    cout << content << "\n";
    cout << createBorder() << "\n\n";
}