#include "../headers/trainer_card.h"

void TrainerCard::displayInfo() const {
        cout << "Trainer Card - Name: " << cardName
             << ", Effect: " << trainerEffect << endl;
    }

string TrainerCard::getEffectDescription() const {
        return trainerEffect;
    }

void TrainerCard::applyEffect(vector<PokemonCard*>& actionCards) {
        for (auto& pokemon : actionCards) {
            pokemon->heal();
        }
    }