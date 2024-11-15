/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 11: Assignment
10 Nov 2024
This header file defines the PetCatalog class for managing
the pet catalog binary tree. It requires PetNode.h for node
management and vector for data storage.
-------------------------------------------------- */

#ifndef PET_CATALOG_H
#define PET_CATALOG_H

#include "PetNode.h"
#include <memory>
#include <vector>

class PetCatalog {
private:
    shared_ptr<PetNode> root;

    // Private helper methods
    void insertPet(shared_ptr<PetNode>& node, const PetProfile& pet);
    void loadSamplePets();
    string getRandomOption(const vector<string>& options);

public:
    // Constructor
    PetCatalog();

    // Public interface methods
    string displayCatalog() const;
    bool isEmpty() const { return root == nullptr; }
    void addPet(const PetProfile& pet);
};

#endif