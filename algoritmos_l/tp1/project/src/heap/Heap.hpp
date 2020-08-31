#ifndef HEAP_H
#define HEAP_H

#include "NodeHeap.hpp"
#include "../graph/Graph.hpp"
#include "../graph/NodeGraph.hpp"
#include "../player/Player.hpp"
#include <vector>

class Heap {

    private:
        Graph _graph;
        std::vector<NodeHeap*> _node_control;
        std::vector<std::vector<int>> _players_position;

    public:
        Heap(Graph, std::vector<std::vector<int>>);
        void searchBFS(Player*);
        std::vector<NodeHeap*> startNextLayer(std::vector<NodeHeap*>, std::vector<std::vector<int>>);
        std::vector<int> getPath(NodeHeap*);
};
#endif
