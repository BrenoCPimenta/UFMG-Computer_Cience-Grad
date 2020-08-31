#include "NodeHeap.hpp"


NodeHeap::NodeHeap(NodeHeap *father, NodeGraph *graph_reference):_father(father), _graph_reference(graph_reference){}

std::vector<int> NodeHeap::getPosition(){
    return this->_graph_reference->getPosition();
}

int NodeHeap::getValue(){
    return this->_graph_reference->getValue();
}

bool NodeHeap::hasPath(){
    return this->_has_path;
}

void NodeHeap::setEmptyPath(){
    this->_has_path = false;
}
