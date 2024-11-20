#ifndef POKEMON_CARD_H
#define POKEMON_CARD_H
#include "card.h"
#include <string>
#include <vector>
#include <tuple>
using namespace std;

class PokemonCard: public Card {
    private:
        string pokemonType;
        string familyName;
        int evolutionLevel;
        int maxHP;
        int hp;
        vector<tuple<int, int, string, int>> attacks;
        int energyCost;
        int actualEnergyCost;
        string attackDescription;
        int attackDamage;

    public:
        PokemonCard() : Card("") {}
        PokemonCard(const string &PokemonName, const string &pokemonType, const string &familyName, int evolutionLevel, int maxHP, 
           int energycost, const string attack1, int damage1, int energy1, const string attack2, int damage2);
        void displayInfo() const override;
        void attachEnergy(int attackIndex);
        void takeDamage(int damage);
        void heal();
        bool isKnockedOut() const;
        int getHP() const;
        const tuple<int, int, string, int>& getAttack(int index) const;
        int getAttackDamage(int index) const;
};


#endif