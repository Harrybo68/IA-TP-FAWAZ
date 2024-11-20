#ifndef TRAINER_CARD_H
#define TRAINER_CARD_H

#include "card.h"
#include <iostream>
#include <vector>
#include "pokemon_card.h"

class TrainerCard : public Card {
private:
    string trainerEffect;

public:
    TrainerCard(const string& name, const string& effect) : Card(name), trainerEffect(effect) {}

    void displayInfo() const override;

    void applyEffect(vector<PokemonCard*>& actionCards);
};

#endif // TRAINER_CARD_H
