// PetNode.h
/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 11: Assignment
10 Nov 2024
This header file defines the PetNode class for pet entries.
It requires Node.h for base class functionality and
PetProfile.h for pet data management.
-------------------------------------------------- */

#ifndef PET_NODE_H
#define PET_NODE_H

#include "Node.h"
#include "PetProfile.h"
#include "Utilities.h"

class PetNode : public Node {
private:
    const PetProfile profile;

public:

    // Constructor
    explicit PetNode(const PetProfile& petProfile);

    // Getter
    const PetProfile& getProfile() const { return profile; }

    // Tree traversal methods
    string getInOrderTraversal() const override;
    string getPreOrderTraversal(int level = 0) const override { return ""; } // Not used
};

#endif