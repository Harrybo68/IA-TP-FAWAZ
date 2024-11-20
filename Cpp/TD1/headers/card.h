#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>
using namespace std;

class Card {
    protected:
        string cardName;
    public:
        Card(const string& name);
        virtual ~Card();
        virtual void displayInfo() const;
        string getCardName() const;
};

#endif