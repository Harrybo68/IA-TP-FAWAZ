#include "pokemon_card.h"

PokemonCard::PokemonCard(const string &pokemonName, const string &pokemonType, const string &familyName, int evolutionLevel, int hp, 
int energycost1, const string attack1, int damage1, int energycost2, const string attack2, int damage2)
    : Card(pokemonName), pokemonType(pokemonType), familyName(familyName), evolutionLevel(evolutionLevel), maxHP(maxHP), hp(maxHP)
{
    attacks.push_back({energycost1, 0, attack1, damage1});
    attacks.push_back({energycost2, 0, attack2, damage2});
}

void PokemonCard::displayInfo() const {
    cout << "Pokemon Card - Name: " << cardName
                  << ", Type: " << pokemonType
                  << ", Evolution Level: " << evolutionLevel
                  << " of the family \"" << familyName
                  << "\", HP: " << hp << endl;
        cout << "Attacks:\n";
        for (size_t i = 0; i < attacks.size(); ++i) {
            cout << "Attack #" << i << ":\n"
                      << "Attack cost: " << get<0>(attacks[i]) << "\n"
                      << "Attack current energy storage: " << get<1>(attacks[i]) << "\n"
                      << "Attack description: " << get<2>(attacks[i]) << "\n"
                      << "Attack damage: " << get<3>(attacks[i]) << "\n";
        }
}

void PokemonCard::attachEnergy(int attackIndex) {
    if (attackIndex < attacks.size()) {
        get<1>(attacks[attackIndex])++;
    }
}

void PokemonCard::takeDamage(int damage) {
    hp = max(0, hp - damage);
}

void PokemonCard::heal() {
    hp = maxHP;
}

bool PokemonCard::isKnockedOut() const { 
    return hp <= 0; 
}

int PokemonCard::getHP() const { 
    return hp; 
}

const tuple<int, int, string, int>& PokemonCard::getAttack(int index) const {
    if (index >= 0 && index < attacks.size()) {
        return attacks[index];
    }
    throw out_of_range("Invalid attack index");
}

int PokemonCard::getAttackDamage(int index) const {
    if (index >= 0 && index < attacks.size()) {
        return get<3>(attacks[index]); // Dégâts de l'attaque
    }
    return 0;
}