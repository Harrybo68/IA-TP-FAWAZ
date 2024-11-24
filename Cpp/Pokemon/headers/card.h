#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>
using namespace std;

class Card {
    protected:
        string cardName;

    public:
        Card(const string& name) : cardName(name) {}
        virtual ~Card() = default;

        virtual void displayInfo() const = 0;
        
        string getCardName() const;
};

#endif