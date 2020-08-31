
#include "Player.hpp"

using namespace std;

Player::Player(int y, int x){
    this->_position.push_back(y);
    this->_position.push_back(x);
}

bool Player::isWinner(){
    return _winner;
}

std::vector<std::vector<int>> Player::getPath(){
    return this->_path;
}

std::vector<int> Player::getPosition(){
    return this->_position;
}

void Player::setPath(std::vector<std::vector<int>> path){
    this->_path = path;
}

void Player::setNumberOfTurns(int turns){
    this->_turns = turns;
}

void Player::setWinner(){
    this->_winner = true;
}
