/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 11: Assignment
10 Nov 2024
This implementation file contains the functions for the
PetProfile class. It requires PetProfile.h for class definition.
-------------------------------------------------- */

#include "PetProfile.h"

// Creates default profile with safe values
PetProfile::PetProfile()
    : species(Species::PURRMAID),
    name("Unnamed"),
    sex(Sex::OTHER),
    color("Unknown"),
    ageMonths(0),
    size(Size::MEDIUM),
    personality(Personality::PLAYFUL),
    uniqueTrait(""),
    uniqueNeed("") {
    initializeTraits();
    initializeNeeds();
}

// Creates profile with specified characteristics
PetProfile::PetProfile(Species sp, const string& n, Sex s, const string& c,
    int age, Size sz, Personality p,
    const string& uTrait, const string& uNeed)
    : species(sp),
    name(n),
    sex(s),
    color(c),
    ageMonths(age),
    size(sz),
    personality(p),
    uniqueTrait(uTrait),
    uniqueNeed(uNeed) {
    initializeTraits();
    initializeNeeds();
}

// Initializes traits vector with defaults and unique trait
void PetProfile::initializeTraits() {
    traits.clear();
    traits.reserve(3);

    auto defaultTraits = getDefaultTraits(species);
    traits = move(defaultTraits);

    if (!uniqueTrait.empty()) {
        traits.emplace_back(uniqueTrait);
    }
}

// Initializes needs vector with defaults and size-specific needs
void PetProfile::initializeNeeds() {
    needs.clear();
    needs.reserve(5);

    auto defaultNeeds = getDefaultNeeds(species, size);
    needs = move(defaultNeeds);

    if (!uniqueNeed.empty()) {
        needs.emplace_back(uniqueNeed);
    }

    if (size == Size::GARGANTUAN) {
        needs.emplace_back("Olympic-sized aquarium");
        needs.emplace_back("Industrial-strength filters");
        needs.emplace_back("Heavy-duty toys and reinforced structures");
    }
}

// Returns default traits for each species
vector<string> PetProfile::getDefaultTraits(Species species) {
    vector<string> traits;
    traits.reserve(2);

    switch (species) {
    case Species::PURRMAID:
        traits.emplace_back("Sings sea shanties");
        traits.emplace_back("Makes pearls from hairballs");
        break;
    case Species::OCTOPUSS:
        traits.emplace_back("Multitasking belly rubs");
        traits.emplace_back("Ink spray when startled");
        break;
    case Species::SHARKITTEN:
        traits.emplace_back("Gentle nibbler");
        traits.emplace_back("Loves tuna cake");
        break;
    case Species::JELLYKITTY:
        traits.emplace_back("Glows when happy");
        traits.emplace_back("Floating naps");
        break;
    case Species::CRABCAT:
        traits.emplace_back("Sideways zoomies");
        traits.emplace_back("Shell decorating");
        break;
    }

    return traits;
}

// Returns default needs based on species and size
vector<string> PetProfile::getDefaultNeeds(Species species, Size size) {
    vector<string> needs;
    needs.reserve(2);

    switch (species) {
    case Species::PURRMAID:
        needs.emplace_back("Daily grooming");
        needs.emplace_back("Singing practice");
        break;
    case Species::OCTOPUSS:
        needs.emplace_back("Puzzle toys");
        needs.emplace_back("Multiple scratching posts");
        break;
    case Species::SHARKITTEN:
        needs.emplace_back("Tooth care");
        needs.emplace_back("Regular exercise");
        break;
    case Species::JELLYKITTY:
        needs.emplace_back("Specialized tank");
        needs.emplace_back("Gentle handling");
        break;
    case Species::CRABCAT:
        needs.emplace_back("Shell maintenance");
        needs.emplace_back("Climbing structures");
        break;
    }

    return needs;
}

