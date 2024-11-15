/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 11: Assignment
10 Nov 2024
This implementation file contains the functions for the
PetCatalog class. It requires cstdlib and ctime for random
number generation and PetCatalog.h for class definition.
-------------------------------------------------- */

#include "PetCatalog.h"
#include <cstdlib>
#include <ctime>
#include <sstream>

// Creates catalog and initializes random seed
PetCatalog::PetCatalog() : root(nullptr) {
    srand(static_cast<unsigned>(time(nullptr)));
    loadSamplePets();
}

// Returns randomly selected option from vector
string PetCatalog::getRandomOption(const vector<string>& options) {
    if (options.empty()) return "";
    return options[rand() % options.size()];
}

// Loads sample pets into catalog
void PetCatalog::loadSamplePets() {

    // Adds Purrmaids
    addPet(PetProfile(
        Species::PURRMAID,
        "Pearl",
        Sex::FEMALE,
        "Pearl-white with iridescent scales",
        18,
        Size::MEDIUM,
        Personality::DIVA,
        getRandomOption(PetProfile::getUniqueTraitOptions(Species::PURRMAID)),
        getRandomOption(PetProfile::getUniqueNeedOptions(Species::PURRMAID))
    ));

    addPet(PetProfile(
        Species::PURRMAID,
        "Melody",
        Sex::FEMALE,
        "Sapphire blue with silver fins",
        24,
        Size::LARGE,
        Personality::PLAYFUL,
        getRandomOption(PetProfile::getUniqueTraitOptions(Species::PURRMAID)),
        getRandomOption(PetProfile::getUniqueNeedOptions(Species::PURRMAID))
    ));

    addPet(PetProfile(
        Species::PURRMAID,
        "Jazz",
        Sex::MALE,
        "Golden stripes with coral highlights",
        6,
        Size::SMALL,
        Personality::ENERGETIC,
        getRandomOption(PetProfile::getUniqueTraitOptions(Species::PURRMAID)),
        getRandomOption(PetProfile::getUniqueNeedOptions(Species::PURRMAID))
    ));

    // Adds Octopusses
    addPet(PetProfile(
        Species::OCTOPUSS,
        "Inky",
        Sex::MALE,
        "Deep purple with spots",
        24,
        Size::LARGE,
        Personality::CLEVER,
        getRandomOption(PetProfile::getUniqueTraitOptions(Species::OCTOPUSS)),
        getRandomOption(PetProfile::getUniqueNeedOptions(Species::OCTOPUSS))
    ));

    addPet(PetProfile(
        Species::OCTOPUSS,
        "Tentacles",
        Sex::FEMALE,
        "Rainbow-shifting colors",
        12,
        Size::MEDIUM,
        Personality::MISCHIEVOUS,
        getRandomOption(PetProfile::getUniqueTraitOptions(Species::OCTOPUSS)),
        getRandomOption(PetProfile::getUniqueNeedOptions(Species::OCTOPUSS))
    ));

    addPet(PetProfile(
        Species::OCTOPUSS,
        "Widget",
        Sex::OTHER,
        "Metallic copper with gold spots",
        36,
        Size::GARGANTUAN,
        Personality::CURIOUS,
        getRandomOption(PetProfile::getUniqueTraitOptions(Species::OCTOPUSS)),
        getRandomOption(PetProfile::getUniqueNeedOptions(Species::OCTOPUSS))
    ));

    // Adds Sharkittens
    addPet(PetProfile(
        Species::SHARKITTEN,
        "Finn",
        Sex::MALE,
        "Grey and white tuxedo with fins",
        8,
        Size::MEDIUM,
        Personality::ENERGETIC,
        getRandomOption(PetProfile::getUniqueTraitOptions(Species::SHARKITTEN)),
        getRandomOption(PetProfile::getUniqueNeedOptions(Species::SHARKITTEN))
    ));

    addPet(PetProfile(
        Species::SHARKITTEN,
        "Chomper",
        Sex::FEMALE,
        "Silver tabby with blue fins",
        15,
        Size::LARGE,
        Personality::GENTLE,
        getRandomOption(PetProfile::getUniqueTraitOptions(Species::SHARKITTEN)),
        getRandomOption(PetProfile::getUniqueNeedOptions(Species::SHARKITTEN))
    ));

    addPet(PetProfile(
        Species::SHARKITTEN,
        "Tiger",
        Sex::MALE,
        "Orange striped with black fins",
        4,
        Size::TINY,
        Personality::PLAYFUL,
        getRandomOption(PetProfile::getUniqueTraitOptions(Species::SHARKITTEN)),
        getRandomOption(PetProfile::getUniqueNeedOptions(Species::SHARKITTEN))
    ));

    // Adds Jellykitties
    addPet(PetProfile(
        Species::JELLYKITTY,
        "Luna",
        Sex::FEMALE,
        "Translucent with bioluminescent spots",
        12,
        Size::SMALL,
        Personality::GENTLE,
        getRandomOption(PetProfile::getUniqueTraitOptions(Species::JELLYKITTY)),
        getRandomOption(PetProfile::getUniqueNeedOptions(Species::JELLYKITTY))
    ));

    addPet(PetProfile(
        Species::JELLYKITTY,
        "Aurora",
        Sex::FEMALE,
        "Pastel rainbow translucent",
        9,
        Size::MEDIUM,
        Personality::SHY,
        getRandomOption(PetProfile::getUniqueTraitOptions(Species::JELLYKITTY)),
        getRandomOption(PetProfile::getUniqueNeedOptions(Species::JELLYKITTY))
    ));

    addPet(PetProfile(
        Species::JELLYKITTY,
        "Sparkle",
        Sex::MALE,
        "Crystal clear with glowing patterns",
        3,
        Size::TINY,
        Personality::CURIOUS,
        getRandomOption(PetProfile::getUniqueTraitOptions(Species::JELLYKITTY)),
        getRandomOption(PetProfile::getUniqueNeedOptions(Species::JELLYKITTY))
    ));

    // Adds Crabcats
    addPet(PetProfile(
        Species::CRABCAT,
        "Hermie",
        Sex::MALE,
        "Orange tabby with spotted shell",
        15,
        Size::SMALL,
        Personality::ADVENTUROUS,
        getRandomOption(PetProfile::getUniqueTraitOptions(Species::CRABCAT)),
        getRandomOption(PetProfile::getUniqueNeedOptions(Species::CRABCAT))
    ));

    addPet(PetProfile(
        Species::CRABCAT,
        "Pincer",
        Sex::FEMALE,
        "Black and white with pearl shell",
        20,
        Size::MEDIUM,
        Personality::MISCHIEVOUS,
        getRandomOption(PetProfile::getUniqueTraitOptions(Species::CRABCAT)),
        getRandomOption(PetProfile::getUniqueNeedOptions(Species::CRABCAT))
    ));

    addPet(PetProfile(
        Species::CRABCAT,
        "Shell",
        Sex::OTHER,
        "Calico with rainbow shell",
        10,
        Size::SMALL,
        Personality::LAZY,
        getRandomOption(PetProfile::getUniqueTraitOptions(Species::CRABCAT)),
        getRandomOption(PetProfile::getUniqueNeedOptions(Species::CRABCAT))
    ));
}

