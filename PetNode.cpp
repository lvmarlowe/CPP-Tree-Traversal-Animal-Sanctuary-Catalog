// PetNode.cpp
/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 11: Assignment
10 Nov 2024
This implementation file contains the functions for the
PetNode class. It requires sstream for string stream operations
and PetNode.h for class definition.
-------------------------------------------------- */

#include "PetNode.h"
#include <sstream>

// Creates node with specified pet profile
PetNode::PetNode(const PetProfile& petProfile) : profile(petProfile) {}

// Returns formatted pet information using inorder traversal
string PetNode::getInOrderTraversal() const {
    stringstream result;
    const string DOUBLE_BORDER = Utilities::createBorder(80, '=');
    const string SINGLE_BORDER = Utilities::createBorder(80, '-');

    // Processes left subtree
    if (left) {
        result << left->getInOrderTraversal();
    }

    // Formats current node's information
    result << "  " << DOUBLE_BORDER << "\n";
    result << "  " << profile.getName() << " the " << speciesString(profile.getSpecies()) << "\n";
    result << "  " << SINGLE_BORDER << "\n";

    // Formats basic information section
    result << "      Sex: " << sexString(profile.getSex()) << "      ";

    // Formats age display
    const int age = profile.getAge();
    if (age < 12) {
        result << "Age: " << age << " months      ";
    }
    else {
        const int years = age / 12;
        const int months = age % 12;
        result << "Age: " << years << " year" << (years != 1 ? "s" : "");
        if (months > 0) {
            result << ", " << months << " month" << (months != 1 ? "s" : "");
        }
        result << "      ";
    }
    result << "Size: " << sizeString(profile.getSize()) << "\n";

    // Formats additional characteristics
    result << "      Color: " << profile.getColor() << "\n";
    result << "      Personality: " << personalityString(profile.getPersonality()) << "\n";

    // Formats traits section
    result << "      " << SINGLE_BORDER << "\n";
    result << "      Special Traits:\n";
    for (const auto& trait : profile.getTraits()) {
        result << "      - " << trait << "\n";
    }

    // Formats needs section
    result << "      " << SINGLE_BORDER << "\n";
    result << "      Care Needs:\n";
    for (const auto& need : profile.getNeeds()) {
        result << "      - " << need << "\n";
    }
    result << "\n";

    // Processes right subtree
    if (right) {
        result << right->getInOrderTraversal();
    }

    return result.str();
}