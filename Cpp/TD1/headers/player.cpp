#include "player.h"

Player::~Player() {
    for (Card* card : benchCards) {
        delete card;
    }
}

void Player::addCardToBench(Card* card) {
    benchCards.push_back(card);
}

void Player::activatePokemonCard(int index) {
    if (index >= 0 && index < benchCards.size()) {
        auto* pokemon = dynamic_cast<PokemonCard*>(benchCards[index]);
        if (pokemon) {
            actionCards.push_back(pokemon);
            benchCards.erase(benchCards.begin() + index);
            cout << playerName << " is activating a Pokemon Card: " << pokemon->getCardName() << endl;
        }
    }
}

void Player::attachEnergyCard(int benchIndex, int attackIndex) {
    if (benchIndex >= 0 && benchIndex < benchCards.size()) {
        auto* energy = dynamic_cast<EnergyCard*>(benchCards[benchIndex]);
        if (energy && !actionCards.empty()) {
            actionCards.back()->attachEnergy(attackIndex);
            cout << playerName << " is attaching Energy Card of type " << energy->getEnergyType()
                        << " to the Pokemon " << actionCards.back()->getCardName() << endl;
        }
    }
}

void Player::attack(int attackerIndex, int attackIndex, Player& opponent, int targetIndex) {
    if (attackerIndex >= 0 && attackerIndex < actionCards.size() &&
        targetIndex >= 0 && targetIndex < opponent.actionCards.size()) {
        auto* attacker = actionCards[attackerIndex];
        auto* target = opponent.actionCards[targetIndex];

        try {
            int damage = attacker->getAttackDamage(attackIndex);
            cout << playerName << " attacking " << opponent.playerName << "'s Pokemon "
                      << target->getCardName() << " with the Pokemon " << attacker->getCardName()
                      << " with its attack: " << get<2>(attacker->getAttack(attackIndex)) << endl;

            target->takeDamage(damage);

            cout << "Reducing " << damage << " from " << opponent.playerName << "'s Pokemon's HP" << endl;
        } catch (const out_of_range& e) {
            cout << "Invalid attack index!" << endl;
        }
    }
}

void Player::useTrainer(int benchIndex) {
    if (benchIndex >= 0 && benchIndex < benchCards.size()) {
        auto* trainer = dynamic_cast<TrainerCard*>(benchCards[benchIndex]);
        if (trainer) {
            trainer->applyEffect(actionCards);
            cout << playerName << " is using the Trainer Card to \"" << trainer->getCardName() << "\"" << endl;
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