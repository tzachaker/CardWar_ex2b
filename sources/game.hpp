#ifndef GAME_HPP
#define GAME_HPP
#include "player.hpp"
#include <string>
#include <vector>
using namespace std;

namespace ariel{

    class Game{

        private:
            Player &player1;
            Player &player2;
            int tieOneAfterOne = 0;
            int ties = 0;
            int numOfTurns = 0;
            string turnsLog= "";
            string lastTurn= "";

        public:
            Game();
            
            Game(Player &player1, Player &player2);

            void playTurn();

            void printLastTurn();

            void playAll();

            void printWiner();

            void printLog();

            void printStats();
            
    };
}
#endif