// SpeciesGuide.h
/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 11: Assignment
10 Nov 2024
This header file defines the SpeciesGuide class for managing
species guide tree. It requires GuideNode.h for node management
and memory for smart pointers.
-------------------------------------------------- */

#ifndef SPECIES_GUIDE_H
#define SPECIES_GUIDE_H

#include "GuideNode.h"
#include <memory>

class SpeciesGuide {
private:
    shared_ptr<GuideNode> root;

    // Private helper methods for tree construction
    void buildGuideTree();
    void buildShallowWaterBranch(const shared_ptr<GuideNode>& parent);
    void buildDeepWaterBranch(const shared_ptr<GuideNode>& parent);

public:
    // Constructor
    SpeciesGuide();

    // Public interface methods
    string displayGuide() const;
    bool isEmpty() const { return root == nullptr; }
};

#endif