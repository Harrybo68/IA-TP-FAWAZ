#include "../headers/pokemon_card.h"

PokemonCard::PokemonCard(const string &name, const string &type, const string &family, int evolution, int maxHP, 
                         int cost1, const string& description1, int damage1, 
                         int cost2, const string& description2, int damage2)
    : Card(name), pokemonType(type), familyName(family), evolutionLevel(evolution), maxHP(maxHP), hp(maxHP) {

    //initialize attacks
    attacks.push_back(make_tuple(cost1, 0, description1, damage1));
    attacks.push_back(make_tuple(cost2, 0, description2, damage2));
    }


void PokemonCard::displayInfo() const {
    cout << "Pokemon Card - Name: " << cardName
         << ", Type: " << pokemonType
         << ", Evolution Level: " << evolutionLevel
         << " of the family \"" << familyName
         << ", HP: " << hp << "\"" << endl;
    cout << "Attacks:\n";

    for (unsigned int i = 0; i < attacks.size(); ++i) {
        cout << "Attack #" << i << ":\n"
             << "Attack cost: " << get<0>(attacks[i]) << "\n"
             << "Attack current energy storage: " << get<1>(attacks[i]) << "\n"
             << "Attack description: " << get<2>(attacks[i]) << "\n"
             << "Attack damage: " << get<3>(attacks[i]) << "\n";
    }
}

bool PokemonCard::attachEnergy(const EnergyCard* energy) {
    if (energy->getEnergyType() == pokemonType) {
        get<1>(attacks[0])++;
        get<1>(attacks[1])++;
        return true;
    }

    return false;
}

void PokemonCard::heal() {
    hp = maxHP;
}

int PokemonCard::getHP() const { 
    return hp; 
}


tuple<int, int, string, int> PokemonCard::getAttack1() const {
    return attacks[0];
}

tuple<int, int, string, int> PokemonCard::getAttack2() const {
    return attacks[1];
}


bool PokemonCard::attack(unsigned int attackNumber, PokemonCard *target) {
    //check if current energy is enough to attack
    if (get<1>(attacks[attackNumber]) >= get<0>(attacks[attackNumber])) {

        //deal damage
        target->damage(get<3>(attacks[attackNumber]));

        //remove energy
        get<1>(attacks[0]) -= get<0>(attacks[attackNumber]);
        get<1>(attacks[1]) -= get<0>(attacks[attackNumber]);

        //check if the target is KO
        if (target->getHP() == 0) {
           return true;
        }
    }

    return false;
}

void PokemonCard::damage(int damage) {
    //reduce hp
    hp -= damage;
    
    if (hp < 0) {
        hp = 0;
        cout << "Pokemon " << cardName << " is KO" << endl;
    }
}

int PokemonCard::getNumberOfAttacks() const {
    return attacks.size();
}
