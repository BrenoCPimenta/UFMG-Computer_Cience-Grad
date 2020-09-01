#include "NodeGraph.hpp"

using namespace std;

NodeGraph::NodeGraph(int value, int y, int x):_value(value), _x_position(x), _y_position(y){}

bool NodeGraph::hasChildren(){
    return this->_has_children;
}

std::vector<NodeGraph*> NodeGraph::getChildren(){
    return this->_children;
}

std::vector<std::vector<int>> NodeGraph::getChildrenPosition(){
    std::vector<std::vector<int>> children_position;
    if(!this->_children.empty()){
        for(int i=0; i<(int)this->_children.size(); i++){
            std::vector<int> temp_posicao = this->_children[i]->getPosition();
            children_position.push_back(temp_posicao);
        }
    }
    return children_position;
}


int NodeGraph::getValue(){
    return this->_value;
}

int NodeGraph::getNumberOfChildren(){
    return this->_children.size();
}

vector<int> NodeGraph::getPosition(){
    std::vector<int> positions;
    positions.push_back(this->_y_position);
    positions.push_back(this->_x_position);
    return positions;
}

bool NodeGraph::isFinalPosition(){
    return _is_final_position;
}

void NodeGraph::setAsFinalPosition(){
    this->_is_final_position = true;
}

void NodeGraph::setChildren(NodeGraph *node){
    this->_has_children = true;
    this->_children.push_back(node);
}

