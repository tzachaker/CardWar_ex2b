#include "card.hpp"
#include <string>
using namespace std;

namespace ariel{
    Card::Card() : num(0), sign("")
    {
        // Default constructor
    }
    Card::Card(int num, string sign) : num(num), sign(sign)
    {
        // The color of card doesn't matter
        this->num = num;
        this->sign = sign;
    }
    int Card::getNum()  
    {
        // Returns the value of the card
        return this->num;
    }
    string Card::getSign()  
    {
        // Returns the string's sign of the card
        return this->sign;
    }
    //getColor is unnecessary here

}