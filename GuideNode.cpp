// GuideNode.cpp
/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 11: Assignment
10 Nov 2024
This implementation file contains the functions for the
GuideNode class. It requires sstream for string stream operations
and GuideNode.h for class definition.
-------------------------------------------------- */

#include "GuideNode.h"
#include <sstream>

// Creates node with specified title and description
GuideNode::GuideNode(const string& t, const string& desc)
    : title(t), description(desc) {}

// Returns formatted guide information using preorder traversal
string GuideNode::getPreOrderTraversal(int level) const {
    stringstream result;
    const string DOUBLE_BORDER = Utilities::createBorder(80, '=');
    const string SINGLE_BORDER = Utilities::createBorder(80, '-');

    // Formats current node based on level
    switch (level) {
    case 0: {

        // Root level formatting
        result << DOUBLE_BORDER << "\n";
        result << "SPECIES GUIDE\n";
        result << SINGLE_BORDER << "\n";
        result << description << "\n";
        result << DOUBLE_BORDER << "\n\n";
        break;
    }
    case 1: {

        // Habitat section formatting
        result << "  HABITAT: " << title << "\n";
        result << "  " << DOUBLE_BORDER << "\n";
        result << "  " << description << "\n";
        result << "  " << DOUBLE_BORDER << "\n\n";
        break;
    }
    default: {

        // Species entry formatting
        result << "    SPECIES: " << title << "\n";
        result << "    " << SINGLE_BORDER << "\n";
        istringstream descStream(description);
        string line;
        while (getline(descStream, line)) {
            result << "    " << line << "\n";
        }
        result << "    " << SINGLE_BORDER << "\n\n";
        break;
    }
    }

    // Processes subtrees in preorder
    if (left) {
        result << left->getPreOrderTraversal(level + 1);
    }
    if (right) {
        result << right->getPreOrderTraversal(level + 1);
    }

    return result.str();
}