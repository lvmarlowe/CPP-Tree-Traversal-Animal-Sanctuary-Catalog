/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 11: Assignment
10 Nov 2024
This header file defines the base Node interface for the binary
tree implementation. It requires memory for smart pointers and
string for text manipulation.
-------------------------------------------------- */

#ifndef NODE_H
#define NODE_H

#include <memory>
#include <string>
using namespace std;

class Node {
protected:
    shared_ptr<Node> left;
    shared_ptr<Node> right;

public:

    // Constructor/Destructor
    Node() : left(nullptr), right(nullptr) {}
    virtual ~Node() = 0;

    // Getters/Setters
    shared_ptr<Node> getLeft() const { return left; }
    shared_ptr<Node> getRight() const { return right; }
    void setLeft(const shared_ptr<Node>& l) { left = l; }
    void setRight(const shared_ptr<Node>& r) { right = r; }

    // Pure virtual tree traversal methods
    virtual string getInOrderTraversal() const = 0;
    virtual string getPreOrderTraversal(int level = 0) const = 0;
};

inline Node::~Node() = default;

#endif