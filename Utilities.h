// Utilities.h
/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 11: Assignment
10 Nov 2024
This header file defines utility functions for consistent
formatting throughout the program. It requires string and
iostream for string manipulation and output operations.
-------------------------------------------------- */

#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <iostream>
using namespace std;

class Utilities {
public:

    // Formatting methods
    static string createBorder(int length = 80, char borderChar = '=');
    static void displayFormattedSection(const string& title,
        const string& content);
    static void displayBoxedContent(const string& title,
        const string& content);
};

#endif