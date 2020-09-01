#include "NodeHeap.hpp"

using namespace std;

NodeHeap::NodeHeap(){
    this->_chain_end = true;
}

NodeHeap::NodeHeap(NodeHeap *father, NodeGraph *graph_reference):_father(father){
    this->_graph_reference = graph_reference;
}
NodeGraph* NodeHeap::getReference(){
    return this->_graph_reference;
}

std::vector<std::vector<int>> NodeHeap::getChildrenPosition(){
    return this->_graph_reference->getChildrenPosition();
}

NodeHeap* NodeHeap::getFather(){
    return this->_father;
}

std::vector<int> NodeHeap::getPosition(){
    return this->_graph_reference->getPosition();
}

int NodeHeap::getValue(){
    return this->_graph_reference->getValue();
}

bool NodeHeap::hasPath(){
    return this->_has_path;
}

bool NodeHeap::hasChildren(){
    return this->_graph_reference->hasChildren();
}

bool NodeHeap::isChainEnd(){
    return this->_chain_end;
}

void NodeHeap::setEmptyPath(){
    this->_has_path = false;
}


