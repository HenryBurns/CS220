#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <iostream>
class Player {
    public:
        int hands_played = 0;
        int wars = 0;
        int battles_won = 0;
        int wins = 0;
        std::string name;
        LLC<PlayingCard> cards;
        PlayingCard card;
        Player(){
                name = "[empty]";
        }
        Player(std::string val){
                name = val;
        }
	    friend std::ostream& operator<<(std::ostream &out_stream, const Player &other){
        out_stream << other.name << " (" << other.wins << ") ";
        return out_stream;
    }
};

 

#endif
