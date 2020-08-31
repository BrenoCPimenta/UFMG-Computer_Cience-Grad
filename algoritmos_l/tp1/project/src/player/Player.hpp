#ifndef PLAYER_H
#define PLAYER_H


#include <vector>

class Player {

    private:
        std::vector<std::vector<int>> _path;
        bool _finished = false;
        std::vector <int> _position;
        int _turns;

    public:
        Player(int, int);
        bool hasFinished();
        std::vector<std::vector<int>> getPath();
        std::vector<int> getPosition();
        void setPath( std::vector<std::vector<int>> );
        void setNumberOfTurns(int);
        void setFinished();
};
#endif
