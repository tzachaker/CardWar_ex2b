#include "player.hpp"
#include <string>
#include <vector>
using namespace std;

namespace ariel{
Player::Player()
    {
    }

    Player::Player(string name)
    {
        this->playerName = name;
    }
    
    int Player::stacksize()
    {
        return this->stack_size;
    }
    
    int Player::cardesTaken()
    {
        return this->cards_taken;
    }
    string Player::getName()
    {
        return this->playerName;
    }
    
    vector<Card> &Player::getCards()
    {
        return deckCards;
    }
    
    void Player::setCards(vector<Card> &deckCards)
    {
        this->deckCards = deckCards;
    }
    
    int Player::getStackSize() const {
        return stack_size;
    }
    
    void Player::setStackSize(int stackSize)
    {
        if (stackSize < 0 || stackSize > 52)
        {
            throw"Illegal size of stack";
        }
        this->stack_size = stackSize;
    }
    
    int Player::getCardsTaken() const {
        return cards_taken;
    }
    
    void Player::setCardsTaken(int cardsTaken)
    {
        if (cardsTaken < 0 || cardsTaken > 52)
        {
            throw "Illegal number of cards taken";
        }
        this->cards_taken = cardsTaken;
    }

}