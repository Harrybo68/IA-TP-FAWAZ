#ifndef POKEMON_CARD_H
#define POKEMON_CARD_H
#include "card.h"
#include "energy_card.h"
#include <string>
#include <vector>
#include <tuple>
using namespace std;

class PokemonCard : public Card {
    private:
        string pokemonType;
        string familyName;
        int evolutionLevel;
        int maxHP;
        int hp;
        vector<tuple<int, int, string, int>> attacks;

    public:
        PokemonCard(const string &name, const string &type, const string &family, int evolution, int maxHP, 
                    int cost1, const string& description1, int damage1, 
                    int cost2, const string& description2, int damage2);
        ~PokemonCard() = default;

        void displayInfo() const;
        bool attachEnergy(const EnergyCard* energy);
        void heal();
        int getHP() const;
        tuple<int, int, string, int> getAttack1() const;
        tuple<int, int, string, int> getAttack2() const;
        bool attack(unsigned int attackNumber, PokemonCard *target);
        void damage(int damage);
        int getNumberOfAttacks() const;
};


#endif