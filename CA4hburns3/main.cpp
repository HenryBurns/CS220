#include "LinkedList.hpp"
#include "PlayingCard.hpp"
#include "Game.hpp"
#include <iostream>
#include <vector>
#include <algorithm>


std::vector<Player*> getWinners(std::vector<Player*> &contestants, std::ofstream &out, totalData &data );
int main(int argc, char** argv){
    if(argc < 3){
            std::cout << "Please enter a valid number of arguments." << std::endl;
            return 1;
    }
    totalData* data = new totalData();
    std::vector<Player*>* players = new std::vector<Player*>();
    auto list = *players;
    std::ifstream reader;
    std::ofstream writer;
    writer.open(argv[2]);
    reader.open(argv[1]);
    reader >> std::noskipws;
    std::string line;
    Player *temp;
    int size;
    while(getline(reader, line)){
        if(line.length() > 1){
            temp = new Player(line);
            players->push_back(temp);
        }
    }
    for(auto i = players->begin(); i != players->end(); ++i){
        std::cout << *(*i) << std::endl;
    }
    {
        unsigned int iter = 1;
        size = players->size();
        while(iter < size)
            iter *=2;
        if(iter != size){
            std::cout << "Number of players is not a power of two" << std::endl;
            return 1;
        }
    }
    auto winnerVector = getWinners(*players, writer, *data);
    auto winner = winnerVector[0]; 
    std::cout << "Winner: " << winner->name << ". Average number of battles in the tournament: " << (data->total_battles/(size-1)) << " The greatest number of battles in a single tournament was " << data->best_battles << std::endl;
    for(auto i = players->begin(); i != players->end(); ++i){
        delete &(*i);
    }
    delete &winnerVector;
    //delete players;
    //std::cout << *game << std::endl;
/*
    winner.wins++;
    std::cout << "Winner: " << winner << std::endl;
    std::cout << "Player 1: " << *player1 << std::endl;
    std::cout << "Player 2: " << *player2 << std::endl;
    delete game;
*/
    return 0;
}

    std::vector<Player*> getWinners(std::vector<Player*> &contestants, std::ofstream &out, totalData &data){
        if(contestants.size() == 1)
            return contestants;
        Game* game = new Game();
        std::cout << "===" << std::endl;
        std::cout << "===" << std::endl;
        std::cout << "===" << std::endl;
        std::cout << "===" << std::endl;
        std::vector<Player*> *nextTier = new std::vector<Player*>();
        for(unsigned int i = 0; i < contestants.size()-1; i+=2){
            out << "===" << std::endl;
            Player* winner = game->play(contestants[i], contestants[i+1], &out, data);
            winner->cards.clear();
            Player* loser;
            for(int j = 0; j < 2; j++){
                if(contestants[j] != winner)
                    loser = contestants[j];
            }
            out << *winner << " DEFEATED " << loser->name <<  " in " << winner->battles_won << " Battles and " << winner->wars <<  " Wars" << std::endl;
            out << "===" << std::endl;
            nextTier->push_back(winner);
        }
        for(auto i = contestants.begin(); i != contestants.end(); ++i){
            if(std::find(nextTier->begin(), nextTier->end(), *i) == nextTier->end())
                int j;
                //delete &(*i);
        }
        //delete &contestants;
        delete game;
        return getWinners(*nextTier, out, data);
        
    }
