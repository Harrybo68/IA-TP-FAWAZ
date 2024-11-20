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

    ~Player();

    void addCardToBench(Card* card);
    void activatePokemonCard(int index);

    void attachEnergyCard(int benchIndex, int attackIndex);

    void attack(int attackerIndex, int attackIndex, Player& opponent, int targetIndex);
    void useTrainer(int benchIndex);

    void displayBench() const;

    void displayAction() const;
};

#endif