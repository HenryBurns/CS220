#ifndef GAME_HPP
#define GAME_HPP
#include "Player.hpp"
#include <fstream>
#include <string>
class totalData{
    public:
    int total_battles = 0;
    int best_battles = 0;
};

class Game {
    public:
        Player player1;
        Player player2;
        void setUp();
        void setCommunity();
        void readyPlayers(Player *player1, Player *player2);
        LLC<PlayingCard> community;
        Game();
        ~Game(); 
        Player* play(Player *player1, Player *player2, std::ofstream *out, totalData &data);
        void battle(Player *player1, Player *player2, std::ofstream *out);
        void war(Player *player1, Player *player2, std::ofstream *out);
	friend std::ostream& operator<<(std::ostream &, const Game &);
};

       
        
#endif
