#ifndef GRAPH_H
#define GRAPH_H

#include "NodeGraph.hpp"
#include <vector>

class Graph {

    private:
        std::vector <NodeGraph*> _node_control;
        int _n;
        int _m;

    public:
        Graph(int, int, int**);

};

#endif
