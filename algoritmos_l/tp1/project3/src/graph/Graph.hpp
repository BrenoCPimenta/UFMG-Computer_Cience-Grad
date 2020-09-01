#ifndef GRAPH_H
#define GRAPH_H

#include "NodeGraph.hpp"
#include <vector>

class Graph {

    private:
        std::vector <NodeGraph*> _node_sequence;
        int _n;
        int _m;
        int _size;

    public:
        Graph(int, int, std::vector<int>);
        void clean();
        NodeGraph* getNodeByLinearPosition(int, int);
};
#endif
