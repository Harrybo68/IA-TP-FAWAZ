#include "energy_card.h"



void EnergyCard::displayInfo() const {
        cout << "Energy Card - Type: " << energyType << endl;
    }   

string EnergyCard::getEnergyType() const {
    return energyType;
}