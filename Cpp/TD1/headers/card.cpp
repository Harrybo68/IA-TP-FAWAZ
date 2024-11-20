#include "card.h"

Card::Card(const string& name) : cardName(name) {}

Card::~Card() {}

void Card::displayInfo() const {
    cout << "Card Name: " << cardName << endl;
}

string Card::getCardName() const {
    return cardName;
}