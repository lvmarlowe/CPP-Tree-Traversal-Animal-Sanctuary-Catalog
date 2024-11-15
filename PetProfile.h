/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 11: Assignment
10 Nov 2024
This header file defines the PetProfile class which manages
individual pet data and related enums. It requires string
and vector for data management.
-------------------------------------------------- */

#ifndef PET_PROFILE_H
#define PET_PROFILE_H

#include <string>
#include <vector>
using namespace std;

// Enums for pet characteristics
enum class Species { PURRMAID = 1, OCTOPUSS, SHARKITTEN, JELLYKITTY, CRABCAT };
enum class Sex { MALE = 1, FEMALE, OTHER };
enum class Size { TINY = 1, SMALL, MEDIUM, LARGE, GARGANTUAN };
enum class Personality {
    SHY = 1, PLAYFUL, ENERGETIC, LAZY, CURIOUS,
    MISCHIEVOUS, DIVA, GENTLE, CLEVER, ADVENTUROUS
};

class PetProfile {
private:
    const Species species;
    const string name;
    const Sex sex;
    const string color;
    const int ageMonths;
    const Size size;
    const Personality personality;
    vector<string> traits;
    vector<string> needs;
    const string uniqueTrait;
    const string uniqueNeed;

    // Private helper methods
    void initializeTraits();
    void initializeNeeds();

public:

    // Constructors
    PetProfile();
    PetProfile(Species sp, const string& n, Sex s, const string& c,
        int age, Size sz, Personality p,
        const string& uTrait = "", const string& uNeed = "");

    // Getters
    Species getSpecies() const { return species; }
    string getName() const { return name; }
    Sex getSex() const { return sex; }
    string getColor() const { return color; }
    int getAge() const { return ageMonths; }
    Size getSize() const { return size; }
    Personality getPersonality() const { return personality; }
    const vector<string>& getTraits() const { return traits; }
    const vector<string>& getNeeds() const { return needs; }
    string getUniqueTrait() const { return uniqueTrait; }
    string getUniqueNeed() const { return uniqueNeed; }

    // Comparison operator
    bool operator<(const PetProfile& other) const { return name < other.name; }

    // Static factory methods
    static vector<string> getDefaultTraits(Species species);
    static vector<string> getDefaultNeeds(Species species, Size size);
    static vector<string> getUniqueTraitOptions(Species species);
    static vector<string> getUniqueNeedOptions(Species species);
};

// Helper functions
string speciesString(Species species);
string sexString(Sex sex);
string sizeString(Size size);
string personalityString(Personality personality);

#endif