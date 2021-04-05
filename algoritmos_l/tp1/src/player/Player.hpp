#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

class Player {

    private:
        char _name;
        std::vector<int> _path;
        bool _finished = false;
        std::vector <int> _position;

    public:
        Player(int, int);
        bool hasFinished();
        char getName();
        void setName(char);
        std::vector<int> getPath();
        std::vector<int> getPosition();
        void setPath( std::vector<int> );
        int getNumberOfTurns();
        void setFinished();
};
#endif
