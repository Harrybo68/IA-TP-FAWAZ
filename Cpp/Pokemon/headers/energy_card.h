#ifndef ENERGY_CARD_H
#define ENERGY_CARD_H

#include "card.h"
#include <iostream>

class EnergyCard : public Card {
private:
    string energyType;

public:
    EnergyCard(const string& type) : Card("Energy"), energyType(type) {}

    void displayInfo() const override;

    string getEnergyType() const;
};

#endif // ENERGY_CARD_H