// Adds pet to catalog
void PetCatalog::addPet(const PetProfile& pet) {
    auto newNode = make_shared<PetNode>(pet);

    if (!root) {
        root = newNode;
        return;
    }

    insertPet(root, pet);
}

// Inserts pet into binary tree in alphabetical order
void PetCatalog::insertPet(shared_ptr<PetNode>& node, const PetProfile& pet) {
    if (!node) {
        node = make_shared<PetNode>(pet);
        return;
    }

    if (pet.getName() < node->getProfile().getName()) {
        auto leftChild = dynamic_pointer_cast<PetNode>(node->getLeft());
        insertPet(leftChild, pet);
        node->setLeft(leftChild);
    }
    else {
        auto rightChild = dynamic_pointer_cast<PetNode>(node->getRight());
        insertPet(rightChild, pet);
        node->setRight(rightChild);
    }
}

// Returns formatted catalog using inorder traversal
string PetCatalog::displayCatalog() const {
    if (!root) {
        return "No pets available for adoption at this time.\n";
    }

    const string DOUBLE_BORDER = Utilities::createBorder(80, '=');
    const string SINGLE_BORDER = Utilities::createBorder(80, '-');

    stringstream result;
    result << DOUBLE_BORDER << "\n";
    result << "AVAILABLE PETS FOR ADOPTION\n";
    result << SINGLE_BORDER << "\n";
    result << "Find your perfect magical companion from our current residents:\n";
    result << DOUBLE_BORDER << "\n\n";
    result << root->getInOrderTraversal();

    return result.str();
}