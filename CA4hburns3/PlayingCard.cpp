#include "PlayingCard.hpp"
#include <iostream>

PlayingCard::PlayingCard(){

}
PlayingCard::PlayingCard(int new_val, suit new_card_suit ){
        card_suit = new_card_suit;
        val = new_val;
}

bool PlayingCard::operator>(const PlayingCard &other){
        if( val > other.val)
            return true;
        return false;
}

bool PlayingCard::operator<(const PlayingCard &other){
        if( val < other.val)
            return true;
        return false;
}
bool PlayingCard::operator==(const PlayingCard &other){
    if( val == other.val)
        return true;
    return false;
}

std::ostream& operator<<(std::ostream &out_stream, const PlayingCard &other){
    out_stream << "(";
    if(other.val < 10)
            out_stream << other.val;
    else{
            switch(other.val){
                    case 10:
                            out_stream << "T";
                            break;
                    case 11:
                            out_stream << "J";
                            break;
                    case 12:
                            out_stream << "Q";
                            break;
                    case 13:
                            out_stream << "K";
                            break;
                    case 14:
                            out_stream << "A";
                            break;
            }
    }
    switch(other.card_suit){
            case HEARTS:
                    out_stream << "H";
                    break;
            case DIAMONDS:
                    out_stream << "D";
                    break;
            case SPADES:
                    out_stream << "S";
                    break;
            case CLUBS:
                    out_stream << "C";
                    break;
    }
    out_stream << ")";
    return out_stream;
}



