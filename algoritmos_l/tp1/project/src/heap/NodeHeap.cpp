#include "NodeHeap.hpp"

using namespace std;

NodeHeap::NodeHeap(){
    this->_chain_end = true;
}

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

std::vector<std::vector<int>> NodeHeap::getChildrenPosition(){
    std::vector<NodeGraph*> graph_children = _graph_reference->getChildren();
    std::vector<std::vector<int>> children_position;
    for(int i=0; i<graph_children.size(); i++){
        children_position.push_back(graph_children[i]->getPosition());
    }
    return children_position;
}
