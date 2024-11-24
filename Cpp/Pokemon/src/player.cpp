#include "../headers/player.h"


void Player::addCardToBench(Card* card) {
    //add card to bench
    benchCards.push_back(card);
}

void Player::activatePokemonCard(unsigned int index) {
    if (index < benchCards.size()) {
        PokemonCard* pokemon = dynamic_cast<PokemonCard*>(benchCards[index]);
        if (pokemon) {
            //move PokemonCard to the actionDeck
            actionCards.push_back(pokemon);
            benchCards.erase(benchCards.begin() + index);

            cout << playerName << " is activating a Pokemon Card: " << pokemon->getCardName() << endl;
        }
    }
}

void Player::attachEnergyCard(unsigned int benchIndex, unsigned int attackIndex) {
    if (benchIndex < benchCards.size()) {
        PokemonCard* pokemon = actionCards[benchIndex];
        EnergyCard* energy = dynamic_cast<EnergyCard*>(benchCards[benchIndex]);
        
        cout << playerName << " is attaching Energy Card of type " << energy->getEnergyType()
             << " to the Pokemon " << actionCards.back()->getCardName() << endl;
        
        if (pokemon->attachEnergy(energy))
        {
            //remove energy card from bench
            benchCards.erase(benchCards.begin() + benchIndex);
        }
        
    }
}

void Player::attack(unsigned int attackerIndex,unsigned int attackIndex, Player& opponent,unsigned int targetIndex) {
    if (attackerIndex < actionCards.size() && targetIndex < opponent.actionCards.size()) {
        PokemonCard* attacker = actionCards[attackerIndex];
        PokemonCard* target = opponent.actionCards[targetIndex];

        bool ko = attacker->attack(attackIndex, target);

        tuple<int, int, string, int> attack;
        if (attackIndex == 0) 
            attack = attacker->getAttack1();
        else 
            attack = attacker->getAttack2();

        cout << "Only " << attacker->getNumberOfAttacks() << " attacks exist." << endl << playerName << " attacking " << opponent.playerName 
            << "'s Pokemon " << target->getCardName() 
            << " with the Pokemon " << attacker->getCardName() << " with its attack: " << get<2>(attack) << endl;
        cout << "Reducing " << get<3>(attack) << " from " << opponent.playerName << "'s Pokemon's " << " HP" << endl;

        if(ko)
            cout << opponent.playerName << "'s Pokemon " << target->getCardName() << " is KO" << endl;
        else
            cout << "Pokemon " << target->getCardName() << " is still alive" << endl;
    }
}

void Player::useTrainer(unsigned int benchIndex) {
    if (benchIndex < benchCards.size()) {
        TrainerCard* trainer = dynamic_cast<TrainerCard*>(benchCards[benchIndex]);

        if (trainer) {
            trainer->applyEffect(actionCards);
            cout << playerName << " is using the Trainer Card to \"" << trainer->getEffectDescription() << "\"" << endl;
        }
    }
}

void Player::displayBench() const {
    cout << "Bench cards for Player " << playerName << ":\n";

    for (const auto& card : benchCards) {
        card->displayInfo();
    }
}

void Player::displayAction() const {
    cout << "Action cards for Player " << playerName << ":\n";
    
    for (const auto& card : actionCards) {
        card->displayInfo();
    }
}