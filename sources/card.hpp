#ifndef CARD_HPP
#define CARD_HPP
#include <string>
using namespace std;

namespace ariel{
    class Card{

        private:
            int num;
            string sign;
            // The color of card doesn't matter

        public:
            Card();
            Card(int num , string sign);
            int getNum();
            string getSign();
            string toString();
    };
}
#endif