// Returns unique trait options for each species
vector<string> PetProfile::getUniqueTraitOptions(Species species) {
    vector<string> traits;
    traits.reserve(4);

    switch (species) {
    case Species::PURRMAID:
        traits.emplace_back("Especially melodious purr");
        traits.emplace_back("Creates rainbow bubbles");
        traits.emplace_back("Harmonizes with whales");
        traits.emplace_back("Speaks dolphin");
        break;
    case Species::OCTOPUSS:
        traits.emplace_back("Master escape artist");
        traits.emplace_back("Expert puzzle solver");
        traits.emplace_back("Mimics other sea creatures");
        traits.emplace_back("Juggles underwater treasures");
        break;
    case Species::SHARKITTEN:
        traits.emplace_back("Professional treat catcher");
        traits.emplace_back("Winning smile");
        traits.emplace_back("Expert fish herder");
        traits.emplace_back("Creates whirlpools while playing");
        break;
    case Species::JELLYKITTY:
        traits.emplace_back("Changes colors with mood");
        traits.emplace_back("Creates bioluminescent light shows");
        traits.emplace_back("Floats belly up");
        traits.emplace_back("Makes glowing bubble rings");
        break;
    case Species::CRABCAT:
        traits.emplace_back("Shell art curator");
        traits.emplace_back("Professional hide and seeker");
        traits.emplace_back("Builds underwater castles");
        traits.emplace_back("Treasure-hunting expert");
        break;
    }

    return traits;
}

// Returns unique need options for each species
vector<string> PetProfile::getUniqueNeedOptions(Species species) {
    vector<string> needs;
    needs.reserve(4);

    switch (species) {
    case Species::PURRMAID:
        needs.emplace_back("Daily singing lessons");
        needs.emplace_back("Pearl collection basket");
        needs.emplace_back("Sparkling fur jewels");
        needs.emplace_back("Soundproof tank");
        break;
    case Species::OCTOPUSS:
        needs.emplace_back("Weekly puzzle box subscription");
        needs.emplace_back("Rotating toy collection");
        needs.emplace_back("Tentacle booties");
        needs.emplace_back("Treasure maps");
        break;
    case Species::SHARKITTEN:
        needs.emplace_back("Automatic treat dispenser");
        needs.emplace_back("Water wave maker");
        needs.emplace_back("Extra-thick floss");
        needs.emplace_back("Water-powered tooth brush");
        break;
    case Species::JELLYKITTY:
        needs.emplace_back("Color-changing LED tank lights");
        needs.emplace_back("Current diffuser");
        needs.emplace_back("Extra-soft food supplements");
        needs.emplace_back("Wide-tooth tentacle comb");
        break;
    case Species::CRABCAT:
        needs.emplace_back("In-shell pillow");
        needs.emplace_back("Iridescent shell decorating kit");
        needs.emplace_back("Claw maintenance tools");
        needs.emplace_back("Underwater construction set");
        break;
    }

    return needs;
}

// Converts Species enum to string
string speciesString(Species species) {
    switch (species) {
    case Species::PURRMAID: return "Purrmaid";
    case Species::OCTOPUSS: return "Octopuss";
    case Species::SHARKITTEN: return "Sharkitten";
    case Species::JELLYKITTY: return "Jellykitty";
    case Species::CRABCAT: return "Crabcat";
    default: return "Unknown Species";
    }
}

// Converts Sex enum to string
string sexString(Sex sex) {
    switch (sex) {
    case Sex::MALE: return "Male";
    case Sex::FEMALE: return "Female";
    case Sex::OTHER: return "Other";
    default: return "Unknown Sex";
    }
}

// Converts Size enum to string
string sizeString(Size size) {
    switch (size) {
    case Size::TINY: return "Tiny";
    case Size::SMALL: return "Small";
    case Size::MEDIUM: return "Medium";
    case Size::LARGE: return "Large";
    case Size::GARGANTUAN: return "Gargantuan";
    default: return "Unknown Size";
    }
}

// Converts Personality enum to string
string personalityString(Personality personality) {
    switch (personality) {
    case Personality::SHY: return "Shy";
    case Personality::PLAYFUL: return "Playful";
    case Personality::ENERGETIC: return "Energetic";
    case Personality::LAZY: return "Lazy";
    case Personality::CURIOUS: return "Curious";
    case Personality::MISCHIEVOUS: return "Mischievous";
    case Personality::DIVA: return "Diva";
    case Personality::GENTLE: return "Gentle";
    case Personality::CLEVER: return "Clever";
    case Personality::ADVENTUROUS: return "Adventurous";
    default: return "Unknown Personality";
    }
}