// GuideNode.h
/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 11: Assignment
10 Nov 2024
This header file defines the GuideNode class for species guide
entries. It requires Node.h for base class functionality,
Utilities.h for formatting, and string for text manipulation.
-------------------------------------------------- */

#ifndef GUIDE_NODE_H
#define GUIDE_NODE_H

#include "Node.h"
#include "Utilities.h"
#include <string>

class GuideNode : public Node {
private:
    const string title;
    const string description;

public:

    // Constructor
    GuideNode(const string& t, const string& desc);

    // Getters
    string getTitle() const { return title; }
    string getDescription() const { return description; }

    // Tree traversal methods
    string getInOrderTraversal() const override { return ""; } // Not used
    string getPreOrderTraversal(int level = 0) const override;
};

#endif