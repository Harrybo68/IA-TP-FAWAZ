#ifndef PLAYER_H
#define PLAYER_H

#include "pokemon_card.h"
#include "energy_card.h"
#include "trainer_card.h"
#include <vector>
#include <iostream>
using namespace std;

class Player {
private:
    string playerName;
    vector<Card*> benchCards;
    vector<PokemonCard*> actionCards;

public:
    Player(const string& name) : playerName(name) {}
    ~Player() = default;

    void addCardToBench(Card* card);
    void activatePokemonCard(unsigned int index);

    void attachEnergyCard(unsigned int benchIndex, unsigned int attackIndex);

    void attack(unsigned int attackerIndex,unsigned int attackIndex, Player& opponent,unsigned int targetIndex);
    void useTrainer(unsigned int benchIndex);

    void displayBench() const;

    void displayAction() const;
};

#endif