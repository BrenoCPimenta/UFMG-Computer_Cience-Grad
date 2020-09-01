#ifndef NODEHEAP_H
#define NODEHEAP_H

#include "../graph/NodeGraph.hpp"
#include <vector>

class NodeHeap {
    private:
        NodeHeap* _father;
        NodeGraph* _graph_reference;
        bool _has_path = true;
        bool _chain_end = false;
        
    public:
        NodeHeap();
        NodeHeap(NodeHeap*, NodeGraph*);
        std::vector<std::vector<int>> getChildrenPosition();
        NodeHeap* getFather();
        std::vector<int> getPosition();
        int getValue();
        bool hasPath();
        bool hasChildren();
        bool isChainEnd();
        void setEmptyPath();
        NodeGraph* getReference();

};

#endif
