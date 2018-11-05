#include "LinkedList.hpp"
#include "PlayingCard.hpp" 
#include "Game.hpp"

Game::~Game(){ 
}
Game::Game(){ 
}
void Game::readyPlayers(Player *player1, Player *player2){
            for(int i = 0; i < 26; i++){
                player1->cards.addNode(community.getElement());
            }
            for(int i = 26; i < 52; i++){
               player2->cards.addNode(community.getElement());
            }
}
void Game::setCommunity(){
        for(int i = 2; i < 15; i++){ 
                community.insert(PlayingCard(i,HEARTS)); 
                community.insert(PlayingCard(i, DIAMONDS));
                community.insert(PlayingCard(i, SPADES)); 
                community.insert(PlayingCard(i, CLUBS)); 
        }
            community.shuffle();

}

void Game::setUp(){
                }
 
    std::ostream& operator<<(std::ostream &out_stream, const Game &other){
            out_stream << "Player1: " << other.player1 << std::endl; 
            out_stream << "Player2: " << other.player2 << std::endl; 
            return out_stream; }
    
    Player* Game::play(Player *player1, Player *player2, std::ofstream *file, totalData &data){ 
            *file << player1->name << " VS. " << player2->name << std::endl;
            setCommunity();
            readyPlayers( player1, player2);
            community.clear();
            int cntr = 0;
            Player* winner;
            int p1_battles = player1->hands_played;
            int p2_battles = player2->hands_played;
            while(player1->cards.len() > 0 && player2->cards.len() > 0 ){
                    cntr++;
                    *file << "Battle " << cntr << ": ";
                    battle(player1, player2, file); 
                    *file << " : " << player1->name << " " << player1->cards.len() << ", " << player2->name << " " << player2->cards.len() << std::endl;
                    if(cntr >= 1000){
                            break;
                    }
            }
            winner = (player1->cards.len() > player2->cards.len())? player1 : player2;
            if(winner == player1){
                data.total_battles += (player1->hands_played - p1_battles);
                if(data.best_battles < (player1->hands_played - p1_battles))
                    data.best_battles = (player1->hands_played - p1_battles);
            *file << *player1 << " DEFEATED " << *player2 <<  " in " << winner->battles_won << " Battles and " << winner->wars <<  " Wars" << std::endl;
            }
            else{
                data.total_battles += (player2->hands_played - p2_battles);
                if(data.best_battles < (player2->hands_played - p2_battles))
                    data.best_battles = (player2->hands_played - p2_battles);
            *file << *player2 << " DEFEATED " << *player1 <<  " in " << winner->battles_won << " Battles and " << winner->wars <<  " Wars" << std::endl;
            }
            return winner;

    }
    
    void Game::battle(Player *player1, Player *player2, std::ofstream *out){
            player1->hands_played++;
            player2->hands_played++;
            community.addNode(player1->cards.getElement());
            community.addNode(player2->cards.getElement());
            PlayingCard card1 = community.getData(0);
            PlayingCard card2 = community.getData(1);
            if(card1 > card2){
                    *out << player1->name << " " << card1 << " DEFEATED " << player2->name << " " << card2;
                    player1->battles_won++;
                    player1->cards.addNode(community.getElement());
                    player1->cards.addNode(community.getElement());
                    }
            else if (card1 < card2){
                    *out << player2->name << " " << card2 << " DEFEATED " << player1->name << " " << card1;
                    player2->battles_won++;
                    player2->cards.addNode(community.getElement());
                    player2->cards.addNode(community.getElement());  
            }
            else {
                    *out << player2->name << " " << card2 << " TIED " << player1->name << " " << card1;
                    war(player1, player2, out); 
            }
    }

    void Game::war(Player *player1, Player *player2, std::ofstream *out ){ 
            player1->wars++;
            player2->wars++;
            PlayingCard card1;
            PlayingCard card2;
            NODE<PlayingCard>* temp;
            int more_cards = 0;
            if(player1->cards.len() == 0){
                    player2->battles_won++;
                    for(int i = 0; i< community.len(); i++){
                        player2->cards.addNode(community.getElement());
                    }
            }
            else if(player2->cards.len() == 0){
                    player1->battles_won++;
                    for(int i = 0; i< community.len(); i++){
                        player1->cards.addNode(community.getElement());
                    }
            }
                    if(player1->cards.len() < 4){
                            for(int i = 0; i < player1->cards.len() ; i++){
                                temp = player1->cards.getElement();
                                community.addNode(temp);
                            }
                            if(temp != NULL)
                                card1 = temp->data;
                    } else {
                        more_cards++;
                        for(int i = 0; i < 4 ; i++){
                                temp = player1->cards.getElement();
                                community.addNode(temp);
                            }
                            if(temp != NULL)
                                card1 = temp->data;
                    }
                    if(player2->cards.len() < 4){
                            for(int i = 0; i < player2->cards.len() ; i++){
                                temp = player2->cards.getElement();
                                community.addNode(temp);
                            }
                            card2 = temp->data;
                    } else {
                        more_cards++;
                        for(int i = 0; i < 4 ; i++){
                                temp = player2->cards.getElement();
                                community.addNode(temp);
                            }
                        card2 = temp->data;
                    }
                    if(card1 > card2){
                        player1->battles_won++;
                        for(int i = 0; i< community.len();){
                            player1->cards.addNode(community.getElement());
                        }
                            return;
                    }
                    else if (card2 > card1){
                        player2->battles_won++;
                        for(int i = 0; i< community.len();){
                            player2->cards.addNode(community.getElement());
                        }
                            return;
                    }
                    else{
                        if(more_cards == 2){
                            war(player1, player2, out);
                            return;
                        } else if (more_cards == 1){
                            Player* temp = (player1->cards.len() > player2->cards.len())? player1 : player2;
                            temp->wins++;
                            for(int i = 0; i< community.len();){
                                temp->cards.addNode(community.getElement());
                            }
                        }
                        else{
                        player1->battles_won++;
                        for(int i = 0; i< community.len();){
                            player1->cards.addNode(community.getElement());
                            }
                        }
                    }
            }
