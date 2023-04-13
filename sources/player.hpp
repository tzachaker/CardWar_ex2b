#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "card.hpp"
#include <string>
#include <vector>
using namespace std;

namespace ariel {

    class Player {

        private: 
            int stack_size = 0, cards_taken = 0;
            string playerName;
            vector<Card> deckCards;
            
        public: 
            Player();
            Player(string playerName);

            int stacksize();
            int cardesTaken();

            string getName();

            vector<Card>& getCards() const; 
            vector<Card>& getCards();
            void setCards(vector<Card> &deckCards);

            int getStackSize() const; // Not used
            void setStackSize(int stackSize);

            int getCardsTaken() const; // Not used
            void setCardsTaken(int cardsTaken);

    };
}
#endif