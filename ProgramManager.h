// ProgramManager.h
/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 11: Assignment
10 Nov 2024
This header file defines the ProgramManager class which manages
program flow and user interface. It requires SpeciesGuide.h and
PetCatalog.h for core functionality.
-------------------------------------------------- */

#ifndef PROGRAM_MANAGER_H
#define PROGRAM_MANAGER_H

#include "SpeciesGuide.h"
#include "PetCatalog.h"
#include "Utilities.h"
#include <memory>

class ProgramManager {
private:
    SpeciesGuide speciesGuide;
    PetCatalog petCatalog;

    // Private UI methods
    void displayMenu() const;
    void displayWelcome() const;
    void displayExit() const;

    // Private functionality methods
    void viewSpeciesGuide() const;
    void viewAvailablePets() const;
    int getValidInput(int min, int max) const;

public:
    // Main program loop
    void run();
};

#endif