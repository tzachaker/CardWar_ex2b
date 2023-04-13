#include "game.hpp"
#include "player.hpp"
#include <string>
#include <iostream>
#include <algorithm>    //random_shuffle
#include <vector>       
#include <ctime>        
#include <cstdlib>      
#include <random>
using namespace std; 

namespace ariel{

    Player p1 = Player();
    Player p2 = Player();

    Game::Game(Player &p1, Player &p2) : player1(p1), player2(p2)
    {
    const std::vector<std::string> signs = {"Heart", "Diamond", "Club", "Spade"};
    const int num_cards_per_sign = 13;
    std::vector<Card> deck;
    deck.reserve(signs.size() * num_cards_per_sign);
    for (const auto& sign : signs)
    {
        for (int i = 1; i <= num_cards_per_sign; ++i)
        {
            deck.emplace_back(i, sign);
        }
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(deck.begin(), deck.end(), gen);
    auto p1_cards = std::vector<Card>(deck.begin(), deck.begin() + deck.size() / 2);
    player1.setCards(p1_cards);
    player1.setStackSize(p1_cards.size());
    auto p2_cards = std::vector<Card>(deck.begin() + deck.size() / 2, deck.end());
    player2.setCards(p2_cards);
    player2.setStackSize(p2_cards.size());
}
    void Game::playTurn()
    { //before the turn starts
        if(&player1 == &player2){
            throw std::invalid_argument("The players should be different");
        }
        if (player1.stacksize() == 0 || player2.stacksize() == 0)
        {
            throw std::invalid_argument("There is no more turn. game over");
        }
        
        Card card1, card2;
        if (!player1.getCards().empty()) {
            card1 = std::move(player1.getCards().back());
            player1.getCards().pop_back(); //Take the card out of the pack
            player1.setStackSize(player1.stacksize() - 1);
        }
        if (!player2.getCards().empty()) {
            card2 = std::move(player2.getCards().back());
            player2.getCards().pop_back(); //Take the card out of the pack
            player2.setStackSize(player2.stacksize() - 1);
        }

        if(card1.getNum()==1 || card2.getNum()==1)
        {
            if(card1.getNum()>card2.getNum() && card2.getNum()==1 && card1.getNum()!=2)
            {
                int cardStack2= player2.cardesTaken()+ 2+4*tieOneAfterOne;
                player2.setCardsTaken(cardStack2);
                lastTurn += player1.getName()+" pulled out " + to_string(card1.getNum()) +" " + card1.getSign() + " and "+player2.getName()+" pulled out " + to_string(card2.getNum()) +" " + card2.getSign()
                +". The winner is : "+ player2.getName() +"\n";
                tieOneAfterOne = 0;
                numOfTurns++;
                int size1= player1.getCards().size();
                int size2= player2.getCards().size();
                player1.setStackSize(size1);
                player2.setStackSize(size2);
            }

            else if(card2.getNum()>card1.getNum() && card1.getNum()==1 && card2.getNum()!=2)
            {
                int cardStack1= player1.cardesTaken()+ 2+4*tieOneAfterOne;
                player1.setCardsTaken(cardStack1);
                lastTurn += player1.getName()+" pulled out " + to_string(card1.getNum()) +" " + card1.getSign() + " and "+player2.getName()+" pulled out " + to_string(card2.getNum()) +" " + card2.getSign()
                +". The winner is : "+ player1.getName() +"\n";
                tieOneAfterOne = 0;
                numOfTurns++;
                int size1= player1.getCards().size();
                int size2= player2.getCards().size();
                player1.setStackSize(size1);
                player2.setStackSize(size2);
            }

            else if(card2.getNum()>card1.getNum() && card1.getNum()==1 && card2.getNum()==2)
            {
                int cardStack2= player2.cardesTaken()+ 2+4*tieOneAfterOne;
                player2.setCardsTaken(cardStack2);
                lastTurn += player1.getName()+" pulled out " + to_string(card1.getNum()) +" " + card1.getSign() + " and "+player2.getName()+" pulled out " + to_string(card2.getNum()) +" " + card2.getSign()
                +". The winner is : "+ player2.getName() +"\n";
                tieOneAfterOne = 0;
                numOfTurns++;
                int size1= player1.getCards().size();
                int size2= player2.getCards().size();
                player1.setStackSize(size1);
                player2.setStackSize(size2);
            }

            else if(card1.getNum()>card2.getNum() && card1.getNum()==2 && card2.getNum()==1)
            {
                int cardStack1= player1.cardesTaken()+ 2+4*tieOneAfterOne;
                player1.setCardsTaken(cardStack1);
                lastTurn += player1.getName()+" pulled out " + to_string(card1.getNum()) +" " + card1.getSign() + " and "+player2.getName()+" pulled out " + to_string(card2.getNum()) +" " + card2.getSign()
                +". The winner is : "+ player1.getName() +"\n";
                tieOneAfterOne = 0;
                numOfTurns++;
                int size1= player1.getCards().size();
                int size2= player2.getCards().size();
                player1.setStackSize(size1);
                player2.setStackSize(size2);
            }
        }
        else if (card1.getNum()>card2.getNum())
        {
            int cardStack1= player1.cardesTaken()+ 2+4*tieOneAfterOne;
            player1.setCardsTaken(cardStack1);
            lastTurn += player1.getName()+" pulled out " + to_string(card1.getNum()) +" " + card1.getSign() + " and "+player2.getName()+" pulled out " + to_string(card2.getNum()) +" " + card2.getSign()
            +". The winner is : "+ player1.getName() +"\n";
            tieOneAfterOne = 0;
            numOfTurns++;
            int size1= player1.getCards().size();
            int size2= player2.getCards().size();
            player1.setStackSize(size1);
            player2.setStackSize(size2);
        }

        else if (card1.getNum()<card2.getNum())
        {
            int cardStack2= player2.cardesTaken()+ 2+4*tieOneAfterOne;
            player2.setCardsTaken(cardStack2);
            lastTurn += player1.getName()+" pulled out " + to_string(card1.getNum()) +" " + card1.getSign() + " and "+player2.getName()+" pulled out " + to_string(card2.getNum()) +" " + card2.getSign()
            +". The winner is : "+ player2.getName() +"\n";
            tieOneAfterOne = 0;
            numOfTurns++;
            int size1= player1.getCards().size();
            int size2= player2.getCards().size();
            player1.setStackSize(size1);
            player2.setStackSize(size2);
        }

        else 
        { // tie
            ties++;
            lastTurn += player1.getName()+" pulled out " + to_string(card1.getNum()) +" " + card1.getSign() + " and "+player2.getName()+" pulled out " + to_string(card2.getNum()) +" " + card2.getSign()
            +". tie. The winner is still unknown \n";
            if(player1.stacksize()!=0 && player2.stacksize()!=0)
            {
                tieOneAfterOne++;
                if (player1.stacksize()>=2 && player2.stacksize()>=2)
                { // tie and and the players have more cards
                    player1.getCards().pop_back();
                    player2.getCards().pop_back();
                    int size1= player1.stacksize() - 1;
                    int size2= player2.stacksize() - 1;
                    player1.setStackSize(size1);
                    player2.setStackSize(size2);
                }
                else if (player1.stacksize()==1 || player2.stacksize()==1)
                { // tie and one card left for one of the players
                    int size1= player1.stacksize() - 1;
                    int size2= player2.stacksize() - 1;
                    player1.setStackSize(size1);
                    player2.setStackSize(size2);
                    int cardStack1= player1.cardesTaken()+ 1+4*tieOneAfterOne;
                    int cardStack2= player2.cardesTaken()+ 1+4*tieOneAfterOne;
                    player1.setCardsTaken(cardStack1);
                    player2.setCardsTaken(cardStack2);
                }
                playTurn();
            }
            else 
            { // tie and and one of the players ran out of cards
                int cardStack1= player1.cardesTaken()+ 4*tieOneAfterOne;
                int cardStack2= player2.cardesTaken()+ 4*tieOneAfterOne;
                player1.setCardsTaken(cardStack1);
                player2.setCardsTaken(cardStack2);
                int size1= 0;
                int size2= 0;
                player1.setStackSize(size1);
                player2.setStackSize(size2);
            }   
        }
    }

        void Game::printLastTurn()
    {
            // cout <<"The last turn is : \n"<< lastTurn ;
    }
    void Game::playAll()
    {
        while (player1.stacksize()>0 && player2.stacksize()>0)
        {
            if(&player1 == &player2){
                throw std::invalid_argument("The players should be different");
            }
            else{
                playTurn();
                turnsLog += lastTurn;
            }
        }

    }
    void Game::printWiner()
    {
        if (player1.cardesTaken()>player2.cardesTaken())
        {
            // cout <<"The winner is : \n" <<player1.getName();
        }
        else if (player1.cardesTaken()<player2.cardesTaken())
        {
            // cout <<"The winner is : \n" <<player2.getName();
        }
        else
        {
            // cout<<"A tie between " <<player1.getName()<< "to" <<player2.getName()<< "\n"<<endl;
        }
    }
    void Game::printLog()
    {
        // cout <<"The log is : "<< turnsLog << "\n"<< endl;
    }
    void Game::printStats()
    {
    //    cout <<player1.getName()<< "has" <<player1.cardesTaken()<< " cards and " <<player2.getName()<< "has" <<player2.cardesTaken()<< "cards \n"<< endl;
    // It can also show numOfTurns, ties ...
    }
}