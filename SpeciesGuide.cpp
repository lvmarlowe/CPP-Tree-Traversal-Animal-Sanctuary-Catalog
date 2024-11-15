// SpeciesGuide.cpp
/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 11: Assignment
10 Nov 2024
This implementation file contains the functions for the
SpeciesGuide class. It requires GuideNode.h for node management
and SpeciesGuide.h for class definition.
-------------------------------------------------- */

#include "SpeciesGuide.h"

// Constructs guide and builds tree structure
SpeciesGuide::SpeciesGuide() {
    buildGuideTree();
}

// Creates main guide tree structure
void SpeciesGuide::buildGuideTree() {
    root = make_shared<GuideNode>(
        "Magical Sea-Cat Species Guide",
        "Our unique hybrids combine feline grace with marine adaptations"
        );

    buildShallowWaterBranch(root);
    buildDeepWaterBranch(root);
}

// Creates shallow water branch of guide tree
void SpeciesGuide::buildShallowWaterBranch(const shared_ptr<GuideNode>& parent) {
    auto shallowWater = make_shared<GuideNode>(
        "Shallow Water",
        "Species adapted to coastal waters, reefs, and tidal pools"
        );

    auto purrmaid = make_shared<GuideNode>(
        "Purrmaid",
        "Graceful swimmers combining cat grace with mermaid tails.\n"
        "Known for: Pearl-making abilities and melodious sea shanties\n"
        "Habitat: Coastal waters and coral reefs\n"
        "Special traits: Natural musicians, excellent swimmers"
        );

    auto crabcat = make_shared<GuideNode>(
        "Crabcat",
        "Armored felines with impressive climbing abilities.\n"
        "Known for: Shell collection and sideways running\n"
        "Habitat: Rocky shores and tide pools\n"
        "Special traits: Enhanced armor, expert climbers"
        );

    parent->setLeft(shallowWater);
    shallowWater->setLeft(purrmaid);
    shallowWater->setRight(crabcat);
}

// Creates deep water branch of guide tree
void SpeciesGuide::buildDeepWaterBranch(const shared_ptr<GuideNode>& parent) {
    auto deepWater = make_shared<GuideNode>(
        "Deep Water",
        "Species evolved for life in deeper oceanic waters"
        );

    auto sharkitten = make_shared<GuideNode>(
        "Sharkitten",
        "Powerful swimmers with gentle personalities.\n"
        "Known for: Playful nature despite fearsome appearance\n"
        "Habitat: Open ocean and deep reefs\n"
        "Special traits: Excellent hunters, surprisingly gentle"
        );

    auto octopuss = make_shared<GuideNode>(
        "Octopuss",
        "Eight-tentacled felines with remarkable intelligence.\n"
        "Known for: Problem-solving and escape artistry\n"
        "Habitat: Deep water caves and crevices\n"
        "Special traits: Master puzzle-solvers, shape-shifters"
        );

    auto jellykitty = make_shared<GuideNode>(
        "Jellykitty",
        "Bioluminescent beauties with translucent forms.\n"
        "Known for: Glowing displays and graceful movement\n"
        "Habitat: Mid-water zones\n"
        "Special traits: Light shows, floating meditation"
        );

    parent->setRight(deepWater);
    deepWater->setLeft(octopuss);
    deepWater->setRight(sharkitten);
    octopuss->setRight(jellykitty);
}

// Returns formatted guide using preorder traversal
string SpeciesGuide::displayGuide() const {
    if (!root) {
        return "Species guide is not available.\n";
    }
    return root->getPreOrderTraversal();
}