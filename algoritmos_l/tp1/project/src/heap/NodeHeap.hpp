#ifndef NODEHEAP_H
#define NODEHEAP_H

#include "../graph/NodeGraph.hpp"
#include <vector>

class NodeHeap {
    private:
        NodeHeap* _father;
        NodeGraph* _graph_reference;
        bool _has_path = true;
        
    public:
        NodeHeap(NodeHeap*, NodeGraph*);
        std::vector<int> getPosition();
        int getValue();
        bool hasPath();
        void setEmptyPath();
};

#endif
